#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "CGraphParser.h"
#include "utils.h"
#include "CException.h"

CGraph * CGraphParser::PGRAreadGraph(char* pcFileName)
{
	/* Open the file */
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
	
	/* Prepare graph */
	CGraph * poGRAgraph = new CGraph();
	
	/* Get vertices count */
	char * pcLineRead = PGRAreadLineFromFile(poFILEfile);
	char * pcLineValue = PGRAgetLineValue(pcLineRead);
	char * pcLineKey = PGRAgetLineKey(pcLineRead, pcLineValue - 1);
	if(STRCMPI("NBSommets", pcLineKey) != 0)
	{
		free(pcLineKey);
		free(pcLineRead);
		free(poGRAgraph);
		
		throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "NBSommets expected, get something else");
	}
	unsigned int uiVertexCount = (unsigned int) atoi(pcLineValue);
	free(pcLineKey);
	free(pcLineRead);
	
	/* Get arcs count */
	pcLineRead = PGRAreadLineFromFile(poFILEfile);
	pcLineValue = PGRAgetLineValue(pcLineRead);
	pcLineKey = PGRAgetLineKey(pcLineRead, pcLineValue - 1);
	if(STRCMPI("NBArcs", pcLineKey) != 0)
	{
		free(pcLineKey);
		free(pcLineRead);
		free(poGRAgraph);
		
		throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "NBArcs expected, get something else");
	}
	unsigned int uiArcCount = (unsigned int) atoi(pcLineValue);
	free(pcLineKey);
	free(pcLineRead);
	
	/* Get vertices */
	pcLineRead = PGRAreadLineFromFile(poFILEfile);
	pcLineValue = PGRAgetLineValue(pcLineRead);
	pcLineKey = PGRAgetLineKey(pcLineRead, pcLineValue - 1);
	if(STRCMPI("Sommets", pcLineKey) != 0)
	{
		free(pcLineKey);
		free(pcLineRead);
		free(poGRAgraph);
		
		throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "Sommets expected, get something else");
	}
	free(pcLineKey);
	free(pcLineRead);
	
	for(unsigned int uiVertexIndex = 0; uiVertexIndex < uiVertexCount; uiVertexIndex++)
	{
		pcLineRead = PGRAreadLineFromFile(poFILEfile);
		pcLineValue = PGRAgetLineValue(pcLineRead);
		pcLineKey = PGRAgetLineKey(pcLineRead, pcLineValue - 1);
		if(STRCMPI("Numero", PGRAtrim(pcLineKey)) != 0)
		{
			free(pcLineKey);
			free(pcLineRead);
			free(poGRAgraph);
			
			throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "Sommets expected, get something else");
		}
		poGRAgraph->GRAaddVertex((unsigned int) atoi(pcLineValue));
		free(pcLineKey);
		free(pcLineRead);
	}
	
	/* Skip line containing ] */
	free(PGRAreadLineFromFile(poFILEfile));
	
	/* Get arcs */
	pcLineRead = PGRAreadLineFromFile(poFILEfile);
	pcLineValue = PGRAgetLineValue(pcLineRead);
	pcLineKey = PGRAgetLineKey(pcLineRead, pcLineValue - 1);
	if(STRCMPI("Arcs", pcLineKey) != 0)
	{
		free(pcLineKey);
		free(pcLineRead);
		free(poGRAgraph);
		
		throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "Arcs expected, get something else");
	}
	free(pcLineKey);
	free(pcLineRead);
	
	for(unsigned int uiArcIndex = 0; uiArcIndex < uiArcCount; uiArcIndex++)
	{
		pcLineRead = PGRAreadLineFromFile(poFILEfile);
		
		int iStart = -1;
		int iEnd = -1;
		
		unsigned int uiValuesCount = 0;
		char ** pcValues = PGRAsplit((char *) ",", &uiValuesCount, pcLineRead);
		
		for(unsigned int uiValueIndex = 0; uiValueIndex < uiValuesCount; uiValueIndex++)
		{
			char * pcValueValue = PGRAgetLineValue(pcValues[uiValueIndex]);
			char * pcValueKey = PGRAgetLineKey(pcValues[uiValueIndex], pcValueValue - 1);
			
			if(STRCMPI("Debut", PGRAtrim(pcValueKey)) == 0)
				iStart = atoi(pcValueValue);
			else if(STRCMPI("Fin", PGRAtrim(pcValueKey)) == 0)
				iEnd = atoi(pcValueValue);
			
			free(pcValueKey);
		}
		free(pcValues);
		
		if(iStart < 0 || iEnd < 0)
		{
			free(pcLineRead);
			free(poGRAgraph);
			
			throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "Arcs malformatted");
		}
		
		poGRAgraph->GRAaddArc((unsigned int) iStart, (unsigned int) iEnd);
		free(pcLineRead);
	}
	
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

char * CGraphParser::PGRAreadLineFromFile(FILE * poFILEfile)
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
		if((iEndString = PGRAgetLine(&pcLineRead, &uiSize, poFILEfile)) == -1) // Read a line, and return NULL if end of poFILEfile
			return NULL;
	} while(*pcLineRead == '\n' || (*pcLineRead == '\r' && pcLineRead[1] == '\n')); // While we have a non empty line
	
	/* Clean ending \n \r \r */
	while(iEndString > 0 && (pcLineRead[iEndString] == '\0' || pcLineRead[iEndString] == '\n' || pcLineRead[iEndString] == '\r' || pcLineRead[iEndString] == '\t'))
		iEndString--;
	iEndString++;
	pcLineRead[iEndString] = '\0';
	// RREALLOC(pcLineRead, char, iEndString, "Error realloc PGRAreadLineFromFile");
	return pcLineRead;
}

int CGraphParser::PGRAgetLine(char ** pcLinePtr, size_t * pcLineSize, FILE * poFILEfile)
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

char ** CGraphParser::PGRAsplit(char * cSeparators, unsigned int * puiSize, char * pcString)
{
	char ** ppcValues = nullptr;
	*puiSize = 0;
	
	while(pcString != nullptr)
	{
		(*puiSize)++;
		RREALLOC(ppcValues, char *, *puiSize, "REALLOC ERROR PGRASPLIT");
		ppcValues[*puiSize - 1] = PGRAstrsep(&pcString, cSeparators);
	}
	
	return ppcValues;
}

char * CGraphParser::PGRAtrim(char * pcString)
{
	char * start = pcString;
	char * end = start + strlen(pcString);
	while(*start == '\t' || *start == '\n' || *start == ' ')
		start++;
	while(*end == '\t' || *end == '\n' || *end == ' ' || *end == '\0')
		end--;
	*(end + 1) = '\0';
	return start;
}

char* CGraphParser::PGRAstrsep(char ** ppcNextString, const char * pcDelims)
{
  char* pcString = *ppcNextString;
  char* pcToken;
  pcToken = (pcString != nullptr) ? strpbrk(pcString, pcDelims) : nullptr;
  if(pcToken == nullptr)
    *ppcNextString = nullptr;
  else
  {
    *pcToken = '\0';
    *ppcNextString = pcToken + 1;
  }
  return pcString;
}