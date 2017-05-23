#include <iostream>
#include "tests/CUnit.h"

#include "CGraph.h"
#include "CGraphToolbox.h"

int main(int argc, char * argv[])
{
	if(argc == 1)
	{
		CUnit::UNITlaunchTests();
	}
	else if(argc == 2)
	{
		CGraph oGRAgraph = CGraph(argv[1]);
		CGraphToolbox oGRTtoolbox = CGraphToolbox(oGRAgraph);
		
		oGRTtoolbox.GRTgetGraph().GRAdisplay();
		
		printf("Is this graph connex? %d\n", oGRTtoolbox.GRTisConnex());
		
		oGRTtoolbox.GRTtransformNonOriented();
		printf("Is this non oriented graph connex? %d\n", oGRTtoolbox.GRTisConnex());
	}
	else
	{
		std::cout << "Several arguments are present. Only one file name is expected." << std::endl;
	}
#ifdef _MSC_VER
	std::cout << "Appuyez sur une touche pour continuer...";
	getchar();
#endif
	return 0;
}
 