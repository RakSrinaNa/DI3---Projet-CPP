#ifndef CVERTEX
#define CVERTEX

#include "CArc.h"


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

	void VERaddArc(unsigned int uiToIndex);
	void VERremoveArc(unsigned int uiToIndex);
	void VERmodifyArc(unsigned int uiLastIndex, unsigned int uiNewIndex);
	unsigned int VERgetVertexIndex();

};

#endif