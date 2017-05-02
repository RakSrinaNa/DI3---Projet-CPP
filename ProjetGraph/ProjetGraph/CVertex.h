#ifndef CVERTEX
#define CVERTEX

#include "CArc.h"

#define MISSING_VERTEX_INDEX_EXCEPTION 8792
#define DUPLICATE_ARC_EXCEPTION 8794
#define DUPLICATE_VERTEX_EXCEPTION 8794

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
	explicit CVertex(unsigned int uiVertexIndexParam);
	
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
	 * Renvoi le nombre d'arcs entrants.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 *      unsigned int: Le nombre d'arcs entrants.
	 * PreCond:
	 * PostCond:
	 */
	unsigned int VERgetArcInCount() const;
	
	/**************************************************************
	 * Renvoi le nombre d'arcs sortants.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 *      unsigned int: Le nombre d'arcs sortants.
	 * PreCond:
	 * PostCond:
	 */
	unsigned int VERgetArcOutCount() const;
	
	/**************************************************************
	 * Ajoute un arc entrant au noeud.
	 **************************************************************
	 *
	 * Entree:
	 *      uiFromVertexIndex: L'ID du noeud qui pointe sur notre noeud actuel.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `DUPLICATE_ARC_EXCEPTION` si l'arc est deja present.
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
	 *      Renvoie une CException avec l'ID `DUPLICATE_ARC_EXCEPTION` si l'arc est deja present.
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
	 *      Si uiLastFromVertexIndex n'existe pas, le nouvel index n'est pas ajoute.
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
	 *      Si uiLastToVertexIndex n'existe pas, le nouvel index n'est pas ajoute.
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
	unsigned int VERgetVertexIndex() const
	{
		return uiVertexIndex;
	};
	
	/**************************************************************
	 * Recherche un arc entrant dans le noeud.
	 **************************************************************
	 *
	 * Entree:
	 *      uiFromVertexIndex:  L'ID du noeud a rechercher.
	 * Sortie:
	 *      bool:               true si l'arc entrant existe, false sinon.
	 * PreCond:
	 * PostCond:
	 */
	bool VERhasIndexIn(unsigned int uiFromVertexIndex) const;
	
	/**************************************************************
	 * Recherche un arc sortant dans le noeud.
	 **************************************************************
	 *
	 * Entree:
	 *      uiToVertexIndex:    L'ID du noeud a rechercher.
	 * Sortie:
	 *      bool:               true si l'arc sortant existe, false sinon.
	 * PreCond:
	 * PostCond:
	 */
	bool VERhasIndexOut(unsigned int uiToVertexIndex) const;
	
	/**************************************************************
	 * Affiche la liste des arcs entrants dans la console.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void VERdisplayArcIn() const;
	
	/**************************************************************
	 * Affiche la liste des arcs sortants dans la console.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void VERdisplayArcOut() const;
	
	/**************************************************************
	 * Inverse le sens de tous les arcs du noeud.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void VERinvert();

	/**************************************************************
	 * Define the operator =.
	 **************************************************************
	 *
	 * Entree:
	 *      oVERvertexParam: The vertex to copy.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	CVertex& operator=(CVertex const& oVERvertexParam);
};

#endif