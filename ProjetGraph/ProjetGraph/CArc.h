#ifndef CARC
#define CARC

#define MISSING_ARC_INDEX_EXCEPTION 1564

class CArc{

protected:
	unsigned int uiVertexIndex;

public:
	CArc();
	CArc(unsigned int uiVertexIndexParam);
	~CArc();

	unsigned int ARCgetVertexIndex();
	void ARCsetVertexIndex(unsigned int uiVertexIndexParam);

};

#endif