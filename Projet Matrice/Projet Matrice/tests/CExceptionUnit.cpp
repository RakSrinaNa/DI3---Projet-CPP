#include <cstring>
#include "CExceptionUnit.h"
#include "UnitUtils.h"
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
		assertError((char *) "CException A1");
	
	poEXexception->EXsetExceptionID(30);
	if(poEXexception->EXgetExceptionID() != 30)
		assertError((char *) "CException A2");
	
	free(poEXexception);
}

void CExceptionUnit::EXUnitTestMessage()
{
	CException * poEXexception = new CException(10);
	if(poEXexception->EXgetExceptionMessage() != nullptr)
		assertError((char *) "CException B1");
	
	free(poEXexception);
	
	poEXexception = new CException(10, (char *) "Test");
	if(strcmp(poEXexception->EXgetExceptionMessage(), "Test") != 0)
		assertError((char *) "CException B2");
	
	poEXexception->EXsetExceptionMessage((char *) "HAHA");
	if(strcmp(poEXexception->EXgetExceptionMessage(), "HAHA") != 0)
		assertError((char *) "CException B3");
	
	free(poEXexception);
}
