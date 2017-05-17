#include <cstdlib>
#include "CGraphToolbox.h"
#include "CException.h"
#include "utils.h"

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
	unsigned int * puiVertexIndices = oGRAgraph.GRAgetVertexIndices();
	for(unsigned int uiVertexIndex1 = 0; uiVertexIndex1 < oGRAgraph.GRAgetVertexCount(); uiVertexIndex1++)
		for(unsigned int uiVertexIndex2 = 0; uiVertexIndex2 < oGRAgraph.GRAgetVertexCount(); uiVertexIndex2++)
			if(oGRAgraph.GRAhasArc(puiVertexIndices[uiVertexIndex1], puiVertexIndices[uiVertexIndex2]))
			{
				try
				{
					oGRAgraph.GRAaddArc(puiVertexIndices[uiVertexIndex2], puiVertexIndices[uiVertexIndex1]);
				}
				catch(CException const &oEXexception)
				{
					if(oEXexception.EXgetExceptionID() != DUPLICATE_ARC_EXCEPTION)
						printf("CException: %s\n", oEXexception.EXgetExceptionMessage());
				}
			}
	free(puiVertexIndices);
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
 * Output:
 *      bool:                   True if a path exists between the two, false else.
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if the source or destination doesn't exist.
 */
bool CGraphToolbox::GRThasPath(unsigned int uiStartIndex, unsigned int uiEndIndex)
{
	unsigned int * puiAlreadyExplored;
	MMALLOC(puiAlreadyExplored, unsigned int, 1, "GRTisConnex");
	puiAlreadyExplored[0] = 0;
	bool result;
	try
	{
		result = GRThasPath(uiStartIndex, uiEndIndex, &puiAlreadyExplored);
	}
	catch(CException const& oEXexception)
	{
		free(puiAlreadyExplored);
		throw oEXexception;
	}
	free(puiAlreadyExplored);
	return result;
}

/**************************************************************
 * Tell if a path between two vertices exists.
 **************************************************************
 *
 * Input:
 *      uiStartIndex:           The starting vertex.
 *      uiEndIndex:             The ending vertex.
 *      puiAlreadyExplored:     The table of the already explored vertices.
 * Output:
 *      bool:                   True if a path exists between the two, false else.
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if the source or destination doesn't exist. //TODO Victor
 */
bool CGraphToolbox::GRThasPath(unsigned int uiStartIndex, unsigned int uiEndIndex, unsigned int ** puiAlreadyExplored)
{
	unsigned int * puiReachableIndices;
	unsigned int uiReachableSize = oGRAgraph.GRAgetReachableIndices(uiStartIndex, &puiReachableIndices);

	(*puiAlreadyExplored)[0]++;
	RREALLOC(*puiAlreadyExplored, unsigned int, (*puiAlreadyExplored)[0] + 1, "GRThasPath");
	(*puiAlreadyExplored)[(*puiAlreadyExplored)[0]] = uiStartIndex;

	for(unsigned int uiIndex = 0; uiIndex < uiReachableSize; uiIndex++)
	{
		//If the end is directly reachable
		if(puiReachableIndices[uiIndex] == uiEndIndex)
		{
			free(puiReachableIndices);
			return true;
		}

		//Verify if the next vertex hasn't already been explored
		bool bIsExplored = false;
		for(unsigned int uiIndex2 = 0; uiIndex2 < (*puiAlreadyExplored)[0]; uiIndex2++)
			if(puiReachableIndices[uiIndex] == (*puiAlreadyExplored)[uiIndex2 + 1])
			{
				bIsExplored = true;
				break;
			}
		if(bIsExplored)
			continue;

		//In any other case, explore the next vertex
		bool bHasPath = GRThasPath(puiReachableIndices[uiIndex], uiEndIndex, puiAlreadyExplored);
		if(bHasPath)
		{
			free(puiReachableIndices);
			return true;
		}
	}
	free(puiReachableIndices);
	return false;
}
