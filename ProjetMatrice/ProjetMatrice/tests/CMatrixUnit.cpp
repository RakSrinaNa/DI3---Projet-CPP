#include "CMatrixUnit.h"
#include "../CMatrix.h"
#include "CUnit.h"

void CMatrixUnit::MTXUnitTests()
{
	MTXUnitTestGetSet();
	MTXUnitTestConstructors();
	MTXUnitTestOperations();
}

void CMatrixUnit::MTXUnitTestGetSet()
{
	CMatrix<double> oMTXmatrix = CMatrix<double>(3, 4);
	if(oMTXmatrix.MTXgetHeight() != 3 || oMTXmatrix.MTXgetWidth() != 4)
		CUnit::UNITassertError("CMatrix A1");
	
	for(unsigned int uiIndex = 0; uiIndex < 12; uiIndex++)
		oMTXmatrix.MTXsetValue(uiIndex / 4, uiIndex % 4, uiIndex + 1);
	for(unsigned int uiIndex = 0; uiIndex < 12; uiIndex++)
		if(oMTXmatrix.MTXgetValue(uiIndex / 4, uiIndex % 4) !=  uiIndex + 1)
			CUnit::UNITassertError("CMatrix A2");
	
	try
	{
		oMTXmatrix.MTXgetValue(99, 99);
		CUnit::UNITassertError("CMatrix A3.1");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != OUT_OF_RANGE_EXCEPTION)
			CUnit::UNITassertError("CMatrix A3.2");
	}
	
	try
	{
		oMTXmatrix.MTXsetValue(99, 99, 99);
		CUnit::UNITassertError("CMatrix A4.1");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != OUT_OF_RANGE_EXCEPTION)
			CUnit::UNITassertError("CMatrix A4.2");
	}
}

void CMatrixUnit::MTXUnitTestConstructors()
{
	CMatrix<double> oMTXmatrix1 = CMatrix<double>();
	if(oMTXmatrix1.MTXgetHeight() != 1 || oMTXmatrix1.MTXgetWidth() != 1)
		CUnit::UNITassertError("CMatrix B1");
	
	oMTXmatrix1.MTXsetValue(0, 0, 10);
	CMatrix<double> oMTXmatrix2 = CMatrix<double>(oMTXmatrix1);
	if(oMTXmatrix2.MTXgetHeight() != 1 || oMTXmatrix2.MTXgetWidth() != 1 || oMTXmatrix2.MTXgetValue(0, 0) != 10)
		CUnit::UNITassertError("CMatrix B2");
	
	CMatrix<double> oMTXmatrix3 = CMatrix<double>(4, 3);
	if(oMTXmatrix3.MTXgetHeight() != 4 || oMTXmatrix3.MTXgetWidth() != 3)
		CUnit::UNITassertError("CMatrix B3");
}

