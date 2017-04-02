#ifndef CARC
#define CARC


/**************************************************************
 * Classe représentant un arc d'un graph.
 **************************************************************/
class CArc
{

protected:
	unsigned int uiVertexIndex;

public:
	/**************************************************************
	 * Constructeur par defaut. A ne pas utiliser. Utiliser CArc(unsigned int)
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `MISSING_ARC_INDEX_EXCEPTION`.
	 */
	CArc();
	
	/**************************************************************
	 * Constructeur de confort.
	 **************************************************************
	 *
	 * Entree:
	 *      uiVertexIndexParam: L'ID du noeud cible de notre arc.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	CArc(unsigned int uiVertexIndexParam);
	
	/**************************************************************
	 * Destructeur.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	~CArc();
	
	
	/**************************************************************
	 * Permet d'obtenir l'ID du noeud cible.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 *      unsigned int: L'ID du noeud cible.
	 * PreCond:
	 * PostCond:
	 */
	unsigned int ARCgetVertexIndex(){return uiVertexIndex;};
	
	/**************************************************************
	 * Permet de definir l'ID du noeud cible.
	 **************************************************************
	 *
	 * Entree:
	 *      uiVertexIndexParam: L'ID du noeud cible de notre arc.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void ARCsetVertexIndex(unsigned int uiVertexIndexParam){uiVertexIndex = uiVertexIndexParam;};
};

#endif