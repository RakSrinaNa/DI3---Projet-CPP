#include <cstdlib>
#include <stdio.h>
#include <iostream>

#include "CGraph.h"
#include "CException.h"
#include "utils.h"
#include "CGraphParser.h"

/**************************************************************
 * Default constructor.
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 *      The graph have no vertices nor arcs.
 */
CGraph::CGraph() : uiVertexCount(0), poVERvertexList(nullptr), uiBiggestVertex(0)
{
}

/**************************************************************
 * Parameterized constructor with a file.
 **************************************************************
 *
 * Input:
 *      pcFilename: The path to the file to read.
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `IO_FILE_EXCEPTION` if a reading error happened.
 *      Throws a CException with the ID `MALFORMATTED_FILE_EXCEPTION` if the file is malformatted.
 */
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

/**************************************************************
 * Destructor.
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 *      Delete the graph with its vertices and arcs.
 */
CGraph::~CGraph()
{
	GRAclear();
}

/**************************************************************
 * Add a vertex to the graph.
 **************************************************************
 *
 * Input:
 *      uiVertexIndex: The ID of the vertex to add.
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `DUPLICATE_VERTEX_EXCEPTION` if the vertex already exists.
 *      Throws a CException with the ID `BAD_INDEX_VERTEX_EXCEPTION` if the ID of the vertex is less than 1.
 */
void CGraph::GRAaddVertex(unsigned int uiVertexIndex)
{
	if(uiVertexIndex == 0)
		throw CException(BAD_INDEX_VERTEX_EXCEPTION, (char *) "This index is impossible");
	/* If the index of the new vertex is bigger than the biggest, realloc the list for the new size and fill it with nullptr */
	if(uiVertexIndex > uiBiggestVertex)
	{
		RREALLOC(poVERvertexList, CVertex *, uiVertexIndex, "RREALLOC ERROR GRAaddVertex");
		for(unsigned int uiIndex = uiBiggestVertex; uiIndex < uiVertexIndex; uiIndex++)
			poVERvertexList[uiIndex] = nullptr;
		uiBiggestVertex = uiVertexIndex;
	}
	
	if(poVERvertexList[uiVertexIndex - 1] != nullptr)
		throw CException(DUPLICATE_VERTEX_EXCEPTION, (char *) "Vertex already existing");
	
	poVERvertexList[uiVertexIndex - 1] = new CVertex(uiVertexIndex);
	uiVertexCount++;
}

/**************************************************************
 * Remove a vertex from the graph.
 **************************************************************
 *
 * Input:
 *      uiVertexIndex: The ID of the vertex to remove.
 * Output:
 * PreCond:
 * PostCond:
 */
void CGraph::GRAremoveVertex(unsigned int uiVertexIndex)
{
	if(GRAhasVertex(uiVertexIndex))
	{
		for(unsigned int uiIndex = 1; uiIndex <= uiBiggestVertex; uiIndex++)
			if(GRAhasVertex(uiIndex))
			{
				poVERvertexList[uiIndex - 1]->VERremoveArcIn(uiVertexIndex);
				poVERvertexList[uiIndex - 1]->VERremoveArcOut(uiVertexIndex);
			}
		
		delete poVERvertexList[uiVertexIndex - 1];
		poVERvertexList[uiVertexIndex - 1] = nullptr;
		uiVertexCount--;
		
		/*If the biggest vertex was deleted, reallocation of the list */
		int uiIndex;
		for(uiIndex = uiBiggestVertex - 1; uiIndex >= 0u && poVERvertexList[uiIndex] == nullptr; uiIndex--);
		uiBiggestVertex = (unsigned int) (uiIndex + 1);
		RREALLOC(poVERvertexList, CVertex *, uiBiggestVertex, "RREALLOC ERROR GRAremoveVertex");
	}
}

/**************************************************************
 * Verify if a vertex is in the graph.
 **************************************************************
 *
 * Input:
 *      uiVertexIndex:  The ID of the vertex to find.
 * Output:
 *      bool:           True if the vertex exists, false else.
 * PreCond:
 * PostCond:
 */
