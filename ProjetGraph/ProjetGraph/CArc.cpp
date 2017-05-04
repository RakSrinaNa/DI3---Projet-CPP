#include "CArc.h"
#include "CException.h"

/**************************************************************
 * Default constructor. Do not use. Prefer CArc(unsigned int).
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `MISSING_ARC_INDEX_EXCEPTION`
 */
CArc::CArc()
{
	throw CException(MISSING_ARC_INDEX_EXCEPTION, (char *) "Use the constructor : CArc(unsigned int)");
}

/**************************************************************
 * Copy constructor.
 **************************************************************
 *
 * Input:
 *      oARCarcParam: The arc to copy.
 * Output:
 * PreCond:
 * PostCond:
 */
CArc::CArc(CArc const &oARCarcParam) : uiVertexIndex(oARCarcParam.uiVertexIndex)
{
}

/**************************************************************
 * Parameterized constructor.
 **************************************************************
 *
 * Input:
 *     uiVertexIndexParam: The ID of the target vertex of our arc.
 * Output:
 * PreCond:
 * PostCond:
 */
CArc::CArc(unsigned int uiVertexIndexParam) : uiVertexIndex(uiVertexIndexParam)
{
}

/**************************************************************
 * Destructor
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 */
CArc::~CArc()
{
}

/**************************************************************
 * Define the = operator.
 **************************************************************
 *
 * Input:
 *      oARCarcParam:   The arc to copy.
 * Output:
 *      Carc&:          This arc modified.
 * PreCond:
 * PostCond:
 */
CArc &CArc::operator=(CArc const &oARCarcParam)
{
	uiVertexIndex = oARCarcParam.uiVertexIndex;
	return *this;
}