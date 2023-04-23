#pragma once
//Author:Leventure
//Date:2023-4-23
//Info:ϵͳ���ԣ����ڴ��һЩ��ǰϵͳ�µ���Ϣ
#include <QObject>
#include "qmutex.h"
#include "qsharedpointer.h"
#include "qjsonobject.h"
#include "qjsonvalue.h"
#include "qexception.h"
#include "qjsonarray.h"
//����0��Ȩ
enum class DevState {
	None = 0, //�û�ģʽ
	Developer_Mode = 1 , //������ģʽ
	Infomation_Mode = 2 //����ģʽ
};

class SystemInfo  : public QObject
{
	Q_OBJECT

public:
	SystemInfo();
	~SystemInfo();

	static SystemInfo* SystemInfo::Singleton() {
		static QMutex mutext;
		static QSharedPointer<SystemInfo> inst;
		if (Q_UNLIKELY(!inst)) {
			if (!inst) {
				inst.reset(new SystemInfo());
			}
		}
		return inst.data();
	}

	DevState Dev_Mode = DevState::None;   //������ģʽ

};
