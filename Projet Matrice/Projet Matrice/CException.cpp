#include <cstdlib>
#include <iostream>

#include "CException.h"

CException::CException()
{
	uiEXID = 0;
	pcEXMessage = nullptr;
}

CException::CException(CException const&oEXexception)
{
	uiEXID = oEXexception.uiEXID;
	pcEXMessage = strdup(oEXexception.pcEXMessage);
}

CException::CException(unsigned int uiEXIDParam)
{
	uiEXID = uiEXIDParam;
	pcEXMessage = nullptr;
}

CException::CException(unsigned int uiEXIDParam, char * pcEXMessageParam)
{
	uiEXID = uiEXIDParam;
	EXecrireExceptionMessage(pcEXMessageParam);
}

CException::~CException()
{
	free(pcEXMessage);
}

void CException::operator=(CException &oEXexception)
{
	uiEXID = oEXexception.uiEXID;
	free(pcEXMessage);
	pcEXMessage = strdup(oEXexception.pcEXMessage);
}

void CException::EXecrireExceptionMessage(char * pcEXMessageParam)
{
	if(pcEXMessage == nullptr)
		free(pcEXMessage);
	pcEXMessage = strdup(pcEXMessageParam);
}
