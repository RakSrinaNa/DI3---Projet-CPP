#include "CArc.h"
#include "CException.h"

CArc::CArc()
{
	throw CException(MISSING_ARC_INDEX_EXCEPTION, (char *) "Use the constructor : CArc(unsigned int)");
}

CArc::CArc(unsigned int uiVertexIndexParam) : uiVertexIndex(uiVertexIndexParam)
{
}

CArc::~CArc()
{
}

void CArc::operator=(CArc & oARCarcParam){
	uiVertexIndex = oARCarcParam.uiVertexIndex;
}