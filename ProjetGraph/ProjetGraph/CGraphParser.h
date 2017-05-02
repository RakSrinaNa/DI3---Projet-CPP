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
	
	/**************************************************************
	 * Renvoie un tableau de clef/valeur.
	 **************************************************************
	 *
	 * Entree:
	 *      pcSeparators:   Un string representant une liste des separateurs.
	 *      puiSize:        Un pointeur sur un entier qui contiendra la taille du tableau.
	 *      pcString:       Le string a decouper.
	 * Sortie:
	 *      char**:         Un tableau de string contenant les clefs/valeurs.
	 * PreCond:
	 * PostCond:
	 *      puiSize contient la taille du tableau retourne.
	 */
	static char ** PGRAsplit(char * pcSeparators, unsigned int * puiSize, char * pcString);
	
	/**************************************************************
	 * Rogne le string.
	 **************************************************************
	 *
	 * Entree:
	 *      pcString:   Le string a rogner.
	 * Sortie:
	 *      char*:      Le string rogne.
	 * PreCond:
	 *      pcString non null.
	 * PostCond:
	 */
	static char * PGRAtrim(char * pcString);
	
	/**************************************************************
	 * Decoupe une portion d'un string jusqu'a un delimiteur.
	 **************************************************************
	 *
	 * Entree:
	 *      ppcNextString:  Un pointeur sur le string a decouper.
	 *      pcDelims:       Un string contenant les delimiteurs.
	 * Sortie:
	 *      char*:          Un pointeur sur le debut du string jusqu'au prochain delimiteur.
	 * PreCond:
	 * PostCond:
	 *      ppcNextString contient un pointeur sur le string apres le delimiteur, ou null si le string ne contenait pas de delimiteur.
	 *      La valeur pointee par ppcNextString est modifiee.
	 *      Le retour pointe sur une partie du string contenu dans ppcNextString, a ne pas desalouer.
	 */
	static char * PGRAstrsep(char ** ppcNextString, const char * pcDelims);
};

#endif
