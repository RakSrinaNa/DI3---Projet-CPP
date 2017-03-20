#ifndef PREOJET3MATRICE_CUNIT_H
#define PREOJET3MATRICE_CUNIT_H

#include <cstdio>
#include <csignal>
#include <cstdlib>

class CUnit
{
public:
	static void UNITlaunchTests();
	static void UNITassertError(const char * pcMessage);
};

#endif