bool CGraph::GRAhasVertex(unsigned int uiVertexIndex) const
{
	return uiVertexIndex > 0 && uiVertexIndex <= uiBiggestVertex && poVERvertexList[uiVertexIndex - 1] != nullptr;
}

/**************************************************************
 * Add an arc to the graph.
 **************************************************************
 *
 * Input:
 *      uiFromVertexIndex:  The ID of the starting vertex.
 *      uiToVertexIndex:    The ID of the ending vertex.
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if one of the vertices doesn't exist.
 *      Throws a CException with the ID `DUPLICATE_ARC_EXCEPTION` if the arc already exists.
 */
void CGraph::GRAaddArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex)
{
	if(!GRAhasVertex(uiFromVertexIndex) || !GRAhasVertex(uiToVertexIndex))
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of these vertex doesn't exist");
	
	poVERvertexList[uiFromVertexIndex - 1]->VERaddArcOut(uiToVertexIndex);
	poVERvertexList[uiToVertexIndex - 1]->VERaddArcIn(uiFromVertexIndex);
}

/**************************************************************
 * Remove an arc from the graph.
 **************************************************************
 *
 * Input:
 *      uiFromVertexIndex:  The ID of the starting vertex.
 *      uiToVertexIndex:    The ID of the ending vertex.
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if one of the vertices doesn't exist.
 */
void CGraph::GRAremoveArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex)
{
	if(!GRAhasVertex(uiFromVertexIndex) || !GRAhasVertex(uiToVertexIndex))
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of these vertex doesn't exist");
	
	poVERvertexList[uiFromVertexIndex - 1]->VERremoveArcOut(uiToVertexIndex);
	poVERvertexList[uiToVertexIndex - 1]->VERremoveArcIn(uiFromVertexIndex);
}

/**************************************************************
 * Modify the ending vertex of an existing arc.
 **************************************************************
 *
 * Input:
 *      uiFromVertexIndex:  The ID of the starting vertex.
 *      uiLastToVertexIndex:The ID of the old ending vertex.
 *      uiNewToVertexIndex: The ID of the new ending vertex.
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if one of the vertices doesn't exist.
 *      Throws a CException with the ID `MISSING_ARC_INDEX_EXCEPTION` if the arc doesn't exists.
 *      Throws a CException with the ID `DUPLICATE_ARC_EXCEPTION` if the new arc already exists.
 */
void CGraph::GRAmodifyArc(unsigned int uiFromVertexIndex, unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex)
{
	if(!GRAhasVertex(uiFromVertexIndex) || !GRAhasVertex(uiLastToVertexIndex) || !GRAhasVertex(uiNewToVertexIndex))
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of those vertex doesn't exist");
	
	if(!GRAhasArc(uiFromVertexIndex, uiLastToVertexIndex))
		throw CException(MISSING_ARC_INDEX_EXCEPTION, (char *) "Modifying non existing arc");
	
	if(GRAhasArc(uiFromVertexIndex, uiNewToVertexIndex))
		throw CException(DUPLICATE_ARC_EXCEPTION, (char *) "The new arc already exists");
	
	poVERvertexList[uiLastToVertexIndex - 1]->VERremoveArcIn(uiFromVertexIndex);
	poVERvertexList[uiFromVertexIndex - 1]->VERmodifyArcOut(uiLastToVertexIndex, uiNewToVertexIndex);
	poVERvertexList[uiNewToVertexIndex - 1]->VERaddArcIn(uiFromVertexIndex);
}

/**************************************************************
 * Verify if the arc contains an arc.
 **************************************************************
 *
 * Input:
 *      uiFromVertexIndex:  The ID of the starting vertex.
 *      uiToVertexIndex:    The ID of the ending vertex.
 * Output:
 *      bool:               True if the arc exists, false else.
 * PreCond:
 * PostCond:
 */
bool CGraph::GRAhasArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex) const
{
	if(!GRAhasVertex(uiFromVertexIndex) || !GRAhasVertex(uiToVertexIndex))
		return false;
	
	return poVERvertexList[uiFromVertexIndex - 1]->VERhasIndexOut(uiToVertexIndex) && poVERvertexList[uiToVertexIndex - 1]->VERhasIndexIn(uiFromVertexIndex);
}

