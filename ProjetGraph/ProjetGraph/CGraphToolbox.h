#ifndef PROJETGRAPH_CGRAPHTOOLBOX_H
#define PROJETGRAPH_CGRAPHTOOLBOX_H

#include "CGraph.h"

#define NO_GRAPH_EXCEPTION 9876

class CGraphToolbox
{
private:
	CGraph oGRAgraph;

public:
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
	CGraphToolbox();
	
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
	explicit CGraphToolbox(CGraph const &graph);
	
	/**************************************************************
	 * Destructor.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	~CGraphToolbox();
	
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
	CGraph const& GRTgetGraph() const;
	
	/**************************************************************
	 * Transform the current graph into a non oriented one.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void GRTtransformNonOriented();
	
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
	bool GRTisConnex();
	
	/**************************************************************
	 * Tell if a path between two vertices exists.
	 **************************************************************
	 *
	 * Input:
	 *      uiStartIndex:   The starting vertex.
	 *      uiEndIndex:     The ending vertex.
	 * Output:
	 *      bool:           True if a path exists between the two, false else.
	 * PreCond:
	 * PostCond:
	 */
	bool GRThasPath(unsigned int uiStartIndex, unsigned int uiEndIndex);
};

#endif
