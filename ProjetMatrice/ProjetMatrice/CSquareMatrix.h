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
	CSquareMatrix(CMatrix const& oMTXmatrixParam);
	CSquareMatrix(unsigned int uiSize);
	CSquareMatrix(unsigned int uiSize, char * eye);
	~CSquareMatrix();

	unsigned int SMTXgetSize();

	double SMTXgetDeterminant();
	CSquareMatrix<T>& SMTXpow(unsigned int power);
	CMatrix<T>& SMTXcomatrix();
	CMatrix<T>& SMTXinverse();
	
	CSquareMatrix<T>& operator= (CSquareMatrix const& oSMTXmatrixParam);
	CSquareMatrix<T>& operator*= (CSquareMatrix const& oSMTXmatrixParam);
	CSquareMatrix<T>& operator*= (double dCoefficient);
	CSquareMatrix<T>& operator/= (double dCoefficient);

};

#include "CSquareMatrix.cpp"

#endif
