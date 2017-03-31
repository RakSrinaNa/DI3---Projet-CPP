#ifndef CVERTEX
#define CVERTEX

#include "CArc.h"

#define MISSING_VERTEX_INDEX_EXCEPTION 8792

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
	 * Constructeur par defaut. A ne pas utiliser. Utiliser CVertex(unsigned int).
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `MISSING_VERTEX_INDEX_EXCEPTION`.
	 */
	CVertex();
	
	/**************************************************************
	 * Constructeur de confort.
	 **************************************************************
	 *
	 * Entree:
	 *      uiVertexIndexParam: L'ID du noeud.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	CVertex(unsigned int uiVertexIndexParam);
	
	/**************************************************************
	 * Destructeur.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	~CVertex();
	
	/**************************************************************
	 * Ajoute un arc entrant au noeud.
	 **************************************************************
	 *
	 * Entree:
	 *      uiFromVertexIndex: L'ID du noeud qui pointe sur notre noeud actuel.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void VERaddArcIn(unsigned int uiFromVertexIndex);
	
	/**************************************************************
	 * Retire un arc entrant du noeud.
	 **************************************************************
	 *
	 * Entree:
	 *      uiFromVertexIndex: L'ID du noeud a retirer qui pointe sur notre noeud actuel.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void VERremoveArcIn(unsigned int uiFromVertexIndex);
	
	/**************************************************************
	 * Ajoute un arc sortant au noeud.
	 **************************************************************
	 *
	 * Entree:
	 *      uiToVertexIndex: L'ID du noeud a pointer.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void VERaddArcOut(unsigned int uiToVertexIndex);
	
	/**************************************************************
	 * Retire un arc sortant du noeud.
	 **************************************************************
	 *
	 * Entree:
	 *      uiToVertexIndex: L'ID du noeud pointe a retirer.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void VERremoveArcOut(unsigned int uiToVertexIndex);
	
	/**************************************************************
	* Modifie un arc entrant au noeud.
	**************************************************************
	*
	* Entree:
	*      uiLastFromVertexIndex:   L'ID du noeud qui nous pointe a remplacer.
	 *     uiNewFromVertexIndex:    L'ID du nouveau noeud qui nous pointe.
	* Sortie:
	* PreCond:
	* PostCond:
	*/
	void VERmodifyArcIn(unsigned int uiLastFromVertexIndex, unsigned int uiNewFromVertexIndex);
	
	/**************************************************************
	* Modifie un arc sortant du noeud.
	**************************************************************
	*
	* Entree:
	*      uiLastToVertexIndex:   L'ID du noeud que nous pointons a remplacer.
	 *     uiNewToVertexIndex:    L'ID du nouveau a pointer.
	* Sortie:
	* PreCond:
	* PostCond:
	*/
	void VERmodifyArcOut(unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex);
	
	/**************************************************************
	 * Recupere l'ID du noeud courrant.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 *      unsigned id: L'ID du noeud.
	 * PreCond:
	 * PostCond:
	 */
	unsigned int VERgetVertexIndex();
};

#endif