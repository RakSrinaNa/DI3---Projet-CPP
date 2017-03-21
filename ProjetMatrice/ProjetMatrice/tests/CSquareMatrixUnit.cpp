#include "CSquareMatrixUnit.h"
#include "../CSquareMatrix.h"
#include "CUnit.h"

void CSquareMatrixUnit::SMXUnitTests()
{
	SMXUnitTestGetSet();
}

void CSquareMatrixUnit::SMXUnitTestGetSet()
{
	CSquareMatrix<double> oMTXmatrix = CSquareMatrix<double>(3);
	if(oMTXmatrix.SMTXgetSize() != 3 || oMTXmatrix.MTXgetWidth() != 3 || oMTXmatrix.MTXgetHeight() != 3)
		CUnit::UNITassertError("CSquareMatrix A1");
	
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		oMTXmatrix.MTXsetValue(uiIndex / 3, uiIndex % 3, uiIndex + 1);
	for(unsigned int uiIndex = 0; uiIndex < 9; uiIndex++)
		if(oMTXmatrix.MTXgetValue(uiIndex / 3, uiIndex % 3) !=  uiIndex + 1)
			CUnit::UNITassertError("CSquareMatrix A2");
}
