#pragma once
#ifndef LOG_H
#define LOG_H

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMutex>

//ѡ����Ļ��ӡ����������ļ����Ը����������ƻ��߿��ƺ�������λ�ö�����
//#define _DEBUG

//Ĭ�ϵ��Լ���Ϊwarning����С��warning����Ķ�����д����־�ļ�
//ֻ��release�汾��ʱ�򣬲Ż��������־��debug�汾����������նˡ�
namespace QT_LOG
{
    //Ĭ���ļ���Ϊ��ǰʱ��������log�ļ�
    static int m_LogLevel = 1;
    static QString m_LogFile = QString("%1.log").arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
    QMutex m_LogMutex;

    void customMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
    {
        //���������־����С�ڸü��𣬽�����д����־�ļ���Ĭ����warning���𣬼�debug��Ϣ����д����־�ļ�
        if (type < m_LogLevel)
        {
            return;
        }

        QString log_info;
        log_info = QString("%1").arg(msg);

        //Ϊ���̰߳�ȫ
        m_LogMutex.lock();

        QFile outFile(m_LogFile);
        outFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
        QTextStream ts(&outFile);
        ts << log_info << endl;
        outFile.close();

        m_LogMutex.unlock();
    }

    //Ĭ�ϵ��Լ���Ϊwarning�����ϲŻ�д����־�ļ���Ĭ��log�ļ���Ϊ��������ʱ��������log�ļ�
    void logInit(QString logFile = "", int logLevel = 1)
    {
#ifndef _DEBUG  //ʵ��debug�汾��ʱ��������նˣ�release�汾��ʱ���������־�ļ�
        if ((logLevel < 0) || (logLevel > 3))
        {
            m_LogLevel = 1;
        }
        else
        {
            m_LogLevel = logLevel;
        }

        if (!logFile.isEmpty())
        {
            m_LogFile = logFile;
        }

        qInstallMessageHandler(customMessageHandler);
#endif
    }
}

#endif // LOG_H