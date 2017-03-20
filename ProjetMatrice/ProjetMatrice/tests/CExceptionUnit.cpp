#include <cstring>
#include "CExceptionUnit.h"
#include "CUnit.h"
#include "../CException.h"

void CExceptionUnit::EXUnitTests()
{
	EXUnitTestID();
	EXUnitTestMessage();
}

void CExceptionUnit::EXUnitTestID()
{
	CException * poEXexception = new CException(10);
	if(poEXexception->EXgetExceptionID() != 10)
		CUnit::UNITassertError((char *) "CException A1");
	
	poEXexception->EXsetExceptionID(30);
	if(poEXexception->EXgetExceptionID() != 30)
		CUnit::UNITassertError((char *) "CException A2");
	
	free(poEXexception);
}

void CExceptionUnit::EXUnitTestMessage()
{
	CException * poEXexception = new CException(10);
	if(poEXexception->EXgetExceptionMessage() != nullptr)
		CUnit::UNITassertError((char *) "CException B1");
	
	free(poEXexception);
	
	poEXexception = new CException(10, (char *) "Test");
	if(strcmp(poEXexception->EXgetExceptionMessage(), "Test") != 0)
		CUnit::UNITassertError((char *) "CException B2");
	
	poEXexception->EXsetExceptionMessage((char *) "HAHA");
	if(strcmp(poEXexception->EXgetExceptionMessage(), "HAHA") != 0)
		CUnit::UNITassertError((char *) "CException B3");
	
	free(poEXexception);
}
