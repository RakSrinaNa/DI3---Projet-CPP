#include "CSquareMatrixUnit.h"
#include "../CSquareMatrix.h"
#include "CUnit.h"

void CSquareMatrixUnit::SMXUnitTests()
{
	SMXUnitTestGetSet();
	SMXUnitTestConstructors();
}

void CSquareMatrixUnit::SMXUnitTestGetSet()
{
	CSquareMatrix<double> oSMXmatrix = CSquareMatrix<double>(3);
	if(oSMXmatrix.SMTXgetSize() != 3 || oSMXmatrix.MTXgetWidth() != 3 || oSMXmatrix.MTXgetHeight() != 3)
		CUnit::UNITassertError("CSquareMatrix A1");
	
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		oSMXmatrix.MTXsetValue(uiIndex / 3, uiIndex % 3, uiIndex + 1);
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		if(oSMXmatrix.MTXgetValue(uiIndex / 3, uiIndex % 3) !=  uiIndex + 1)
			CUnit::UNITassertError("CSquareMatrix A2");
}

void CSquareMatrixUnit::SMXUnitTestConstructors()
{
	CSquareMatrix<double> oSMXmatrix1 = CSquareMatrix<double>();
	if(oSMXmatrix1.SMTXgetSize() != 1)
		CUnit::UNITassertError("CSquareMatrix B1");
	
	oSMXmatrix1.MTXsetValue(0, 0, 10);
	CSquareMatrix<double> oSMXmatrix2 = CSquareMatrix<double>(oSMXmatrix1);
	if(oSMXmatrix2.SMTXgetSize() != 1 || oSMXmatrix2.MTXgetValue(0, 0) != 10)
		CUnit::UNITassertError("CSquareMatrix B2");
	
	CSquareMatrix<double> oSMXmatrix3 = CSquareMatrix<double>(3);
	if(oSMXmatrix3.SMTXgetSize() != 3)
		CUnit::UNITassertError("CSquareMatrix B3");
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		oSMXmatrix3.MTXsetValue(uiIndex / 3, uiIndex % 3, uiIndex + 1);
	
	int piValues[] = {1, 3, 7, 9};
	CSquareMatrix<double> oSMXmatrix4 = CSquareMatrix<double>(oSMXmatrix3, 1, 1);
	if(oSMXmatrix4.SMTXgetSize() != 2)
		CUnit::UNITassertError("CSquareMatrix B4");
	for(unsigned int uiIndex = 0; uiIndex < 4; uiIndex++)
		if(oSMXmatrix4.MTXgetValue(uiIndex / 2, uiIndex % 2) != piValues[uiIndex])
			CUnit::UNITassertError("CSquareMatrix B5");
	
	CMatrix<double> oMTXmatrix5 = CMatrix<double>(2, 2);
	oMTXmatrix5.MTXsetValue(0, 0, 1);
	oMTXmatrix5.MTXsetValue(0, 1, 2);
	oMTXmatrix5.MTXsetValue(1, 0, 3);
	oMTXmatrix5.MTXsetValue(1, 1, 4);
	CSquareMatrix<double> oSMXmatrix6 = CSquareMatrix<double>(oMTXmatrix5);
	if(oSMXmatrix6.SMTXgetSize() != 2)
		CUnit::UNITassertError("CSquareMatrix B6");
	for(unsigned int uiIndex = 0; uiIndex < 4; uiIndex++)
		if(oMTXmatrix5.MTXgetValue(uiIndex / 2, uiIndex % 2) != oSMXmatrix6.MTXgetValue(uiIndex / 2, uiIndex % 2))
			CUnit::UNITassertError("CSquareMatrix B7");
	
	CMatrix<double> oMTXmatrix7 = CMatrix<double>(3, 2);
	try
	{
		CSquareMatrix<double> oSMXmatrix8 = CSquareMatrix<double>(oMTXmatrix7);
	}
	catch(CException * poEXexception)
	{
		if(poEXexception->EXgetExceptionID() != INCOMPATIBLE_MATRIX_EXCEPTION)
			CUnit::UNITassertError("CSquareMatrix B8");
	}
	
	CSquareMatrix<double> oSMXmatrix9 = CSquareMatrix<double>(3, (char *) "eye");
	if(oSMXmatrix9.SMTXgetSize() != 3)
		CUnit::UNITassertError("CSquareMatrix B9");
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		if(oSMXmatrix9.MTXgetValue(uiIndex / 3, uiIndex % 3) != (uiIndex / 3 == uiIndex % 3 ? 1 : 0))
			CUnit::UNITassertError("CSquareMatrix B10");
}
