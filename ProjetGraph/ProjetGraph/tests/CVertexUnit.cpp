#include "CVertexUnit.h"
#include "../CException.h"
#include "CUnit.h"
#include "../CVertex.h"

void CVertexUnit::VERUnitTest()
{
	VERUnitTestConstructorGetSet();
	VERUnitTestArcIn();
	VERUnitTestArcOut();
}

void CVertexUnit::VERUnitTestConstructorGetSet()
{
	/* Test empty constructor, shouldn't be used */
	try
	{
		CVertex();
		CUnit::UNITassertError("ASSERT VERTEX A1");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT VERTEX A2");
	}
	
	/* Test confort constructor & index getter */
	CVertex oVERvertex1 = CVertex(5);
	CVertex oVERvertex2 = CVertex(15);
	
	if(oVERvertex1.VERgetVertexIndex() != 5 || oVERvertex2.VERgetVertexIndex() != 15)
		CUnit::UNITassertError("ASSERT VERTEX A3");
}

void CVertexUnit::VERUnitTestArcIn()
{
	/* Test add arcIn */
	CVertex oVERvertex = CVertex(0);
	
	oVERvertex.VERaddArcIn(10);
	if(!oVERvertex.VERhasIndexIn(10))
		CUnit::UNITassertError("ASSERT VERTEX B1");
	
	/* Test adding duplicate */
	try
	{
		oVERvertex.VERaddArcIn(10);
		CUnit::UNITassertError("ASSERT VERTEX B2");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != DUPLICATE_ARC_EXCEPTION)
			CUnit::UNITassertError("ASSERT VERTEX B3");
	}
	
	/* Test removing arcIn */
	oVERvertex.VERremoveArcIn(10);
	if(oVERvertex.VERhasIndexIn(10))
		CUnit::UNITassertError("ASSERT VERTEX B4");
	
	/* Test removing unknown arcIn */
	oVERvertex.VERremoveArcIn(99);
	
	/* Test modifying existing arcIn */
	oVERvertex.VERaddArcIn(15);
	oVERvertex.VERmodifyArcIn(15, 30);
	if(oVERvertex.VERhasIndexIn(15) || !oVERvertex.VERhasIndexIn(30))
		CUnit::UNITassertError("ASSERT VERTEX B5");
	
	/* Test modifying unknown arcIn */
	oVERvertex.VERmodifyArcIn(15, 20);
	if(oVERvertex.VERhasIndexIn(15) || oVERvertex.VERhasIndexIn(20))
		CUnit::UNITassertError("ASSERT VERTEX B6");
}

void CVertexUnit::VERUnitTestArcOut()
{
	/* Test add arcOut */
	CVertex oVERvertex = CVertex(0);
	
	oVERvertex.VERaddArcOut(10);
	if(!oVERvertex.VERhasIndexOut(10))
		CUnit::UNITassertError("ASSERT VERTEX C1");
	
	/* Test adding duplicate */
	try
	{
		oVERvertex.VERaddArcOut(10);
		CUnit::UNITassertError("ASSERT VERTEX C2");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != DUPLICATE_ARC_EXCEPTION)
			CUnit::UNITassertError("ASSERT VERTEX C3");
	}
	
	/* Test removing arcOut */
	oVERvertex.VERremoveArcOut(10);
	if(oVERvertex.VERhasIndexOut(10))
		CUnit::UNITassertError("ASSERT VERTEX C4");
	
	/* Test removing unknown arcOut */
	oVERvertex.VERremoveArcOut(99);
	
	/* Test modifying existing arcOut */
	oVERvertex.VERaddArcOut(15);
	oVERvertex.VERmodifyArcOut(15, 30);
	if(oVERvertex.VERhasIndexOut(15) || !oVERvertex.VERhasIndexOut(30))
		CUnit::UNITassertError("ASSERT VERTEX C5");
	
	/* Test modifying unknown arcOut */
	oVERvertex.VERmodifyArcOut(15, 20);
	if(oVERvertex.VERhasIndexOut(15) || oVERvertex.VERhasIndexOut(20))
		CUnit::UNITassertError("ASSERT VERTEX C6");
}
