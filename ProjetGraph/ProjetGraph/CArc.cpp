#include "CArc.h"
#include "CException.h"
#include "utils.h"

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
