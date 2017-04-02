#include <iostream>
#include "CUnit.h"
#include "CExceptionUnit.h"
#include "CArcUnit.h"

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
	std::cout << "CException OK" << std::endl << std::endl;
	
	std::cout << "Starting CArc tests..." << std::endl;
	CArcUnit::ARCUnitTests();
	std::cout << "CArc OK" << std::endl << std::endl;
}
