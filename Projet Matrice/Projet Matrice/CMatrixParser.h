#ifndef C_MATRIX_PARSER_H
#define C_MATRIX_PARSER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatrix.h"

class CMatrixParser
{
public:
	template <T>
	CMatrix<T> PMTXreadFile(char* pcFileName);

};
#endif
