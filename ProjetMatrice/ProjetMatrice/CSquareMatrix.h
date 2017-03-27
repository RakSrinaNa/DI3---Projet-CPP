#ifndef C_SQUARE_MATRIX_H
#define C_SQUARE_MATRIX_H

#include "CMatrix.h"

#define NOT_INVERSIBLE_EXCEPTION 99717

template <class T>
class CSquareMatrix : public CMatrix<T>
{
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
	CSquareMatrix();
	
	/**************************************************************
	 * Constructeur de recopie.
	 **************************************************************
	 *
	 * Entree:
	 *      oSMTXmatrixParam: La matrice carree a copier.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	CSquareMatrix(CSquareMatrix<T> const& oSMTXmatrixParam);
	
	/**************************************************************
	 * Constructeur de confort.
	 * A partir d'une matrice carree, construit une recopie de celle-ci en retirant une ligne et une colonne.
	 **************************************************************
	 *
	 * Entree:
	 *      oSMTXmatrixParam:   La matrice carree a considerer.
	 *      uiRow:              La ligne a retirer dans la copie.
	 *      uiColumn:           La colonne a retirer dans la copie.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	CSquareMatrix(CSquareMatrix<T> const& oSMTXmatrixParam, unsigned int uiRow, unsigned int uiColumn);
	
	/**************************************************************
	 * Constructeur de copie a partir d'une matrice non carree.
	 * A partir d'une matrice carree, construit une recopie de celle-ci en retirant une ligne et une colonne.
	 **************************************************************
	 *
	 * Entree:
	 *      oSMTXmatrixParam:   La matrice carree a considerer.
	 *      uiRow:              La ligne a retirer dans la copie.
	 *      uiColumn:           La colonne a retirer dans la copie.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `INCOMPATIBLE_MATRIX_EXCEPTION` si la matrice n'est pas carrée. //TODO A faire
	 */
	CSquareMatrix(CMatrix<T> const& oMTXmatrixParam);
	
	/**************************************************************
	 * Constructeur de confort.
	 **************************************************************
	 *
	 * Entree:
	 *      uiSize: La taille de la matrice carree.
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 *      Les valeurs sont par default a 0.
	 */
	CSquareMatrix(unsigned int uiSize);
	
	/**************************************************************
	 * Constructeur de confort.
	 **************************************************************
	 *
	 * Entree:
	 *      uiSize:     La taille de la matrice carree.
	 *      pcMethod:   La methode de construction de la matrice. Sont supporte:
	 *                      - "eye": cree une matrice identite
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	CSquareMatrix(unsigned int uiSize, char * pcMethod);
	
	/**************************************************************
	 * Destructeur.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 * PreCond:
	 * PostCond:
	 */
	~CSquareMatrix();
	
	
	/**************************************************************
	 * Renvoie la taille de la matrice (nombre de lignes et nombre ed colonnes).
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 *      unsigned int: La taille de la matrice.
	 * PreCond:
	 * PostCond:
	 */
	unsigned int SMTXgetSize();
	
	/**************************************************************
	 * Renvoie le determinant de la matrice.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 *      double: Le determinant.
	 * PreCond:
	 * PostCond:
	 */
	double SMTXgetDeterminant();
	
	/**************************************************************
	 * Renvoie une puissance de la matrice.
	 **************************************************************
	 *
	 * Entree:
	 *      power:          La puissance de la matrice a calculer.
	 * Sortie:
	 *      CSquareMatrix:  La matrice a la puissance power.
	 * PreCond:
	 * PostCond:
	 */
	CSquareMatrix<T>& SMTXpow(unsigned int power);
	
	/**************************************************************
	 * Cree une nouvelle matrice etant la comatrice de celle-ci.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 *      CSquareMatrix:  La comatrice.
	 * PreCond:
	 * PostCond:
	 */
	CSquareMatrix<T>& SMTXcomatrix();
	
	/**************************************************************
	 * Cree une nouvelle matrice etant la transposée de celle-ci.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 *      CSquareMatrix: Transposée de la matrice en cours.
	 * PreCond:
	 * PostCond:
	 */
	CSquareMatrix<T>& SMTXtranspose();
	
	/**************************************************************
	 * Cree une nouvelle matrice etant l'inverse de celle-ci.
	 **************************************************************
	 *
	 * Entree:
	 * Sortie:
	 *      CSquareMatrix: Inverse de la matrice en cours.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `NOT_INVERSIBLE_EXCEPTION` si la matrice n'est pas inversible. //TODO A faire
	 */
	CSquareMatrix<T>& SMTXinverse();
	
	
	/**************************************************************
	 * Définit l'affectation d'une matrice a une autre.
	 **************************************************************
	 *
	 * Entree:
	 *      oMTXmatrixParam:    La matrice a affecter.
	 * Sortie:
	 *      CSquareMatrix:      Un duplicatat de la matrice en paramètre dans la matrice en cours.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `INCOMPATIBLE_MATRIX_EXCEPTION` si les matrices ne sont pas de même taille. //TODO A faire
	 */
	CSquareMatrix<T>& operator= (CSquareMatrix<T> const& oSMTXmatrixParam);
	
	/**************************************************************
	 * Multiplie la matrice actuelle par une autre.
	 **************************************************************
	 *
	 * Entree:
	 *      oMTXmatrixParam:    La matrice a multiplier.
	 * Sortie:
	 *      CSquareMatrix:      La matrice actuelle multipliée.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `INCOMPATIBLE_MATRIX_EXCEPTION` si les matrices ne sont pas de même taille. //TODO A faire
	 */
	CSquareMatrix<T>& operator*= (CSquareMatrix<T> const& oSMTXmatrixParam);
	
	/**************************************************************
	 * Multiplie la matrice actuelle par un coefficient.
	 **************************************************************
	 *
	 * Entree:
	 *      dCoefficient:   Le coefficient de multiplication.
	 * Sortie:
	 *      CSquareMatrix:  Notre matrice multipliée.
	 * PreCond:
	 * PostCond:
	 */
	CSquareMatrix<T>& operator*= (double dCoefficient);
	
	/**************************************************************
	 * Divise la matrice actuelle par un coefficient.
	 **************************************************************
	 *
	 * Entree:
	 *      dCoefficient:   Le coefficient de division.
	 * Sortie:
	 *      CSquareMatrix:  Notre matrice divisée.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `DIVISION_BY_0_EXCEPTION` si le coefficient est 0. //TODO A faire
	 */
	CSquareMatrix<T>& operator/= (double dCoefficient);

};

#include "CSquareMatrix.cpp"

#endif