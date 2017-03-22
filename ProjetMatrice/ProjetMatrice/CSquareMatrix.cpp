//#include "CSquareMatrix.h"

template <class T>
CSquareMatrix<T>::CSquareMatrix() : CMatrix<T>()
{
}

template <class T>
CSquareMatrix<T>::CSquareMatrix(CSquareMatrix<T> const& oSMTXmatrixParam) : CMatrix<T>(oSMTXmatrixParam)
{

}

template <class T>
CSquareMatrix<T>::CSquareMatrix(CSquareMatrix<T> const& oSMTXmatrixParam, unsigned int uiRowParam, unsigned int uiColumnParam) : CMatrix<T>(oSMTXmatrixParam.MTXgetHeight() - 1, oSMTXmatrixParam.MTXgetWidth() - 1)
{
	unsigned int uiPosition = 0;
	for(unsigned int uiRow = 0; uiRow < oSMTXmatrixParam.MTXgetHeight(); uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < oSMTXmatrixParam.MTXgetWidth(); uiColumn++)
		{
			if(uiRow == uiRowParam || uiColumn == uiColumnParam)
				continue;
			this->ptValues[uiPosition / this->uiHeight][uiPosition % this->uiHeight] = oSMTXmatrixParam.MTXgetValue(uiRow, uiColumn);
			uiPosition++;
		}
}


template <class T>
CSquareMatrix<T>::CSquareMatrix(CMatrix<T> const& oMTXmatrixParam) : CMatrix<T>(oMTXmatrixParam)
{
}

template <class T>
CSquareMatrix<T>::CSquareMatrix(unsigned int uiSize) : CMatrix<T>(uiSize, uiSize)
{
}

template <class T>
CSquareMatrix<T>::CSquareMatrix(unsigned int uiSize, char * pcMethod) : CMatrix<T>(uiSize, uiSize)
{
	if(STRCMPI(pcMethod, "eye") == 0 || STRCMPI(pcMethod, "eyes") == 0)
		for(unsigned int uiRow = 0; uiRow < uiSize; uiRow++)
			this->MTXsetValue(uiRow, uiRow, 1);
}

template <class T>
CSquareMatrix<T>::~CSquareMatrix()
{
}

template <class T>
unsigned int CSquareMatrix<T>::SMTXgetSize()
{
	return this->uiHeight;
}

template <class T>
double CSquareMatrix<T>::SMTXgetDeterminant()
{
	if(this->uiHeight == 1)
		return this->ptValues[0][0];
	else if(this->uiHeight == 2)
		return this->ptValues[0][0] * this->ptValues[1][1] - this->ptValues[1][0] * this->ptValues[0][1];
	else
	{
		double dDeterminant = 0;
		for(unsigned int uiRow = 0; uiRow < this->uiHeight; uiRow++)
		{
			CSquareMatrix<T> oMTXmatrix = CSquareMatrix<T>(*this, uiRow, 0);
			dDeterminant += ((uiRow % 2 == 0 ? 1 : -1) * this->ptValues[uiRow][0] * oMTXmatrix.SMTXgetDeterminant());
		}
		return dDeterminant;
	}
}

template <class T>
CSquareMatrix<T>& CSquareMatrix<T>::SMTXpow(unsigned int power)
{
	if(power == 0)
	{
		CSquareMatrix<T> * poMTXmatrix = new CSquareMatrix<T>(SMTXgetSize(), "eye");
		return *poMTXmatrix;
	}
	return (this->SMTXpow(power - 1) *= (*this));

}

template <class T>
CMatrix<T>& CSquareMatrix<T>::SMTXcomatrix()
{
	CMatrix<T> * poMTXcomatrix = new CSquareMatrix<T>(SMTXgetSize());
	for(unsigned int uiRow = 0; uiRow < this->uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < this->uiWidth; uiColumn++)
		{
			CSquareMatrix<T> oMTXmatrix = CSquareMatrix<T>(*this, uiRow, uiColumn);
			poMTXcomatrix->MTXsetValue(uiRow, uiColumn, (((uiRow + uiColumn) % 2 == 0 ? 1 : -1) * oMTXmatrix.SMTXgetDeterminant()));
		}
	return *poMTXcomatrix;
}

template <class T>
CMatrix<T>& CSquareMatrix<T>::SMTXinverse()
{
	CMatrix<T> * poMTXinverse;
	CMatrix<T> oMTXcomatrix = SMTXcomatrix();
	poMTXinverse = &oMTXcomatrix.MTXtranspose();
	return (*poMTXinverse) /= SMTXgetDeterminant();
}

template <class T>
CSquareMatrix<T>& CSquareMatrix<T>::operator= (CSquareMatrix<T> const& oSMTXmatrixParam)
{
	if (this->uiHeight != oSMTXmatrixParam.MTXgetHeight() || this->uiWidth != oSMTXmatrixParam.MTXgetWidth())
	{
		CException * poCEXexception = new CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix don't have the same size");
		throw poCEXexception;
	}

	for (unsigned int uiRow = 0; uiRow < this->uiHeight; uiRow++)
		for (unsigned int uiColumn = 0; uiColumn < this->uiWidth; uiColumn++)
			this->ptValues[uiRow][uiColumn] = oSMTXmatrixParam.MTXgetValue(uiRow, uiColumn);

	return *this;
}

template <class T>
CSquareMatrix<T>& CSquareMatrix<T>::operator*= (CSquareMatrix<T> const& oSMTXmatrixParam)
{
	CSquareMatrix<T> oSMTXmatrix = CSquareMatrix<T>((*this) * oSMTXmatrixParam);
	(*this) = oSMTXmatrix;
	return *this;
}

template <class T>
CSquareMatrix<T>& CSquareMatrix<T>::operator*= (double dCoefficient)
{
	for(unsigned int uiRow = 0; uiRow < this->uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < this->uiWidth; uiColumn++)
			MTXsetValue(uiRow, uiColumn, this->ptValues[uiRow][uiColumn] * dCoefficient);
	return *this;
}

template <class T>
CSquareMatrix<T>& CSquareMatrix<T>::operator/= (double dCoefficient)
{
	return (*this) *= (1/dCoefficient);
}