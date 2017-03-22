//#include "CMatrix.h"

template <class T>
CMatrix<T>::CMatrix() : uiHeight(1), uiWidth(1)
{
	MMALLOC(ptValues, T*, uiHeight, "CMatrix constructor"); //Allocation des lignes
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
	{
		MMALLOC(ptValues[uiRow], T, uiWidth, "CMatrix constructor"); //Allocation des cases (colonnes) sur toutes les lignes
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			ptValues[uiRow][uiColumn] = 0; //Met toutes les cases � 0
	}
}

template <class T>
CMatrix<T>::CMatrix(CMatrix<T> const& oMTXmatrixParam) : uiHeight(oMTXmatrixParam.MTXgetHeight()), uiWidth(oMTXmatrixParam.MTXgetWidth())
{
	MMALLOC(ptValues, T*, uiHeight, "CMatrix constructor"); //Allocation des lignes
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
	{
		MMALLOC(ptValues[uiRow], T, uiWidth, "CMatrix constructor"); //Allocation des cases (colonnes) sur toutes les lignes
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			ptValues[uiRow][uiColumn] = 0;
	}

	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			ptValues[uiRow][uiColumn] = oMTXmatrixParam.MTXgetValue(uiRow, uiColumn); //Recopie les valeurs dans toutes les cases
}

template <class T>
CMatrix<T>::CMatrix(unsigned int uiHeightParam, unsigned int uiWidthParam) : uiHeight(uiHeightParam), uiWidth(uiWidthParam)
{
	if(uiHeight == 0 || uiWidth == 0)
		throw CException(IMPOSSIBLE_MATRIX_SIZE_EXCEPTION, (char *) "At least one of the dimensions was 0");

	MMALLOC(ptValues, T*, uiHeight, "CMatrix constructor"); //Allocation des lignes
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
	{
		MMALLOC(ptValues[uiRow], T, uiWidth, "CMatrix constructor"); //Allocation des cases (colonnes) sur toutes les lignes
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			ptValues[uiRow][uiColumn] = 0; //Met toutes les cases � 0
	}
}

template <class T>
CMatrix<T>::~CMatrix()
{
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		free(ptValues[uiRow]); //Lib�re toutes les cases
	free(ptValues); //Lib�re toutes les lignes
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
		throw oEXPexception = new CException(OUT_OF_RANGE_EXCEPTION, (char *) "Coordinate is out of matrix");
	return ptValues[uiRow][uiColumn]; //Retourne la valeur dans la case de la ligne et de la colonne demand�es
}

template <class T>
void CMatrix<T>::MTXsetValue(unsigned int uiRow, unsigned int uiColumn, T tValueParam)
{
	if(uiRow >= uiHeight || uiColumn >= uiWidth)
		throw oEXPexception = new CException(OUT_OF_RANGE_EXCEPTION, (char *) "Coordinate is out of matrix");
	ptValues[uiRow][uiColumn] = uiValueParam; //Modifie la valeur dans la case de la ligne et de la colonne demand�es par la valeur donn�e
}

template <class T>
void CMatrix<T>::MTXdisplay()
{
	std::cout << " __" << std::endl;
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
	{
		std::cout << "| ";
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			std::cout << ptValues[uiRow][uiColumn] << "\t"; //Affiche toutes les cases
		std::cout << "\n";
	}
}

