#ifndef C_MATRIX_H
#define C_MATRIX_H

#include <iostream>

#include "utils.h"
#include "CException.h"

#define OUT_OF_RANGE_EXCEPTION 89714
#define DIVISION_BY_ZEO_EXCEPTION 89715
#define INCOMPATIBLE_MATRIX_EXCEPTION 89716

template <class T>
class CMatrix
{
protected:
	unsigned int uiHeight;
	unsigned int uiWidth;
	T** ptValues;

public:
	CMatrix<T>();
	CMatrix<T>(CMatrix<T> const& oMTXmatrixParam);
	CMatrix<T>(unsigned int uiHeightParam, unsigned int uiWidthParam);
	~CMatrix<T>();

	unsigned int MTXgetHeight() const;
	unsigned int MTXgetWidth() const;
	T MTXgetValue(unsigned int uiRow, unsigned int uiColumn) const;
	
	void MTXsetValue(unsigned int uiRow, unsigned int uiColumn, T uiValueParam);

	void MTXdisplay();
	CMatrix<T>& MTXtranspose();
	
	CMatrix<T>& operator+(CMatrix<T> const& oMTXmatrixParam);
	CMatrix<T>& operator-(CMatrix<T> const& oMTXmatrixParam);
	CMatrix<T>& operator*(CMatrix<T> const& oMTXmatrixParam);
	CMatrix<T>& operator*(double iCoeficient);
	CMatrix<T>& operator/(double iCoeficient);
	CMatrix<T>& operator=(CMatrix<T> const& oMTXmatrixParam);
	bool operator==(CMatrix<T> const& oMTXmatrixParam);
	T* operator[](unsigned int uiRow);
};

#include "CMatrix.cpp"

#endif
