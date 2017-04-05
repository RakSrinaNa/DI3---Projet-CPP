#include "CGraphUnit.h"
#include "../CGraph.h"
#include "CUnit.h"
#include "../CException.h"

void CGraphUnit::GRAUnitTests()
{
	GRAUnitTestVertices();
	GRAUnitTestArcs();
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
	
	oGraph.GRAremoveVertex(5);
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
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B3.2");
	}
	try
	{
		oGraph.GRAaddArc(6, 1);
		CUnit::UNITassertError("ASSERT CGRAPH B3.3");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B3.4");
	}
	
	/* Test removing arc with missing vertex */
	try
	{
		oGraph.GRAaddArc(1, 6);
		CUnit::UNITassertError("ASSERT CGRAPH B4.1");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B4.2");
	}
	try
	{
		oGraph.GRAaddArc(6, 1);
		CUnit::UNITassertError("ASSERT CGRAPH B4.3");
	}
	catch(CException const& oEXexception)
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
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B6.2");
	}
	try
	{
		oGraph.GRAmodifyArc(1, 6, 3);
		CUnit::UNITassertError("ASSERT CGRAPH B6.3");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B6.4");
	}
	try
	{
		oGraph.GRAmodifyArc(1, 2, 6);
		CUnit::UNITassertError("ASSERT CGRAPH B6.5");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B6.6");
	}
	try
	{
		oGraph.GRAmodifyArc(1, 2, 3);
		CUnit::UNITassertError("ASSERT CGRAPH B6.7");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_ARC_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPH B6.8");
	}
	
	oGraph.GRAremoveArc(1, 3);
	
	/* Test adding link */
	oGraph.GRAaddLink(1, 2);
	if(!oGraph.GRAhasArc(1, 2) || ! oGraph.GRAhasArc(2, 1))
		CUnit::UNITassertError("ASSERT CGRAPH B7");
	
	oGraph.GRAaddLink(2, 3);
	oGraph.GRAremoveVertex(2);
	if(oGraph.GRAhasArc(1, 2) || oGraph.GRAhasArc(2, 1) || oGraph.GRAhasArc(2, 3) || oGraph.GRAhasArc(3, 2))
		CUnit::UNITassertError("ASSERT CGRAPH B8");
}
