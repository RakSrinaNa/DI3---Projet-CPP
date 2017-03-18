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
	CMatrix<double> oMTXmatrix = CMatrix(3, 4);
	if(oMTXmatrix.MTXgetHeight() != 3 || oMTXmatrix.MTXgetWidth() != 4)
		CUnit::UNITassertError("CMatrix A1");
	
	for(unsigned int uiIndex = 0; uiIndex < 12; uiIndex++)
		oMTXmatrix.MTXsetValue(uiIndex / 4, uiIndex % 4, uiIndex + 1);
	for(unsigned int uiIndex = 0; uiIndex < 12; uiIndex++)
		if(oMTXmatrix.MTXgetValue(uiIndex / 4, uiIndex % 4) !=  uiIndex + 1)
			CUnit::UNITassertError("CMatrix A2");
}

void CMatrixUnit::MTXUnitTestConstructors()
{
	CMatrix<double> oMTXmatrix1 = CMatrix();
	if(oMTXmatrix1.MTXgetHeight() != 1 || oMTXmatrix1.MTXgetWidth() != 1)
		CUnit::UNITassertError("CMatrix B1");
	
	oMTXmatrix1.MTXsetValue(0, 0, 10);
	CMatrix<double> oMTXmatrix2 = CMatrix(oMTXmatrix1);
	if(oMTXmatrix2.MTXgetHeight() != 1 || oMTXmatrix2.MTXgetWidth() != 1 || oMTXmatrix2.MTXgetValue(0, 0) != 10)
		CUnit::UNITassertError("CMatrix B2");
}

void CMatrixUnit::MTXUnitTestOperations()
{
	CMatrix<double> oMTXmatrix1 = CMatrix(2, 2);
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
	if(oMTXmatrix3.MTXgetValue(0, 0) != 1 || oMTXmatrix3.MTXgetValue(0, 1) != 3 || oMTXmatrix3.MTXgetValue(1, 0) != 2 || oMTXmatrix3.MTXgetValue(1, 1) != 4)
		CUnit::UNITassertError("CMatrix C3");
	
	if(!(oMTXmatrix1 == oMTXmatrix3) || oMTXmatrix1 == oMTXmatrix2)
		CUnit::UNITassertError("CMatrix C4");
	
	oMTXmatrix1 = oMTXmatrix2;
	if(oMTXmatrix1.MTXgetHeight() != 2 || oMTXmatrix1.MTXgetWidth() != 2 || oMTXmatrix1.MTXgetValue(0, 0) != 2 || oMTXmatrix1.MTXgetValue(0, 1) != 4 || oMTXmatrix1.MTXgetValue(1, 0) != 6 || oMTXmatrix1.MTXgetValue(1, 1) != 8)
		CUnit::UNITassertError("CMatrix C5");
	
	if(oMTXmatrix1[0][0] != 1 || oMTXmatrix1[0][1] != 2 || oMTXmatrix1[1][0] != 3 || oMTXmatrix1[1][1] != 4)
		CUnit::UNITassertError("CMatrix C6");
}
