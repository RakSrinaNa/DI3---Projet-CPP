#include "CGraphToolboxUnit.h"
#include "../CGraph.h"
#include "../CGraphToolbox.h"
#include "CUnit.h"

void CGraphToolboxUnit::GRTUnitTests()
{
	CGraph oGRAgraph1 = CGraph((char *) "g3.txt");
	CGraphToolbox oGRTtoolbox = CGraphToolbox(oGRAgraph1);
	
	oGRTtoolbox.GRTtransformNonOriented();
	if(!oGRTtoolbox.GRTgetGraph().GRAhasArc(1, 2) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(2, 1) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(2, 3) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(3, 2) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(3, 4) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(4, 3) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(4, 5) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(5, 4) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(5, 1) || !oGRTtoolbox.GRTgetGraph().GRAhasArc(1, 5))
		CUnit::UNITassertError("ASSERT CGRAPHTOOLBOX 1");
}
