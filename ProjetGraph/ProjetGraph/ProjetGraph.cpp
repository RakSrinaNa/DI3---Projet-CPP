#include <iostream>
#include "tests/CUnit.h"

#include "CGraph.h"

int main(int argc, char * argv[])
{
	if(argc == 1)
	{
		CUnit::UNITlaunchTests();
	}
	else if(argc == 2)
	{
		CGraph * poGRAgraph1 = new CGraph(argv[1]);
		
		poGRAgraph1->GRAdisplay();
		
		CGraph oGRAgraph2;
		oGRAgraph2 = *poGRAgraph1;
		
		oGRAgraph2.GRAinvert();
		
		oGRAgraph2.GRAdisplay();
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
 