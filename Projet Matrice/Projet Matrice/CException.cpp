#include <cstdlib>
#include <iostream>

#include "CException.h"

CException::CException()
{
	uiEXID = 0;
	pcEXmessage = nullptr;
}

CException::CException(CException const&oEXexception)
{
	uiEXID = oEXexception.uiEXID;
	pcEXmessage = _strdup(oEXexception.pcEXmessage);
}

CException::CException(unsigned int uiEXIDParam)
{
	uiEXID = uiEXIDParam;
	pcEXmessage = nullptr;
}

CException::CException(unsigned int uiEXIDParam, char * pcEXmessageParam)
{
	uiEXID = uiEXIDParam;
	EXsetExceptionMessage(pcEXmessageParam);
}

CException::~CException()
{
	free(pcEXmessage);
}

void CException::operator=(CException &oEXexception)
{
	uiEXID = oEXexception.uiEXID;
	free(pcEXmessage);
	pcEXmessage = _strdup(oEXexception.pcEXmessage);
}

void CException::EXsetExceptionMessage(char * pcEXmessageParam)
{
	if(pcEXmessage == nullptr)
		free(pcEXmessage);
	pcEXmessage = _strdup(pcEXmessageParam);
}
