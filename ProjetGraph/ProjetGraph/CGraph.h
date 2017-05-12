#ifndef CGRAPH
#define CGRAPH

#include "CVertex.h"
#include "CArc.h"

class CGraph
{

protected:
	unsigned int uiVertexCount;
	CVertex ** poVERvertexList;
	unsigned int uiBiggestVertex;

public:
	/**************************************************************
	 * Default constructor.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      The graph have no vertices nor arcs.
	 */
	CGraph();
	
	/**************************************************************
	 * Parameterized constructor with a file.
	 **************************************************************
	 *
	 * Input:
	 *      pcFilename: The path to the file to read.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `IO_FILE_EXCEPTION` if a reading error happened.
	 *      Throws a CException with the ID `MALFORMATTED_FILE_EXCEPTION` if the file is malformatted.
	 */
	explicit CGraph(char * pcFilename);
	
	/**************************************************************
	 * Destructor.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Delete the graph with its vertices and arcs.
	 */
	~CGraph();
	
	/**************************************************************
	 * Add a vertex to the graph.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndex: The ID of the vertex to add.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `DUPLICATE_VERTEX_EXCEPTION` if the vertex already exists.
	 *      Throws a CException with the ID `BAD_INDEX_VERTEX_EXCEPTION` if the ID of the vertex is less than 1.
	 */
	void GRAaddVertex(unsigned int uiVertexIndex);
	
	/**************************************************************
	 * Remove a vertex from the graph.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndex: The ID of the vertex to remove.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void GRAremoveVertex(unsigned int uiVertexIndex);
	
	/**************************************************************
	 * Verify if a vertex is in the graph.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndex:  The ID of the vertex to find.
	 * Output:
	 *      bool:           True if the vertex exists, false else.
	 * PreCond:
	 * PostCond:
	 */
	bool GRAhasVertex(unsigned int uiVertexIndex) const;
	