void CMatrixUnit::MTXUnitTestOperations()
{
	CMatrix<double> oMTXmatrix1 = CMatrix<double>(2, 2);
	oMTXmatrix1.MTXsetValue(0, 0, 1);
	oMTXmatrix1.MTXsetValue(0, 1, 2);
	oMTXmatrix1.MTXsetValue(1, 0, 3);
	oMTXmatrix1.MTXsetValue(1, 1, 4);
	
	CMatrix<double> oMTXmatrix1Trans = oMTXmatrix1.MTXtranspose();
	if(oMTXmatrix1Trans.MTXgetValue(0, 0) != 1 || oMTXmatrix1Trans.MTXgetValue(0, 1) != 3 || oMTXmatrix1Trans.MTXgetValue(1, 0) != 2 || oMTXmatrix1Trans.MTXgetValue(1, 1) != 4)
		CUnit::UNITassertError("CMatrix C1");
	
	CMatrix<double> oMTXmatrix2 = oMTXmatrix1 * 2;
	if(oMTXmatrix2.MTXgetValue(0, 0) != 2 || oMTXmatrix2.MTXgetValue(0, 1) != 4 || oMTXmatrix2.MTXgetValue(1, 0) != 6 || oMTXmatrix2.MTXgetValue(1, 1) != 8)
		CUnit::UNITassertError("CMatrix C2");
	
	CMatrix<double> oMTXmatrix3 = oMTXmatrix2 / 2;
	if(oMTXmatrix3.MTXgetValue(0, 0) != 1 || oMTXmatrix3.MTXgetValue(0, 1) != 2 || oMTXmatrix3.MTXgetValue(1, 0) != 3 || oMTXmatrix3.MTXgetValue(1, 1) != 4)
		CUnit::UNITassertError("CMatrix C3");
	
	try
	{
		oMTXmatrix3 / 0;
		CUnit::UNITassertError("CMatrix C3.1");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != DIVISION_BY_ZERO_EXCEPTION)
			CUnit::UNITassertError("CMatrix C3.2");
	}
	
	if(!(oMTXmatrix1 == oMTXmatrix3) || oMTXmatrix1 == oMTXmatrix2)
		CUnit::UNITassertError("CMatrix C4");
	
	
	oMTXmatrix1 = oMTXmatrix2;
	if(oMTXmatrix1.MTXgetHeight() != 2 || oMTXmatrix1.MTXgetWidth() != 2 || oMTXmatrix1.MTXgetValue(0, 0) != 2 || oMTXmatrix1.MTXgetValue(0, 1) != 4 || oMTXmatrix1.MTXgetValue(1, 0) != 6 || oMTXmatrix1.MTXgetValue(1, 1) != 8)
		CUnit::UNITassertError("CMatrix C5");
	
	if(oMTXmatrix1(0, 0) != 2 || oMTXmatrix1(0, 1) != 4 || oMTXmatrix1(1, 0) != 6 || oMTXmatrix1(1, 1) != 8)
		CUnit::UNITassertError("CMatrix C6");
	
	try
	{
		oMTXmatrix1(0, 99);
		CUnit::UNITassertError("CMatrix C6.1");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != OUT_OF_RANGE_EXCEPTION)
			CUnit::UNITassertError("CMatrix C6.2");
	}
	
	try
	{
		oMTXmatrix1(99, 0);
		CUnit::UNITassertError("CMatrix C6.3");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != OUT_OF_RANGE_EXCEPTION)
			CUnit::UNITassertError("CMatrix C6.4");
	}
	
	try
	{
		oMTXmatrix1(0, 99);
		CUnit::UNITassertError("CMatrix C6.5");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != OUT_OF_RANGE_EXCEPTION)
			CUnit::UNITassertError("CMatrix C6.6");
	}
		
	CMatrix<double> oMTXmatrix4 = oMTXmatrix1 + oMTXmatrix3;
	if(oMTXmatrix4.MTXgetValue(0, 0) != 3 || oMTXmatrix4.MTXgetValue(0, 1) != 6 || oMTXmatrix4.MTXgetValue(1, 0) != 9 || oMTXmatrix4.MTXgetValue(1, 1) != 12)
		CUnit::UNITassertError("CMatrix C7");
	
	oMTXmatrix4 = oMTXmatrix1 - oMTXmatrix3;
	if(oMTXmatrix4.MTXgetValue(0, 0) != 1 || oMTXmatrix4.MTXgetValue(0, 1) != 2 || oMTXmatrix4.MTXgetValue(1, 0) != 3 || oMTXmatrix4.MTXgetValue(1, 1) != 4)
		CUnit::UNITassertError("CMatrix C8");
	
	oMTXmatrix2 = oMTXmatrix4 * oMTXmatrix1;
	if(oMTXmatrix2.MTXgetValue(0, 0) != 14 || oMTXmatrix2.MTXgetValue(0, 1) != 20 || oMTXmatrix2.MTXgetValue(1, 0) != 30 || oMTXmatrix2.MTXgetValue(1, 1) != 44)
		CUnit::UNITassertError("CMatrix C9");
	
	try
	{
		oMTXmatrix4 * CMatrix<double>(10, 20);
		CUnit::UNITassertError("CMatrix C9.1");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != INCOMPATIBLE_MATRIX_EXCEPTION)
			CUnit::UNITassertError("CMatrix C9.2");
	}
	
	oMTXmatrix2 *= 2;
	if(oMTXmatrix2.MTXgetValue(0, 0) != 28 || oMTXmatrix2.MTXgetValue(0, 1) != 40 || oMTXmatrix2.MTXgetValue(1, 0) != 60 || oMTXmatrix2.MTXgetValue(1, 1) != 88)
		CUnit::UNITassertError("CMatrix C10");
	
	oMTXmatrix2 *= oMTXmatrix4;
	if(oMTXmatrix2.MTXgetValue(0, 0) != 148 || oMTXmatrix2.MTXgetValue(0, 1) != 216 || oMTXmatrix2.MTXgetValue(1, 0) != 324 || oMTXmatrix2.MTXgetValue(1, 1) != 472)
		CUnit::UNITassertError("CMatrix C11");
	
	try
	{
		oMTXmatrix4 *= CMatrix<double>(10, 20);
		CUnit::UNITassertError("CMatrix C11.1");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != INCOMPATIBLE_MATRIX_EXCEPTION)
			CUnit::UNITassertError("CMatrix C11.2");
	}
	
	oMTXmatrix2 /= 4;
	if(oMTXmatrix2.MTXgetValue(0, 0) != 37 || oMTXmatrix2.MTXgetValue(0, 1) != 54 || oMTXmatrix2.MTXgetValue(1, 0) != 81 || oMTXmatrix2.MTXgetValue(1, 1) != 118)
		CUnit::UNITassertError("CMatrix C12");
	
	try
	{
		oMTXmatrix4 /= 0;
		CUnit::UNITassertError("CMatrix C12.1");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != DIVISION_BY_ZERO_EXCEPTION)
			CUnit::UNITassertError("CMatrix C12.2");
	}
}
