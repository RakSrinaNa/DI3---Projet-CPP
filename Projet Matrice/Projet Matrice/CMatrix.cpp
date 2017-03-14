#include <iostream>

#include "CMatrix.h"
#include "utils.h"
#include "CException.h"

template <class T>
CMatrix<T>::CMatrix() : CMatrix(1, 1)
{
}

template <class T>
CMatrix<T>::CMatrix(CMatrix<T> const& oMTXmatrixParam)
{
}

//TODO
template <class T>
CMatrix<T>::CMatrix(unsigned int uiHeightParam, unsigned int uiWidthParam) : uiHeight(uiHeightParam), uiWidth(uiWidthParam)
{
	MMALLOC(ptValues, T*, uiHeight, "CMatrix constructor");
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
	{
		MMALLOC(ptValues[uiRow], T, uiWidth, "CMatrix constructor");
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			ptValues[uiRow][uiColumn] = 0;
	}
}

template <class T>
CMatrix<T>::~CMatrix()
{
	for(int iRow = 0; iRow < uiHeight; iRow++)
		free(ptValues[iRow]);
	free(ptValues);
}

template <class T>
inline unsigned int CMatrix<T>::MTXgetHeight()
{
	return uiHeight;
}

template <class T>
inline unsigned int CMatrix<T>::MTXgetWidth()
{
	return uiWidth;
}

template <class T>
inline T CMatrix<T>::MTXgetValue(unsigned int uiRow, unsigned int uiColumn)
{
	if(uiRow >= uiHeight || uiColumn >= uiWidth)
	{
		CException * poCEXexception = new CException(OUT_OF_RANGE_EXCEPTION, (char *) "Coordinate is out of matrix");
		throw poCEXexception;
	}
	return ptValues[uiRow][uiColumn];
}

template <class T>
void CMatrix<T>::MTXsetValue(unsigned int uiRow, unsigned int uiColumn, T uiValueParam)
{
	if(uiRow >= uiHeight || uiColumn >= uiWidth)
	{
		CException * poCEXexception = new CException(OUT_OF_RANGE_EXCEPTION, (char *) "Coordinate is out of matrix");
		throw poCEXexception;
	}
	ptValues[uiRow][uiColumn] = uiValueParam;
}

template <class T>
void CMatrix<T>::MTXdisplay()
{
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
	{
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			std::cout << ptValues[uiRow][uiColumn] << "\t";
		std::cout << "\n";
	}
}

template <class T>
CMatrix<T>& CMatrix<T>::MTXtranspose()
{
	CMatrix<T> * poMTXtrans = new CMatrix(MTXgetWidth(), MTXgetHeight());
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			*poMTXtrans[uiColumn][uiRow] = 0;
	return *poMTXtrans;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator+(CMatrix<T> const& oMTXmatrixParam)
{
	return *this;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator-(CMatrix<T> const& oMTXmatrixParam)
{
	return *this;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*(int iCoeficient)
{
	return *this;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*(CMatrix<T> const& oMTXmatrixParam)
{
	return *this;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator/(int iCoeficient)
{
	if(iCoeficient == 0)
	{
		CException * poCEXexception = new CException(DIVISION_BY_ZEO_EXCEPTION, "Division par zero");
		throw poCEXexception;
	}
	return *this;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator=(CMatrix<T> const& oMTXmatrixParam)
{
	return *this;
}
