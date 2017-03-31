#include "CArc.h"

CArc::CArc(){
}

CArc::CArc(unsigned int uiVertexIndexParam) : uiVertexIndex(uiVertexIndexParam){
}

CArc::~CArc(){
}

inline unsigned int CArc::ARCgetVertexIndex(){
	return uiVertexIndex;
}

inline void CArc::ARCsetVertexIndex(unsigned int uiVertexIndexParam){
	uiVertexIndex = uiVertexIndexParam;
}
