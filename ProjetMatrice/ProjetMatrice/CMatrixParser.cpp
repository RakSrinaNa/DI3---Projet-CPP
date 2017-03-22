#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "CMatrixParser.h"
#include "CSquareMatrix.h"

SMatrixInfos CMatrixParser::PMTXreadFile(char* pcFileName)
{
	
	FILE* poFILEfile;
	try
	{
		FOPEN(poFILEfile, pcFileName, "r", IO_FILE_EXCEPTION, "Error opening matrix file");
	}
	catch(CException const& poEXexception)
	{
		perror(poEXexception.EXgetExceptionMessage());
		throw poEXexception;
	}
	
	SMatrixInfos sMIFinfos;
	
	char * pcCurrentLine = PMTXreadLineFromFile(poFILEfile);
	char * pcTypeValue = PMTXgetLineValue(pcCurrentLine);
	sMIFinfos.eMTTtype = PMTXgetValueAsMType(pcTypeValue);
	free(pcCurrentLine);
	
	if(sMIFinfos.eMTTtype == ERROR || sMIFinfos.eMTTtype != DOUBLE)
	{
		throw CException(UNSUPPORTED_TYPE_EXCEPTION, (char *) "Matrix type unsupported");
	}
	
	pcCurrentLine = PMTXreadLineFromFile(poFILEfile);
	char * pcRows = PMTXgetLineValue(pcCurrentLine);
	sMIFinfos.uiHeight = (unsigned int)atoi(pcRows);
	free(pcCurrentLine);
	
	pcCurrentLine = PMTXreadLineFromFile(poFILEfile);
	char * pcColumns = PMTXgetLineValue(pcCurrentLine);
	sMIFinfos.uiWidth = (unsigned int)atoi(pcColumns);
	free(pcCurrentLine);
	
	free(PMTXreadLineFromFile(poFILEfile));
	
	MMALLOC(sMIFinfos.pdValues, double *, sMIFinfos.uiHeight, "REALLOC ERROR CMATRIXPARSER");
	
	for(unsigned int uiRowIndex = 0; uiRowIndex < sMIFinfos.uiHeight; uiRowIndex++)
	{
		pcCurrentLine = PMTXreadLineFromFile(poFILEfile);
		double * pdValues = PMTXgetValuesAsDoubleArray(pcCurrentLine, sMIFinfos.uiWidth);
		sMIFinfos.pdValues[uiRowIndex] = pdValues;
		free(pcCurrentLine);
	}
	
	fclose(poFILEfile);
	return sMIFinfos;
}

double * CMatrixParser::PMTXgetValuesAsDoubleArray(char * pcLine, unsigned int uiValuesCount)
{
	double * pdValues;
	MMALLOC(pdValues, double, uiValuesCount, "parser_lineToIntArray");
	
	unsigned int uiValuesLength = 0; // Number of values actually put in the array
	
	unsigned int uiIndex = 0; // The reading index
	bool bReading = false; // Boolean to know if we are currently reading a number
	
	char * pcStart = pcLine; // The beginning of our number we are reading
	unsigned int uiLength = 0; // The length of the number we are reading
	
	do
	{
		if(uiValuesLength > uiValuesCount)
		{
			free(pdValues);
			throw CException(PARSER_ERROR_EXCEPTION);
		}
		if(pcLine[uiIndex] == '\t' || pcLine[uiIndex] == ' ' || pcLine[uiIndex] == '\0' || pcLine[uiIndex] == '\n') // If we don't read a number
		{
			if(bReading) // If we were reading, add the number to the array
			{
				bReading = false;
				
				uiValuesLength++;
				
				char buffer[10] = {0};
				memcpy(buffer, pcStart, uiLength);
				buffer[uiLength] = '\0';
				pdValues[uiValuesLength - 1] = atof(buffer);
				
				uiLength = 0;
			}
		}
		else // If we read a number
		{
			if(!bReading) // If we just started reading it, change start and reading pdValues
			{
				bReading = true;
				pcStart = pcLine + uiIndex;
			}
			uiLength++;
		}
		uiIndex++;
	} while(pcLine[uiIndex - 1] != '\0'); // Read while we didn't reached the end of the string
	
	if(uiValuesLength < uiValuesCount)
	{
		free(pdValues);
		throw CException(PARSER_ERROR_EXCEPTION);
	}
	return pdValues;
}

char * CMatrixParser::PMTXgetLineValue(char * pcLine)
{
	while(*pcLine != '=' && *pcLine != '\0')
		pcLine++;
	if(*pcLine == '\0')
		throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "File is not in a correct format");
	return pcLine + 1;
}

char * CMatrixParser::PMTXgetLineKey(char * pcStart, char * pcEnd)
{
	char * pcKey;
	unsigned int uiSize = pcEnd - pcStart;
	MMALLOC(pcKey, char, uiSize, "Parser fail getting key");
	for(unsigned int uiIndex = 0; uiIndex < uiSize; uiIndex++)
		pcKey[uiIndex] = pcStart[uiIndex];
	return pcKey;
}

