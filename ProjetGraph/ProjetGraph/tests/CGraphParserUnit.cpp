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
}