/**************************************************************
 * Add a link (arcs in the two directions) between two vertices.
 **************************************************************
 *
 * Input:
 *      uiVertexIndex1: The ID of the first vertex.
 *      uiVertexIndex2: The ID of the second vertex.
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if one of the two vertices doesn't exist.
 */
void CGraph::GRAaddLink(unsigned int uiVertexIndex1, unsigned int uiVertexIndex2)
{
	if(!GRAhasVertex(uiVertexIndex1) || !GRAhasVertex(uiVertexIndex2))
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of those vertex doesn't exist");
	
	GRAaddArc(uiVertexIndex1, uiVertexIndex2);
	GRAaddArc(uiVertexIndex2, uiVertexIndex1);
}

/**************************************************************
 * Invert the graph (every arc is inverted).
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 */
void CGraph::GRAinvert()
{
	for(unsigned int uiIndex = 1; uiIndex <= uiBiggestVertex; uiIndex++)
		if(GRAhasVertex(uiIndex))
			poVERvertexList[uiIndex - 1]->VERinvert();
}

/**************************************************************
 * Resets the graph.
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 */
void CGraph::GRAclear()
{
	/* Destroy and free all vertex */
	for(unsigned int uiIndex = 0; uiIndex < uiBiggestVertex; uiIndex++)
		if(poVERvertexList[uiIndex] != nullptr)
			delete poVERvertexList[uiIndex];
	free(poVERvertexList);
	poVERvertexList = nullptr;
}

/**************************************************************
 * Display the graph in the standard output.
 **************************************************************
 *
 * Input:
 *      uiLevel: The level of detail of the output (default value is 4):
 *                  0 : Show the number of vertices in the graph.
 *                  1 : Level 0 + Show the list of the IDs of the vertices.
 *                  2 : Level 1 + Show the list of the outgoing arcs of every vertex.
 *                  3 : Level 1 + Show the list of the incoming arcs of every vertex.
 *                  4+: Level 2 & 3.
 * Output:
 * PreCond:
 * PostCond:
 */
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

/**************************************************************
 * Define the + operator adding a vertex to the graph.
 **************************************************************
 *
 * Input:
 *      uiVertexIndex: The ID of the vertex to add.
 * Output:
 * PreCond:
 *      The ID of the vertex must be greater or equal to 1.
 * PostCond:
 *      Throws a CException with the ID `DUPLICATE_VERTEX_EXCEPTION` if the vertex already exists.
 */
CGraph &CGraph::operator+(unsigned int uiVertexIndex)
{
	GRAaddVertex(uiVertexIndex);
	return *this;
}

/**************************************************************
 * Define the - operator removing a vertex from the graph.
 **************************************************************
 *
 * Input:
 *      uiVertexIndex: The ID of the vertex to remove.
 * Output:
 * PreCond:
 * PostCond:
 */
CGraph &CGraph::operator-(unsigned int uiVertexIndex)
{
	GRAremoveVertex(uiVertexIndex);
	return *this;
}

/**************************************************************
 * Defines the operator =.
 **************************************************************
 *
 * Entree:
 *      oGRAgraphParam: The graph to copy.
 * Sortie:
 *      CGraph&:        This graph modified.
 * PreCond:
 * PostCond:
 */
CGraph &CGraph::operator=(CGraph const &oGRAgraphParam)
{
	GRAclear();
	
	uiVertexCount = oGRAgraphParam.uiVertexCount;
	uiBiggestVertex = oGRAgraphParam.uiBiggestVertex;
	
	MMALLOC(poVERvertexList, CVertex *, uiBiggestVertex, "MMALLOC ERROR OPERATOR= CGRAPH");
	for(unsigned int uiIndex = 1; uiIndex <= uiBiggestVertex; uiIndex++)
		if(oGRAgraphParam.GRAhasVertex(uiIndex))
			poVERvertexList[uiIndex - 1] = new CVertex(*oGRAgraphParam.poVERvertexList[uiIndex - 1]);
		else
			poVERvertexList[uiIndex - 1] = nullptr;
	
	return *this;
}