	/**************************************************************
	 * Add an arc to the graph.
	 **************************************************************
	 *
	 * Input:
	 *      uiFromVertexIndex:  The ID of the starting vertex.
	 *      uiToVertexIndex:    The ID of the ending vertex.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if one of the vertices doesn't exist.
	 *      Throws a CException with the ID `DUPLICATE_ARC_EXCEPTION` if the arc already exists.
	 */
	void GRAaddArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex);
	
	/**************************************************************
	 * Remove an arc from the graph.
	 **************************************************************
	 *
	 * Input:
	 *      uiFromVertexIndex:  The ID of the starting vertex.
	 *      uiToVertexIndex:    The ID of the ending vertex.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if one of the vertices doesn't exist.
	 */
	void GRAremoveArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex);
	
	/**************************************************************
	 * Modify the ending vertex of an existing arc.
	 **************************************************************
	 *
	 * Input:
	 *      uiFromVertexIndex:  The ID of the starting vertex.
	 *      uiLastToVertexIndex:The ID of the old ending vertex.
	 *      uiNewToVertexIndex: The ID of the new ending vertex.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if one of the vertices doesn't exist.
	 *      Throws a CException with the ID `MISSING_ARC_INDEX_EXCEPTION` if the arc doesn't exists.
	 *      Throws a CException with the ID `DUPLICATE_ARC_EXCEPTION` if the new arc already exists.
	 */
	void GRAmodifyArc(unsigned int uiFromVertexIndex, unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex);
	
	/**************************************************************
	 * Verify if the arc contains an arc.
	 **************************************************************
	 *
	 * Input:
	 *      uiFromVertexIndex:  The ID of the starting vertex.
	 *      uiToVertexIndex:    The ID of the ending vertex.
	 * Output:
	 *      bool:               True if the arc exists, false else.
	 * PreCond:
	 * PostCond:
	 */
	bool GRAhasArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex) const;
	
	/**************************************************************
	 * Add a link (arcs in the two directions) between two vertices.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndex1: The ID of the first vertex.
	 *      uiVertexIndex2: The ID of the second vertex.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if one of the two vertices doesn't exist.
	 */
	void GRAaddLink(unsigned int uiVertexIndex1, unsigned int uiVertexIndex2);
	
	/**************************************************************
	 * Invert the graph (every arc is inverted).
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void GRAinvert();
	
	/**************************************************************
	 * Resets the graph.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void GRAclear();
	
	/**************************************************************
	 * Display the graph in the standard output.
	 **************************************************************
	 *
	 * Input:
	 *      uiLevel: The level of detail of the output (default value is 4):
	 *                  0 : Show the number of vertices in the graph.
	 *                  1 : Level 0 + Show the list of the IDs of the vertices.
	 *                  2 : Level 1 + Show the list of the outgoing arcs of every vertex.
	 *                  3 : Level 1 + Show the list of the incoming arcs of every vertex.
	 *                  4+: Level 2 & 3.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void GRAdisplay(unsigned int uiLevel = 4) const;
	
	/**************************************************************
	 * Define the + operator adding a vertex to the graph.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndex: The ID of the vertex to add.
	 * Output:
	 * PreCond:
	 *      The ID of the vertex must be greater or equal to 1.
	 * PostCond:
	 *      Throws a CException with the ID `DUPLICATE_VERTEX_EXCEPTION` if the vertex already exists.
	 */
	CGraph &operator+(unsigned int uiVertexIndex);
	
	/**************************************************************
	 * Define the - operator removing a vertex from the graph.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndex: The ID of the vertex to remove.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	CGraph &operator-(unsigned int uiVertexIndex);
	
	/**************************************************************
	 * Defines the operator =.
	 **************************************************************
	 *
	 * Entree:
	 *      oGRAgraphParam: The graph to copy.
	 * Sortie:
	 *      CGraph&:        This graph modified.
	 * PreCond:
	 * PostCond:
	 */
	CGraph &operator=(CGraph const &oGRAgraphParam);
	
	/**************************************************************
	 * Add a property to a vertex.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndex:  The ID of the vertex.
	 *      pcKey:          The key associated with the value.
	 *      dValue:         The value to set for the key.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `KEY_ALREADY_DEFINED_EXCEPTION` if the key already exists.
	 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if the vertex doesn't exists.
	 */
	void GRAaddVertexProperty(unsigned int uiVertexIndex, char * pcKey, double dValue);
	
	/**************************************************************
	 * Modify a property of the vertex.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndex:  The ID of the vertex.
	 *      pcKey:          The key associated with the value.
	 *      dValue:         The new value to set for the key.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `KEY_NOT_FOUND_EXCEPTION` if the key doesn't exist.
	 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if the vertex doesn't exists.
	 */
	void GRAmodifyVertexProperty(unsigned int uiVertexIndex, char * pcKey, double dValue);
	
	/**************************************************************
	 * Get the value of a property of the vertex.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndex:  The ID of the vertex.
	 *      pcKey:          The key associated with the value.
	 * Output:
	 *      double: The value of the key.
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `KEY_NOT_FOUND_EXCEPTION` if the key doesn't exist.
	 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if the vertex doesn't exists.
	 */
	double GRAgetVertexProperty(unsigned int uiVertexIndex, char * pcKey) const;
	
	/**************************************************************
	 * Delete a property from the vertex.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndex:  The ID of the vertex.
	 *      pcKey:          The key associated with the value.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if the vertex doesn't exists.
	 */
	void GRAdeleteVertexProperty(unsigned int uiVertexIndex, char * pcKey);
	
	/**************************************************************
	 * Add a property to an arc of the graph.
	 **************************************************************
	 *
	 * Input:
	 *      uiArcSource:        The source of the arc.
	 *      uiArcDestination:   The destination of the arc.
	 *      pcKey:              The key associated with the value.
	 *      dValue:             The value to set for the key.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `KEY_ALREADY_DEFINED_EXCEPTION` if the key already exists.
	 *      Throws a CException with the ID `MISSING_ARC_INDEX_EXCEPTION` if the arc doesn't exists.
	 */
	void GRAaddArcProperty(unsigned int uiArcSource, unsigned int uiArcDestination, char * pcKey, double dValue);
	
	/**************************************************************
	 * Modify a property of an arc of the graph.
	 **************************************************************
	 *
	 * Input:
	 *      uiArcSource:        The source of the arc.
	 *      uiArcDestination:   The destination of the arc.
	 *      pcKey:              The key associated with the value.
	 *      dValue:             The new value to set for the key.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `KEY_NOT_FOUND_EXCEPTION` if the key doesn't exist.
	 *      Throws a CException with the ID `MISSING_ARC_INDEX_EXCEPTION` if the arc doesn't exists.
	 */
	void GRAmodifyArcProperty(unsigned int uiArcSource, unsigned int uiArcDestination, char * pcKey, double dValue);
	
	/**************************************************************
	 * Get the value of a property of an arc of the graph.
	 **************************************************************
	 *
	 * Input:
	 *      uiArcSource:        The source of the arc.
	 *      uiArcDestination:   The destination of the arc.
	 *      pcKey:              The key associated with the value.
	 * Output:
	 *      double: The value of the key.
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `KEY_NOT_FOUND_EXCEPTION` if the key doesn't exist.
	 *      Throws a CException with the ID `MISSING_ARC_INDEX_EXCEPTION` if the arc doesn't exists.
	 */
	double GRAgetArcProperty(unsigned int uiArcSource, unsigned int uiArcDestination, char * pcKey) const;
	
	/**************************************************************
	 * Delete a property from an arc of the graph.
	 **************************************************************
	 *
	 * Input:
	 *      uiArcSource:        The source of the arc.
	 *      uiArcDestination:   The destination of the arc.
	 *      pcKey:              The key associated with the value.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `MISSING_ARC_INDEX_EXCEPTION` if the arc doesn't exists.
	 */
	void GRAdeleteArcProperty(unsigned int uiArcSource, unsigned int uiArcDestination, char * pcKey);
	
	/**************************************************************
     * Get the number of vertices in the graph.
     **************************************************************
     *
	 * Input:
	 * Output:
	 *      unsigned int: The number of vertices.
	 * PreCond:
     * PostCond:
	 */
	unsigned int GRAgetVertexCount();
	
	/**************************************************************
	 * Get the list of the vertex indices.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 *      unsigned int *: The list of the different vertex indices.
	 * PreCond:
	 * PostCond:
	 */
	unsigned int * GRAgetVertexIndices();
	
	/**************************************************************
	 * Get the list of the vertex indices reached by a given vertex.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndex:  The ID of the vertex.
	 * Output:
	 *      unsigned int *: The list of the reachable vertex indices.
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `MISSING_VERTEX_INDEX_EXCEPTION` if the vertex doesn't exists.
	 */
	unsigned int * GRAgetReachableIndices(unsigned int uiVertexIndex);
};

#endif
