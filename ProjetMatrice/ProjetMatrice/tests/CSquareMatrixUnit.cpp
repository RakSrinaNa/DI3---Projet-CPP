#include "CSquareMatrixUnit.h"
#include "../CSquareMatrix.h"
#include "CUnit.h"

void CSquareMatrixUnit::SMXUnitTests()
{
	SMXUnitTestGetSet();
	SMXUnitTestConstructors();
	SMXUnitTestOperations();
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
	
	try
	{
		oSMXmatrix.MTXgetValue(99, 99);
		CUnit::UNITassertError("CMatrix A3.1");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != OUT_OF_RANGE_EXCEPTION)
			CUnit::UNITassertError("CMatrix A3.2");
	}
	
	try
	{
		oSMXmatrix.MTXsetValue(99, 99, 99);
		CUnit::UNITassertError("CMatrix A4.1");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != OUT_OF_RANGE_EXCEPTION)
			CUnit::UNITassertError("CMatrix A4.2");
	}
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
	
	int piValues[] = {1, 2, 7, 8};
	CSquareMatrix<double> oSMXmatrix4 = CSquareMatrix<double>(oSMXmatrix3, 1, 2);
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
	catch(CException const& poEXexception)
	{
		if(poEXexception.EXgetExceptionID() != INCOMPATIBLE_MATRIX_EXCEPTION)
			CUnit::UNITassertError("CSquareMatrix B8");
	}
	
	CSquareMatrix<double> oSMXmatrix9 = CSquareMatrix<double>(3, (char *) "eye");
	if(oSMXmatrix9.SMTXgetSize() != 3)
		CUnit::UNITassertError("CSquareMatrix B9");
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		if(oSMXmatrix9.MTXgetValue(uiIndex / 3, uiIndex % 3) != (uiIndex / 3 == uiIndex % 3 ? 1 : 0))
			CUnit::UNITassertError("CSquareMatrix B10");
}

void CSquareMatrixUnit::SMXUnitTestOperations()
{
	CSquareMatrix<double> oSMXmatrix1 = CSquareMatrix<double>(3);
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		oSMXmatrix1.MTXsetValue(uiIndex / 3, uiIndex % 3, uiIndex + 1);
	if(oSMXmatrix1.SMTXgetDeterminant() != 0)
		CUnit::UNITassertError("CSquareMatrix C1");
	
	double piValues[] = {2, 8, 9, 26, 98, 54, 62, 30, 9};
	CSquareMatrix<double> oSMXmatrix2 = CSquareMatrix<double>(3);
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		oSMXmatrix2.MTXsetValue(uiIndex / 3, uiIndex % 3, piValues[uiIndex]);
	if(oSMXmatrix2.SMTXgetDeterminant() != -24228)
		CUnit::UNITassertError("CSquareMatrix C2");
	
	double piValues2[] = {-738, 3114, -5296, 198, -540, 436, -450, 126, -12};
	CSquareMatrix<double> oSMXmatrix3 = oSMXmatrix2.SMTXcomatrix();
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		if(oSMXmatrix3.MTXgetValue(uiIndex / 3, uiIndex % 3) != piValues2[uiIndex])
			CUnit::UNITassertError("CSquareMatrix C3");
	
	double piValues3[] = {369/12114.0, -99/12114.0, 225/12114.0, -1557/12114.0, 270/12114.0, -63/12114.0, 2648/12114.0, -218/12114.0, 6/12114.0};
	CSquareMatrix<double> oSMXmatrix4 = oSMXmatrix2.SMTXinverse();
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		if(CUnit::UNITabsolute(oSMXmatrix4.MTXgetValue(uiIndex / 3, uiIndex % 3) - piValues3[uiIndex]) > 0.00000000001)
			CUnit::UNITassertError("CSquareMatrix C4");
	
	try
	{
		CSquareMatrix<double>(2).SMTXinverse();
		CUnit::UNITassertError("CSquareMatrix C4.1");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != NOT_INVERSIBLE_EXCEPTION)
			CUnit::UNITassertError("CSquareMatrix C4.2");
	}
	
	double piValues4[] = {62282, 126950, 69489, 681872, 1348280, 724968, 239338, 442654, 233613};
	oSMXmatrix4 = oSMXmatrix2.SMTXpow(3);
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		if(oSMXmatrix4.MTXgetValue(uiIndex / 3, uiIndex % 3) != piValues4[uiIndex])
			CUnit::UNITassertError("CSquareMatrix C5");
}
