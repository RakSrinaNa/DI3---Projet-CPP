#include "CMatrix.h"
#include "CMatrixParser.h"

int main(int argc, char* argv[])
{
	char * file = "M1.txt";
	CMatrix<double> matrix = CMatrixParser::PMTXreadFile<double>(file);
	matrix.MTXdisplay();
	return 0;
}

