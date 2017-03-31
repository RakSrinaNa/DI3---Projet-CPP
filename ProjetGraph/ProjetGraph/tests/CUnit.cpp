#include "CUnit.h"
#include "CExceptionUnit.h"
#include "CMatrixUnit.h"
#include "CMatrixParserUnit.h"
#include "CSquareMatrixUnit.h"

void CUnit::UNITassertError(const char * pcMessage)
{
	perror(pcMessage);
	raise(SIGINT);
	exit(EXIT_FAILURE);
}

void CUnit::UNITlaunchTests()
{
	fflush(stdout);
}
