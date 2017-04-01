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
	//TODO grosse merde à venir
	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++){
		free(poARCinList[uiIndex]);
	}
	free(poARCinList);

	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		free(poARCoutList[uiIndex]);
	free(poARCoutList);
}

void CVertex::VERaddArcIn(unsigned int uiFromVertexIndex)
{
	for(int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		if(uiFromVertexIndex == poARCinList[uiIndex]->ARCgetVertexIndex())
			return;
	RREALLOC(poARCinList, CArc *, ++uiArcInCount, "Fail realloc VERaddArcOut");
	poARCinList[uiArcInCount - 1] = new CArc(uiFromVertexIndex);
}

void CVertex::VERremoveArcIn(unsigned int uiFromVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		if(uiFromVertexIndex == poARCinList[uiIndex]->ARCgetVertexIndex())
		{
			free(poARCinList[uiIndex]);
			poARCinList[uiIndex] = poARCinList[--uiArcInCount];
			RREALLOC(poARCinList, CArc *, uiArcInCount, "Fail realloc VERremoveArcOut");
		}
}

void CVertex::VERaddArcOut(unsigned int uiToVertexIndex)
{
	for(int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(uiToVertexIndex == poARCoutList[uiIndex]->ARCgetVertexIndex())
			return;
	RREALLOC(poARCoutList, CArc *, ++uiArcOutCount, "Fail realloc VERaddArcOut");
	poARCoutList[uiArcOutCount - 1] = new CArc(uiToVertexIndex);
}

void CVertex::VERremoveArcOut(unsigned int uiToVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(uiToVertexIndex == poARCoutList[uiIndex]->ARCgetVertexIndex())
		{
			free(poARCoutList[uiIndex]);
			poARCoutList[uiIndex] = poARCoutList[--uiArcOutCount];
			RREALLOC(poARCoutList, CArc *, uiArcOutCount, "Fail realloc VERremoveArcOut");
		}
}

unsigned int CVertex::VERgetVertexIndex()
{
	return uiVertexIndex;
}

void CVertex::VERmodifyArcIn(unsigned int uiLastFromVertexIndex, unsigned int uiNewFromVertexIndex)
{
	//TODO
}

void CVertex::VERmodifyArcOut(unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex)
{
	//TODO
}
