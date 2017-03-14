#ifndef C_SQUARE_MATRIX_H
#define C_SQUARE_MATRIX_H

#include "CMatrix.h"

template <class T>
class CSquareMatrix : public CMatrix<T>
{
public:
	CSquareMatrix(CSquareMatrix const& oSMTXmatrixParam, unsigned int uiRow, unsigned int uiColumn);

	unsigned int SMTXgetSize();

	double SMTXgetDeterminant();
};
#endif
