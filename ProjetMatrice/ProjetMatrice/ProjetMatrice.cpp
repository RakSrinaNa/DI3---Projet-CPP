#include "tests/CUnit.h"

int main(int argc, char* argv[])
{
	CUnit::UNITlaunchTests();

#ifdef _MSC_VER
	getchar();
#endif

	return 0;
}

