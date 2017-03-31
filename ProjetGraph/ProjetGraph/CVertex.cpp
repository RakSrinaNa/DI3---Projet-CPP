#include "CVertex.h"
#include "CException.h"
#include "utils.h"

CVertex::CVertex()
{
	throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "Use the constructor : CVertex(unsigned int)");
}

CVertex::CVertex(unsigned int uiVertexIndexParam) : uiVertexIndex(uiVertexIndexParam), uiArcInCount(0), uiArcOutCount(0), poARCinList(nullptr), poARCoutList(nullptr)
{
}

CVertex::~CVertex()
{
	//TODO: free arcs and the lists
}

void CVertex::VERaddArcIn(unsigned int uiFromVertexIndex)
{
	//TODO: Verify if arc is already in, else create and add it
}

void CVertex::VERremoveArcIn(unsigned int uiFromIndex)
{
	//TODO
}

void CVertex::VERaddArcOut(unsigned int uiToVertexIndex)
{
	for(int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(uiToVertexIndex == poARCoutList[uiIndex]->ARCgetVertexIndex())
			return;
	RREALLOC(poARCoutList, CArc *, ++uiArcOutCount, "Fail realloc VERaddArc");
	poARCoutList[uiArcOutCount - 1] = new CArc(uiToVertexIndex);
}

void CVertex::VERremoveArcOut(unsigned int uiToVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(uiToVertexIndex == poARCoutList[uiIndex]->ARCgetVertexIndex())
		{
			free(poARCoutList[uiIndex]);
			poARCoutList[uiIndex] = poARCoutList[--uiArcOutCount];
		}
	//TODO
}

unsigned int CVertex::VERgetVertexIndex()
{
	return 0; //TODO
}

void CVertex::VERmodifyArcIn(unsigned int uiLastFromVertexIndex, unsigned int uiNewFromVertexIndex)
{
	//TODO
}

void CVertex::VERmodifyArcOut(unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex)
{
	//TODO
}
