//
// Created by Thomas Couchoud on 17/03/2017.
//

#include <cstring>
#include "CMatrixParserUnit.h"
#include "UnitUtils.h"
#include "../CMatrix.h"
#include "../CMatrixParser.h"

void CMatrixParserUnit::MTXPUnitTests()
{
	CMatrix<double> * poMTXmatrix = CMatrixParser::PMTXreadFile((char *) "M1.txt");
}
