#include "CSquareMatrix.h"


template <class T>
CSquareMatrix<T>::CSquareMatrix(CSquareMatrix const& oSMTXmatrixParam, unsigned int uiRowParam, unsigned int uiColumnParam) : CMatrix(oMTXmatrixParam.MTXgetHeight() - 1, oMTXmatrixParam.MTXgetWidth() - 1)
{
	unsigned int uiPosition = 0;
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
		{
			if(uiRow == uiRowParam || uiColumn == uiColumnParam)
				continue;
			ptValues[uiPosition / uiHeight][uiPosition % uiHeight] = oSMTXmatrixParam.MTXgetValue(uiRow, uiColumn);
			uiPosition++;
		}
}

template <class T>
unsigned int CSquareMatrix<T>::SMTXgetSize()
{
	return uiHeight;
}

template <class T>
double CSquareMatrix<T>::SMTXgetDeterminant()
{
	if(uiHeight == 1)
		return ptValues[0][0];
	else if(uiHeight == 2)
		return ptValues[0][0] * ptValues[1][1] - ptValues[1][0] * ptValues[0][1];
	else
	{
		double dDeterminant = 0;
		for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		{
			CSquareMatrix<T> oMTXmatrix = CSquareMatrix<T>(*this, uiRow, 0);
			dDeterminant += (uiRow%2 == 0 ? 1 : -1) * ptValues[uiRow][0] * oMTXmatrix.SMTXgetDeterminant();
		}
		return dDeterminant;
	}
}
