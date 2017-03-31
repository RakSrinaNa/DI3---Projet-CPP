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
	return 0;
}
 