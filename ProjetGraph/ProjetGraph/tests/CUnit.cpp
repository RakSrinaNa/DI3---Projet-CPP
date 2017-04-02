#include <iostream>
#include "CUnit.h"
#include "CExceptionUnit.h"
#include "CArcUnit.h"
#include "CVertexUnit.h"
#include "CGraphUnit.h"

void CUnit::UNITassertError(const char * pcMessage)
{
	perror(pcMessage);
	perror("\n");
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
	
	std::cout << "Starting CVertex tests..." << std::endl;
	CVertexUnit::VERUnitTest();
	std::cout << "CVertex OK" << std::endl << std::endl;
	
	std::cout << "Starting CGraph tests..." << std::endl;
	CGraphUnit::GRAUnitTests();
	std::cout << "CGraph OK" << std::endl << std::endl;
}
