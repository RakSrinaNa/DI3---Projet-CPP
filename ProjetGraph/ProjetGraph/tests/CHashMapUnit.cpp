#include "CHashMapUnit.h"
#include "../CHashMap.h"
#include "../CException.h"
#include "CUnit.h"

void CHashMapUnit::HMPUnitTest()
{
	CHashMap oHMPmap;
	
	try
	{
		oHMPmap.CHMPgetValue((char *) "LOL");
		CUnit::UNITassertError("ASSERT CHASHMAP 1.1");
	}
	catch(CException &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != KEY_NOT_FOUND_EXCEPTION)
			CUnit::UNITassertError("ASSERT CHASHMAP 1.2");
	}
	
	try
	{
		oHMPmap.CHMPmodifyValue((char *) "LOL", 4);
		CUnit::UNITassertError("ASSERT CHASHMAP 2.1");
	}
	catch(CException &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != KEY_NOT_FOUND_EXCEPTION)
			CUnit::UNITassertError("ASSERT CHASHMAP 2.2");
	}
	
	oHMPmap.CHMPaddValue((char *) "LOL", 5);
	if(oHMPmap.CHMPgetValue((char *) "LOL") != 5)
		CUnit::UNITassertError("ASSERT CHASHMAP 3");
	
	try
	{
		oHMPmap.CHMPaddValue((char *) "LOL", 7);
		CUnit::UNITassertError("ASSERT CHASHMAP 4.1");
	}
	catch(CException &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != KEY_ALREADY_DEFINED_EXCEPTION)
			CUnit::UNITassertError("ASSERT CHASHMAP 4.2");
	}
	
	oHMPmap.CHMPaddValue((char *) "LOOL", 3);
	if(oHMPmap.CHMPgetValue((char *) "LOOL") != 3)
		CUnit::UNITassertError("ASSERT CHASHMAP 5");
	
	oHMPmap.CHMPdeleteValue((char *) "LOOL");
	try
	{
		oHMPmap.CHMPgetValue((char *) "LOOL");
		CUnit::UNITassertError("ASSERT CHASHMAP 6.1");
	}
	catch(CException &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != KEY_NOT_FOUND_EXCEPTION)
			CUnit::UNITassertError("ASSERT CHASHMAP 6.2");
	}
}
