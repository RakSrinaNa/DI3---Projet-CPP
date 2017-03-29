#include "iostream"
#include "tests/CUnit.h"
#include "CMatrix.h"
#include "CSquareMatrix.h"
#include "CMatrixParser.h"
#include "utils.h"

int main(int argc, char* argv[])
{
	if(argc == 1)
		CUnit::UNITlaunchTests();
	else
	{
		CMatrix<double> ** ppoMTXmatrices;
		MMALLOC(ppoMTXmatrices, CMatrix<double> *, argc-1, "MALLOC ERROR MAIN");

		//Lire les matrices
		try
		{
			for(unsigned int uiIndex = 1; uiIndex < argc; uiIndex++)
				ppoMTXmatrices[uiIndex-1] = CMatrixParser::PMTXreadMatrix(argv[uiIndex]);
		}
		catch(CException const & oEXexception)
		{
			std::cout << oEXexception.EXgetExceptionMessage();
			exit(EXIT_FAILURE);
		}
		
		//Lire un coefficient
		double dValue;
		std::cout << "Entrez le coefficient: ";
		std::cin >> dValue;

		//Produit des matrices par le coefficient
		for(unsigned int uiIndex = 1; uiIndex < argc; uiIndex++)
			(*ppoMTXmatrices[uiIndex-1] * dValue).MTXdisplay();

		//Division des matrices par le coefficient
		try
		{
			for(unsigned int uiIndex = 1; uiIndex < argc; uiIndex++)
				(*ppoMTXmatrices[uiIndex-1] / dValue).MTXdisplay();
		}
		catch(CException const & oEXexception)
		{
			std::cout << oEXexception.EXgetExceptionMessage();
			exit(EXIT_FAILURE);
		}

		//Somme de toutes les matrices
		try
		{
			CMatrix<double> oMTXmatrixSum = *ppoMTXmatrices[0];
			for(unsigned int uiIndex = 2; uiIndex < argc; uiIndex++)
				oMTXmatrixSum = oMTXmatrixSum + *ppoMTXmatrices[uiIndex-1];
			oMTXmatrixSum.MTXdisplay();
		}
		catch(CException const & oEXexception)
		{
			std::cout << oEXexception.EXgetExceptionMessage();
			exit(EXIT_FAILURE);
		}

		//Somme alternée de toutes les matrices
		try
		{
			CMatrix<double> oMTXmatrixSum = *ppoMTXmatrices[0];
			for(unsigned int uiIndex = 2; uiIndex < argc; uiIndex++)
			{
				if(uiIndex%2 == 0)
					oMTXmatrixSum = oMTXmatrixSum - *ppoMTXmatrices[uiIndex-1];
				else
					oMTXmatrixSum = oMTXmatrixSum + *ppoMTXmatrices[uiIndex-1];
			}
			oMTXmatrixSum.MTXdisplay();
		}
		catch(CException const & oEXexception)
		{
			std::cout << oEXexception.EXgetExceptionMessage();
			exit(EXIT_FAILURE);
		}

		//Produit de toutes les matrices
		try
		{
			CMatrix<double> oMTXmatrixProd = *ppoMTXmatrices[0];
			for(unsigned int uiIndex = 2; uiIndex < argc; uiIndex++)
				oMTXmatrixProd = oMTXmatrixProd * *ppoMTXmatrices[uiIndex-1];
			oMTXmatrixProd.MTXdisplay();
		}
		catch(CException const & oEXexception)
		{
			std::cout << oEXexception.EXgetExceptionMessage();
			exit(EXIT_FAILURE);
		}

		//Nettoyage de toutes les matrices
		for(unsigned int uiIndex = 1; uiIndex < argc; uiIndex++)
			free(ppoMTXmatrices[uiIndex-1]);
		free(ppoMTXmatrices);

	}

#ifdef _MSC_VER
	getchar();
#endif

	return 0;
}
