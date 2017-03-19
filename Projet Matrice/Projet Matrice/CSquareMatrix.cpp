#include "CMatrix.h"
#include "CSquareMatrix.h"

template <class T>
CSquareMatrix<T>::CSquareMatrix() : CMatrix()
{
}

template <class T>
CSquareMatrix<T>::CSquareMatrix(CSquareMatrix const& oSMTXmatrixParam) : CMatrix(oSMTXmatrixParam)
{

}

template <class T>
CSquareMatrix<T>::CSquareMatrix(CSquareMatrix const& oSMTXmatrixParam, unsigned int uiRowParam, unsigned int uiColumnParam) : CMatrix(oSMTXmatrixParam.MTXgetHeight() - 1, oSMTXmatrixParam.MTXgetWidth() - 1)
{
	unsigned int uiPosition = 0;
	for(unsigned int uiRow = 0; uiRow < oSMTXmatrixParam.MTXgetHeight(); uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < oSMTXmatrixParam.MTXgetWidth(); uiColumn++)
		{
			if(uiRow == uiRowParam || uiColumn == uiColumnParam)
				continue;
			ptValues[uiPosition / uiHeight][uiPosition % uiHeight] = oSMTXmatrixParam.MTXgetValue(uiRow, uiColumn);
			uiPosition++;
		}
}

template <class T>
CSquareMatrix<T>::CSquareMatrix(unsigned int uiSize) : CMatrix(uiSize, uiSize)
{
}

template <class T>
CSquareMatrix<T>::CSquareMatrix(unsigned int uiSize, char * eye) : CMatrix(uiSize, uiSize)
{
	if(STRCMPI(eye, "eye") == 0 || STRCMPI(eye, "eyes") == 0)
		for(unsigned int uiRow = 0; uiRow < uiSize; uiRow++)
			MTXsetValue(uiRow, uiRow, 1);
}

template <class T>
CSquareMatrix<T>::~CSquareMatrix()
{
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
			dDeterminant += ((uiRow%2 == 0 ? 1 : -1) * ptValues[uiRow][0] * oMTXmatrix.SMTXgetDeterminant());
		}
		return dDeterminant;
	}
}

//TODO a changer pour eviter fuites memoire
template <class T>
CMatrix<T>& CSquareMatrix<T>::SMTXpow(unsigned int power)
{
	if(power == 0)
	{
		CSquareMatrix<T> * poMTXmatrix = new CSquareMatrix<T>(SMTXgetSize(), "eye");
		return *poMTXmatrix;
	}
	return ((*this) * this->SMTXpow(power - 1));

}

template <class T>
CMatrix<T>& CSquareMatrix<T>::SMTXcomatrix()
{
	CMatrix<T> * poMTXcomatrix = new CSquareMatrix<T>(SMTXgetSize());
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
		{
			CSquareMatrix<T> oMTXmatrix = CSquareMatrix<T>(*this, uiRow, uiColumn);
			MTXsetValue(uiRow, uiColumn, (((uiRow + uiColumn)%2 == 0 ? 1 : -1) * oMTXmatrix.SMTXgetDeterminant()));
		}
	return *poMTXcomatrix;
}

template <class T>
CMatrix<T>& CSquareMatrix<T>::SMTXinverse()
{
	CMatrix<T> * poMTXinverse;
	CMatrix<T> oMTXcomatrix = SMTXcomatrix();
	poMTXinverse = &oMTXcomatrix.MTXtranspose();
	oMTXcomatrix.~CMatrix();
	return (*poMTXinverse) /= SMTXgetDeterminant();
}

