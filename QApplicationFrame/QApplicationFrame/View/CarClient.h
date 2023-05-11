#pragma once
#pragma execution_character_set("utf-8")
#include <QMainWindow>
#include "ui_CarClient.h"
#include <QString>
#include <QSerialPort>
#include "qdebug.h"
#include "qfile.h"
#include "qtimeline.h"
#include "qtimezone.h"
#include "qserialportinfo.h"
#include "qthread.h"
class SerialPortParam
{
public:
	QString portName = "COM1";
	int baudRate = 921600;
	QSerialPort::DataBits dataBits = QSerialPort::Data8;
	QSerialPort::StopBits stopBits = QSerialPort::OneStop;
	QSerialPort::Parity parity = QSerialPort::NoParity;

	static int getBuadRate(int n)
	{
		switch (n)
		{
		case 1200: return QSerialPort::Baud1200;
		case 2400: return QSerialPort::Baud2400;
		case 4800: return QSerialPort::Baud4800;
		case 9600: return QSerialPort::Baud9600;
		case 19200: return QSerialPort::Baud19200;
		case 38400: return QSerialPort::Baud38400;
		case 57600: return QSerialPort::Baud57600;
		case 115200: return QSerialPort::Baud115200;
		case 460800: return 460800;
		default: return 921600;
		}
	}

	static QSerialPort::DataBits getDataBits(int n)
	{
		switch (n)
		{
		case 5: return QSerialPort::Data5;
		case 6: return QSerialPort::Data6;
		case 7: return QSerialPort::Data7;
		case 8: return QSerialPort::Data8;
		default: return QSerialPort::UnknownDataBits;
		}
	}

	static QSerialPort::StopBits getStopBits(int n)
	{
		switch (n)
		{
		case 1: return QSerialPort::OneStop;
		case 2: return QSerialPort::TwoStop;
		case 3: return QSerialPort::OneAndHalfStop;
		default: return QSerialPort::UnknownStopBits;
		}
	}

	static QSerialPort::Parity getParity(int n)
	{
		switch (n)
		{
		case 0: return QSerialPort::NoParity;
		case 2: return QSerialPort::EvenParity;
		case 3: return QSerialPort::OddParity;
		case 4: return QSerialPort::SpaceParity;
		case 5: return QSerialPort::MarkParity;
		default: return QSerialPort::UnknownParity;
		}
	}

	static int getBuadRate(QSerialPort::BaudRate n)
	{
		switch (n)
		{
		case QSerialPort::Baud1200: return 1200;
		case QSerialPort::Baud2400: return 2400;
		case QSerialPort::Baud4800: return 4800;
		case QSerialPort::Baud9600: return 9600;
		case QSerialPort::Baud19200: return 19200;
		case QSerialPort::Baud38400: return 38400;
		case QSerialPort::Baud57600: return 57600;
		case QSerialPort::Baud115200: return 115200;
		default: return 921600;
		}
	}

	static int getDataBits(QSerialPort::DataBits n)
	{
		switch (n)
		{
		case QSerialPort::Data5: return 5;
		case QSerialPort::Data6: return 6;
		case QSerialPort::Data7: return 7;
		case QSerialPort::Data8: return 8;
		default: return -1;
		}
	}

	static int getStopBits(QSerialPort::StopBits n)
	{
		switch (n)
		{
		case QSerialPort::OneStop: return 1;
		case QSerialPort::TwoStop: return 2;
		case QSerialPort::OneAndHalfStop: return 3;
		default: return -1;
		}
	}

	static int getParity(QSerialPort::Parity n)
	{
		switch (n)
		{
		case QSerialPort::NoParity: return 0;
		case QSerialPort::EvenParity: return 2;
		case QSerialPort::OddParity: return 3;
		case QSerialPort::SpaceParity: return 4;
		case QSerialPort::MarkParity: return 5;
		default: return -1;
		}
	}
};
class SerialPortHelper : public QObject
{
	Q_OBJECT

public:
	SerialPortHelper();
	~SerialPortHelper();
	QStringList getSerialPorts();
	virtual bool openSerialPort(const SerialPortParam&);
	virtual qint64 writeData(const QByteArray&);
	virtual void analysisData(const QByteArray& data);
	void closeSerialPort();
	//static SerialPortHelper* getInstance();

