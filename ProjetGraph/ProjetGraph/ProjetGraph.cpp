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
		CGraph * poGRAgraph1 = new CGraph(argv[1]);
		CGraphToolbox oGRTtoolbox = CGraphToolbox(*poGRAgraph1);
		delete poGRAgraph1;
		
		oGRTtoolbox.GRTgetGraph().GRAdisplay();
		
		printf("Is this graph connex? %d\n", oGRTtoolbox.GRTisConnex());
	}
	else
	{
		std::cout << "Plusieurs parametres sont presents. Seulement UN nom de fichier est attendu." << std::endl;
	}
#ifdef _MSC_VER
	std::cout << "Appuyez sur une touche pour continuer...";
	getchar();
#endif
	return 0;
}
 