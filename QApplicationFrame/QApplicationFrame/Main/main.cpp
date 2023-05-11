#include <QtCore/QCoreApplication>
#include "../Main/MainApplication.h"
#include "../Tools/Tools_South.h"
//#include "../QDumper/LgQDumper.h"
#include "Log.h"
#include "qdebug.h"
//Author:Leventure
//Date:2023-4-23
//Info:Qt����Ļ�����ܣ�����Qt����Ӧ�õĿ�ܣ�����QDump�����̵�
//��Ҫ���ݰ���һ����ʽע���˵�QDumper����д�˵�QApplication����������ʵ������������־ϵͳ
//��Ҫʹ��Application��Ϊ������ĵײ���̿�ܣ���Ϊ��֪�������᲻��ʹ�õ�������Ϣ����Ȼ��Ҳ����ֱ�ӻ���QCoreApplication������Ҫ�����м���
// ����Ҫ�ṩһ������ģʽ��������ͨ��https://github.com/LeventureQys/Leventure_DevelopKey�����ߵ��Թ��߽���
//������:MSVC2017_32
//����ģ��:core;gui;widgets
int main(int argc, char *argv[])
{
    MainApplication app(argc, argv);


    qDebug() << "��ǰʹ�õ���Windowsϵͳ";
    //SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);
    QT_LOG::logInit("errorlog.txt", 0);

    app.Start();

    return app.exec();
}