	virtual uint CRC16_2(uchar* buf, int len);	//CRCУ��
protected:
	QSerialPort* serialPort = nullptr;
private:
	static SerialPortHelper* serialPortHelper;
signals:
	void infoSignal(QString);
private slots:
	virtual void dataReceive();
};
class CarClient : public SerialPortHelper
{
	Q_OBJECT

public:
	CarClient();
	~CarClient();
	bool GetControll();
	bool releseControll();
	bool run();
	bool stop();
private:
	void code(QByteArray& allArr, const QByteArray& funDataArr)
	{
		allArr.clear();
		allArr.append(gId, gIdLen);
		allArr.append(gAddress, gAddressLen);
		allArr.append(funDataArr);
		uchar crcBuf[gCrcLen];
		CRC16_2(allArr, crcBuf);
		allArr.append((char*)crcBuf, gCrcLen);
		allArr.append(gEnd, gEndLen);
	}
	Ui::CarClientClass ui;
	SerialPortParam car_param;
	QByteArray dataBuff;
	
private slots:
	void analysisData(const QByteArray& dataArr);
	 void dataReceived();
	
	void CRC16_2(const QByteArray& ba, uchar* crcBuf);
	void mileInfoRet(const QByteArray& data);
	QString getLittleEnd(const QByteArray& data);
private :

	bool isReSetTime = false;
	bool isGetCarStat = false;
	double carDeta = 0.0001791;			//�������ļ��ж�ȡ
	double maxVol = 29;			//���۵�ѹ��29.4V,��ѹ���޷��ﵽ100%
	double minVol = 22.4;		//
	double volFullScale = 4096;	//�������
	double volRef = 3;			//�ο���ѹ
	double volRadio = 11;		//��ѹ����
	double timeFactor = 1;		//ʱ��ϵ��

	qlonglong detaTime = 0;	//detaTime = scannerT1 - carT1; scannerT2 = carT2 + detaTime; ��λΪ100ns
	double lastM = 0;		//��һ�������Ϣ�����ڼ�����̲�����ٶ�
	qulonglong lastT = 0;	//��һ��ʱ����Ϣ��ͬ��
	int nowFlsNumber = 1;	//�������ɵ�FLS���
	int id = 0;			//�����������ID
	QFile mileFile;
	QTime startTime;		//��ɨ���ǿ�ʼ��¼���ݵ�ʱ��Ϊ׼
	static const int gIdLen = 2;		//��ʶ������
	static const int gAddressLen = 1;	//��ַλ����
	static const int gFunLen = 1;		//�����볤��
	static const int gCrcLen = 2;		//crcУ���볤��
	static const int gEndLen = 2;		//��β����
	static const int gGnssHeadLen = 1;	//gnss���ݿ�ͷ����#
	static const int gGnssEndLen = 2;	//gnss���ݽ�β����
	static const int gGnssCmdHeadLen = 8;//gnss�����ͷ����
	static const int gBaseCodeLen = gIdLen + gAddressLen + gFunLen + gCrcLen + gEndLen;	//����ָ��ĳ���

	const char gId[gIdLen] = { 0x41, 0x54 };
	const char gAddress[gAddressLen] = { 0x64 };
	const char gEnd[gEndLen] = { 0x0D, 0x0A };

	static const int gScannerTLen = 8;	//ɨ����ʱ�����ݳ���
	static const int gCarTLen = 8;		//С��ʱ�����ݳ���
	static const int gSpeedLen = 2;		//�ٶ����ݳ���
	static const int gVoltLen = 2;		//��ѹ���ݳ���, tsd��Ŀ
	static const int gTempLen = 3;		//�¶����ݳ��ȣ�tsd��Ŀ
	static const int gMileLen = 9;		//������ݣ���һ��Ϊ����λ
	static const int gScannerDataLen = 9;	//ɨ��������֡��1��־+8����
	static const int gBtnDataLen = 2;	//��������Ϣ��1����ֵ+1��ťֵ
};

class CarClientView : public QMainWindow {
	Q_OBJECT
public:
	~CarClientView();
	CarClientView(QWidget* parent = nullptr);


private:

	Ui::CarClientClass ui;
	CarClient client;
private slots:
	void on_btn_start_clicked();
	void on_btn_stop_clicked();
	void on_btn_controll_clicked();
	void on_btn_release_clicked();

	void em(QString strMessage);
};