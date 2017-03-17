#include "CMatrixParserUnit.h"
#include "CUnit.h"
#include "../CMatrix.h"
#include "../CMatrixParser.h"
#include "../CException.h"

void CMatrixParserUnit::MTXPUnitTests()
{
	CMatrix<double> * poMTXmatrix = CMatrixParser::PMTXreadFile((char *) "M1.txt");
	if(poMTXmatrix->MTXgetHeight() != 3)
		CUnit::UNITassertError("CMatrix 1");
	if(poMTXmatrix->MTXgetWidth() != 4)
		CUnit::UNITassertError("CMatrix 2");
	for(unsigned int uiIndex = 0; uiIndex < 12; uiIndex++)
		if(poMTXmatrix->MTXgetValue(uiIndex / 4, uiIndex % 4) != uiIndex)
			CUnit::UNITassertError("CMatrix 3");
	free(poMTXmatrix);
	
	int piValues[] = {3, 5, 7, 1, 5, 9, 7, 4, 1, 3, 6, 9};
	poMTXmatrix = CMatrixParser::PMTXreadFile((char *) "M2.txt");
	if(poMTXmatrix->MTXgetHeight() != 4)
		CUnit::UNITassertError("CMatrix 4");
	if(poMTXmatrix->MTXgetWidth() != 3)
		CUnit::UNITassertError("CMatrix 5");
	for(unsigned int uiIndex = 0; uiIndex < 12; uiIndex++)
		if(poMTXmatrix->MTXgetValue(uiIndex / 3, uiIndex % 3) != piValues[uiIndex])
			CUnit::UNITassertError("CMatrix 6");
	free(poMTXmatrix);
	
	try
	{
		poMTXmatrix = CMatrixParser::PMTXreadFile((char *) "M4.txt");
		free(poMTXmatrix);
		CUnit::UNITassertError("CMatrix 7");
	}
	catch(CException * poEXexception)
	{
		if(poEXexception->EXgetExceptionID() != UNSUPPORTED_TYPE_EXCEPTION)
			CUnit::UNITassertError("CMatrix 8");
	}
}
