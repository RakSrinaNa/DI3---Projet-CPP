#include "CGraphUnit.h"
#include "../CGraph.h"
#include "CUnit.h"
#include "../CException.h"

void CGraphUnit::GRAUnitTests()
{
	GRAUnitTestVertices();
	GRAUnitTestArcs();
	GRAUnitTestCopy();
	GRAUnitTestReadFromFile();
}

void CGraphUnit::GRAUnitTestVertices()
{
	CGraph oGraph = CGraph();
	
	/* Test adding vertex */
	oGraph.GRAaddVertex(10);
	if(!oGraph.GRAhasVertex(10))
		CUnit::UNITassertError("ASSERT CGRAPH A1");
	
	/* Test remove vertex */
	oGraph.GRAremoveVertex(10);
	if(oGraph.GRAhasVertex(10))
		CUnit::UNITassertError("ASSERT CGRAPH A2");
	
	/* Test remove unknown vertex */
	oGraph.GRAremoveVertex(10);
	
	/* Test operator + */
	oGraph + 5;
	if(!oGraph.GRAhasVertex(5))
		CUnit::UNITassertError("ASSERT CGRAPH A3");
	
	oGraph - 5;
	if(oGraph.GRAhasVertex(5))
		CUnit::UNITassertError("ASSERT CGRAPH A4");
}

void CGraphUnit::GRAUnitTestArcs()
{
	CGraph oGraph = CGraph();
	oGraph + 1;
	oGraph + 2;
	oGraph + 3;
	
	/* Test adding arc */
	oGraph.GRAaddArc(1, 2);
	if(!oGraph.GRAhasArc(1, 2))
		CUnit::UNITassertError("ASSERT CGRAPH B1");
	
	/* Test removing arc */
	oGraph.GRAremoveArc(1, 2);
	if(oGraph.GRAhasArc(1, 2))
		CUnit::UNITassertError("ASSERT CGRAPH B2");
	
	/* Test adding arc with missing vertex */
	try
	{
		oGraph.GRAaddArc(1, 6);
		CUnit::UNITassertError("ASSERT CGRAPH B3.1");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B3.2");
	}
	try
	{
		oGraph.GRAaddArc(6, 1);
		CUnit::UNITassertError("ASSERT CGRAPH B3.3");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B3.4");
	}
	
	/* Test removing arc with missing vertex */
	try
	{
		oGraph.GRAremoveArc(1, 6);
		CUnit::UNITassertError("ASSERT CGRAPH B4.1");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B4.2");
	}
	try
	{
		oGraph.GRAremoveArc(6, 1);
		CUnit::UNITassertError("ASSERT CGRAPH B4.3");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B4.4");
	}
	
	/* Test modifying arc */
	oGraph.GRAaddArc(1, 2);
	oGraph.GRAmodifyArc(1, 2, 3);
	if(oGraph.GRAhasArc(1, 2) || !oGraph.GRAhasArc(1, 3))
		CUnit::UNITassertError("ASSERT CGRAPH B5");
	
	/* Test modifying arc with missing vertex */
	try
	{
		oGraph.GRAmodifyArc(6, 2, 3);
		CUnit::UNITassertError("ASSERT CGRAPH B6.1");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B6.2");
	}
	try
	{
		oGraph.GRAmodifyArc(1, 6, 3);
		CUnit::UNITassertError("ASSERT CGRAPH B6.3");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B6.4");
	}
	try
	{
		oGraph.GRAmodifyArc(1, 2, 6);
		CUnit::UNITassertError("ASSERT CGRAPH B6.5");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B6.6");
	}
	try
	{
		oGraph.GRAmodifyArc(1, 2, 3);
		CUnit::UNITassertError("ASSERT CGRAPH B6.7");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_ARC_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B6.8");
	}
	
	oGraph.GRAremoveArc(1, 3);
	
	/* Test adding link */
	oGraph.GRAaddLink(1, 2);
	if(!oGraph.GRAhasArc(1, 2) || !oGraph.GRAhasArc(2, 1))
		CUnit::UNITassertError("ASSERT CGRAPH B7");
	
	oGraph.GRAaddLink(2, 3);
	oGraph.GRAremoveVertex(2);
	if(oGraph.GRAhasArc(1, 2) || oGraph.GRAhasArc(2, 1) || oGraph.GRAhasArc(2, 3) || oGraph.GRAhasArc(3, 2))
		CUnit::UNITassertError("ASSERT CGRAPH B8");
}

