#ifndef C_SQUARE_MATRIX_H
#define C_SQUARE_MATRIX_H

#include "CMatrix.h"

template <class T>
class CSquareMatrix : public CMatrix<T>
{
public:
	CSquareMatrix();
	CSquareMatrix(CSquareMatrix const& oSMTXmatrixParam);
	CSquareMatrix(CSquareMatrix const& oSMTXmatrixParam, unsigned int uiRow, unsigned int uiColumn);
	CSquareMatrix(unsigned int uiSize);
	CSquareMatrix(unsigned int uiSize, char * eye);
	~CSquareMatrix();

	unsigned int SMTXgetSize();

	double SMTXgetDeterminant();
	CMatrix<T>& SMTXpow(unsigned int power);
	CMatrix<T>& SMTXcomatrix();
	CMatrix<T>& SMTXinverse();
};

#include "CSquareMatrix.cpp"

#endif
