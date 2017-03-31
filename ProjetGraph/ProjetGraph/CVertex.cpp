#include "CVertex.h"

CVertex::CVertex(){
}

CVertex::CVertex(unsigned int uiVertexIndexParam) : uiVertexIndex(uiVertexIndexParam), uiArcInCount(0), uiArcOutCount(0){
}

CVertex::~CVertex(){
}

void CVertex::VERaddArc(unsigned int uiToIndex){
}

void CVertex::VERremoveArc(unsigned int uiToIndex){
}

void CVertex::VERmodifyArc(unsigned int uiLastIndex, unsigned int uiNewIndex){
}

unsigned int CVertex::VERgetVertexIndex(){
}
