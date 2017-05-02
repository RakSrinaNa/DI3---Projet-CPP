#ifndef UTILS
#define UTILS

#include <stdlib.h>
#include <stdio.h>

#define UNUSED(var) (void)(var)

// Malloc utils, to get the memory space and verify it.
#define MALLOC(type, count) (type *) malloc((count) * sizeof(type))
#define MCHECK(pointer, errorMessage) if(!(pointer)){perror("MALLOC ERROR"); if(errorMessage)perror(errorMessage); exit(EXIT_FAILURE);}
#define MMALLOC(pointer, type, count, errorMessage) pointer = MALLOC(type, count); MCHECK(pointer, errorMessage);

// Realloc utils, to get the memory space and verify it.
#define REALLOC(type, pointer, count) (type *) realloc(pointer, (count) * sizeof(type))
#define RCHECK(pointer, errorMessage) if(!(pointer)){perror("REALLOC ERROR"); if(errorMessage)perror(errorMessage); exit(EXIT_FAILURE);}
#define RREALLOC(pointer, type, count, errorMessage) if((count) == 0){free(pointer); (pointer) = nullptr;} else{(pointer) = REALLOC(type, pointer, count); RCHECK(pointer, errorMessage)};

// Define functions for Visual studio or UNIX (else)
#ifdef _MSC_VER
#define STRDUP(str) _strdup(str)
#define STRCMPI(base, test) _strcmpi(base, test)
#define FOPEN(pointer, filename, mode, exceptionID, exceptionMessage) if(fopen_s(&(pointer), filename, mode) != 0){throw CException(exceptionID, (char *) (exceptionMessage));}
#else
#define STRDUP(str) strdup(str)
#define STRCMPI(base, test) strcasecmp(base, test)
#define FOPEN(pointer, filename, mode, exceptionID, exceptionMessage) pointer = fopen(filename, mode); if((pointer) == nullptr){throw CException(exceptionID, (char *) (exceptionMessage));}
#endif

#endif
