#include "CMatrix.h"
#include "CSquareMatrix.h"
#include "CMatrixParser.h"

int main(int argc, char* argv[])
{
	char * file = (char *) "M1.txt";
	CMatrix<double> matrix = CMatrix<double>(2, 2);

	matrix.MTXsetValue(0, 0, 1);
	matrix.MTXsetValue(0, 1, 2);
	matrix.MTXsetValue(1, 0, 3);
	matrix.MTXsetValue(1, 1, 4);
	
	matrix.MTXdisplay();

	std::cout << std::endl;

	CMatrix<double> matrix2 = matrix.MTXtranspose();
	matrix2.MTXdisplay();
	
	std::cout << std::endl;
	(matrix + matrix2).MTXdisplay();
	
	std::cout << std::endl;
	(matrix - matrix2).MTXdisplay();
	
	std::cout << std::endl;
	(matrix * 2).MTXdisplay();
	
	std::cout << std::endl;
	(matrix / 2).MTXdisplay();
	
	std::cout << std::endl;
	(matrix * matrix2).MTXdisplay();

	CSquareMatrix<double> square = CSquareMatrix<double>(3);
	
	std::cout << std::endl;
	square.MTXsetValue(0, 0, 1);
	square.MTXsetValue(1, 1, 2);
	square.MTXsetValue(2, 2, 6);
	square.MTXdisplay();
	
	std::cout << std::endl << "Det : " << square.SMTXgetDeterminant() << std::endl;;


	getchar();

	return 0;
}

