#include <cstdlib>
#include "CHashMap.h"
#include "utils.h"
#include "CException.h"

/**************************************************************
 * Default constructor.
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 */
CHashMap::CHashMap()
{
	uiCount = 0;
	ppcKeys = nullptr;
	pdValues = nullptr;
}

/**************************************************************
 * Copy constructor.
 **************************************************************
 *
 * Input:
 *      oHMPmap: The hashmap to copy.
 * Output:
 * PreCond:
 * PostCond:
 */
CHashMap::CHashMap(CHashMap const &oHMPmap)
{
	uiCount = oHMPmap.uiCount;
	RREALLOC(ppcKeys, char *, uiCount, "REALLOC ERROR CHashMap Copy Constructor");
	RREALLOC(pdValues, double, uiCount, "REALLOC ERROR CHashMap Copy Constructor");
	for(unsigned int uiIndex = 0; uiIndex < uiCount; uiIndex++)
	{
		ppcKeys[uiIndex] = oHMPmap.ppcKeys[uiIndex] == nullptr ? nullptr : STRDUP(oHMPmap.ppcKeys[uiIndex]);
		pdValues[uiIndex] = oHMPmap.pdValues[uiIndex];
	}
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
CHashMap::~CHashMap()
{
	HMPclear();
	ppcKeys = nullptr;
	pdValues = nullptr;
}

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
void CHashMap::CHMPaddValue(char * pcKeyParam, double dValue)
{
	
	if(CHMPgetKeyIndex(pcKeyParam) < 0)
	{
		uiCount++;
		RREALLOC(ppcKeys, char *, uiCount, "REALLOC ERROR CHMPaddValue");
		RREALLOC(pdValues, double, uiCount, "REALLOC ERROR CHMPaddValue");
		ppcKeys[uiCount - 1] = STRDUP(pcKeyParam);
		pdValues[uiCount - 1] = dValue;
	}
	else
		throw CException(KEY_ALREADY_DEFINED_EXCEPTION, (char *) "This key is already used.");
}

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
void CHashMap::CHMPmodifyValue(char * pcKeyParam, double dValue)
{
	int iIndex = CHMPgetKeyIndex(pcKeyParam);
	if(iIndex < 0)
		throw CException(KEY_NOT_FOUND_EXCEPTION, (char *) "This key is doesn't exists.");
	else
		pdValues[iIndex] = dValue;
}

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
int CHashMap::CHMPgetKeyIndex(char * pcKeyParam) const
{
	if(pcKeyParam == nullptr)
		return -1;
	for(unsigned int uiIndex = 0; uiIndex < uiCount; uiIndex++)
		if(ppcKeys[uiIndex] != nullptr && STRCMPI(pcKeyParam, ppcKeys[uiIndex]) == 0)
			return uiIndex;
	return -1;
}

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
double CHashMap::CHMPgetValue(char * pcKeyParam) const
{
	int iIndex = CHMPgetKeyIndex(pcKeyParam);
	if(iIndex < 0)
		throw CException(KEY_NOT_FOUND_EXCEPTION, (char *) "This key is doesn't exists.");
	return pdValues[iIndex];
}

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
void CHashMap::CHMPdeleteValue(char * pcKeyParam)
{
	int iIndex = CHMPgetKeyIndex(pcKeyParam);
	if(iIndex >= 0)
		ppcKeys[iIndex] = nullptr;
}

/**************************************************************
 * Clear the hashmap by deleting every values.
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 */
void CHashMap::HMPclear()
{
	for(unsigned int uiIndex = 0; uiIndex < uiCount; uiIndex++)
		free(ppcKeys[uiIndex]);
	uiCount = 0;
	free(ppcKeys);
	free(pdValues);
}

/**************************************************************
 * Define the = operator.
 **************************************************************
 *
 * Input:
 *      oHMPmap: The map to copy.
 * Output:
 * PreCond:
 * PostCond:
 */
CHashMap & CHashMap::operator=(CHashMap const& oHMPmap)
{
	HMPclear();
	uiCount = oHMPmap.uiCount;
	RREALLOC(ppcKeys, char *, uiCount, "REALLOC ERROR CHashMap Copy Constructor");
	RREALLOC(pdValues, double, uiCount, "REALLOC ERROR CHashMap Copy Constructor");
	for(unsigned int uiIndex = 0; uiIndex < uiCount; uiIndex++)
	{
		ppcKeys[uiIndex] = oHMPmap.ppcKeys[uiIndex] == nullptr ? nullptr : STRDUP(oHMPmap.ppcKeys[uiIndex]);
		pdValues[uiIndex] = oHMPmap.pdValues[uiIndex];
	}
}
