#ifndef PREOJET3MATRICE_UNITUTILS_H
#define PREOJET3MATRICE_UNITUTILS_H

#include <cstdio>
#include <csignal>
#include <cstdlib>

static void assertError(const char * pcMessage)
{
	perror(pcMessage);
	raise(SIGINT);
	exit(EXIT_FAILURE);
}

#endif
