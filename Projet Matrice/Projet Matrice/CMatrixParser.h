#ifndef C_MATRIX_PARSER_H
#define C_MATRIX_PARSER_H

#define IO_FILE_EXCEPTION 4890
#define MALFORMATTED_FILE_EXCEPTION 4891
#define UNSUPPORTED_TYPE_EXCEPTION 4892

#include "CMatrix.h"

enum CMatrixType{
	BYTE,
	SHORT,
	INT,
	FLOAT,
	DOUBLE,
	CHAR,
	BOOLEAN
};

class CMatrixParser
{
public:
	template <class T>
	static CMatrix<T> PMTXreadFile(char* pcFileName);
	static char * PMTXgetLineValue(char * pcLine);
	static double * PMTXgetValuesAsDoubleArray(char * pcLine, unsigned int uiValuesCount);
	static CMatrixType PMTXgetValueAsMType(char * pcLine);
	static int PMTXgetLine(char ** pcLinePtr, size_t * pcLineSize, FILE * poFILEfile);
	static char * PMTXreadLineFromFile(FILE * poFILEfile);
};
#endif
