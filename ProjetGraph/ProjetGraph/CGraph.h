#ifndef CGRAPH
#define CGRAPH

#include "CVertex.h";

class CGraph{

protected:
	unsigned int uiVertexCount;
	CVertex ** poVERvertexList;

public:
	CGraph();
	~CGraph();

	void GRAaddVertex(unsigned int uiVertexIndex);
	void GRAremoveVertex(unsigned int uiVertexIndex);
	void GRAaddArc(unsigned int uiFromVertex, unsigned int uiToVertex);
	void GRAremoveArc(unsigned int uiFromVertex, unsigned int uiToVertex);
	void GRAmodifyArc(unsigned int uiFromVertex, unsigned int uiLastTo, unsigned int uiNewTo);

};

#endif