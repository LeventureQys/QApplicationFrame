#include "CarClient.h"
#pragma execution_character_set("utf-8")

SerialPortHelper::SerialPortHelper()
{
}

SerialPortHelper::~SerialPortHelper()
{
}

QStringList SerialPortHelper::getSerialPorts()
{
	QStringList portNames = {};
	QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
	for (QSerialPortInfo port : ports)
	{
		portNames << port.portName();
	}
	return portNames;
}

bool SerialPortHelper::openSerialPort(const SerialPortParam& param)
{
	serialPort = new QSerialPort;
	if (serialPort->open(QIODevice::ReadWrite))
	{
		connect(serialPort, &QSerialPort::readyRead, this, &SerialPortHelper::dataReceive);
		serialPort->setBaudRate(param.baudRate);
		serialPort->setDataBits(param.dataBits);
		serialPort->setStopBits(param.stopBits);
		serialPort->setParity(param.parity);
		serialPort->setPortName(param.portName);
		return true;
	}
	else return false;
}

void SerialPortHelper::dataReceive()
{
	QByteArray buffer = serialPort->readAll();
	analysisData(buffer);
}

qint64 SerialPortHelper::writeData(const QByteArray& data)
{
	qint64 ret = -1;
	if (serialPort->isOpen())
	{
		ret = serialPort->write(data);
		if (!serialPort->waitForBytesWritten(10000))	//默认参数为30秒
		{
			qDebug() << "发送失败：" + data.toHex(' ');
			emit infoSignal("发送失败：" + data.toHex(' '));
		}
	}
	return ret;
}

void SerialPortHelper::closeSerialPort()
{
	serialPort->clear();
	serialPort->close();
	serialPort->deleteLater();
}

void SerialPortHelper::analysisData(const QByteArray& data)
{

}

uint SerialPortHelper::CRC16_2(uchar* buf, int len)
{
	int pos, i;
	unsigned int crc = 0xFFFF;
	for (pos = 0; pos < len; pos++)
	{
		crc ^= (unsigned int)buf[pos]; // XOR byte into least sig. byte of crc
		for (i = 8; i != 0; i--) // Loop over each bit
		{
			if ((crc & 0x0001) != 0) // If the LSB is set
			{
				crc >>= 1; // Shift right and XOR 0xA001
				crc ^= 0xA001;
			}
			else // Else LSB is not set
			{
				crc >>= 1; // Just shift right
			}
		}
	}
	//高低字节转换
	crc = ((crc & 0x00ff) << 8) | ((crc & 0xff00) >> 8);
	qDebug() << QString().sprintf("%04x", crc);
	return crc;
}

//SerialPortHelper* SerialPortHelper::serialPortHelper = nullptr;
//
//SerialPortHelper* SerialPortHelper::getInstance()
//{
//	if (serialPortHelper == nullptr)
//		serialPortHelper = new SerialPortHelper;
//	return serialPortHelper;
//}

CarClient::CarClient()
	: SerialPortHelper()
{
	//ui.setupUi(this);
	this->car_param.portName = "COM4";
	this->car_param.baudRate = 921600;
	this->car_param.dataBits = QSerialPort::Data8;
	this->car_param.stopBits = QSerialPort::OneStop;
	this->car_param.parity = QSerialPort::NoParity;

	mileFile.setFileName("Mile.txt");

}

CarClient::~CarClient()
{

}

void CarClientView::on_btn_start_clicked() {

	if (this->client.run()) {
		this->em("启动指令发送成功");
	}
	else {
		this->em("启动指令发送失败");
	}
}

