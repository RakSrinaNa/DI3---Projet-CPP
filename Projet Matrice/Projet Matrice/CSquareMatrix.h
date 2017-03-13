#ifndef C_SQUARE_MATRIX_H
#define C_SQUARE_MATRIX_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatrix.h"

template <class T>
class CSquareMatrix : public CMatrix<T>
{
public:
	double SMTXgetDeterminant();

};
#endif
