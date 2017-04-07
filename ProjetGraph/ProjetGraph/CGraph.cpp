#include <cstdlib>
#include <stdio.h>
#include <iostream>

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
	
	if(poVERvertexList[uiVertexIndex - 1] != nullptr)
		throw CException(DUPLICATE_VERTEX_EXCEPTION, "Vertex already existing");

	poVERvertexList[uiVertexIndex - 1] = new CVertex(uiVertexIndex);
	uiVertexCount++;
}

void CGraph::GRAremoveVertex(unsigned int uiVertexIndex)
{
	if(GRAhasVertex(uiVertexIndex))
	{
		for(unsigned int uiIndex = 1; uiIndex <= uiBiggestVertex; uiIndex++)
		{
			if(poVERvertexList[uiVertexIndex - 1]->VERhasIndexOut(uiIndex))
				poVERvertexList[uiIndex - 1]->VERremoveArcIn(uiVertexIndex);
			if(poVERvertexList[uiVertexIndex - 1]->VERhasIndexIn(uiIndex))
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
	if(uiFromVertexIndex > uiBiggestVertex  || uiToVertexIndex > uiBiggestVertex  || poVERvertexList[uiFromVertexIndex - 1] == nullptr || poVERvertexList[uiToVertexIndex - 1] == nullptr)
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of these vertex doesn't exist");
	
	poVERvertexList[uiFromVertexIndex - 1]->VERaddArcOut(uiToVertexIndex);
	poVERvertexList[uiToVertexIndex - 1]->VERaddArcIn(uiFromVertexIndex);
}

void CGraph::GRAremoveArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex)
{
	poVERvertexList[uiFromVertexIndex - 1]->VERremoveArcOut(uiToVertexIndex);
	poVERvertexList[uiToVertexIndex - 1]->VERremoveArcIn(uiFromVertexIndex);
}

void CGraph::GRAmodifyArc(unsigned int uiFromVertexIndex, unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex)
{
	if(uiFromVertexIndex > uiBiggestVertex  || uiLastToVertexIndex > uiBiggestVertex  || uiNewToVertexIndex > uiBiggestVertex  || poVERvertexList[uiFromVertexIndex - 1] == nullptr || poVERvertexList[uiLastToVertexIndex - 1] == nullptr || poVERvertexList[uiNewToVertexIndex - 1] == nullptr)
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of these vertex doesn't exist");
	
	if(!GRAhasArc(uiFromVertexIndex, uiLastToVertexIndex))
		throw CException(MISSING_ARC_INDEX_EXCEPTION, (char *) "Modifying non existing arc");
	poVERvertexList[uiLastToVertexIndex - 1]->VERremoveArcIn(uiFromVertexIndex);
	poVERvertexList[uiFromVertexIndex - 1]->VERmodifyArcOut(uiLastToVertexIndex, uiNewToVertexIndex);
	poVERvertexList[uiNewToVertexIndex - 1]->VERaddArcIn(uiFromVertexIndex);
}

bool CGraph::GRAhasArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex) const
{
	if(uiFromVertexIndex > uiBiggestVertex  || uiToVertexIndex > uiBiggestVertex  || poVERvertexList[uiFromVertexIndex - 1] == nullptr || poVERvertexList[uiToVertexIndex - 1] == nullptr)
		return false;
	
	return poVERvertexList[uiFromVertexIndex - 1]->VERhasIndexOut(uiToVertexIndex) && poVERvertexList[uiToVertexIndex - 1]->VERhasIndexIn(uiFromVertexIndex);
}

void CGraph::GRAaddLink(unsigned int uiVertexIndex1, unsigned int uiVertexIndex2)
{
	if(uiVertexIndex1 > uiBiggestVertex  || uiVertexIndex2 > uiBiggestVertex  || poVERvertexList[uiVertexIndex1 - 1] == nullptr || poVERvertexList[uiVertexIndex2 - 1] == nullptr)
		throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "One of these vertex doesn't exist");
	
	GRAaddArc(uiVertexIndex1, uiVertexIndex2);
	GRAaddArc(uiVertexIndex2, uiVertexIndex1);
}

void CGraph::GRAinvert(){
	for(unsigned int uiIndex = 1; uiIndex <= uiBiggestVertex; uiIndex++)
		if(GRAhasVertex(uiIndex))
			poVERvertexList[uiIndex -1]->VERinvert();
}

void CGraph::GRAdisplay(unsigned int uiLevel) const
{
	std::cout << "This graph contains " << uiVertexCount << " vertex." << std::endl;
	
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