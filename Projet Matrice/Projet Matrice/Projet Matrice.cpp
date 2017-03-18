#include "CMatrix.h"
#include "CSquareMatrix.h"
#include "CMatrixParser.h"

int main(int argc, char* argv[])
{

	CSquareMatrix<double> square = CSquareMatrix<double>(3);
	
	std::cout << std::endl;
	square.MTXsetValue(0, 0, 1);
	square.MTXsetValue(0, 1, 2);
	square.MTXsetValue(0, 2, 3);
	square.MTXsetValue(1, 0, 4);
	square.MTXsetValue(1, 1, 5);
	square.MTXsetValue(1, 2, 6);
	square.MTXsetValue(2, 0, 7);
	square.MTXsetValue(2, 1, 8);
	square.MTXsetValue(2, 2, 10);
	square.MTXdisplay();
	
	
	CSquareMatrix<double> square2 = CSquareMatrix<double>(square, 0, 1);
	square2.MTXdisplay();

	std::cout << std::endl << "Det : " << square.SMTXgetDeterminant() << std::endl;
	std::cout << std::endl << "Det2 : " << square2.SMTXgetDeterminant() << std::endl;


	getchar();

	return 0;
}

