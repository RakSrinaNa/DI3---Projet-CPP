#ifndef TP1_CEXCEPTION_H
#define TP1_CEXCEPTION_H

/**************************************************************
 * Class representing an exception.
 **************************************************************/
class CException
{
private:
	unsigned int uiEXID;
	char * pcEXmessage;

public:
	/**************************************************************
	 * Default constructor.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	CException();
	
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
	CException(CException const &oEXexception);
	
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
	CException(unsigned int uiEXIDParam);
	
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
	CException(unsigned int uiEXIDParam, char * pcEXmessageParam);
	
	/**************************************************************
	 * Destructor.
	 **************************************************************
	 *
	 * Inout:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	~CException();
	
	/**************************************************************
	 * Get the exception ID.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 *      unsigned int: The exception ID.
	 * PreCond:
	 * PostCond:
	 */
	unsigned int EXgetExceptionID() const
	{
		return uiEXID;
	}
	
	/**************************************************************
	 * Get the error message.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 *      char *: The error message.
	 * PreCond:
	 * PostCond:
	 */
	char * EXgetExceptionMessage() const
	{
		return pcEXmessage;
	}
	
	/**************************************************************
	 * Set the exception ID.
	 **************************************************************
	 *
	 * Input:
	 *       uiEXIDParam: The exception ID.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void EXsetExceptionID(unsigned int uiEXIDParam)
	{
		uiEXID = uiEXIDParam;
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
	void EXsetExceptionMessage(char * pcEXmessageParam);
	
	/**************************************************************
	 * Define the = operator.
	 **************************************************************
	 *
	 * Input:
	 *      oEXexception: The CException to copy.
	 * Output:
	 *      CException&:    This exception modified.
	 * PreCond:
	 * PostCond:
	 */
	CException &operator=(CException const &oEXexception);
};

#endif
