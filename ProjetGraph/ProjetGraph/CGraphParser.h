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
	 * Return the value of a line from the file (value after the =).
	 **************************************************************
	 *
	 * Input:
	 *      pcLine:     The line to process.
	 * Output:
	 *      char *:     A pointer on the character after the =.
	 * PreCond:
	 * PostCond:
	 *      Throws a CException with the ID `MALFORMATTED_FILE_EXCEPTION` if no = were found.
	 */
	static char * PGRAgetLineValue(char * pcLine);
	
	/**************************************************************
	 * Return the key of a line from the file (value before the =) duplicated on the heap.
	 **************************************************************
	 *
	 * Input:
	 *      pcStart:    Le beginning of the line.
	 *      pcEnd:      The position of the =.
	 * Output:
	 *      char*:      A new string on the heap representing the key.
	 * PreCond:
	 * PostCond:
	 */
	static char * PGRAgetLineKey(char * pcStart, char * pcEnd);
	
	/**************************************************************
	 * Read a line from the file.
	 **************************************************************
	 *
	 * Input:
	 *      pcLinePtr:      A pointer that will point on the read string.
	 *      pcLineSize:     A pointer that will point on the allocated size.
	 *      poFILEfile:     The file to read.
	 * Output:
	 *      int:            The size of the string read, without taking into account the '\0'.
	 * PreCond:
	 * PostCond:
	 *      pcLinePtr:      Point on the read string.
	 *      pcLineSize:     Point on the size allocated for pcLinePtr.
	 *
	 *      If no line has been read, -1 is returned.
	 */
	static int PGRAgetLine(char ** pcLinePtr, size_t * pcLineSize, FILE * poFILEfile);
	
	/**************************************************************
	 * Read a line from the line until a non empty one is found.
	 **************************************************************
	 *
	 * Input:
	 *      poFILEfile:     The file to read.
	 * Output:
	 *      char *:         The read line.
	 * PreCond:
	 * PostCond:
	 *      If no line could have been read, NULL is returned.
	 */
	static char * PGRAreadLineFromFile(FILE * poFILEfile);
	
	/**************************************************************
	 * Return an array of key/value.
	 **************************************************************
	 *
	 * Input:
	 *      pcSeparators:   A string which represent a list of the different separators.
	 *      puiSize:        A pointer to an int that will contain the array size.
	 *      pcString:       The string to split.
	 * Output:
	 *      char**:         An array containing the key/value.
	 * PreCond:
	 * PostCond:
	 *      puiSize contains the size of the returned array.
	 */
	static char ** PGRAsplit(char * pcSeparators, unsigned int * puiSize, char * pcString);
	
	/**************************************************************
	 * Trim a string.
	 **************************************************************
	 *
	 * Input:
	 *      pcString:   The string to trim.
	 * Output:
	 *      char*:      The trimmed string.
	 * PreCond:
	 *      pcString not null.
	 * PostCond:
	 */
	static char * PGRAtrim(char * pcString);
	
	/**************************************************************
	 * Cut a string until a delimiter is found.
	 **************************************************************
	 *
	 * Input:
	 *      ppcNextString:  A pointer to the next string.
	 *      pcDelims:       A string containing the delimiters.
	 * Output:
	 *      char*:          A pointer to the beginning of the string until the delimiter.
	 * PreCond:
	 * PostCond:
	 *      ppcNextString contains a pointer on the string after the delimiter, or null if the string doesn't contain any delimiter.
	 *      The value pointed by ppcNextString is modified.
	 *      What is pointed by the returned value is a part of ppcNextString, do not free it until you want to use the extracted value.
	 */
	static char * PGRAstrsep(char ** ppcNextString, const char * pcDelims);
};

#endif
