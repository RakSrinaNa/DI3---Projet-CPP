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
	
	bool GRAhasVertex(unsigned int uiVertexIndex);

	void GRAaddArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex);
	
	void GRAremoveArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex);
	
	void GRAmodifyArc(unsigned int uiFromVertexIndex, unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex);
	
	bool GRAhasArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex);

	void GRAaddLink(unsigned int uiVertexIndex1, unsigned int uiVertexIndex2);

	void GRAdisplay();

	CGraph & operator+(unsigned int uiVertexIndex);
};

#endif