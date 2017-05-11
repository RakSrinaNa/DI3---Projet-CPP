#include <cstring>
#include "CGraphParserUnit.h"
#include "../CGraphParser.h"
#include "CUnit.h"
#include "../CException.h"
#include "../utils.h"

void CGraphParserUnit::PGRAUnitTests()
{
	char * pcLine = (char *) "AAA=BBB";
	char * pcValue = CGraphParser::PGRAgetLineValue(pcLine);
	if(pcValue != (pcLine + 4) || strcmp("BBB", pcValue) != 0)
		CUnit::UNITassertError("CGraphParser 1");
	
	try
	{
		CGraphParser::PGRAgetLineValue((char *) "AAABBB");
		CUnit::UNITassertError("CGraphParser 2.1");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MALFORMATTED_FILE_EXCEPTION)
			CUnit::UNITassertError("CGraphParser 2.2");
	}
	
	char * pcKey = CGraphParser::PGRAgetLineKey(pcLine, pcValue - 1);
	if(strcmp("AAA", pcKey) != 0)
		CUnit::UNITassertError("CGraphParser 3");
	free(pcKey);
	
	char * pcDelimTestsOrigin = STRDUP("AAA:BBB=CCC");
	
	char * pcDelimTests = pcDelimTestsOrigin;
	char ** pcHeadSplit = &pcDelimTests;
	
	char * pcAString = CGraphParser::PGRAstrsep(pcHeadSplit, (char *) ":=");
	if(pcAString != pcDelimTestsOrigin || strcmp(pcAString, "AAA") != 0 || *pcHeadSplit != (pcDelimTestsOrigin + 4))
		CUnit::UNITassertError("CGraphParser 4");
	
	char * pcBString = CGraphParser::PGRAstrsep(pcHeadSplit, (char *) ":=");
	if(pcBString != (pcDelimTestsOrigin + 4) || strcmp(pcBString, "BBB") != 0 || *pcHeadSplit != (pcDelimTestsOrigin + 8))
		CUnit::UNITassertError("CGraphParser 5");
	
	char * pcCString = CGraphParser::PGRAstrsep(pcHeadSplit, (char *) ":=");
	if(pcCString != (pcDelimTestsOrigin + 8) || strcmp(pcCString, "CCC") != 0 || *pcHeadSplit != nullptr)
		CUnit::UNITassertError("CGraphParser 6");
	
	free(pcDelimTestsOrigin);
	pcDelimTestsOrigin = STRDUP("AAA:BBB=CCC");
	
	unsigned int uiPartsCount = 0;
	char ** pcParts = CGraphParser::PGRAsplit((char *) ":=", &uiPartsCount, pcDelimTestsOrigin);
	if(uiPartsCount != 3 || strcmp("AAA", pcParts[0]) != 0 || strcmp("BBB", pcParts[1]) != 0 || strcmp("CCC", pcParts[2]) != 0)
		CUnit::UNITassertError("CGraphParser 7");
	
	free(pcDelimTestsOrigin);
	
	char * pcTrimTest = STRDUP("  \t AAA BBB CCC \t\n\t \r ");
	char * pcTrimmed = CGraphParser::PGRAtrim(pcTrimTest);
	if(pcTrimmed != (pcTrimTest + 4) || strcmp("AAA BBB CCC", pcTrimmed) != 0)
		CUnit::UNITassertError("CGraphParser 8");
}
