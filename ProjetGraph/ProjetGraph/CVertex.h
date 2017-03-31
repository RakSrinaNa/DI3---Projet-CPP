#ifndef CVERTEX
#define CVERTEX

#include "CArc.h"

#define MISSING_VERTEX_INDEX_EXCEPTION 8792

class CVertex{

protected:
	unsigned int uiVertexIndex;
	unsigned int uiArcInCount;
	unsigned int uiArcOutCount;
	CArc ** poARCinList;
	CArc ** poARCoutList;

public:
	CVertex();
	CVertex(unsigned int uiVertexIndexParam);
	~CVertex();
	
	void VERaddArcIn(unsigned int uiFromIndex);
	void VERremoveArcIn(unsigned int uiFromIndex);
	void VERaddArcOut(unsigned int uiToIndex);
	void VERremoveArcOut(unsigned int uiToIndex);
	void VERmodifyArc(unsigned int uiLastIndex, unsigned int uiNewIndex);
	unsigned int VERgetVertexIndex();

};

#endif