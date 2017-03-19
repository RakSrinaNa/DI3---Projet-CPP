#include "CMatrix.h"
#include "CSquareMatrix.h"
#include "CMatrixParser.h"

int main(int argc, char* argv[])
{

	CSquareMatrix<double> square = CSquareMatrix<double>(5, "eye");
	
	square.MTXdisplay();

	std::cout << std::endl;
	square.MTXsetValue(0, 0, 1);
	square.MTXsetValue(0, 1, 2);
	square.MTXsetValue(0, 2, 3);
	square.MTXsetValue(0, 3, 4);
	square.MTXsetValue(0, 4, 5);

	square.MTXsetValue(1, 0, 4);
	square.MTXsetValue(1, 1, 5);
	square.MTXsetValue(1, 2, 6);
	square.MTXsetValue(1, 3, 5);
	square.MTXsetValue(1, 4, 6);

	square.MTXsetValue(2, 0, 7);
	square.MTXsetValue(2, 1, 0);
	square.MTXsetValue(2, 2, 10);
	square.MTXsetValue(2, 3, 8);
	square.MTXsetValue(2, 4, -1);

	square.MTXsetValue(3, 0, 7);
	square.MTXsetValue(3, 1, 8);
	square.MTXsetValue(3, 2, -9);
	square.MTXsetValue(3, 3, 8);
	square.MTXsetValue(3, 4, 10);
	
	square.MTXsetValue(4, 0, 7);
	square.MTXsetValue(4, 1, 8);
	square.MTXsetValue(4, 2, 10);
	square.MTXsetValue(4, 3, -7);
	square.MTXsetValue(4, 4, -4);

	square.MTXdisplay();
	
	std::cout << "Det : " << square.SMTXgetDeterminant() << std::endl;

	square.SMTXinverse().MTXdisplay();

	getchar();

	return 0;
}

