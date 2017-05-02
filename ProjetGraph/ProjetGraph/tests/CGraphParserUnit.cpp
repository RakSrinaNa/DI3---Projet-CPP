#include "CGraphParserUnit.h"
#include "../CGraphParser.h"
#include "CUnit.h"

void CGraphParserUnit::PGRAUnitTests()
{
	CGraph * graph = CGraphParser::PGRAreadGraph((char *) "g1.txt");
	if(!graph->GRAhasVertex(1) || !graph->GRAhasVertex(2) || !graph->GRAhasVertex(3) || !graph->GRAhasVertex(4) || !graph->GRAhasVertex(5))
		CUnit::UNITassertError("ASSERT CGRAPHPARSER 1");
	if(!graph->GRAhasArc(1, 2) || !graph->GRAhasArc(2, 3) || !graph->GRAhasArc(3, 4) || !graph->GRAhasArc(4, 5) || !graph->GRAhasArc(5, 1))
		CUnit::UNITassertError("ASSERT CGRAPHPARSER 2");
	delete graph;
	
	graph = CGraphParser::PGRAreadGraph((char *) "g2.txt");
	if(!graph->GRAhasVertex(1) || !graph->GRAhasVertex(2) || !graph->GRAhasVertex(3) || !graph->GRAhasVertex(4) || !graph->GRAhasVertex(5) || !graph->GRAhasVertex(6) || !graph->GRAhasVertex(7) || !graph->GRAhasVertex(8) || !graph->GRAhasVertex(9) || !graph->GRAhasVertex(10) || !graph->GRAhasVertex(11) || !graph->GRAhasVertex(12) || !graph->GRAhasVertex(13) || graph->GRAhasVertex(14) || !graph->GRAhasVertex(15) || graph->GRAhasVertex(16) || !graph->GRAhasVertex(17))
		CUnit::UNITassertError("ASSERT CGRAPHPARSER 3");
	if(!graph->GRAhasArc(1, 2) || !graph->GRAhasArc(2, 3) || !graph->GRAhasArc(3, 4) || !graph->GRAhasArc(4, 5) || !graph->GRAhasArc(5, 1) || !graph->GRAhasArc(5, 2) || !graph->GRAhasArc(5, 3) || !graph->GRAhasArc(5, 4) || !graph->GRAhasArc(5, 5) || !graph->GRAhasArc(5, 6) || !graph->GRAhasArc(5, 7) || !graph->GRAhasArc(5, 8) || !graph->GRAhasArc(5, 9) || !graph->GRAhasArc(5, 10) || !graph->GRAhasArc(5, 11) || !graph->GRAhasArc(5, 12) || !graph->GRAhasArc(5, 13) || !graph->GRAhasArc(5, 15) || !graph->GRAhasArc(5, 17))
		CUnit::UNITassertError("ASSERT CGRAPHPARSER 4");
	delete graph;
}
