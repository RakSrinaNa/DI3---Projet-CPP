#include "CVertex.h"
#include "CException.h"
#include "utils.h"

CVertex::CVertex(){
	throw CException(MISSING_VERTEX_INDEX_EXCEPTION, "Use the constructor : CVertex(unsigned int)");
}

CVertex::CVertex(unsigned int uiVertexIndexParam) : uiVertexIndex(uiVertexIndexParam), uiArcInCount(0), uiArcOutCount(0), poARCinList(nullptr), poARCoutList(nullptr){
}

CVertex::~CVertex(){
}

void CVertex::VERaddArcIn(unsigned int uiFromIndex){
}

void CVertex::VERremoveArcIn(unsigned int uiFromIndex){
}

void CVertex::VERaddArcOut(unsigned int uiToIndex){
	for(int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(uiToIndex == poARCoutList[uiIndex]->ARCgetVertexIndex())
			return;
	RREALLOC(poARCoutList, CArc *, ++uiArcOutCount, "Fail realloc VERaddArc");
	poARCoutList[uiArcOutCount-1] = new CArc(uiToIndex);
}

void CVertex::VERremoveArcOut(unsigned int uiToIndex){
	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(uiToIndex == poARCoutList[uiIndex]->ARCgetVertexIndex()){
			free(poARCoutList[uiIndex]);
			poARCoutList[uiIndex] = poARCoutList[--uiArcOutCount];
		}
		//TODO
}

void CVertex::VERmodifyArc(unsigned int uiLastIndex, unsigned int uiNewIndex){
}

unsigned int CVertex::VERgetVertexIndex(){
}