void CGraphUnit::GRAUnitTestCopy()
{
	CGraph oGRAgraph1 = CGraph();
	oGRAgraph1.GRAaddVertex(1);
	oGRAgraph1.GRAaddVertex(2);
	oGRAgraph1.GRAaddVertex(3);
	oGRAgraph1.GRAaddArc(1, 2);
	oGRAgraph1.GRAaddArc(2, 3);
	oGRAgraph1.GRAaddArc(3, 1);
	
	CGraph oGRAgraph2;
	oGRAgraph2 = oGRAgraph1;
	if(!oGRAgraph2.GRAhasVertex(1) || !oGRAgraph2.GRAhasVertex(2) || !oGRAgraph2.GRAhasVertex(3) || !oGRAgraph2.GRAhasArc(1, 2) || !oGRAgraph2.GRAhasArc(2, 3) || !oGRAgraph2.GRAhasArc(3, 1))
		CUnit::UNITassertError("ASSERT CGRAPH C2");
}

void CGraphUnit::GRAUnitTestReadFromFile()
{
	CGraph * graph = new CGraph((char *) "g1.txt");
	if(!graph->GRAhasVertex(1) || !graph->GRAhasVertex(2) || !graph->GRAhasVertex(3) || !graph->GRAhasVertex(4) || !graph->GRAhasVertex(5))
		CUnit::UNITassertError("ASSERT CGRAPH D1");
	if(!graph->GRAhasArc(1, 2) || !graph->GRAhasArc(2, 3) || !graph->GRAhasArc(3, 4) || !graph->GRAhasArc(4, 5) || !graph->GRAhasArc(5, 1))
		CUnit::UNITassertError("ASSERT CGRAPH D2");
	delete graph;
	
	graph = new CGraph((char *) "g2.txt");
	if(!graph->GRAhasVertex(1) || !graph->GRAhasVertex(2) || !graph->GRAhasVertex(3) || !graph->GRAhasVertex(4) || !graph->GRAhasVertex(5) || !graph->GRAhasVertex(6) || !graph->GRAhasVertex(7) || !graph->GRAhasVertex(8) || !graph->GRAhasVertex(9) || !graph->GRAhasVertex(10) || !graph->GRAhasVertex(11) || !graph->GRAhasVertex(12) || !graph->GRAhasVertex(13) || graph->GRAhasVertex(14) || !graph->GRAhasVertex(15) || graph->GRAhasVertex(16) || !graph->GRAhasVertex(17))
		CUnit::UNITassertError("ASSERT CGRAPH D3");
	if(!graph->GRAhasArc(1, 2) || !graph->GRAhasArc(2, 3) || !graph->GRAhasArc(3, 4) || !graph->GRAhasArc(4, 5) || !graph->GRAhasArc(5, 1) || !graph->GRAhasArc(5, 2) || !graph->GRAhasArc(5, 3) || !graph->GRAhasArc(5, 4) || !graph->GRAhasArc(5, 5) || !graph->GRAhasArc(5, 6) || !graph->GRAhasArc(5, 7) || !graph->GRAhasArc(5, 8) || !graph->GRAhasArc(5, 9) || !graph->GRAhasArc(5, 10) || !graph->GRAhasArc(5, 11) || !graph->GRAhasArc(5, 12) || !graph->GRAhasArc(5, 13) || !graph->GRAhasArc(5, 15) || !graph->GRAhasArc(5, 17))
		CUnit::UNITassertError("ASSERT CGRAPH D4");
	delete graph;
}
