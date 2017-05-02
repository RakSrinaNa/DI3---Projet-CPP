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
	 * Constructeur par defaut.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Graph initialise sans sommets ni arcs.
	 */
	CGraph();
	
	/**************************************************************
	 * Constructeur de confort, initialisant un matrice a partir d'un fichier.
	 **************************************************************
	 *
	 * Entree:
	 *      pcFileName:     Le chemin du fichier a lire.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `IO_FILE_EXCEPTION` si une erreur de lecture est survenue.
	 *      Renvoie une CException avec l'ID `MALFORMATTED_FILE_EXCEPTION` si le fichier est mal formatte.
	 */
	explicit CGraph(char * pcFilename);
	
	/**************************************************************
	 * Destructeur.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Libere le graph ainsi que tout les arcs et sommets.
	 */
	~CGraph();
	
	/**************************************************************
	 * Ajoute un sommet au graph.
	 **************************************************************
	 *
	 * Entree:
	 *      uiVertexIndex: L'indice du sommet a ajouter.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `DUPLICATE_VERTEX_EXCEPTION` si le sommet existe deja.
	 *      Renvoie une CException avec l'ID `BAD_INDEX_VERTEX_EXCEPTION` si le sommet a un index inferieur a 1.
	 */
	void GRAaddVertex(unsigned int uiVertexIndex);
	
	/**************************************************************
	 * Retire un sommet du graph.
	 **************************************************************
	 *
	 * Entree:
	 *      uiVertexIndex: L'indice du sommet a retirer.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void GRAremoveVertex(unsigned int uiVertexIndex);
	
	/**************************************************************
	 * Verifie si un sommet est present dans le graph.
	 **************************************************************
	 *
	 * Entree:
	 *      uiVertexIndex:  L'indice du sommet a tester.
	 * Sortie:
	 *      bool:           True si le sommet est present dans le graph, False sinon.
	 * PreCond:
	 * PostCond:
	 */
	bool GRAhasVertex(unsigned int uiVertexIndex) const;
	
	/**************************************************************
	 * Ajoute un arc au graph.
	 **************************************************************
	 *
	 * Entree:
	 *      uiFromVertexIndex:  ID du sommet de depart.
	 *      uiToVertexIndex:    ID du sommet d'arrivee.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `MISSING_VERTEX_INDEX_EXCEPTION` si l'un des deux sommets n'existe pas.
	 *      Renvoie une CException avec l'ID `DUPLICATE_ARC_EXCEPTION` si l'arc existe deja.
	 */
	void GRAaddArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex);
	
	/**************************************************************
	 * Retire un arc du graph.
	 **************************************************************
	 *
	 * Entree:
	 *      uiFromVertexIndex:  ID du sommet de depart.
	 *      uiToVertexIndex:    ID du sommet d'arrivee.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `MISSING_VERTEX_INDEX_EXCEPTION` si l'un des deux sommets n'existe pas.
	 */
	void GRAremoveArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex);
	
	/**************************************************************
	 * Modifie le sommet d'arrivee d'un arc existant.
	 **************************************************************
	 *
	 * Entree:
	 *      uiFromVertexIndex:  ID du sommet de depart.
	 *      uiLastToVertexIndex:ID de l'ancien sommet d'arrivee.
	 *      uiNewToVertexIndex: ID du nouveau sommet d'arrivee.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `MISSING_VERTEX_INDEX_EXCEPTION` si l'un des deux sommets n'existe pas.
	 *      Renvoie une CException avec l'ID `MISSING_ARC_INDEX_EXCEPTION` si l'arc n'existe pas.
	 *      Renvoie une CException avec l'ID `DUPLICATE_ARC_EXCEPTION` si le nouvel arc existe deja.
	 */
	void GRAmodifyArc(unsigned int uiFromVertexIndex, unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex);
	
	/**************************************************************
	 * Verifie si le graph contient un arc.
	 **************************************************************
	 *
	 * Entree:
	 *      uiFromVertexIndex:  ID du sommet de depart.
	 *      uiToVertexIndex:    ID du sommet d'arrivee.
	 * Sortie:
	 *      bool:               True si l'arc est present dans le graph, False sinon.
	 * PreCond:
	 * PostCond:
	 */
	bool GRAhasArc(unsigned int uiFromVertexIndex, unsigned int uiToVertexIndex) const;
	
	/**************************************************************
	 * Ajoute un lien etre deux sommets (arc dans les deux sens).
	 **************************************************************
	 *
	 * Entree:
	 *      uiVertexIndex1: L'ID de l'un des sommets.
	 *      uiVertexIndex2: L'ID de l'autre sommet.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `MISSING_VERTEX_INDEX_EXCEPTION` si l'un des deux sommets n'existe pas.
	 */
	void GRAaddLink(unsigned int uiVertexIndex1, unsigned int uiVertexIndex2);
	
	/**************************************************************
	 * Inverse le sens de tous les arcs du grpah.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void GRAinvert();
	
	/**************************************************************
	 * Resets the graph.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void GRAclear();

	/**************************************************************
	 * Affiche le graph dans la sortie standard.
	 **************************************************************
	 *
	 * Entree:
	 *      uiLevel: Le niveau de precision de l'affichage:
	 *                  0 : Affiche le nombre de sommets du graph.
	 *                  1 : Niveau 0 + Affiche la liste des indices des sommets.
	 *                  2 : Niveau 1 + Affiche la liste des arcs sortant de chaque sommet.
	 *                  3 : Niveau 1 + Affiche la liste des arcs entrant de chaque sommet.
	 *                  4+: Niveau 2 & 3.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void GRAdisplay(unsigned int uiLevel = 4) const;

	/**************************************************************
	 * Definit l'operateur d'addition permettant d'ajouer un sommet au graph.
	 **************************************************************
	 *
	 * Entree:
	 *      uiVertexIndex: L'indice du sommet a ajouter.
	 * Sortie:
	 * PreCond:
	 *      L'ID du sommet doit etre superieur ou egal a 1.
	 * PostCond:
	 *      Renvoie une CException avec l'ID `DUPLICATE_VERTEX_EXCEPTION` si le sommet existe deja.
	 */
	CGraph & operator+(unsigned int uiVertexIndex);
	
	/**************************************************************
	 * Definit l'operateur de soustraction permettant de retirer un sommet du graph.
	 **************************************************************
	 *
	 * Entree:
	 *      uiVertexIndex: L'indice du sommet a retirer.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	CGraph & operator-(unsigned int uiVertexIndex);

	/**************************************************************
	 * Defines the operator =.
	 **************************************************************
	 *
	 * Entree:
	 *      oGRAgraphParam: The graph to copy.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	CGraph & operator=(CGraph const& oGRAgraphParam);
};

#endif