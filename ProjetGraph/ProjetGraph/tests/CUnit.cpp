#include <iostream>
#include "CUnit.h"
#include "CExceptionUnit.h"

void CUnit::UNITassertError(const char * pcMessage)
{
	perror(pcMessage);
	raise(SIGINT);
	exit(EXIT_FAILURE);
}

void CUnit::UNITlaunchTests()
{
	std::cout << "Starting CException tests..." << std::endl;
	CExceptionUnit::EXUnitTests();
	std::cout << "CException OK" << std::endl;
}
