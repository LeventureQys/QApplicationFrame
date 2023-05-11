#pragma once
//Author:Leventure
//Date:2023-4-23
//Info:�����̣��ý���ֻӦ�ñ�����һ��
#include <QApplication>
#include "qapplication.h"
#include "../Tools/Tools_South.h"
#include "../LocalInfo/SystemInfo.h"
#include "qlist.h"
#include "../View/CarClient.h"
class MainApplication  : public QApplication
{
	Q_OBJECT

public:
	MainApplication(int& argc, char** argv);
	~MainApplication();
	
	void Start();

private:


	void initApplication();
	void AnalysisArgs(QList<QString> argv); //�������飬������ģʽ���

	//Ѱ����־
	inline void nLog(QString FuncName, QString strValue) {
		South_Tools::WriteNormalMessage(this->metaObject()->className(), FuncName, strValue);
	}
	//�쳣��־
	inline void eLog(QString FuncName, QString strValue) {
		South_Tools::WriteErrorMessage(this->metaObject()->className(), FuncName, strValue);
	}

	QSharedPointer<QThread> thread_tcp;
	QSharedPointer<QThread> thread_file;
	CarClientView view;
};