bool CarClient::GetControll()
{
	if (serialPort != nullptr)
	{
		if (serialPort->isOpen())   //已连接，直接返回
		{
			this->ui.txt->appendPlainText("connected already!");
			return true;
		}
		else                        //未连接，先delete
		{
			serialPort->close();
			serialPort->deleteLater();
			serialPort = nullptr;
		}
	}
	serialPort = new QSerialPort();
	serialPort->setPortName(this->car_param.portName);
	if (serialPort->open(QIODevice::ReadWrite))
	{
		serialPort->setBaudRate(this->car_param.baudRate);
		serialPort->setDataBits(this->car_param.dataBits);
		serialPort->setStopBits(this->car_param.stopBits);
		serialPort->setParity(this->car_param.parity);
		connect(serialPort, &QSerialPort::readyRead, this, &CarClient::dataReceived);
		
		//qDebug() << "connect:" << param.portName;
		//emit checkConnableRetSig(true);

		//setStartTime();
		//emit comConnStatus(true);
		return true;
	}
	else
	{
		//qDebug() << "connect fail..." << param.portName;
		//this->ui.txt->appendPlainText(QString("connect failed %1").arg(this->car_param.portName));
		return false;
	}
}

bool CarClient::releseControll()
{
	if (serialPort != nullptr && serialPort->isOpen())
	{
		serialPort->disconnect();
		serialPort->close();
		serialPort->deleteLater();
		serialPort = nullptr;
	}
	return true;
}

bool CarClient::run()
{
	QByteArray allArr, funDataArr;
	funDataArr.clear();
	funDataArr.append(0x0E);
	QByteArray speedBarr;
	//速度两字节，低字节在前
	ushort speed = 2000;
	while (speed > 0)
	{
		char c = speed & 0x00ff;
		speedBarr.append(c);
		speed >>= 8;
	}
	funDataArr.append(speedBarr);
	code(allArr, funDataArr);
	if (!writeData(allArr)) {
		return false;
	}

	QThread::msleep(1000);

	funDataArr.clear();
	funDataArr.append(0x0B);
	funDataArr.append((char)0x00);
	funDataArr.append(0x01);
	code(allArr, funDataArr);
	this->mileFile.setFileName("mileFIle.txt");
	this->mileFile.open(QIODevice::ReadOnly);
	//qDebug() << "is mile file open" + QString("%1").arg(this->mileFile.isOpen());
	return writeData(allArr);
}

bool CarClient::stop()
{
	QByteArray allArr, funDataArr;
	funDataArr.clear();
	funDataArr.append(0x0C);
	funDataArr.append((char)0x00);
	funDataArr.append(0x01);
	code(allArr, funDataArr);
	return writeData(allArr);
}

void CarClientView::on_btn_stop_clicked() {
	if (this->client.stop()) {
		this->em("停车成功");
	}
	else {
		this->em("停车失败");
	}
	
}

void CarClientView::on_btn_controll_clicked()
{
	if (this->client.GetControll()) {
		this->em("获取串口控制");
	}
	else {
		this->em("串口控制获取失败");
	}
}

void CarClientView::on_btn_release_clicked()
{
	this->client.releseControll();
	this->em("放弃小车控制");
}

void CarClientView::em(QString strMessage)
{
	this->ui.txt->appendPlainText(strMessage);
}

