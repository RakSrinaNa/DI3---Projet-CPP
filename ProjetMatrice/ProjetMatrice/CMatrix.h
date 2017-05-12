#ifndef C_MATRIX_H
#define C_MATRIX_H

#include <iostream>

#include "utils.h"
#include "CException.h"

#define OUT_OF_RANGE_EXCEPTION 89714
#define DIVISION_BY_ZERO_EXCEPTION 89715
#define INCOMPATIBLE_MATRIX_EXCEPTION 89716
#define IMPOSSIBLE_MATRIX_SIZE_EXCEPTION 89717

/**************************************************************
 * Classe représentant une matrice.
 **************************************************************/
template <class T>
class CMatrix
{
protected:
	/**************************************************************
    * Nombre de lignes de la matrice.
	**************************************************************/
	unsigned int uiHeight;
	/**************************************************************
    * Nombre de colonnes de la matrice.
    **************************************************************/
	unsigned int uiWidth;
	/**************************************************************
    * Tableau 2D des valeurs de la matrice.
    **************************************************************/
	T** ptValues;

public:
	/**************************************************************
	 * Constructeur par defaut.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      La matrice sera de taille 1x1.
	 *      Les valeurs sont par default a 0.
	 */
	CMatrix();
	
	/**************************************************************
	 * Constructeur de recopie.
	 **************************************************************
	 *
	 * Entree:
	 *      oMTXmatrixParam: Une référence sur la matrice a recopier.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	CMatrix(CMatrix<T> const& oMTXmatrixParam);
	
	/**************************************************************
	 * Constructeur de confort.
	 **************************************************************
	*
	* Entree:
	*      uiHeightParam:  Nombre de lignes de la matrice.
	*      uiWidthParam:   Nombre de colonnes de la matrice.
	* Sortie:
	* PreCond:
	* PostCond:
	*      Renvoie une CException avec ID `IMPOSSIBLE_MATRIX_SIZE_EXCEPTION` si au moins l'un des paramètres est inférieur à 1.
	*      Les valeurs sont par default a 0.
	*/
	CMatrix(unsigned int uiHeightParam, unsigned int uiWidthParam);
	
	/**************************************************************
	 * Destructeur.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	~CMatrix();
	
	/**************************************************************
	 * Renvoie le nombre de lignes.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 *      unsigned int: Le nombre de lignes.
	 * PreCond:
	 * PostCond:
	 */
	unsigned int MTXgetHeight() const;
	
	/**************************************************************
	 * Renvoie le nombre de colonnes.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 *      unsigned int: Le nombre de colonnes.
	 * PreCond:
	 * PostCond:
	 */
	unsigned int MTXgetWidth() const;
	
	/**************************************************************
	 * Renvoie la valeur d'une case de la matrice.
	 **************************************************************
	 *
	 * Entree:
	 *      uiRow:      L'indice de la ligne.
	 *      uiColumn:   L'indice de la colonne.
	 * Sortie:
	 *      T:          L'élément de la case.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `OUT_OF_RANGE_EXCEPTION` si la case n'existe pas.
	 */
	T MTXgetValue(unsigned int uiRow, unsigned int uiColumn) const;
	
	
	/**************************************************************
	 * Ecrit la valeur d'une case de la matrice.
	 **************************************************************
	 *
	 * Entree:
	 *      uiRow:      L'indice de la ligne.
	 *      uiColumn:   L'indice de la colonne.
	 *      tValueParam:La valeur a affecter.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `OUT_OF_RANGE_EXCEPTION` si la case n'existe pas.
	 */
	void MTXsetValue(unsigned int uiRow, unsigned int uiColumn, T tValueParam);
	
	
	/**************************************************************
	 * Affiche la matrice dans la sortie standard.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	void MTXdisplay();
	
	/**************************************************************
	 * Cree une nouvelle matrice etant la transposée de celle-ci.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 *      CMatrix: Transposée de la matrice en cours.
	 * PreCond:
	 * PostCond:
	 */
	CMatrix<T>& MTXtranspose();
	
	
	/**************************************************************
	 * Définit l'addition entre matrices.
	 **************************************************************
	 *
	 * Entree:
	 *      oMTXmatrixParam:    La matrice a ajouter.
	 * Sortie:
	 *      CMatrix:            Une matrice représentant la somme des matrices.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `INCOMPATIBLE_MATRIX_EXCEPTION` si les matrices ne sont pas de même taille.
	 */
	CMatrix<T>& operator+(CMatrix<T> const& oMTXmatrixParam);
	
