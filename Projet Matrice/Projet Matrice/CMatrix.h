#ifndef C_MATRIX_H
#define C_MATRIX_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

template <class T>
class CMatrix
{
protected:
	unsigned int uiHeight;

	unsigned int uiWidth;

	T ptBody[][];


public:
	CMatrix();

	CMatrix(CMatrix const& oMTXmatrixParam);

	CMatrix(unsigned int uiHeightParam, unsigned int uiWidthParam);

	~CMatrix();

	unsigned int MTXgetHeight();

	unsigned int MTXgetWidth();

	T MTXgetValue(unsigned int uiHeightParam, unsigned int uiWidthParam);

	void MTXsetValue(unsigned int uiHeightParam, unsigned int uiWidthParam, T uiValueParam);

	void MTXdisplay();

	CMatrix& MTXtranspose();

	CMatrix& operator+(CMatrix const& oMTXmatrixParam);

	CMatrix& operator-(CMatrix const& oMTXmatrixParam);

	CMatrix& operator*(int iCoeficient);

	CMatrix& operator*(CMatrix const& oMTXmatrixParam);

	CMatrix& operator/(int iCoeficient);

};
#endif
