#ifndef C_MATRIX_PARSER_H
#define C_MATRIX_PARSER_H

#define IO_FILE_EXCEPTION 4890
#define MALFORMATTED_FILE_EXCEPTION 4891
#define UNSUPPORTED_TYPE_EXCEPTION 4892
#define NOT_SQUARE_MATRIX 4893
#define PARSER_ERROR_EXCEPTION 4894

#include <cstdio>
#include <cstdlib>
#include "CMatrix.h"
#include "CSquareMatrix.h"

/**************************************************************
* Types primitifs qu'une matrice peut avoir.
**************************************************************/
enum EMatrixType{
	UNSET,
	ERROR,
	BYTE,
	SHORT,
	INT,
	FLOAT,
	DOUBLE,
	CHAR,
	BOOLEAN
};

/**************************************************************
* Informations d'une matrice avant d'être construite.
**************************************************************/
typedef struct{
	unsigned int uiWidth;
	unsigned int uiHeight;
	double ** pdValues;
	EMatrixType eMTTtype;
} SMatrixInfos;

class CMatrixParser
{
public:
	/**************************************************************
	 * Lis une matrice a partir d'une fichier.
	 **************************************************************
	 *
	 * Entree:
	 *      pcFileName:     Le chemin du fichier a lire.
	 * Sortie:
	 *      CMatrix<double>:La matrice lu.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `UNSUPPORTED_TYPE_EXCEPTION` si le type de la matrice n'est pas supporté (si différent de double dans notre cas).
	 *      Renvoie une CException avec l'ID `IO_FILE_EXCEPTION` si une erreur de lecture est survenue.
	 */
	static CMatrix<double> * PMTXreadMatrix(char * pcFileName);
	
	/**************************************************************
	 * Lis une matrice carrée a partir d'une fichier.
	 **************************************************************
	 *
	 * Entree:
	 *      pcFileName:             Le chemin du fichier a lire.
	 * Sortie:
	 *      CSquareMatrix<double>:  La matrice lu.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `UNSUPPORTED_TYPE_EXCEPTION` si le type de la matrice n'est pas supporté (si différent de double dans notre cas).
	 *      Renvoie une CException avec l'ID `IO_FILE_EXCEPTION` si une erreur de lecture est survenue.
	 *      Renvoie une CException avec l'ID `NOT_SQUARE_MATRIX` si la matrice n'est pas carrée.
	 */
	static CSquareMatrix<double> * PMTXreadSquareMatrix(char * pcFileName);

private:
	/**************************************************************
	 * Lis les infos d'une matrice a partir d'une matrice.
	 **************************************************************
	 *
	 * Entree:
	 *      pcFileName:     Le chemin du fichier a lire.
	 * Sortie:
	 *      SMatrixInfos:   Les infos de la matrice lue.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `UNSUPPORTED_TYPE_EXCEPTION` si le type de la matrice n'est pas supporté (si différent de double dans notre cas).
	 *      Renvoie une CException avec l'ID `IO_FILE_EXCEPTION` si une erreur de lecture est survenue.
	 */
	static SMatrixInfos PMTXreadFile(char* pcFileName);
	
	/**************************************************************
	 * Renvoi la valeur d'une ligne du ficher (valeur après le =).
	 **************************************************************
	 *
	 * Entree:
	 *      pcLine:     La ligne concernée.
	 * Sortie:
	 *      char *:     Un pointeur sur le premier caractère après le =.
	 * PreCond:
	 * PostCond:
	 */
	static char * PMTXgetLineValue(char * pcLine);
	
	/**************************************************************
	 * Renvoi les valeur contenues sur une ligne du fichier.
	 **************************************************************
	 *
	 * Entree:
	 *      pcLine:         La ligne concernée.
	 *      uiValuesCount:  Le nombre de valeurs a lire.
	 * Sortie:
	 *      double *:       Un tableau des valeurs.
	 * PreCond:
	 * PostCond:
	 *      Renvoi une CException avec l'ID `PARSER_ERROR_EXCEPTION` si le nombre de valeurs lues est différent du nombre attendu.
	 */
	static double * PMTXgetValuesAsDoubleArray(char * pcLine, unsigned int uiValuesCount);
	
	/**************************************************************
	 * Renvoi le type d'une matrice.
	 **************************************************************
	 *
	 * Entree:
	 *      pcLine:         La valeur de la ligne `type=`.
	 * Sortie:
	 *      CMatrixType:    Le type de la matrice.
	 * PreCond:
	 * PostCond:
	 *      Si le type est inconnu, le type ERROR sera renvoyé.
	 */
	static EMatrixType PMTXgetValueAsMType(char * pcLine);
	
	/**************************************************************
	 * Lis une ligne du fichier.
	 **************************************************************
	 *
	 * Entree:
	 *      pcLinePtr:      Un pointeur qui pointera sur la destination du string lu.
	 *      pcLineSize:     Un pointeur qui pointera sur la taille allouée.
	 *      poFILEfile:     Le fichier a lire.
	 * Sortie:
	 *      int:            La longeur de la chaine lue, sans compter le '\0'.
	 * PreCond:
	 * PostCond:
	 *      pcLinePtr:      Pointe sur la ligne lue.
	 *      pcLineSize:     Pointe sur la tailel allouée pour pcLinePtr.
	 *
	 *      Si aucune ligne n'a pu être lue, -1 est renvoyé.
	 */
	static int PMTXgetLine(char ** pcLinePtr, size_t * pcLineSize, FILE * poFILEfile);
	
	/**************************************************************
	 * Lis une ligne non vide du fichier.
	 **************************************************************
	 *
	 * Entree:
	 *      poFILEfile:     Le fichier a lire.
	 * Sortie:
	 *      char *:         La ligne lue.
	 * PreCond:
	 * PostCond:
	 *      Si aucune ligne n'a pu être lue, NULL est renvoyé.
	 */
	static char * PMTXreadLineFromFile(FILE * poFILEfile);
};
#endif
