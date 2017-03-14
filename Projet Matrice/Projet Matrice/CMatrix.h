#ifndef C_MATRIX_H
#define C_MATRIX_H

#define OUT_OF_RANGE_EXCEPTION 89714
#define DIVISION_BY_ZEO_EXCEPTION 89715

template <class T>
class CMatrix
{
protected:
	unsigned int uiHeight;
	unsigned int uiWidth;
	T** ptValues;

public:
	CMatrix();
	CMatrix(CMatrix const& oMTXmatrixParam);
	CMatrix(unsigned int uiHeightParam, unsigned int uiWidthParam);
	~CMatrix();

	unsigned int MTXgetHeight();
	unsigned int MTXgetWidth();
	T MTXgetValue(unsigned int uiRow, unsigned int uiColumn);
	
	void MTXsetValue(unsigned int uiRow, unsigned int uiColumn, T uiValueParam);

	void MTXdisplay();
	CMatrix& MTXtranspose();
	
	CMatrix& operator+(CMatrix const& oMTXmatrixParam);
	CMatrix& operator-(CMatrix const& oMTXmatrixParam);
	CMatrix& operator*(CMatrix const& oMTXmatrixParam);
	CMatrix& operator*(double iCoeficient);
	CMatrix& operator/(double iCoeficient);
	CMatrix& operator=(CMatrix const& oMTXmatrixParam);
	bool operator==(CMatrix const& oMTXmatrixParam);
};
#endif
