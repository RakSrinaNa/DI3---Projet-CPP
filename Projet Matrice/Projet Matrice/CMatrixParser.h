#ifndef C_MATRIX_PARSER_H
#define C_MATRIX_PARSER_H

#define IO_FILE_EXCEPTION 4890
#define MALFORMATTED_FILE_EXCEPTION 4891
#define UNSUPPORTED_TYPE_EXCEPTION 4892

#include <cstdio>
#include <cstdlib>
#include "CMatrix.h"

enum CMatrixType{
	ERROR,
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
	static CMatrix * PMTXreadFile(char* pcFileName);

private:
	static char * PMTXgetLineValue(char * pcLine);
	static double * PMTXgetValuesAsDoubleArray(char * pcLine, unsigned int uiValuesCount);
	static CMatrixType PMTXgetValueAsMType(char * pcLine);
	static int PMTXgetLine(char ** pcLinePtr, size_t * pcLineSize, FILE * poFILEfile);
	static char * PMTXreadLineFromFile(FILE * poFILEfile);
};
#endif
