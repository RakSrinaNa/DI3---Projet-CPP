#ifndef CVERTEX
#define CVERTEX

#include "CArc.h"

#define MISSING_VERTEX_INDEX_EXCEPTION 8792
#define DUPLICATE_ARC_EXCEPTION 8794
#define DUPLICATE_VERTEX_EXCEPTION 8794
#define BAD_INDEX_VERTEX_EXCEPTION 8795

class CVertex
{

protected:
	unsigned int uiVertexIndex;
	unsigned int uiArcInCount;
	unsigned int uiArcOutCount;
	CArc ** poARCinList;
	CArc ** poARCoutList;

public:
	/**************************************************************
	 * Default constructor. Do not use. Prefer CVertex(unsigned int).
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION`.
	 */
	CVertex();
	
	/**************************************************************
	 * Copy constructor.
	 **************************************************************
	 *
	 * Input:
	 *      oVERvertexParam: The vertex to copy.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	CVertex(CVertex const &oVERvertexParam);
	
	/**************************************************************
	 * Parameterized constructor with the vertex ID.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndexParam: The ID of the vertex.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	explicit CVertex(unsigned int uiVertexIndexParam);
	
	/**************************************************************
	 * Destructor.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	~CVertex();
	
	/**************************************************************
	 * Return the number of incoming arcs.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 *      unsigned int: The number of incoming arcs.
	 * PreCond:
	 * PostCond:
	 */
	unsigned int VERgetArcInCount() const
	{
		return uiArcInCount;
	}
	
	/**************************************************************
	 * Return the number of outgoing arcs.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 *      unsigned int: The number of outgoing arcs.
	 * PreCond:
	 * PostCond:
	 */
	unsigned int VERgetArcOutCount() const
	{
		return uiArcOutCount;
	}
	
	/**************************************************************
	 * Add an incoming arc to the vertex.
	 **************************************************************
	 *
	 * Input:
	 *      uiFromVertexIndex: The ID of the vertex pointing on the current vertex.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `DUPLICATE_ARC_EXCEPTION` if the arc already exists.
	 */
	void VERaddArcIn(unsigned int uiFromVertexIndex);
	
	/**************************************************************
	 * Remove an incoming arc to the node.
	 **************************************************************
	 *
	 * Input:
	 *      uiFromVertexIndex: The ID of the vertex pointing on the current vertex.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void VERremoveArcIn(unsigned int uiFromVertexIndex);
	
	/**************************************************************
	 * Add an outgoing arc to the vertex.
	 **************************************************************
	 *
	 * Input:
	 *      uiToVertexIndex: The ID of the vertex the current vertex is pointing to.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `DUPLICATE_ARC_EXCEPTION` if the arc already exists.
	 */
	void VERaddArcOut(unsigned int uiToVertexIndex);
	
	/**************************************************************
	 * Remove an outgoing arc to the node.
	 **************************************************************
	 *
	 * Input:
	 *      uiToVertexIndex: The ID of the vertex the current vertex is pointing to.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void VERremoveArcOut(unsigned int uiToVertexIndex);
	
	/**************************************************************
	 * Modify an incoming arc to the vertex.
	 **************************************************************
	 *
	 * Input:
	 *      uiLastFromVertexIndex:  The ID of the vertex that is pointing to the current vertex.
	 *      uiNewFromVertexIndex:   The ID of the new vertex that will point to the current vertex.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      If uiLastFromVertexIndex doesn't exists, nothing is changed.
	 */
	void VERmodifyArcIn(unsigned int uiLastFromVertexIndex, unsigned int uiNewFromVertexIndex);
	
	/**************************************************************
	 * Modify an outgoing arc to the vertex.
	 **************************************************************
	 *
	 * Input:
	 *      uiLastToVertexIndex:  The ID of the vertex that is pointed by the current vertex.
	 *      uiNewToVertexIndex:   The ID of the new vertex that will be pointed by the current vertex.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      If uiLastToVertexIndex doesn't exists, nothing is changed.
	 */
	void VERmodifyArcOut(unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex);
	
	/**************************************************************
	 * Return the ID of the current vertex.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 *      unsigned id: The current vertex index..
	 * PreCond:
	 * PostCond:
	 */
	unsigned int VERgetVertexIndex() const
	{
		return uiVertexIndex;
	};
	
	/**************************************************************
	 * Verify if the node has an incoming arc from a specific arc.
	 **************************************************************
	 *
	 * Input:
	 *      uiFromVertexIndex:  The ID of the source vertex.
	 * Output:
	 *      bool:               True if the arc exists, false else.
	 * PreCond:
	 * PostCond:
	 */
	bool VERhasIndexIn(unsigned int uiFromVertexIndex) const;
	
	/**************************************************************
	 * Verify if the node has an outgoing arc from a specific arc.
	 **************************************************************
	 *
	 * Input:
	 *      uiToVertexIndex:  The ID of the destination vertex.
	 * Output:
	 *      bool:               True if the arc exists, false else.
	 * PreCond:
	 * PostCond:
	 */
	bool VERhasIndexOut(unsigned int uiToVertexIndex) const;
	
	/**************************************************************
	 * Display the list of the incoming arcs.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void VERdisplayArcIn() const;
	
	/**************************************************************
	 * Display the list of the outgoing arcs.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void VERdisplayArcOut() const;
	
	/**************************************************************
	 * Invert the orientation of every arcs.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void VERinvert();
	
	/**************************************************************
	 * Define the operator =.
	 **************************************************************
	 *
	 * Input:
	 *      oVERvertexParam: The vertex to copy.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	CVertex &operator=(CVertex const &oVERvertexParam);
};

#endif