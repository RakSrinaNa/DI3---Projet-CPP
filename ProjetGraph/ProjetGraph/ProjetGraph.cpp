#include <iostream>
#include "tests/CUnit.h"

#include "CGraph.h"
#include "CGraphParser.h"

int main(int argc, char * argv[])
{
	if(argc == 1)
		CUnit::UNITlaunchTests();
	else if(argc == 2)
	{
		CGraph * graph =  new CGraph(argv[1]);

		graph->GRAdisplay();

		graph->GRAinvert();

		graph->GRAdisplay();
	}
#ifdef _MSC_VER
	std::cout << "Appuyez sur une touche pour continuer...";
	getchar();
#endif
	return 0;
}
 