#include <cstdlib>
#include <stdio.h>
#include <iostream>

#include "CGraph.h"
#include "CException.h"
#include "utils.h"
#include "CGraphParser.h"

CGraph::CGraph() : uiVertexCount(0), poVERvertexList(nullptr), uiBiggestVertex(0)
{
}

CGraph::CGraph(char * pcFileName) : uiVertexCount(0), poVERvertexList(nullptr), uiBiggestVertex(0)
{
	/* Open the file */
	FILE * poFILEfile;
	try
	{
		FOPEN(poFILEfile, pcFileName, "r", IO_FILE_EXCEPTION, "Error opening graph file");
	}
	catch(CException const &poEXexception)
	{
		perror(poEXexception.EXgetExceptionMessage());
		throw poEXexception;
	}
	
	/* Get vertices count */
	char * pcLineRead = CGraphParser::PGRAreadLineFromFile(poFILEfile);
	char * pcLineValue = CGraphParser::PGRAgetLineValue(pcLineRead);
	char * pcLineKey = CGraphParser::PGRAgetLineKey(pcLineRead, pcLineValue - 1);
	if(STRCMPI("NBSommets", pcLineKey) != 0)
	{
		free(pcLineKey);
		free(pcLineRead);
		
		throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "NBSommets expected, get something else");
	}
	unsigned int uiVertexCount = (unsigned int) atoi(pcLineValue);
	free(pcLineKey);
	free(pcLineRead);
	
	/* Get arcs count */
	pcLineRead = CGraphParser::PGRAreadLineFromFile(poFILEfile);
	pcLineValue = CGraphParser::PGRAgetLineValue(pcLineRead);
	pcLineKey = CGraphParser::PGRAgetLineKey(pcLineRead, pcLineValue - 1);
	if(STRCMPI("NBArcs", pcLineKey) != 0)
	{
		free(pcLineKey);
		free(pcLineRead);
		
		throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "NBArcs expected, get something else");
	}
	unsigned int uiArcCount = (unsigned int) atoi(pcLineValue);
	free(pcLineKey);
	free(pcLineRead);
	
	/* Get vertices */
	pcLineRead = CGraphParser::PGRAreadLineFromFile(poFILEfile);
	pcLineValue = CGraphParser::PGRAgetLineValue(pcLineRead);
	pcLineKey = CGraphParser::PGRAgetLineKey(pcLineRead, pcLineValue - 1);
	if(STRCMPI("Sommets", pcLineKey) != 0)
	{
		free(pcLineKey);
		free(pcLineRead);
		
		throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "Sommets expected, get something else");
	}
	free(pcLineKey);
	free(pcLineRead);
	
	/* For each expected vertex */
	for(unsigned int uiVertexIndex = 0; uiVertexIndex < uiVertexCount; uiVertexIndex++)
	{
		pcLineRead = CGraphParser::PGRAreadLineFromFile(poFILEfile);
		pcLineValue = CGraphParser::PGRAgetLineValue(pcLineRead);
		pcLineKey = CGraphParser::PGRAgetLineKey(pcLineRead, pcLineValue - 1);
		if(STRCMPI("Numero", CGraphParser::PGRAtrim(pcLineKey)) != 0)
		{
			free(pcLineKey);
			free(pcLineRead);
			
			throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "Sommets expected, get something else");
		}
		GRAaddVertex((unsigned int) atoi(pcLineValue));
		free(pcLineKey);
		free(pcLineRead);
	}
	
	/* Skip line containing ] */
	free(CGraphParser::PGRAreadLineFromFile(poFILEfile));
	
	/* Get arcs */
	pcLineRead = CGraphParser::PGRAreadLineFromFile(poFILEfile);
	pcLineValue = CGraphParser::PGRAgetLineValue(pcLineRead);
	pcLineKey = CGraphParser::PGRAgetLineKey(pcLineRead, pcLineValue - 1);
	if(STRCMPI("Arcs", pcLineKey) != 0)
	{
		free(pcLineKey);
		free(pcLineRead);
		
		throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "Arcs expected, get something else");
	}
	free(pcLineKey);
	free(pcLineRead);
	
	/* For each expected arc */
	for(unsigned int uiArcIndex = 0; uiArcIndex < uiArcCount; uiArcIndex++)
	{
		pcLineRead = CGraphParser::PGRAreadLineFromFile(poFILEfile);
		
		int iStart = -1;
		int iEnd = -1;
		
		unsigned int uiValuesCount = 0;
		char ** pcValues = CGraphParser::PGRAsplit((char *) ",", &uiValuesCount, pcLineRead);
		
		/* For each key/value */
		for(unsigned int uiValueIndex = 0; uiValueIndex < uiValuesCount; uiValueIndex++)
		{
			char * pcValueValue = CGraphParser::PGRAgetLineValue(pcValues[uiValueIndex]);
			char * pcValueKey = CGraphParser::PGRAgetLineKey(pcValues[uiValueIndex], pcValueValue - 1);
			
			if(STRCMPI("Debut", CGraphParser::PGRAtrim(pcValueKey)) == 0)
				iStart = atoi(pcValueValue);
			else if(STRCMPI("Fin", CGraphParser::PGRAtrim(pcValueKey)) == 0)
				iEnd = atoi(pcValueValue);
			
			free(pcValueKey);
		}
		free(pcValues);
		
		/* If we don't have the required keys, start and end */
		if(iStart < 0 || iEnd < 0)
		{
			free(pcLineRead);
			
			throw CException(MALFORMATTED_FILE_EXCEPTION, (char *) "Arcs malformatted");
		}
		
		GRAaddArc((unsigned int) iStart, (unsigned int) iEnd);
		free(pcLineRead);
	}
	
	fclose(poFILEfile);
}