void CarClient::dataReceived()
{
	if (serialPort != nullptr && serialPort->isOpen())
	{
		QByteArray buffer = serialPort->readAll();
		analysisData(buffer);
	}
}
void CarClient::CRC16_2(const QByteArray& ba, uchar* crcBuf)
{
	int pos, i;
	uchar* buf = (uchar*)ba.data();
	int len = ba.size();
	unsigned int crc = 0xFFFF;
	for (pos = 0; pos < len; pos++)
	{
		crc ^= (unsigned int)buf[pos]; // XOR byte into least sig. byte of crc
		for (i = 8; i != 0; i--) // Loop over each bit
		{
			if ((crc & 0x0001) != 0) // If the LSB is set
			{
				crc >>= 1; // Shift right and XOR 0xA001
				crc ^= 0xA001;
			}
			else // Else LSB is not set
			{
				crc >>= 1; // Just shift right
			}
		}
	}
	//高低字节转换
	crc = ((crc & 0x00ff) << 8) | ((crc & 0xff00) >> 8);
	//qDebug() << QString().sprintf("CRC:%04x", crc);
	crcBuf[0] = crc >> 8;
	crcBuf[1] = crc;
}
void CarClient::analysisData(const QByteArray& dataArr)
{
	//qDebug() << "recv data: " << dataArr.toHex(' ');
	dataBuff.append(dataArr);
	QList<QByteArray> dataList;
	for (;;)
	{
		int index = dataBuff.indexOf(QByteArray(gEnd, gEndLen));
		if (index == -1) break;
		dataList.append(dataBuff.mid(0, index + gEndLen));
		dataBuff = dataBuff.right(dataBuff.size() - index - gEndLen);
	}
	if (dataList.size() == 0) return;

	QByteArray data;
	data.clear();
	for (int i = 0; i < dataList.size(); ++i)
	{
		data = dataList.at(i);
		int len = data.length();
		if (len < gBaseCodeLen)
		{
			//emit sendWarningSig("recv data len err: " + data.toHex(' '));
			qDebug() << QString("recv data len err: " + data.toHex(' '));
			return;
		}
		//if (data.startsWith(gId) && data.endsWith(gEnd))
		//{
			uchar crcS[gCrcLen];											//内容对应crc
			QByteArray buf = data.left(len - gCrcLen - gEndLen);			//算crc的内容
			CRC16_2(buf, crcS);
			QByteArray crcT = data.mid(len - gCrcLen - gEndLen, gCrcLen);	//返回的crc
			if (QByteArray((char*)crcS, gCrcLen) == crcT)					//crc
			{
				char funCode = data.at(gIdLen + gAddressLen);
				QByteArray dataArr = data.mid(gIdLen + gAddressLen + gFunLen, len - gBaseCodeLen);
				switch ((uchar)funCode)
				{
				case 0xFE:
				{
					mileInfoRet(dataArr);
					break;
				}
				default:
					break;
				}
			}
		//}
		//else
		//{
		//	//emit sendWarningSig("analysisData err: " + data.toHex(' '));
		//	qDebug() << QString("analysisData err: " + data.toHex(' '));
		//}
	}

}

void CarClient::mileInfoRet(const QByteArray& data)
{
	if (data.size() != gMileLen + gCarTLen) return;
	int sign = -1;	//0x00为正，0x01为负
	if (data[0] == 0x00) sign = 1;
	QString mileStr = getLittleEnd(data.mid(1, gMileLen - 1));	//m
	double mileage = sign * mileStr.toLongLong() * carDeta;
	QString carTStr = getLittleEnd(data.mid(gMileLen, gCarTLen));
	//将小车时间同步成对应的扫描仪时间
	qulonglong carT = carTStr.toULongLong() * timeFactor;	//us
	QString scannerT = QString::number(carT + detaTime);	//us

	qulonglong detaT = (carT - lastT);
	double speed = 0;
	if (detaT != 0)
		speed = (mileage - lastM) * 3600 / detaT * 1000000;
	lastM = mileage;
	lastT = carT;
	id++;
	QString str =
		"{\"ID\":" + QString::number(id) + ","
		+ "\"Mileage\":" + QString::number(mileage, 'f') + ","
		+ "\"Time\":\"" + scannerT + "\"};";
	qDebug() << str;
	//if (mileFile.isOpen())
	//{
	//	mileFile.write(str.toUtf8());
	//	mileFile.flush();
	//}

	if (id % 20 == 0)
	{
		int t = startTime.secsTo(QTime::currentTime());
		QString jStr = "{\"mileage\":\"" + QString::number(mileage, 'f') + "\",\"time\":\"" + QString::number(t) + "\"}";
		//std::cout << jStr.toStdString();
	}
}

QString CarClient::getLittleEnd(const QByteArray& data)
{
	if (data.size() > 8) return "";
	qulonglong result = 0;
	for (int i = 0; i < data.size(); ++i)
	{
		qulonglong tmp = (uchar)data[i];
		result += tmp <<= i * 8;
	}
	return QString::number(result);
}

CarClientView::~CarClientView()
{
}

CarClientView::CarClientView(QWidget* parent)
{
	ui.setupUi(this);


}
