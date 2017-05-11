#include <cstdlib>
#include "CGraphToolbox.h"
#include "CException.h"

/**************************************************************
 * Default constructor. Do not use. Prefer CGraphToolbox(CGraph *).
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `NO_GRAPH_EXCEPTION`.
 */
CGraphToolbox::CGraphToolbox()
{
	throw CException(NO_GRAPH_EXCEPTION, (char *) "No graph were given.");
}

/**************************************************************
 * Confort constructor taking a graph.
 **************************************************************
 *
 * Input:
 *      poGRAgraph: The graph we'll use. A copy will be made.
 * Output:
 * PreCond:
 * PostCond:
 */
CGraphToolbox::CGraphToolbox(CGraph const &graph)
{
	oGRAgraph = graph;
}

/**************************************************************
 * Destructor.
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 */
CGraphToolbox::~CGraphToolbox()
{
}

/**************************************************************
 * Get the current graph.
 **************************************************************
 *
 * Input:
 * Output:
 *      CGraph: The current graph.
 * PreCond:
 * PostCond:
 */
CGraph const &CGraphToolbox::GRTgetGraph() const
{
	return oGRAgraph;
}

/**************************************************************
 * Transform the current graph into a non oriented one.
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 */
void CGraphToolbox::GRTtransformNonOriented()
{
	for(unsigned int uiVertexIndex1 = 1; uiVertexIndex1 < oGRAgraph.uiBiggestVertex; uiVertexIndex1++)
        if(oGRAgraph.GRAhasVertex(uiVertexIndex1))
            for(unsigned int uiVertexIndex2 = uiVertexIndex1 +1; uiVertexIndex2 < oGRAgraph.uiBiggestVertex; uiVertexIndex2++)
                if(oGRAgraph.GRAhasArc(uiVertexIndex1, uiVertexIndex2))
                {
                    try
                    {
                        oGRAgraph.GRAaddArc(uiVertexIndex2, uiVertexIndex1);
                    }
                    catch(CException const &oEXexception)
                    {
                    }
                }
}

/**************************************************************
 * Tell if the graph is connected.
 **************************************************************
 *
 * Input:
 * Output:
 *      bool: True if the graph is connected, false else.
 * PreCond:
 * PostCond:
 */
bool CGraphToolbox::GRTisConnex()
{
	GRTtransformNonOriented();
	unsigned int * puiVertexIndices = oGRAgraph.GRAgetVertexIndices();
	for(unsigned int uiVertexStartIndex = 0; uiVertexStartIndex < oGRAgraph.GRAgetVertexCount(); uiVertexStartIndex++)
	{
		for(unsigned int uiVertexEndIndex = uiVertexStartIndex + 1; uiVertexEndIndex < oGRAgraph.GRAgetVertexCount(); uiVertexEndIndex++)
		{
			if(!GRThasPath(puiVertexIndices[uiVertexStartIndex], puiVertexIndices[uiVertexEndIndex]))
			{
				free(puiVertexIndices);
				return false;
			}
		}
	}
	free(puiVertexIndices);
	return true;
}

/**************************************************************
 * Tell if a path between two vertices exists.
 **************************************************************
 *
 * Input:
 *      uiStartIndex:           The starting vertex.
 *      uiEndIndex:             The ending vertex.
 *      puiAlreadyExplored :    The table of the already explored vertices.
 *      puiSize :               The size of the previous table.
 * Output:
 *      bool:           True if a path exists between the two, false else.
 * PreCond:
 * PostCond:
 */
bool CGraphToolbox::GRThasPath(unsigned int uiStartIndex, unsigned int uiEndIndex, unsigned int * puiAlreadyExplored, unsigned int uiSize)
{
	return false; //TODO
}
