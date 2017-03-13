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
	int uiHeight;

	int uiWidth;

	T[][] ptBody;


public:
	void CMatrix();

	void CMatrix(CMatrix oMTXmatrixParam);

	void CMatrix(int uiHeightParam, int uiWidthParam);

	void ~CMatrix();

	int MTXgetHeight();

	int MTXgetWidth();

	T MTXgetValue(int uiHeightParam, int uiWidthParam);

	void MTXsetValue(int uiHeightParam, int uiWidthParam, T uiValueParam);

	void MTXdisplay();

	CMatrix& MTXtranspose();

	CMatrix& operator+(CMatrix oMTXmatrixParam);

	CMatrix& operator-(CMatrix oMTXmatrixParam);

	CMatrix& operator*(int iCoeficient);

	CMatrix& operator*(CMatrix oMTXmatrixParam);

	CMatrix& operator/(int iCoeficient);

};
#endif
