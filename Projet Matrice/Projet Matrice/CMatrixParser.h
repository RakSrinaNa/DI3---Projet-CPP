#ifndef C_MATRIX_PARSER_H
#define C_MATRIX_PARSER_H

#define IO_FILE_EXCEPTION 4890

#include "CMatrix.h"

class CMatrixParser
{
public:
	template <class T>
	static CMatrix<T> PMTXreadFile(char* pcFileName);
	static int PMTXgetLine(char ** pcLinePtr, size_t * pcLineSize, FILE * poFILEfile);
	static char * PMTXreadLineFromFile(FILE * poFILEfile);
};
#endif
