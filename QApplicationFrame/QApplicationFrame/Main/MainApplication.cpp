#include "MainApplication.h"

MainApplication::MainApplication(int& argc, char** argv) :
	QApplication(argc, argv)
{
	this->initApplication();
	QList<QString> string_argv;
	for (int i = 0; i < argc; ++i) {
		string_argv.append(QString(argv[i]));
	}

	this->AnalysisArgs(string_argv);
}

MainApplication::~MainApplication()
{

}
void MainApplication::initApplication() {
	SystemInfo::Singleton(); //��ʼ����������
}

void MainApplication::AnalysisArgs(QList<QString> argv)
{
	//���ڰ�ȫ���ǣ��ѹر���������뿪����ģʽ�Ͳ���ģʽ�����
	// ���������Ҫ���뿪����ģʽ�Ͳ���ģʽ����Ҫ�����ҵĸ�����Կ����Ϊ�˺����Ŀ������ܹ�����ʹ��
	// �ҽ���� ������Կ ��Դ��github��ȥ�������Ҫ�����������Ŀ¼�»�ȡ
	// δ���ϸ���ܣ���Ȼ����Ҳ����������Կ������Դ�붼��������
	// https://github.com/LeventureQys/Leventure_DevelopKey
	// 
	// Leventure TODO:Ŀǰ�������ʶ�������⣬��ʱ�����������Կ�ˣ�ֱ��ͨ������������
	if (argv.contains("Dev")) {
		SystemInfo::Singleton()->Dev_Mode = DevState::Developer_Mode;
	}



}

void MainApplication::Start() {
	//�ṩ��ʼ��
	//��������״̬
	switch (SystemInfo::Singleton()->Dev_Mode)
	{
	case DevState::None:
		break;
	case DevState::Developer_Mode:
		break;
	case DevState::Infomation_Mode:
		break;
	default:
		break;
	}


	view.show();

}

