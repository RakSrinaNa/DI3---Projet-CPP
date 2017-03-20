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
	printf("Executing CException tests... ");
	CExceptionUnit::EXUnitTests();
	printf("OK\n");
	
	printf("Executing CMatrix tests... ");
	CMatrixUnit::MTXUnitTests();
	printf("OK\n");
	
	printf("Executing CMatrixParser tests... ");
	CMatrixParserUnit::MTXPUnitTests();
	printf("OK\n");
	
	
	fflush(stdout);
}
