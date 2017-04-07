#include <iostream>
#include "tests/CUnit.h"

int main(int argc, char * argv[])
{
	if(argc == 1)
		CUnit::UNITlaunchTests();
	else if(argc == 2)
	{
		// CGraphParser::readGraph(argv[1]);
		// Actions TODO
	}
#ifdef _MSC_VER
	std::cout << "Appuyez sur une touche pour continuer...";
	getchar();
#endif
	return 0;
}
 