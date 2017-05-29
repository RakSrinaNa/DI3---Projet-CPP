#include "CGraphToolboxUnit.h"
#include "../CGraph.h"
#include "../CGraphToolbox.h"
#include "../CException.h"
#include "CUnit.h"

void CGraphToolboxUnit::GRTUnitTests()
{
	CGraph oGRAgraph1 = CGraph((char *) "g3.txt");
	CGraphToolbox oGRTtoolbox = CGraphToolbox(oGRAgraph1);
	
	oGRTtoolbox.GRTtransformNonOriented();
	if(!oGRTtoolbox.GRTgetGraph().GRAhasArc(1, 2) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(2, 1) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(2, 3) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(3, 2) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(3, 4) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(4, 3) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(4, 5) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(5, 4) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(5, 1) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(1, 5))
		CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 1");
	
	CGraph oGRAgraph2 = CGraph((char *) "g4.txt");
	CGraphToolbox oGRTtoolbox2 = CGraphToolbox(oGRAgraph2);
	oGRTtoolbox2.GRTtransformNonOriented();
	
	if(!oGRTtoolbox2.GRThasPath(7, 4))
		CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 2");
	
	if(!oGRTtoolbox2.GRThasPath(1, 8) || !oGRTtoolbox2.GRThasPath(8, 1))
		CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 3");
	
	CGraphToolbox oGRTtoolbox3 = CGraphToolbox(oGRAgraph2);
	if(!oGRTtoolbox3.GRThasPath(1, 8) || oGRTtoolbox3.GRThasPath(8, 1))
		CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 4");
	
	try
	{
		oGRTtoolbox3.GRThasPath(10, 8);
		CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 4.1");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 4.2");
	}
	
	try
	{
		oGRTtoolbox3.GRThasPath(1, 80);
		CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 5.1");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 5.2");
	}
	
	if(!oGRTtoolbox.GRTisConnex() || !oGRTtoolbox2.GRTisConnex() || !oGRTtoolbox3.GRTisConnex())
		CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 6");
	
	CGraph oGRAgraph3 = CGraph((char *) "g5.txt");
	CGraphToolbox oGRTtoolbox4 = CGraphToolbox(oGRAgraph3);
	if(oGRTtoolbox4.GRTisConnex())
		CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 7");
	
	if(oGRTtoolbox3.GRTisConnex())
		CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 8");
	
	oGRTtoolbox3.GRTtransformNonOriented();
	if(!oGRTtoolbox3.GRTisConnex())
		CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 9");
}
