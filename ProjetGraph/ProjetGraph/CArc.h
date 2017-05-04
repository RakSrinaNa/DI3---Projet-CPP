#ifndef CARC
#define CARC

#define MISSING_ARC_INDEX_EXCEPTION 8793

/**************************************************************
 * Class representing an arc in the graph.
 **************************************************************/
class CArc
{

protected:
	unsigned int uiVertexIndex;

public:
	/**************************************************************
	 * Default constructor. Do not use. Prefer CArc(unsigned int).
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `MISSING_ARC_INDEX_EXCEPTION`
	 */
	CArc();
	
	/**************************************************************
	 * Copy constructor.
	 **************************************************************
	 *
	 * Input:
	 *      oARCarcParam: The arc to copy.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	CArc(CArc const &oARCarcParam);
	
	/**************************************************************
	 * Parameterized constructor.
	 **************************************************************
	 *
	 * Input:
	 *     uiVertexIndexParam: The ID of the target vertex of our arc.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	explicit CArc(unsigned int uiVertexIndexParam);
	
	/**************************************************************
	 * Destructor
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	~CArc();
	
	/**************************************************************
	 * Get the ID of the target vertex.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 *     unsigned int: The ID of the target vertex.
	 * PreCond:
	 * PostCond:
	 */
	unsigned int ARCgetVertexIndex() const
	{
		return uiVertexIndex;
	};
	
	/**************************************************************
	 * Set the ID of the target vertex.
	 **************************************************************
	 *
	 * Input:
	 *      uiVertexIndexParam: The ID of the target vertex.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void ARCsetVertexIndex(unsigned int uiVertexIndexParam)
	{
		uiVertexIndex = uiVertexIndexParam;
	};
	
	/**************************************************************
	 * Define the = operator.
	 **************************************************************
	 *
	 * Input:
	 *      oARCarcParam:   The arc to copy.
	 * Output:
	 *      Carc&:          This arc modified.
	 * PreCond:
	 * PostCond:
	 */
	CArc &operator=(CArc const &oARCarcParam);
};

#endif