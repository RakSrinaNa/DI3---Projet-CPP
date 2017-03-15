#include <iostream>

#include "CMatrix.h"
#include "utils.h"
#include "CException.h"

template <class T>
CMatrix<T>::CMatrix() : CMatrix(1, 1)
{
}

template <class T>
CMatrix<T>::CMatrix(CMatrix<T> const& oMTXmatrixParam) : CMatrix(oMTXmatrixParam.MTXgetHeight(), oMTXmatrixParam.MTXgetWidth())
{
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			ptValues[uiRow][uiColumn] = oMTXmatrixParam.MTXgetValue(uiRow, uiColumn);

	return *this;
}

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
inline unsigned int CMatrix<T>::MTXgetHeight() const
{
	return uiHeight;
}

template <class T>
inline unsigned int CMatrix<T>::MTXgetWidth() const
{
	return uiWidth;
}

template <class T>
inline T CMatrix<T>::MTXgetValue(unsigned int uiRow, unsigned int uiColumn) const
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
	if(uiHeight != oMTXmatrixParam.MTXgetHeight() || uiWidth != oMTXmatrixParam.MTXgetWidth())
	{
		CException * poCEXexception = new CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix don't have the same size");
		throw poCEXexception;
	}

	CMatrix<T> * poMTXsum = new CMatrix(MTXgetHeight(), MTXgetWidth());
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			*poMTXsum[uiRow][uiColumn] = MTXgetValue(uiRow, uiHeight) + oMTXmatrixParam.MTXgetValue(uiRow, uiHeight);

	return *poMTXsum;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator-(CMatrix<T> const& oMTXmatrixParam)
{
	if(uiHeight != oMTXmatrixParam.MTXgetHeight() || uiWidth != oMTXmatrixParam.MTXgetWidth())
	{
		CException * poCEXexception = new CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix don't have the same size");
		throw poCEXexception;
	}

	CMatrix<T> * poMTXsub = new CMatrix(MTXgetHeight(), MTXgetWidth());
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			*poMTXsub[uiRow][uiColumn] = MTXgetValue(uiRow, uiHeight) - oMTXmatrixParam.MTXgetValue(uiRow, uiHeight);

	return *poMTXsub;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*(double iCoeficient)
{
	CMatrix<T> * poMTXtimes = new CMatrix(*this);
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			*poMTXtimes[uiRow][uiColumn] *= iCoeficient;

	return *poMTXtimes;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*(CMatrix<T> const& oMTXmatrixParam)
{
	if(uiWidth != oMTXmatrixParam.MTXgeHeight())
	{
		CException * poCEXexception = new CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix are incompatible for multiplication");
		throw poCEXexception;
	}

	CMatrix<T> * poMTXtimes = new CMatrix(uiHeight, oMTXmatrixParam.MTXgetWidth());

	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
		{
			T dSum = 0;
			for(unsigned int uiTimes = 0; uiTimes < uiWidth; uiTimes++)
				dSum += ptValues[uiRow][uiTimes] * oMTXmatrixParam.MTXgetValue(uiTimes, uiColumn);
			poMTXtimes->MTXsetValue(uiRow, uiHeight, dSum);
		}

	return *poMTXtimes;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator/(double iCoeficient)
{
	if(iCoeficient == 0)
	{
		CException * poCEXexception = new CException(DIVISION_BY_ZEO_EXCEPTION, "Division par zero");
		throw poCEXexception;
	}
	return (*this) * (1/iCoeficient);
}

template <class T>
CMatrix<T>& CMatrix<T>::operator=(CMatrix<T> const& oMTXmatrixParam)
{
	if (uiHeight != oMTXmatrixParam.MTXgetHeight() || uiWidth != oMTXmatrixParam.MTXgetWidth())
	{
		CException * poCEXexception = new CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix don't have the same size");
		throw poCEXexception;
	}

	for (unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for (unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			ptValues[uiRow][uiColumn] = oMTXmatrixParam.MTXgetValue(uiRow, uiColumn);

	return *this;
}

template <class T>
bool CMatrix<T>::operator==(CMatrix<T> const& oMTXmatrixParam)
{
	if(uiHeight != oMTXmatrixParam.MTXgetHeight || uiWidth != oMTXmatrixParam.MTXgetWidth)
		return false;
	
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			if(ptValues[uiRow][uiColumn] != oMTXmatrixParam.MTXgetValue(uiRow, uiColumn))
				return false;

	return true;
}


template <class T>
T* CMatrix<T>::operator[](unsigned int uiRow)
{
	return ptValues[uiRow];
}
