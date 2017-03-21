#ifndef C_SQUARE_MATRIX_H
#define C_SQUARE_MATRIX_H

#include "CMatrix.h"

template <class T>
class CSquareMatrix : public CMatrix<T>
{
public:
	CSquareMatrix();
	CSquareMatrix(CSquareMatrix<T> const& oSMTXmatrixParam);
	CSquareMatrix(CSquareMatrix<T> const& oSMTXmatrixParam, unsigned int uiRow, unsigned int uiColumn);
	CSquareMatrix(CMatrix<T> const& oMTXmatrixParam);
	CSquareMatrix(unsigned int uiSize);
	CSquareMatrix(unsigned int uiSize, char * pcMethod);
	~CSquareMatrix();

	unsigned int SMTXgetSize();

	double SMTXgetDeterminant();
	CSquareMatrix<T>& SMTXpow(unsigned int power);
	CMatrix<T>& SMTXcomatrix();
	CMatrix<T>& SMTXinverse();
	
	CSquareMatrix<T>& operator= (CSquareMatrix<T> const& oSMTXmatrixParam);
	CSquareMatrix<T>& operator*= (CSquareMatrix<T> const& oSMTXmatrixParam);
	CSquareMatrix<T>& operator*= (double dCoefficient);
	CSquareMatrix<T>& operator/= (double dCoefficient);

};

#include "CSquareMatrix.cpp"

#endif
