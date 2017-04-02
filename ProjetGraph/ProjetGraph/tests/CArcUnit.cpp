#include "CArcUnit.h"
#include "../CException.h"
#include "../CArc.h"
#include "CUnit.h"

void CArcUnit::ARCUnitTests()
{
	/* Test empty constructor, shouldn't be used */
	try
	{
		CArc();
		CUnit::UNITassertError("ASSERT CARC 1");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_ARC_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CARC 2");
	}
	
	/* Test confort constructor & index getter */
	CArc oARCarc1 = CArc(1);
	CArc oARCarc2 = CArc(15);
	
	if(oARCarc1.ARCgetVertexIndex() != 1 || oARCarc2.ARCgetVertexIndex() != 15)
		CUnit::UNITassertError("ASSERT CARC 3");
	
	/* Test index setter */
	oARCarc1.ARCsetVertexIndex(10);
	oARCarc2.ARCsetVertexIndex(150);
	if(oARCarc1.ARCgetVertexIndex() != 10 || oARCarc2.ARCgetVertexIndex() != 150)
		CUnit::UNITassertError("ASSERT CARC 4");
}
