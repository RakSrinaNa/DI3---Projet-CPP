#ifndef C_MATRIX_PARSER_H
#define C_MATRIX_PARSER_H

#define IO_FILE_EXCEPTION 4890

#include "CMatrix.h"

class CMatrixParser
{
public:
	template <class T>
	CMatrix<T> PMTXreadFile(char* pcFileName);
	static int getLine(char ** pcLinePtr, size_t * pcLineSize, FILE * poFILEfile);
	static char * parser_readLine(FILE * poFILEfile);
};
#endif
