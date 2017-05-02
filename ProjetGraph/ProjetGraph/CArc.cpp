#include "CArc.h"
#include "CException.h"

CArc::CArc()
{
	throw CException(MISSING_ARC_INDEX_EXCEPTION, (char *) "Use the constructor : CArc(unsigned int)");
}

CArc::CArc(CArc const& oARCarcParam) : uiVertexIndex(oARCarcParam.uiVertexIndex)
{
}

CArc::CArc(unsigned int uiVertexIndexParam) : uiVertexIndex(uiVertexIndexParam)
{
}

CArc::~CArc()
{
}

CArc& CArc::operator=(CArc const& oARCarcParam){
	uiVertexIndex = oARCarcParam.uiVertexIndex;
	return *this;
}