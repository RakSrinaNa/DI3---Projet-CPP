#include <cstdlib>
#include <iostream>

#include "CVertex.h"
#include "CException.h"
#include "utils.h"

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
CVertex::CVertex()
{
	throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "Use the constructor : CVertex(unsigned int)");
}

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
CVertex::CVertex(CVertex const &oVERvertexParam) : uiVertexIndex(oVERvertexParam.uiVertexIndex), uiArcInCount(oVERvertexParam.uiArcInCount), uiArcOutCount(oVERvertexParam.uiArcOutCount), oHMPproperties(oVERvertexParam.oHMPproperties)
{
	MMALLOC(poARCinList, CArc *, uiArcInCount, "MALLOC ERROR CVERTEX CONSTRUCTOR");
	MMALLOC(poARCoutList, CArc *, uiArcOutCount, "MALLOC ERROR CVERTEX CONSTRUCTOR");

	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		poARCinList[uiIndex] = new CArc(*oVERvertexParam.poARCinList[uiIndex]);

	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		poARCoutList[uiIndex] = new CArc(*oVERvertexParam.poARCoutList[uiIndex]);
}

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
CVertex::CVertex(unsigned int uiVertexIndexParam) : uiVertexIndex(uiVertexIndexParam), uiArcInCount(0), uiArcOutCount(0), poARCinList(nullptr), poARCoutList(nullptr), oHMPproperties()
{
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
CVertex::~CVertex()
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		delete poARCinList[uiIndex];
	free(poARCinList);

	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		delete poARCoutList[uiIndex];
	free(poARCoutList);
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
void CVertex::VERaddArcIn(unsigned int uiFromVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		if(uiFromVertexIndex == poARCinList[uiIndex]->ARCgetVertexIndex())
			throw CException(DUPLICATE_ARC_EXCEPTION, (char *) "This arc is already existing");

	uiArcInCount++;
	RREALLOC(poARCinList, CArc *, uiArcInCount, "RREALLOC ERROR VERaddArcOut");
	poARCinList[uiArcInCount - 1] = new CArc(uiFromVertexIndex);
}

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
void CVertex::VERremoveArcIn(unsigned int uiFromVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		if(uiFromVertexIndex == poARCinList[uiIndex]->ARCgetVertexIndex())
		{
			uiArcInCount--;
			delete poARCinList[uiIndex];
			poARCinList[uiIndex] = poARCinList[uiArcInCount];
			RREALLOC(poARCinList, CArc *, uiArcInCount, "RREALLOC ERROR VERremoveArcIn");
			break;
		}
}

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
void CVertex::VERaddArcOut(unsigned int uiToVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(uiToVertexIndex == poARCoutList[uiIndex]->ARCgetVertexIndex())
			throw CException(DUPLICATE_ARC_EXCEPTION, (char *) "This arc is already existing");

	uiArcOutCount++;
	RREALLOC(poARCoutList, CArc *, uiArcOutCount, "RREALLOC ERROR VERaddArcOut");
	poARCoutList[uiArcOutCount - 1] = new CArc(uiToVertexIndex);
}

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
void CVertex::VERremoveArcOut(unsigned int uiToVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(uiToVertexIndex == poARCoutList[uiIndex]->ARCgetVertexIndex())
		{
			delete poARCoutList[uiIndex];
			poARCoutList[uiIndex] = poARCoutList[--uiArcOutCount];
			RREALLOC(poARCoutList, CArc *, uiArcOutCount, "RREALLOC ERROR VERremoveArcOut");
			break;
		}
}

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
void CVertex::VERmodifyArcIn(unsigned int uiLastFromVertexIndex, unsigned int uiNewFromVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		if(poARCinList[uiIndex]->ARCgetVertexIndex() == uiLastFromVertexIndex)
		{
			poARCinList[uiIndex]->ARCsetVertexIndex(uiNewFromVertexIndex);
			break;
		}
}

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
void CVertex::VERmodifyArcOut(unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(poARCoutList[uiIndex]->ARCgetVertexIndex() == uiLastToVertexIndex)
		{
			poARCoutList[uiIndex]->ARCsetVertexIndex(uiNewToVertexIndex);
			break;
		}
}

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
bool CVertex::VERhasIndexIn(unsigned int uiFromVertexIndex) const
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		if(poARCinList[uiIndex]->ARCgetVertexIndex() == uiFromVertexIndex)
			return true;
	return false;
}

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
bool CVertex::VERhasIndexOut(unsigned int uiToVertexIndex) const
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(poARCoutList[uiIndex]->ARCgetVertexIndex() == uiToVertexIndex)
			return true;
	return false;
}

