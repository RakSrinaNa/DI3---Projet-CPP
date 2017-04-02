#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "CGraphParser.h"
#include "utils.h"
#include "CException.h"

CGraph * CGraphParser::PGRAreadGraph(char* pcFileName)
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
	
	CGraph * poGRAgraph;
	MMALLOC(poGRAgraph, CGraph, 1, "Malloc error PGRAreadGraph");
	
	//TODO
	throw CException(0, (char *) "Reviens plus tard");
	
	fclose(poFILEfile);
	return poGRAgraph;
}

char * CGraphParser::PGRAgetLineValue(char * pcLine)
{
	while(*pcLine != '=' && *pcLine != '\0')
		pcLine++;
	if(*pcLine == '\0')
		throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "File is not in a correct format");
	return pcLine + 1;
}

char * CGraphParser::PGRAgetLineKey(char * pcStart, char * pcEnd)
{
	char * pcKey;
	unsigned int uiSize = (unsigned int) (pcEnd - pcStart);
	MMALLOC(pcKey, char, uiSize + 1, "Parser fail getting key");
	for(unsigned int uiIndex = 0; uiIndex < uiSize; uiIndex++)
		pcKey[uiIndex] = pcStart[uiIndex];
	pcKey[uiSize] = '\0';
	return pcKey;
}

char * CGraphParser::PMTXreadLineFromFile(FILE * poFILEfile)
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
	// RREALLOC(pcLineRead, char, iEndString, "Error realloc PMTXreadLineFromFile");
	return pcLineRead;
}

int CGraphParser::PMTXgetLine(char ** pcLinePtr, size_t * pcLineSize, FILE * poFILEfile)
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