template <class T>
CMatrix<T>& CMatrix<T>::MTXtranspose()
{
	CMatrix<T> * poMTXtrans = new CMatrix(MTXgetWidth(), MTXgetHeight()); //Cr�� une nouvelle matrice
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			poMTXtrans->MTXsetValue(uiColumn, uiRow, MTXgetValue(uiRow, uiColumn)); //Recopie dans la nouvelle matrice les valeurs de l'originale en inversant lignes et colonnes

	return *poMTXtrans;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator+(CMatrix<T> const& oMTXmatrixParam)
{
	if(uiHeight != oMTXmatrixParam.MTXgetHeight() || uiWidth != oMTXmatrixParam.MTXgetWidth())
		throw oEXPexception = new CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix don't have the same size");

	CMatrix<T> * poMTXsum = new CMatrix(MTXgetHeight(), MTXgetWidth()); //Cr�� une nouvelle matrice
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			poMTXsum->MTXsetValue(uiRow, uiColumn, MTXgetValue(uiRow, uiColumn) + oMTXmatrixParam.MTXgetValue(uiRow, uiColumn)); //Recopie dans chaque case de la nouvelle matrice les sommes de chaque case des deux matrices

	return *poMTXsum;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator-(CMatrix<T> const& oMTXmatrixParam)
{
	if(uiHeight != oMTXmatrixParam.MTXgetHeight() || uiWidth != oMTXmatrixParam.MTXgetWidth())
		throw CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix don't have the same size");

	CMatrix<T> * poMTXsub = new CMatrix(MTXgetHeight(), MTXgetWidth()); //Cr�� une nouvelle matrice
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			poMTXsub->MTXsetValue(uiRow, uiColumn, MTXgetValue(uiRow, uiColumn) - oMTXmatrixParam.MTXgetValue(uiRow, uiColumn)); //Recopie dans chaque case de la nouvelle matrice les diff�rences de chaque case des deux matrices

	return *poMTXsub;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*(double dCoefficient)
{
	CMatrix<T> * poMTXtimes = new CMatrix(*this); //Cr�� une nouvelle matrice
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			poMTXtimes->MTXsetValue(uiRow, uiColumn, MTXgetValue(uiRow, uiColumn) * dCoefficient); //Recopie dans chaque case de la nouvelle matrice les produits des valeurs de la matrice originale par le coefficient pass� en param�tre

	return *poMTXtimes;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*(CMatrix<T> const& oMTXmatrixParam)
{
	if(uiWidth != oMTXmatrixParam.MTXgetHeight())
		throw CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix are incompatible for multiplication");

	CMatrix<T> * poMTXtimes = new CMatrix(uiHeight, oMTXmatrixParam.MTXgetWidth()); //Cr�� une nouvelle matrice

	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
		{
			T dSum = 0;
			for(unsigned int uiTimes = 0; uiTimes < uiWidth; uiTimes++)
				dSum += ptValues[uiRow][uiTimes] * oMTXmatrixParam.MTXgetValue(uiTimes, uiColumn); //Calcul le produit d'une ligne par une colonne d'apr�s le matrice matriciel standard
			poMTXtimes->MTXsetValue(uiRow, uiColumn, dSum); //Affecte la valeur pr�c�dement calcul�e dans chaque case
		}

	return *poMTXtimes;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator/(double dCoefficient)
{
	if(dCoefficient == 0)
		throw CException(DIVISION_BY_ZERO_EXCEPTION, (char *) "Division by zero");
	return (*this) * (1/dCoefficient); //Appel l'op�rateur de multiplication avec l'inverse du coefficient demand�
}

template <class T>
CMatrix<T>& CMatrix<T>::operator=(CMatrix<T> const& oMTXmatrixParam)
{
	if (uiHeight != oMTXmatrixParam.MTXgetHeight() || uiWidth != oMTXmatrixParam.MTXgetWidth())
		throw CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix don't have the same size");

	for (unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for (unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			ptValues[uiRow][uiColumn] = oMTXmatrixParam.MTXgetValue(uiRow, uiColumn); //Recopie chaque valeur de la matrice pass�e en param�tre dans la matrice en cours

	return *this;
}

template <class T>
bool CMatrix<T>::operator==(CMatrix<T> const& oMTXmatrixParam)
{
	if(uiHeight != oMTXmatrixParam.MTXgetHeight() || uiWidth != oMTXmatrixParam.MTXgetWidth()) //V�rifie que les matrices sont de m�me taille
		return false;
	
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			if(ptValues[uiRow][uiColumn] != oMTXmatrixParam.MTXgetValue(uiRow, uiColumn)) //V�rifie que chaque case d'une matrice est �gale � son homologue dans l'autre matrice
				return false;

	return true;
}

template <class T>
const T* const CMatrix<T>::operator[](unsigned int uiRow)
{
	if(uiRow >= uiHeight)
		throw CException(OUT_OF_RANGE_EXCEPTION, (char *) "Coordinate is out of matrix");

	return ptValues[uiRow]; //Renvoie la ligne demand�e
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*=(double dCoefficient)
{
	for(unsigned int uiRow = 0; uiRow < uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < uiWidth; uiColumn++)
			MTXsetValue(uiRow, uiColumn, ptValues[uiRow][uiColumn] * dCoefficient); //Affecte � chaque case sa valeur d'origine multipli�e par le coefficient pass� en param�tre
	return *this;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator/=(double dCoefficient)
{
	if(dCoefficient == 0)
		throw CException(DIVISION_BY_ZERO_EXCEPTION, (char *) "Division by zero");
	return (*this) *= (1/dCoefficient); //Appel l'op�rateur *= avec l'inverse du coefficient pass� en param�tre
}