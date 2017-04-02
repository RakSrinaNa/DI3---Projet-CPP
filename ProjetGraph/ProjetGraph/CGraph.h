#ifndef CGRAPH
#define CGRAPH

#include "CVertex.h"

class CGraph
{

protected:
	unsigned int uiVertexCount;
	CVertex ** poVERvertexList;
	unsigned int uiBiggestVertex;

public:
	CGraph();
	
	~CGraph();
	
	void GRAaddVertex(unsigned int uiVertexIndex);
	
	void GRAremoveVertex(unsigned int uiVertexIndex);
	
	void GRAaddArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex);
	
	void GRAremoveArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex);
	
	void GRAmodifyArc(unsigned int uiFromVertexIndex, unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex);
	
	CGraph &operator+(unsigned int uiVertexIndex);
};

#endif