#include "CUnit.h"
#include "../CMatrix.h"
#include "../CMatrixParser.h"
#include "CMatrixParserUnit.h"

void CMatrixParserUnit::MTXPUnitTests()
{
	CMatrix<double> * poMTXmatrix = CMatrixParser::PMTXreadMatrix((char *) "M1.txt");
	if(poMTXmatrix == nullptr)
		CUnit::UNITassertError("CMatrixParser 0");
	if(poMTXmatrix->MTXgetHeight() != 3)
		CUnit::UNITassertError("CMatrixParser 1");
	if(poMTXmatrix->MTXgetWidth() != 4)
		CUnit::UNITassertError("CMatrixParser 2");
	for(unsigned int uiIndex = 0; uiIndex < 12; uiIndex++)
		if(poMTXmatrix->MTXgetValue(uiIndex / 4, uiIndex % 4) != uiIndex + 1)
			CUnit::UNITassertError("CMatrixParser 3");
	delete poMTXmatrix;
	
	int piValues[] = {3, 5, 7, 1, 5, 9, 7, 4, 1, 3, 6, 9};
	poMTXmatrix = CMatrixParser::PMTXreadMatrix((char *) "M2.txt");
	if(poMTXmatrix->MTXgetHeight() != 4)
		CUnit::UNITassertError("CMatrixParser 4");
	if(poMTXmatrix->MTXgetWidth() != 3)
		CUnit::UNITassertError("CMatrixParser 5");
	for(unsigned int uiIndex = 0; uiIndex < 12; uiIndex++)
		if(poMTXmatrix->MTXgetValue(uiIndex / 3, uiIndex % 3) != piValues[uiIndex])
			CUnit::UNITassertError("CMatrixParser 6");
	delete poMTXmatrix;
	
	try
	{
		poMTXmatrix = CMatrixParser::PMTXreadMatrix((char *) "M4.txt");
		delete poMTXmatrix;
		CUnit::UNITassertError("CMatrixParser 7");
	}
	catch(CException const& poEXexception)
	{
		if(poEXexception.EXgetExceptionID() != UNSUPPORTED_TYPE_EXCEPTION)
			CUnit::UNITassertError("CMatrixParser 8");
	}
	
	CSquareMatrix<double> * poSMXmatrix;
	
	try
	{
		poSMXmatrix = CMatrixParser::PMTXreadSquareMatrix((char *) "M6.txt");
		delete poMTXmatrix;
		CUnit::UNITassertError("CMatrixParser 9");
	}
	catch(CException const& poEXexception)
	{
		if(poEXexception.EXgetExceptionID() != NOT_SQUARE_MATRIX)
			CUnit::UNITassertError("CMatrixParser 10");
	}
	
	int piValues2[] = {6, 5, 2, 9, 4, 3, 2, 8, 6};
	poSMXmatrix = CMatrixParser::PMTXreadSquareMatrix((char *) "M5.txt");
	if(poSMXmatrix->SMTXgetSize() != 3)
		CUnit::UNITassertError("CMatrixParser 11");
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		if(poSMXmatrix->MTXgetValue(uiIndex / 3, uiIndex % 3) != piValues2[uiIndex])
			CUnit::UNITassertError("CMatrixParser 12");
	
	delete poSMXmatrix;
}
