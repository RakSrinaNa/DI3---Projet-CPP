#include <cstdlib>
#include <iostream>

#include "CException.h"
#include "utils.h"

/**************************************************************
 * Default constructor.
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 */
CException::CException()
{
	uiEXID = 0;
	pcEXmessage = nullptr;
}

/**************************************************************
 * Copy constructor.
 **************************************************************
 *
 * Input:
 *      oEXexception: The exception to copy.
 * Output:
 * PreCond:
 * PostCond:
 */
CException::CException(CException const &oEXexception)
{
	uiEXID = oEXexception.uiEXID;
	pcEXmessage = STRDUP(oEXexception.pcEXmessage);
}

/**************************************************************
 * Parameterized constructor with exception ID.
 **************************************************************
 *
 * Input:
 *      uiEXIDParam: The exception ID.
 * Output:
 * PreCond:
 * PostCond:
 */
CException::CException(unsigned int uiEXIDParam)
{
	uiEXID = uiEXIDParam;
	pcEXmessage = nullptr;
}

/**************************************************************
 * Parameterized constructor with exception ID & error message.
 **************************************************************
 *
 * Input:
 *      uiEXIDParam:        The exception ID.
 *      pcEXmessageParam:   The error message.
 * Output:
 * PreCond:
 * PostCond:
 */
CException::CException(unsigned int uiEXIDParam, char * pcEXmessageParam)
{
	uiEXID = uiEXIDParam;
	pcEXmessage = STRDUP(pcEXmessageParam);
}

/**************************************************************
 * Destructor.
 **************************************************************
 *
 * Inout:
 * Output:
 * PreCond:
 * PostCond:
 */
CException::~CException()
{
	free(pcEXmessage);
}

/**************************************************************
 * Set the error message.
 **************************************************************
 *
 * Input:
 *      pcEXmessageParam: The error message. A copy of it will be done.
 * Output:
 * PreCond:
 * PostCond:
 */
void CException::EXsetExceptionMessage(char * pcEXmessageParam)
{
	if(pcEXmessage != nullptr)
		free(pcEXmessage);
	pcEXmessage = STRDUP(pcEXmessageParam);
}

/**************************************************************
 * Define the = operator.
 **************************************************************
 *
 * Input:
 *      oEXexception:   The CException to copy.
 * Output:
 *      CException&:    This exception modified.
 * PreCond:
 * PostCond:
 */
CException &CException::operator=(CException const &oEXexception)
{
	uiEXID = oEXexception.uiEXID;
	free(pcEXmessage);
	pcEXmessage = STRDUP(oEXexception.pcEXmessage);
	
	return *this;
}
