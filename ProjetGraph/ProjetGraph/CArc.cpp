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
CArc::CArc(CArc const &oARCarcParam) : uiVertexIndex(oARCarcParam.uiVertexIndex), oHMPproperties(oARCarcParam.oHMPproperties)
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
CArc::CArc(unsigned int uiVertexIndexParam) : uiVertexIndex(uiVertexIndexParam), oHMPproperties()
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
	oHMPproperties = oARCarcParam.oHMPproperties;
	return *this;
}

/**************************************************************
 * Add a property to the arc.
 **************************************************************
 *
 * Input:
 *      pcKey:  The key associated with the value.
 *      dValue: The value to set for the key.
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `KEY_ALREADY_DEFINED_EXCEPTION` if the key already exists.
 */
void CArc::ARCaddProperty(char * pcKey, double dValue)
{
	oHMPproperties.CHMPaddValue(pcKey, dValue);
}

/**************************************************************
 * Modify a property of the arc.
 **************************************************************
 *
 * Input:
 *      pcKey:  The key associated with the value.
 *      dValue: The new value to set for the key.
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `KEY_NOT_FOUND_EXCEPTION` if the key doesn't exist.
 */
void CArc::ARCmodifyProperty(char * pcKey, double dValue)
{
	oHMPproperties.CHMPmodifyValue(pcKey, dValue);
}

/**************************************************************
 * Get the value of a property of the arc.
 **************************************************************
 *
 * Input:
 *      pcKey:  The key associated with the value.
 * Output:
 *      double: The value of the key.
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `KEY_NOT_FOUND_EXCEPTION` if the key doesn't exist.
 */
double CArc::ARCgetProperty(char * pcKey) const
{
	return oHMPproperties.CHMPgetValue(pcKey);
}

/**************************************************************
 * Delete a property from the arc.
 **************************************************************
 *
 * Input:
 *      pcKey:  The key associated with the value.
 * Output:
 * PreCond:
 * PostCond:
 */
void CArc::ARCdeleteProperty(char * pcKey)
{
	oHMPproperties.CHMPdeleteValue(pcKey);
}
