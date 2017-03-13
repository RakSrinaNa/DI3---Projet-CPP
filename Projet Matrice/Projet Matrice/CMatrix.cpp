#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatrix.h"


void CMatrix::CMatrix()
{
}

void CMatrix::CMatrix(CMatrix oMTXmatrixParam)
{
}

void CMatrix::CMatrix(int uiHeightParam, int uiWidthParam)
{
}

void CMatrix::~CMatrix()
{
}

int CMatrix::MTXgetHeight()
{
	return 0;
}

int CMatrix::MTXgetWidth()
{
	return 0;
}

template <class T>
 T CMatrix<T>::MTXgetValue(int uiHeightParam, int uiWidthParam)
{
	return 0;
}

void CMatrix::MTXsetValue(int uiHeightParam, int uiWidthParam, T uiValueParam)
{
}

void CMatrix::MTXdisplay()
{
}

CMatrix& CMatrix::MTXtranspose()
{
	return *this;
}

CMatrix& CMatrix::operator+(CMatrix oMTXmatrixParam)
{
	return *this;
}

CMatrix& CMatrix::operator-(CMatrix oMTXmatrixParam)
{
	return *this;
}

CMatrix& CMatrix::operator*(int iCoeficient)
{
	return *this;
}

CMatrix& CMatrix::operator*(CMatrix oMTXmatrixParam)
{
	return *this;
}

CMatrix& CMatrix::operator/(int iCoeficient)
{
	return *this;
}
