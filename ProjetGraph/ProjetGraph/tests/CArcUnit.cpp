#include "CArcUnit.h"
#include "../CException.h"
#include "../CArc.h"
#include "../utils.h"
#include "CUnit.h"

void CArcUnit::ARCUnitTests()
{
	try
	{
		CArc();
		CUnit::UNITassertError("ASSERT CARC 1");
	}
	catch(CException const& oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_ARC_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CARC 2");
	}
	
	CArc arc1 = CArc(1);
	CArc arc2 = CArc(15);
	
	if(arc1.ARCgetVertexIndex() != 1 || arc2.ARCgetVertexIndex() != 15)
		CUnit::UNITassertError("ASSERT CARC 3");
	
	arc1.ARCsetVertexIndex(10);
	arc2.ARCsetVertexIndex(150);
	if(arc1.ARCgetVertexIndex() != 10 || arc2.ARCgetVertexIndex() != 150)
		CUnit::UNITassertError("ASSERT CARC 4");
}