CGraph::~CGraph()
{
	GRAclear();
}

void CGraph::GRAaddVertex(unsigned int uiVertexIndex)
{
	/* If the index of the new vertex is bigger than the biggest, realloc the list for the new size and fill it with nullptr */
	if(uiVertexIndex > uiBiggestVertex)
	{
		RREALLOC(poVERvertexList, CVertex *, uiVertexIndex, "Fail Realloc GRAaddVertex");
		for(unsigned int uiIndex = uiBiggestVertex; uiIndex < uiVertexIndex; uiIndex++)
			poVERvertexList[uiIndex] = nullptr;
		uiBiggestVertex = uiVertexIndex;
	}

	if(poVERvertexList[uiVertexIndex - 1] != nullptr)
		throw CException(DUPLICATE_VERTEX_EXCEPTION, (char *) "Vertex already existing");
	
	poVERvertexList[uiVertexIndex - 1] = new CVertex(uiVertexIndex);
	uiVertexCount++;
}

void CGraph::GRAremoveVertex(unsigned int uiVertexIndex)
{
	if(GRAhasVertex(uiVertexIndex))
	{
		for(unsigned int uiIndex = 1; uiIndex <= uiBiggestVertex; uiIndex++)
			if(GRAhasVertex(uiIndex)){
				poVERvertexList[uiIndex - 1]->VERremoveArcIn(uiVertexIndex);
				poVERvertexList[uiIndex - 1]->VERremoveArcOut(uiVertexIndex);
			}
		
		delete poVERvertexList[uiVertexIndex - 1];
		poVERvertexList[uiVertexIndex - 1] = nullptr;
		uiVertexCount--;
	}
}

bool CGraph::GRAhasVertex(unsigned int uiVertexIndex) const
{
	return uiVertexIndex > 0 && uiVertexIndex <= uiBiggestVertex && poVERvertexList[uiVertexIndex - 1] != nullptr;
}

void CGraph::GRAaddArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex)
{
	if(!GRAhasVertex(uiFromVertexIndex) || !GRAhasVertex(uiToVertexIndex))
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of these vertex doesn't exist");
	
	poVERvertexList[uiFromVertexIndex - 1]->VERaddArcOut(uiToVertexIndex);
	poVERvertexList[uiToVertexIndex - 1]->VERaddArcIn(uiFromVertexIndex);
}

