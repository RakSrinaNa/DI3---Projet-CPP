#include <cstdio>
#include <cstdlib>
#include "CMatrixParser.h"
#include "CException.h"
#include "utils.h"

template <class T>
static CMatrix<T> CMatrixParser::PMTXreadFile(char* pcFileName)
{
	FILE* poFILEfile = fopen(pcFileName, "r");
	if(poFILEfile == nullptr)
	{
		CException * poCEXexception = new CException(IO_FILE_EXCEPTION, (char *) "Error opening matrix file");
		throw poCEXexception;
	}
	
	char * pcCurrentLine = PMTXreadLineFromFile(poFILEfile);
	
	
	fclose(poFILEfile);
	return nullptr;
}

static char * CMatrixParser::PMTXreadLineFromFile(FILE * poFILEfile)
{
	char * pcLineRead = NULL;
	size_t uiSize = 0;
	do
	{
		if(pcLineRead != NULL) // If an empty line was read before, free it
		{
			free(pcLineRead);
			pcLineRead = NULL;
		}
		if(PMTXgetLine(&pcLineRead, &uiSize, poFILEfile) == -1) // Read a line, and return NULL if end of poFILEfile
			return NULL;
	} while(*pcLineRead == '\n' || (*pcLineRead == '\r' && pcLineRead[1] == '\n')); // While we have a non empty line
	return pcLineRead;
}

static int CMatrixParser::PMTXgetLine(char ** pcLinePtr, size_t * pcLineSize, FILE * poFILEfile)
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