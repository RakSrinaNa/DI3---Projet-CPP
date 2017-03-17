#include "CUnit.h"
#include "CExceptionUnit.h"
#include "CMatrixUnit.h"
#include "CMatrixParserUnit.h"

void CUnit::UNITassertError(const char * pcMessage)
{
	perror(pcMessage);
	raise(SIGINT);
	exit(EXIT_FAILURE);
}

void CUnit::UNITlaunchTests()
{
	CExceptionUnit::EXUnitTests();
	CMatrixUnit::MTXUnitTests();
	CMatrixParserUnit::MTXPUnitTests();
}
