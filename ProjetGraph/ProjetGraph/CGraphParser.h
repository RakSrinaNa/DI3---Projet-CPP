#ifndef CGRAPHPARSER
#define CGRAPHPARSER

#define IO_FILE_EXCEPTION 4890
#define MALFORMATTED_FILE_EXCEPTION 4891
#define PARSER_ERROR_EXCEPTION 4894

#include <cstdio>
#include <cstdlib>
#include "CGraph.h"

class CGraphParser
{
public:
	/**************************************************************
	 * Lis une matrice a partir d'une fichier.
	 **************************************************************
	 *
	 * Entree:
	 *      pcFileName:     Le chemin du fichier a lire.
	 * Sortie:
	 *      CGraph:         Le graph lu.
	 * PreCond:
	 * PostCond:
	 *      Renvoie une CException avec l'ID `IO_FILE_EXCEPTION` si une erreur de lecture est survenue.
	 *      Renvoie une CException avec l'ID `MALFORMATTED_FILE_EXCEPTION` si le fichier est mal formatte.
	 */
	static CGraph * PGRAreadGraph(char * pcFileName);
	
private:
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
	 *      Renvoie une CException avec l'ID `MALFORMATTED_FILE_EXCEPTION` si aucun = n'est trouve.
	 */
	static char * PGRAgetLineValue(char * pcLine);
	
	/**************************************************************
	 * Renvoi la clef d'une ligne du ficher (valeur avant le =) dupliquee sur le tas.
	 **************************************************************
	 *
	 * Entree:
	 *      pcStart:    Le debut de la ligne.
	 *      pcEnd:      La position du signe =;
	 * Sortie:
	 *      char *:     Un string sur le tas representant la clef.
	 * PreCond:
	 * PostCond:
	 */
	static char * PGRAgetLineKey(char * pcStart, char * pcEnd);
	
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
	static int PGRAgetLine(char ** pcLinePtr, size_t * pcLineSize, FILE * poFILEfile);
	
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
	static char * PGRAreadLineFromFile(FILE * poFILEfile);
	
	static char ** PGRASplit(char cSeparator, unsigned int * puiSize, void * pcString);
};
#endif
