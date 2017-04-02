#include <cstdlib>

#include "CGraph.h"
#include "CException.h"
#include "utils.h"

CGraph::CGraph() : uiVertexCount(0), poVERvertexList(nullptr), uiBiggestVertex(0)
{
}

CGraph::~CGraph()
{
	for(unsigned int uiIndex = 0; uiIndex < uiBiggestVertex; uiIndex++)
		if(poVERvertexList[uiIndex] != nullptr)
			poVERvertexList[uiIndex]->~CVertex();
	free(poVERvertexList);
}

void CGraph::GRAaddVertex(unsigned int uiVertexIndex)
{
	if(uiVertexIndex > uiBiggestVertex)
	{
		RREALLOC(poVERvertexList, CVertex *, uiVertexIndex, "Fail Realloc GRAaddVertex");
		for(unsigned int uiIndex = uiBiggestVertex; uiIndex < uiVertexIndex; uiIndex++)
			poVERvertexList[uiIndex] = nullptr;
		uiBiggestVertex = uiVertexIndex;
	}
	
	if(poVERvertexList[uiVertexIndex - 1] == nullptr)
		poVERvertexList[uiVertexIndex - 1] = new CVertex(uiVertexIndex);
	
	uiVertexCount++;
}

void CGraph::GRAremoveVertex(unsigned int uiVertexIndex)
{
	if(poVERvertexList[uiVertexIndex - 1] != nullptr)
	{
		for(unsigned int uiIndex = 1; uiIndex <= uiBiggestVertex; uiIndex++)
		{
			if(poVERvertexList[uiVertexIndex - 1]->VERhasIndexOut(uiIndex))
				poVERvertexList[uiIndex - 1]->VERremoveArcIn(uiVertexIndex);
			if(poVERvertexList[uiVertexIndex - 1]->VERhasIndexIn(uiIndex))
				poVERvertexList[uiIndex - 1]->VERremoveArcOut(uiVertexIndex);
		}
		
		poVERvertexList[uiVertexIndex - 1]->~CVertex();
		poVERvertexList[uiVertexIndex - 1] = nullptr;
	}
}

void CGraph::GRAaddArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex)
{
	if(poVERvertexList[uiFromVertexIndex - 1] == nullptr || poVERvertexList[uiToVertexIndex - 1] == nullptr)
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of these vertex doesn't exist");
	
	poVERvertexList[uiFromVertexIndex - 1]->VERaddArcOut(uiToVertexIndex);
	poVERvertexList[uiToVertexIndex - 1]->VERaddArcIn(uiFromVertexIndex);
}

void CGraph::GRAremoveArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex)
{
	if(poVERvertexList[uiFromVertexIndex - 1] == nullptr || poVERvertexList[uiToVertexIndex - 1] == nullptr)
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of these vertex doesn't exist");
	
	poVERvertexList[uiFromVertexIndex - 1]->VERremoveArcOut(uiToVertexIndex);
	poVERvertexList[uiToVertexIndex - 1]->VERremoveArcIn(uiToVertexIndex);
}

void CGraph::GRAmodifyArc(unsigned int uiFromVertexIndex, unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex)
{
	if(poVERvertexList[uiFromVertexIndex - 1] == nullptr || poVERvertexList[uiLastToVertexIndex - 1] == nullptr || poVERvertexList[uiNewToVertexIndex - 1] == nullptr)
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of these vertex doesn't exist");
	
	poVERvertexList[uiLastToVertexIndex - 1]->VERremoveArcIn(uiFromVertexIndex);
	poVERvertexList[uiFromVertexIndex - 1]->VERmodifyArcOut(uiLastToVertexIndex, uiNewToVertexIndex);
	poVERvertexList[uiNewToVertexIndex - 1]->VERaddArcIn(uiFromVertexIndex);
}

CGraph &CGraph::operator+(unsigned int uiVertexIndex)
{
	GRAaddVertex(uiVertexIndex);
	return *this;
}