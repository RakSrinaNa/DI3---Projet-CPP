#ifndef CARC
#define CARC

#include "CHashMap.h"

#define MISSING_ARC_INDEX_EXCEPTION 8793

/**************************************************************
 * Class representing an arc in the graph.
 **************************************************************/
class CArc
{

protected:
	unsigned int uiVertexIndex;
	CHashMap oHMPproperties;

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
	
	/**************************************************************
	 * Add a property to the arc.
	 **************************************************************
	 *
	 * Input:
	 *      pcKey:  The key associated with the value.
	 *      dValue: The value to set for the key.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `KEY_ALREADY_DEFINED_EXCEPTION` if the key already exists.
	 */
	void ARCaddProperty(char * pcKey, double dValue);
	
	/**************************************************************
	 * Modify a property of the arc.
	 **************************************************************
	 *
	 * Input:
	 *      pcKey:  The key associated with the value.
	 *      dValue: The new value to set for the key.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `KEY_NOT_FOUND_EXCEPTION` if the key doesn't exist.
	 */
	void ARCmodifyProperty(char * pcKey, double dValue);
	
	/**************************************************************
	 * Get the value of a property of the arc.
	 **************************************************************
	 *
	 * Input:
	 *      pcKey:  The key associated with the value.
	 * Output:
	 *      double: The value of the key.
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `KEY_NOT_FOUND_EXCEPTION` if the key doesn't exist.
	 */
	double ARCgetProperty(char * pcKey) const;
	
	/**************************************************************
	 * Delete a property from the arc.
	 **************************************************************
	 *
	 * Input:
	 *      pcKey:  The key associated with the value.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void ARCdeleteProperty(char * pcKey);
};

#endif