/**************************************************************
 * Display the list of the incoming arcs.
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 */
void CVertex::VERdisplayArcIn() const
{
	std::cout << std::endl;
	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		std::cout << "\t" << "<- " << poARCinList[uiIndex]->ARCgetVertexIndex() << std::endl;
}

/**************************************************************
 * Display the list of the outgoing arcs.
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 */
void CVertex::VERdisplayArcOut() const
{
	std::cout << std::endl;
	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		std::cout << "\t" << "-> " << poARCoutList[uiIndex]->ARCgetVertexIndex() << std::endl;
}

/**************************************************************
 * Invert the orientation of every arcs.
 **************************************************************
 *
 * Input:
 * Output:
 * PreCond:
 * PostCond:
 */
void CVertex::VERinvert()
{
	unsigned int uiInTempo = uiArcInCount;
	uiArcInCount = uiArcOutCount;
	uiArcOutCount = uiInTempo;

	CArc ** poARCInTempo = poARCinList;
	poARCinList = poARCoutList;
	poARCoutList = poARCInTempo;
}

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
CVertex &CVertex::operator=(CVertex const &oVERvertexParam)
{

	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		delete poARCinList[uiIndex];
	free(poARCinList);

	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		delete poARCoutList[uiIndex];
	free(poARCoutList);

	uiVertexIndex = oVERvertexParam.uiVertexIndex;
	uiArcInCount = oVERvertexParam.uiArcInCount;
	uiArcOutCount = oVERvertexParam.uiArcOutCount;

	MMALLOC(this->poARCinList, CArc *, uiArcInCount, "MMALLOC ERROR OPERATOR= CVERTEX");
	MMALLOC(this->poARCoutList, CArc *, uiArcOutCount, "MMALLOC ERROR OPERATOR= CVERTEX");

	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		poARCinList[uiIndex] = new CArc(*(oVERvertexParam.poARCinList[uiIndex]));

	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		poARCoutList[uiIndex] = new CArc(*(oVERvertexParam.poARCoutList[uiIndex]));

	return *this;
}

/**************************************************************
 * Add a property to the vertex.
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
void CVertex::VERaddProperty(char * pcKey, double dValue)
{
	oHMPproperties.CHMPaddValue(pcKey, dValue);
}

/**************************************************************
 * Modify a property of the vertex.
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
void CVertex::VERmodifyProperty(char * pcKey, double dValue)
{
	oHMPproperties.CHMPmodifyValue(pcKey, dValue);
}

/**************************************************************
 * Get the value of a property of the vertex.
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
double CVertex::VERgetProperty(char * pcKey) const
{
	return oHMPproperties.CHMPgetValue(pcKey);
}

/**************************************************************
 * Delete a property from the vertex.
 **************************************************************
 *
 * Input:
 *      pcKey:  The key associated with the value.
 * Output:
 * PreCond:
 * PostCond:
 */
void CVertex::VERdeleteProperty(char * pcKey)
{
	oHMPproperties.CHMPdeleteValue(pcKey);
}

/**************************************************************
 * Add a property to an arc of the vertex.
 **************************************************************
 *
 * Input:
 *      uiArcDestination:   The arc concerned.
 *      pcKey:              The key associated with the value.
 *      dValue:             The value to set for the key.
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `KEY_ALREADY_DEFINED_EXCEPTION` if the key already exists.
 *      Throws a CException with the ID `MISSING_ARC_INDEX_EXCEPTION` if the arc doesn't exists.
 */
