#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatrix.h"


template <class T>
CMatrix::CMatrix() : CMatrix(1, 1)
{
}

template <class T>
CMatrix::CMatrix(CMatrix const& oMTXmatrixParam)
{
}

//TODO
template <class T>
CMatrix::CMatrix(unsigned int uiHeightParam, unsigned int uiWidthParam) : uiHeight(uiHeightParam), uiWidth(uiWidthParam)
{
	ptBody = T[uiHeight][uiWidth];
	for(unsigned int i = 0; i < uiHeight; i++)
		for(unsigned int j = 0; j < uiWidth; j++)
			ptBody[i][j] = 0;
}

template <class T>
CMatrix::~CMatrix()
{
}

template <class T>
inline unsigned int CMatrix::MTXgetHeight()
{
	return uiHeight;
}

template <class T>
inline unsigned int CMatrix::MTXgetWidth()
{
	return uiWidth;
}

//TODO
template <class T>
inline T CMatrix<T>::MTXgetValue(unsigned int uiHeightParam, unsigned int uiWidthParam)
{
	if(uiHeightParam >= uiHeight || uiWidthParam >= uiWidth)
	{
	}

	return ptBody[uiHeightParam][uiWidthParam];
}

//TODO
template <T>
void CMatrix::MTXsetValue(unsigned int uiHeightParam, unsigned int uiWidthParam, T uiValueParam)
{
	if(uiHeightParam >= uiHeight || uiWidthParam >= uiWidth)
	{
	}

	ptBody[uiHeightParam][uiWidthParam] = uiValueParam;
}

template <class T>
void CMatrix::MTXdisplay()
{
	for(unsigned int i = 0; i < uiHeight; i++)
	{
		for(unsigned int j = 0; j < uiWidth; j++)
			std::cout << ptBody[i][j] << "\t";
		std::cout << "\n";
	}
}

template <class T>
CMatrix& CMatrix::MTXtranspose()
{
	return *this;
}

template <class T>
CMatrix& CMatrix::operator+(CMatrix const& oMTXmatrixParam)
{
	return *this;
}

template <class T>
CMatrix& CMatrix::operator-(CMatrix const& oMTXmatrixParam)
{
	return *this;
}

template <class T>
CMatrix& CMatrix::operator*(int iCoeficient)
{
	return *this;
}

template <class T>
CMatrix& CMatrix::operator*(CMatrix const& oMTXmatrixParam)
{
	return *this;
}

template <class T>
CMatrix& CMatrix::operator/(int iCoeficient)
{
	return *this;
}