	/**************************************************************
	 * Définit la soustration entre matrices.
	 **************************************************************
	 *
	 * Entree:
	 *      oMTXmatrixParam:    La matrice a soustraire.
	 * Sortie:
	 *      CMatrix:            Une matrice représentant la différence des matrices.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `INCOMPATIBLE_MATRIX_EXCEPTION` si les matrices ne sont pas de même taille.
	 */
	CMatrix<T>& operator-(CMatrix<T> const& oMTXmatrixParam);
	
	/**************************************************************
	 * Définit la multiplication entre matrices.
	 **************************************************************
	 *
	 * Entree:
	 *      oMTXmatrixParam:    La matrice a multiplier.
	 * Sortie:
	 *      CMatrix:            Une matrice représentant le produit des matrices.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `INCOMPATIBLE_MATRIX_EXCEPTION` si la multiplication n'est pas possible.
	 */
	CMatrix<T>& operator*(CMatrix<T> const& oMTXmatrixParam);
	
	/**************************************************************
	 * Définit la multiplication d'une matrice par un scalaire.
	 **************************************************************
	 *
	 * Entree:
	 *      dCoefficient:       Le coefficient de multiplication.
	 * Sortie:
	 *      CMatrix:            Une matrice étant la multiplication de la marice actuelle par le scalaire.
	 * PreCond:
	 * PostCond:
	 */
	CMatrix<T>& operator*(double dCoefficient);
	
	/**************************************************************
	 * Définit la division d'une matrice par un scalaire.
	 **************************************************************
	 *
	 * Entree:
	 *      dCoefficient:       Le coefficient de division.
	 * Sortie:
	 *      CMatrix:            Une matrice étant la division de la matrice actuelle par le scalaire.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `DIVISION_BY_0_EXCEPTION` si le coefficient est 0.
	 */
	CMatrix<T>& operator/(double dCoefficient);
	
	/**************************************************************
	 * Définit l'affectation d'une matrice a une autre.
	 **************************************************************
	 *
	 * Entree:
	 *      oMTXmatrixParam:    La matrice a affecter.
	 * Sortie:
	 *      CMatrix:            Un duplicatat de la matrice en paramètre dans la matrice en cours.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `INCOMPATIBLE_MATRIX_EXCEPTION` si les matrices ne sont pas de même taille.
	 */
	CMatrix<T>& operator=(CMatrix<T> const& oMTXmatrixParam);
	
	/**************************************************************
	 * Définit la comparaison entre matrices.
	 **************************************************************
	 *
	 * Entree:
	 *      oMTXmatrixParam:    La matrice a comparer.
	 * Sortie:
	 *      bool:               true si les matrices sont de même taille et ont les mêmes valeurs, false sinon.
	 * PreCond:
	 * PostCond:
	 */
	bool operator==(CMatrix<T> const& oMTXmatrixParam);	
	
	/**************************************************************
	 * Multiplie la matrice actuelle par un coefficient.
	 **************************************************************
	 *
	 * Entree:
	 *      dCoefficient:   Le coefficient de multiplication.
	 * Sortie:
	 *      CMatrix:        Notre matrice multipliée.
	 * PreCond:
	 * PostCond:
	 */
	CMatrix<T>& operator*=(double dCoefficient);
	
	/**************************************************************
	 * Divise la matrice actuelle par un coefficient.
	 **************************************************************
	 *
	 * Entree:
	 *      dCoefficient:   Le coefficient de division.
	 * Sortie:
	 *      CMatrix:        Notre matrice divisée.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `DIVISION_BY_0_EXCEPTION` si le coefficient est 0.
	 */
	CMatrix<T>& operator/=(double dCoefficient);
	
	/**************************************************************
	 * Obtient la valeur de la matrice aux coordonnees voulues.
	 **************************************************************
	 *
	 * Entree:
	 *      uiRow:      L'indice de la ligne.
	 *      uiColumn:   L'indice de la colonne.
	 * Sortie:
	 *      T:          L'élément de la case.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `OUT_OF_RANGE_EXCEPTION` si la case n'existe pas.
	 */
	T operator()(unsigned int uiRow, unsigned int uiColumn);
};

template<class T>
CMatrix<T>& operator*(double dCoefficient, CMatrix<T> const& oMTXmatrixParam);

#include "CMatrix.cpp"

#endif