void CVertex::VERaddArcProperty(unsigned int uiArcDestination, char * pcKey, double dValue)
{
	if(VERhasIndexOut(uiArcDestination))
	{
		for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
			if(uiArcDestination == poARCoutList[uiIndex]->ARCgetVertexIndex())
			{
				poARCoutList[uiIndex]->ARCaddProperty(pcKey, dValue);
				break;
			}
	}
	else
		throw CException(MISSING_ARC_INDEX_EXCEPTION, (char *) "This arc doesn't exist");
}

/**************************************************************
 * Modify a property of an arc of the vertex.
 **************************************************************
 *
 * Input:
 *      uiArcDestination:   The arc concerned.
 *      pcKey:              The key associated with the value.
 *      dValue:             The new value to set for the key.
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `KEY_NOT_FOUND_EXCEPTION` if the key doesn't exist.
 *      Throws a CException with the ID `MISSING_ARC_INDEX_EXCEPTION` if the arc doesn't exists.
 */
void CVertex::VERmodifyArcProperty(unsigned int uiArcDestination, char * pcKey, double dValue)
{
	if(VERhasIndexOut(uiArcDestination))
	{
		for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
			if(uiArcDestination == poARCoutList[uiIndex]->ARCgetVertexIndex())
			{
				poARCoutList[uiIndex]->ARCmodifyProperty(pcKey, dValue);
				break;
			}
	}
	else
		throw CException(MISSING_ARC_INDEX_EXCEPTION, (char *) "This arc doesn't exist");
}

/**************************************************************
 * Get the value of a property of an arc of the vertex.
 **************************************************************
 *
 * Input:
 *      uiArcDestination:   The arc concerned.
 *      pcKey:              The key associated with the value.
 * Output:
 *      double: The value of the key.
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `KEY_NOT_FOUND_EXCEPTION` if the key doesn't exist.
 *      Throws a CException with the ID `MISSING_ARC_INDEX_EXCEPTION` if the arc doesn't exists.
 */
double CVertex::VERgetArcProperty(unsigned int uiArcDestination, char * pcKey) const
{
	if(VERhasIndexOut(uiArcDestination))
	{
		for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
			if(uiArcDestination == poARCoutList[uiIndex]->ARCgetVertexIndex())
				return poARCoutList[uiIndex]->ARCgetProperty(pcKey);
	}
	throw CException(MISSING_ARC_INDEX_EXCEPTION, (char *) "This arc doesn't exist");
}

/**************************************************************
 * Delete a property from an arc of the vertex.
 **************************************************************
 *
 * Input:
 *      uiArcDestination:   The arc concerned.
 *      pcKey:              The key associated with the value.
 * Output:
 * PreCond:
 * PostCond:
 *      Throws a CException with the ID `MISSING_ARC_INDEX_EXCEPTION` if the arc doesn't exists.
 */
void CVertex::VERdeleteArcProperty(unsigned int uiArcDestination, char * pcKey)
{
	if(VERhasIndexOut(uiArcDestination))
	{
		for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
			if(uiArcDestination == poARCoutList[uiIndex]->ARCgetVertexIndex())
			{
				poARCoutList[uiIndex]->ARCdeleteProperty(pcKey);
				break;
			}
	}
	else
		throw CException(MISSING_ARC_INDEX_EXCEPTION, (char *) "This arc doesn't exist");
}

/**************************************************************
 * Get the list of the reachable vertex indices.
 **************************************************************
 *
 * Input:
 * Output:
 *      unsigned int *: The list of the reachable indices.
 * PreCond:
 * PostCond:
 */
unsigned int * CVertex::VERgetReachableIndices()
{
    unsigned int * puiReachableIndices;
    MMALLOC(puiReachableIndices, unsigned int, uiArcOutCount +1, "VERgetReachableIndices");
    puiReachableIndices[0] = uiArcOutCount;
    for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
        puiReachableIndices[uiIndex +1] = poARCoutList[uiIndex]->ARCgetVertexIndex();
    return puiReachableIndices;
}
