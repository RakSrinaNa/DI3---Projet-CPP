#ifndef C_MATRIX_PARSER_H
#define C_MATRIX_PARSER_H

#define IO_FILE_EXCEPTION 4890
#define MALFORMATTED_FILE_EXCEPTION 4891
#define UNSUPPORTED_TYPE_EXCEPTION 4892
#define NOT_SQUARE_MATRIX 4893

#include <cstdio>
#include <cstdlib>
#include "CMatrix.h"
#include "CSquareMatrix.h"

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

typedef struct{
	unsigned int uiWidth;
	unsigned int uiHeight;
	double ** pdValues;
	CMatrixType eMTTtype;
} SMatrixInfos;

class CMatrixParser
{
public:
	static CMatrix<double> * PMTXreadMatrix(char * pcFileName);
	static CSquareMatrix<double> * PMTXreadSquareMatrix(char * pcFileName);

private:
	static SMatrixInfos PMTXreadFile(char* pcFileName);
	static char * PMTXgetLineValue(char * pcLine);
	static char * PMTXgetLineKey(char * pcStart, char * pcEnd);
	static double * PMTXgetValuesAsDoubleArray(char * pcLine, unsigned int uiValuesCount);
	static CMatrixType PMTXgetValueAsMType(char * pcLine);
	static int PMTXgetLine(char ** pcLinePtr, size_t * pcLineSize, FILE * poFILEfile);
	static char * PMTXreadLineFromFile(FILE * poFILEfile);
};
#endif
