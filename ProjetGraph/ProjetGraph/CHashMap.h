#ifndef PROJETGRAPH_CHASHMAP_H
#define PROJETGRAPH_CHASHMAP_H

#define KEY_ALREADY_DEFINED_EXCEPTION 3947
#define KEY_NOT_FOUND_EXCEPTION 3948

class CHashMap
{
private:
	unsigned int uiCount;
	char ** ppcKeys;
	double * pdValues;
	
	/**************************************************************
	 * Get the index in the array of the value.
	 **************************************************************
	 *
	 * Input:
	 *      pcKeyParam: The key to look for.
	 * Output:
	 *      int:        The index of the key, or a negative number if it was not found.
	 * PreCond:
	 * PostCond:
	 */
	int CHMPgetKeyIndex(char * pcKeyParam) const;
public:
	/**************************************************************
	 * Default constructor.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	CHashMap();
	
	/**************************************************************
	 * Destructor.
	 **************************************************************
	 *
	 * Input:
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	~CHashMap();
	
	/**************************************************************
	 * Add a key/value to the map.
	 **************************************************************
	 *
	 * Input:
	 *      pcKeyParam: The key associate to the value.
	 *      dValue:     The value to set for this key.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `KEY_ALREADY_DEFINED_EXCEPTION` if the key already exists.
	 */
	void CHMPaddValue(char * pcKeyParam, double dValue);
	
	/**************************************************************
	 * Modify the value of a key.
	 **************************************************************
	 *
	 * Input:
	 *      pcKeyParam: The key in which the value will be modified.
	 *      dValue:     The new value to set.
	 * Output:
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `KEY_NOT_FOUND_EXCEPTION` if the key doesn't exists.
	 */
	void CHMPmodifyValue(char * pcKeyParam, double dValue);
	
	/**************************************************************
	 * Get the value of a key.
	 **************************************************************
	 *
	 * Input:
	 *      pcKeyParam: The key to get the value from.
	 * Output:
	 *      double:     The value of the key.
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `KEY_NOT_FOUND_EXCEPTION` if the key doesn't exists.
	 */
	double CHMPgetValue(char * pcKeyParam) const;
	
	/**************************************************************
	 * Delete a key and it's value from the map.
	 **************************************************************
	 *
	 * Input:
	 *      pcKeyParam: The key to remove.
	 * Output:
	 * PreCond:
	 * PostCond:
	 */
	void CHMPdeleteValue(char * pcKeyParam);
};

#endif
