#pragma once

#ifdef _WIN32
#include <windows.h>
#include <dbghelp.h>
class LgQDumper
{
public:
	LgQDumper();
};
//ע������2��ͷ�ļ������˳��


extern char* g_qsDumpName;

class QtDumpGenerate
{
public:
	QtDumpGenerate();

	void ApplicationCrashHandler(EXCEPTION_POINTERS* pException);
};

// dump����
// ʹ�÷����� SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);
//��дdump�ļ�����鱨�� 
//QString g_qsDumpName = "LgInteractSmartCompus";
//SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);
long ApplicationCrashHandler(EXCEPTION_POINTERS* pException);
#endif // _WIN32