CMatrixType CMatrixParser::PMTXgetValueAsMType(char * pcLine)
{
	if(strcmp("byte", pcLine) == 0)
		return BYTE;
	if(strcmp("short", pcLine) == 0)
		return SHORT;
	if(strcmp("int", pcLine) == 0)
		return INT;
	if(strcmp("float", pcLine) == 0)
		return FLOAT;
	if(strcmp("double", pcLine) == 0)
		return DOUBLE;
	if(strcmp("boolean", pcLine) == 0)
		return BOOLEAN;
	if(strcmp("char", pcLine) == 0)
		return CHAR;
	return ERROR;
}

char * CMatrixParser::PMTXreadLineFromFile(FILE * poFILEfile)
{
	char * pcLineRead = NULL;
	size_t uiSize = 0;
	int iEndString;
	do
	{
		if(pcLineRead != NULL) // If an empty line was read before, free it
		{
			free(pcLineRead);
			pcLineRead = NULL;
		}
		if((iEndString = PMTXgetLine(&pcLineRead, &uiSize, poFILEfile)) == -1) // Read a line, and return NULL if end of poFILEfile
			return NULL;
	} while(*pcLineRead == '\n' || (*pcLineRead == '\r' && pcLineRead[1] == '\n')); // While we have a non empty line
	
	/* Clean ending \n \r \r */
	while(iEndString > 0 && (pcLineRead[iEndString] == '\0' || pcLineRead[iEndString] == '\n' || pcLineRead[iEndString] == '\r' || pcLineRead[iEndString] == '\t'))
		iEndString--;
	iEndString++;
	pcLineRead[iEndString] = '\0';
	RREALLOC(pcLineRead, char, iEndString, "Error realloc PMTXreadLineFromFile");
	return pcLineRead;
}

int CMatrixParser::PMTXgetLine(char ** pcLinePtr, size_t * pcLineSize, FILE * poFILEfile)
{
	char * pcBuffer = NULL; // Buffer string
	unsigned int uiWritingHead = 0; // Pointer to the writing position in the buffer
	size_t uiSize = 0; // The uiSize of the buffer
	int iCharRead; // The char read
	
	if(pcLinePtr == NULL || poFILEfile == NULL || pcLineSize == NULL)
		return -1;
	
	pcBuffer = *pcLinePtr;
	uiSize = *pcLineSize;
	iCharRead = fgetc(poFILEfile);
	if(iCharRead == EOF)
		return -1;
	if(pcBuffer == NULL) // If the string passed as parameter is NULL, initialize it
	{
		MMALLOC(pcBuffer, char, 50, NULL);
		uiSize = 50;
	}
	while(iCharRead != EOF) // While we didn't reach the end of the poFILEfile
	{
		if(uiWritingHead > uiSize - 1U) // If we went over the buffer uiSize (letting space for \0), make it bigger
		{
			uiSize += 50;
			RREALLOC(pcBuffer, char, uiSize, NULL);
		}
		pcBuffer[uiWritingHead++] = (char) iCharRead; // Write the char read into out buffer
		if(iCharRead == '\n') // If it's the end of the line, get out of the while
			break;
		iCharRead = fgetc(poFILEfile); // Read next char
	}
	
	pcBuffer[uiWritingHead++] = '\0'; // Write the terminating byte
	*pcLinePtr = pcBuffer; // Set the buffer at being pointed by pcLinePtr
	*pcLineSize = uiSize; // Set uiSize being pointer by pcLineSize
	
	return uiWritingHead - 1; // Return the length of the read string, not counting the terminating byte
}

CMatrix<double> * CMatrixParser::PMTXreadMatrix(char * pcFileName)
{
	SMatrixInfos sMTXinfos = PMTXreadFile(pcFileName);
	CMatrix<double> * poMTXmatrix = new CMatrix<double>(sMTXinfos.uiHeight, sMTXinfos.uiWidth);
	for(unsigned int uiRow = 0; uiRow < sMTXinfos.uiHeight; uiRow++)
	{
		for(unsigned int uiCol = 0; uiCol < sMTXinfos.uiWidth; uiCol++)
			poMTXmatrix->MTXsetValue(uiRow, uiCol, sMTXinfos.pdValues[uiRow][uiCol]);
		free(sMTXinfos.pdValues[uiRow]);
	}
	free(sMTXinfos.pdValues);
	return poMTXmatrix;
}

CSquareMatrix<double> * CMatrixParser::PMTXreadSquareMatrix(char * pcFileName)
{
	SMatrixInfos sMTXinfos = PMTXreadFile(pcFileName);
	
	if(sMTXinfos.uiWidth != sMTXinfos.uiHeight)
		throw CException(NOT_SQUARE_MATRIX);
	
	CSquareMatrix<double> * poMTXmatrix = new CSquareMatrix<double>(sMTXinfos.uiHeight);
	for(unsigned int uiRow = 0; uiRow < sMTXinfos.uiHeight; uiRow++)
	{
		for(unsigned int uiCol = 0; uiCol < sMTXinfos.uiWidth; uiCol++)
			poMTXmatrix->MTXsetValue(uiRow, uiCol, sMTXinfos.pdValues[uiRow][uiCol]);
		free(sMTXinfos.pdValues[uiRow]);
	}
	free(sMTXinfos.pdValues);
	return poMTXmatrix;
}