void CGraph::GRAremoveArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex)
{
	if(!GRAhasVertex(uiFromVertexIndex) || !GRAhasVertex(uiToVertexIndex))
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of these vertex doesn't exist");

	poVERvertexList[uiFromVertexIndex - 1]->VERremoveArcOut(uiToVertexIndex);
	poVERvertexList[uiToVertexIndex - 1]->VERremoveArcIn(uiFromVertexIndex);
}

void CGraph::GRAmodifyArc(unsigned int uiFromVertexIndex, unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex)
{
	if(!GRAhasVertex(uiFromVertexIndex) || !GRAhasVertex(uiLastToVertexIndex) || !GRAhasVertex(uiNewToVertexIndex))
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of those vertex doesn't exist");
	
	if(!GRAhasArc(uiFromVertexIndex, uiLastToVertexIndex))
		throw CException(MISSING_ARC_INDEX_EXCEPTION, (char *) "Modifying non existing arc");
	
	if(GRAhasArc(uiFromVertexIndex, uiNewToVertexIndex))
		throw CException (DUPLICATE_ARC_EXCEPTION, (char *) "The new arc already exists");

	poVERvertexList[uiLastToVertexIndex - 1]->VERremoveArcIn(uiFromVertexIndex);
	poVERvertexList[uiFromVertexIndex - 1]->VERmodifyArcOut(uiLastToVertexIndex, uiNewToVertexIndex);
	poVERvertexList[uiNewToVertexIndex - 1]->VERaddArcIn(uiFromVertexIndex);
}

bool CGraph::GRAhasArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex) const
{
	if(!GRAhasVertex(uiFromVertexIndex) || !GRAhasVertex(uiToVertexIndex))
		return false;
	
	return poVERvertexList[uiFromVertexIndex - 1]->VERhasIndexOut(uiToVertexIndex) && poVERvertexList[uiToVertexIndex - 1]->VERhasIndexIn(uiFromVertexIndex);
}

void CGraph::GRAaddLink(unsigned int uiVertexIndex1, unsigned int uiVertexIndex2)
{
	if(!GRAhasVertex(uiVertexIndex1) || !GRAhasVertex(uiVertexIndex2))
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of those vertex doesn't exist");
	
	GRAaddArc(uiVertexIndex1, uiVertexIndex2);
	GRAaddArc(uiVertexIndex2, uiVertexIndex1);
}

void CGraph::GRAinvert()
{
	for(unsigned int uiIndex = 1; uiIndex <= uiBiggestVertex; uiIndex++)
		if(GRAhasVertex(uiIndex))
			poVERvertexList[uiIndex - 1]->VERinvert();
}

void CGraph::GRAclear(){
	/* Destroy and free all vertex */
	for(unsigned int uiIndex = 0; uiIndex < uiBiggestVertex; uiIndex++)
		if(poVERvertexList[uiIndex] != nullptr)
			delete poVERvertexList[uiIndex];
	free(poVERvertexList);
}

void CGraph::GRAdisplay(unsigned int uiLevel) const
{
	std::cout << "This graph contains " << uiVertexCount << " vertex." << std::endl;
	
	if(uiLevel > 0)
		for(unsigned int uiIndex = 0; uiIndex < uiBiggestVertex; uiIndex++)
		{
			if(poVERvertexList[uiIndex] != nullptr)
			{
				if(uiLevel >= 1)
					std::cout << std::endl << "Vertex number " << poVERvertexList[uiIndex]->VERgetVertexIndex();
				if(uiLevel == 2 || uiLevel > 3)
					poVERvertexList[uiIndex]->VERdisplayArcOut();
				if(uiLevel >= 3)
					poVERvertexList[uiIndex]->VERdisplayArcIn();
			}
		}
	
	std::cout << std::endl;
}

CGraph &CGraph::operator+(unsigned int uiVertexIndex)
{
	GRAaddVertex(uiVertexIndex);
	return *this;
}

CGraph &CGraph::operator-(unsigned int uiVertexIndex)
{
	GRAremoveVertex(uiVertexIndex);
	return *this;
}