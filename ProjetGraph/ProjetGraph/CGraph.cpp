#include <cstdlib>

#include "CGraph.h"
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
	if(uiVertexIndex > uiBiggestVertex){
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
	if(poVERvertexList[uiVertexIndex - 1] != nullptr){
		poVERvertexList[uiVertexIndex - 1]->~CVertex();
		poVERvertexList[uiVertexIndex - 1] = nullptr;
	}
}

void CGraph::GRAaddArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex)
{
	//TODO
}

void CGraph::GRAremoveArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex)
{
	//TODO
}

void CGraph::GRAmodifyArc(unsigned int uiFromVertexIndex, unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex)
{
	//TODO
}
