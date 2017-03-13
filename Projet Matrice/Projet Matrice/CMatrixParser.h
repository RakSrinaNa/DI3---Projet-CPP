#ifndef C_MATRIX_PARSER_H
#define C_MATRIX_PARSER_H

#include "CMatrix.h"

class CMatrixParser
{
public:
	template <class T>
	CMatrix<T> PMTXreadFile(char* pcFileName);

};
#endif
