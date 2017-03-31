#ifndef CARC
#define CARC

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