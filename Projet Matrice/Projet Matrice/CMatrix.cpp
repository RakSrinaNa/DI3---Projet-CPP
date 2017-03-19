//#include "CMatrix.h"

template <class T>
CMatrix<T>::CMatrix() : CMatrix<T>(1, 1)
{
}

template <class T>
CMatrix<T>::CMatrix(CMatrix<T> const& oMTXmatrixParam) : uiHeight(oMTXmatrixParam.MTXgetHeight()), uiWidth(oMTXmatrixParam.MTXgetWidth())
{
	MMALLOC(ptValues, T*, uiHeight, "CMatrix constructor");
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
	{
		MMALLOC(ptValues[uiRow], T, uiWidth, "CMatrix constructor");
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			ptValues[uiRow][uiColumn] = 0;
	}

	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			ptValues[uiRow][uiColumn] = oMTXmatrixParam.MTXgetValue(uiRow, uiColumn);
}

template <class T>
CMatrix<T>::CMatrix(unsigned int uiHeightParam, unsigned int uiWidthParam) : uiHeight(uiHeightParam), uiWidth(uiWidthParam)
{
	MMALLOC(ptValues, T*, uiHeight, "CMatrix constructor");
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
	{
		MMALLOC(ptValues[uiRow], T, uiWidth, "CMatrix constructor");
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			ptValues[uiRow][uiColumn] = 0;
	}
}

template <class T>
CMatrix<T>::~CMatrix()
{
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		free(ptValues[uiRow]);
	free(ptValues);
}

template <class T>
inline unsigned int CMatrix<T>::MTXgetHeight() const
{
	return uiHeight;
}

template <class T>
inline unsigned int CMatrix<T>::MTXgetWidth() const
{
	return uiWidth;
}

template <class T>
inline T CMatrix<T>::MTXgetValue(unsigned int uiRow, unsigned int uiColumn) const
{
	if(uiRow >= uiHeight || uiColumn >= uiWidth)
	{
		CException * poCEXexception = new CException(OUT_OF_RANGE_EXCEPTION, (char *) "Coordinate is out of matrix");
		throw poCEXexception;
	}
	return ptValues[uiRow][uiColumn];
}

template <class T>
void CMatrix<T>::MTXsetValue(unsigned int uiRow, unsigned int uiColumn, T uiValueParam)
{
	if(uiRow >= uiHeight || uiColumn >= uiWidth)
	{
		CException * poCEXexception = new CException(OUT_OF_RANGE_EXCEPTION, (char *) "Coordinate is out of matrix");
		throw poCEXexception;
	}
	ptValues[uiRow][uiColumn] = uiValueParam;
}

template <class T>
void CMatrix<T>::MTXdisplay()
{
	std::cout << " __" << std::endl;
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
	{
		std::cout << "| ";
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			std::cout << ptValues[uiRow][uiColumn] << "\t";
		std::cout << "\n";
	}
}

template <class T>
CMatrix<T>& CMatrix<T>::MTXtranspose()
{
	CMatrix<T> * poMTXtrans = new CMatrix(MTXgetWidth(), MTXgetHeight());
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			poMTXtrans->MTXsetValue(uiColumn, uiRow, MTXgetValue(uiRow, uiColumn));

	return *poMTXtrans;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator+(CMatrix<T> const& oMTXmatrixParam)
{
	if(uiHeight != oMTXmatrixParam.MTXgetHeight() || uiWidth != oMTXmatrixParam.MTXgetWidth())
	{
		CException * poCEXexception = new CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix don't have the same size");
		throw poCEXexception;
	}

	CMatrix<T> * poMTXsum = new CMatrix(MTXgetHeight(), MTXgetWidth());
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			poMTXsum->MTXsetValue(uiRow, uiColumn, MTXgetValue(uiRow, uiColumn) + oMTXmatrixParam.MTXgetValue(uiRow, uiColumn));

	return *poMTXsum;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator-(CMatrix<T> const& oMTXmatrixParam)
{
	if(uiHeight != oMTXmatrixParam.MTXgetHeight() || uiWidth != oMTXmatrixParam.MTXgetWidth())
	{
		CException * poCEXexception = new CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix don't have the same size");
		throw poCEXexception;
	}

	CMatrix<T> * poMTXsub = new CMatrix(MTXgetHeight(), MTXgetWidth());
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			poMTXsub->MTXsetValue(uiRow, uiColumn, MTXgetValue(uiRow, uiColumn) - oMTXmatrixParam.MTXgetValue(uiRow, uiColumn));

	return *poMTXsub;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*(double iCoeficient)
{
	CMatrix<T> * poMTXtimes = new CMatrix(*this);
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			poMTXtimes->MTXsetValue(uiRow, uiColumn, MTXgetValue(uiRow, uiColumn) * iCoeficient);

	return *poMTXtimes;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*(CMatrix<T> const& oMTXmatrixParam)
{
	if(uiWidth != oMTXmatrixParam.MTXgetHeight())
	{
		std::cout << uiWidth << "\t" << oMTXmatrixParam.MTXgetHeight() << std::endl;
		CException * poCEXexception = new CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix are incompatible for multiplication");
		throw * poCEXexception;
	}

	CMatrix<T> * poMTXtimes = new CMatrix(uiHeight, oMTXmatrixParam.MTXgetWidth());

	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
		{
			T dSum = 0;
			for(unsigned int uiTimes = 0; uiTimes < uiWidth; uiTimes++)
				dSum += ptValues[uiRow][uiTimes] * oMTXmatrixParam.MTXgetValue(uiTimes, uiColumn);
			poMTXtimes->MTXsetValue(uiRow, uiColumn, dSum);
		}

	return *poMTXtimes;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator/(double iCoeficient)
{
	if(iCoeficient == 0)
	{
		CException * poCEXexception = new CException(DIVISION_BY_ZEO_EXCEPTION, (char *) "Division par zero");
		throw poCEXexception;
	}
	return (*this) * (1/iCoeficient);
}

template <class T>
CMatrix<T>& CMatrix<T>::operator=(CMatrix<T> const& oMTXmatrixParam)
{
	if (uiHeight != oMTXmatrixParam.MTXgetHeight() || uiWidth != oMTXmatrixParam.MTXgetWidth())
	{
		CException * poCEXexception = new CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix don't have the same size");
		throw poCEXexception;
	}

	for (unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for (unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			ptValues[uiRow][uiColumn] = oMTXmatrixParam.MTXgetValue(uiRow, uiColumn);

	return *this;
}

template <class T>
bool CMatrix<T>::operator==(CMatrix<T> const& oMTXmatrixParam)
{
	if(uiHeight != oMTXmatrixParam.MTXgetHeight() || uiWidth != oMTXmatrixParam.MTXgetWidth())
		return false;
	
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			if(ptValues[uiRow][uiColumn] != oMTXmatrixParam.MTXgetValue(uiRow, uiColumn))
				return false;

	return true;
}

template <class T>
T* CMatrix<T>::operator[](unsigned int uiRow)
{
	if(uiRow >= uiHeight)
	{
		CException * poCEXexception = new CException(OUT_OF_RANGE_EXCEPTION, (char *) "Coordinate is out of matrix");
		throw poCEXexception;
	}

	return ptValues[uiRow];
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*=(double iCoeficient)
{
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			MTXsetValue(uiRow, uiColumn, ptValues[uiRow][uiColumn] * iCoeficient);
	return *this;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator/=(double iCoeficient)
{
	return (*this) *= (1/iCoeficient);
}