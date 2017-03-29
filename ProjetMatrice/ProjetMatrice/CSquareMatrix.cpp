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
	unsigned int uiPosition = 0; //Va parcourir les cases de la NOUVELLE matrice
	for(unsigned int uiRow = 0; uiRow < oSMTXmatrixParam.MTXgetHeight(); uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < oSMTXmatrixParam.MTXgetWidth(); uiColumn++)
		{
			if(uiRow == uiRowParam || uiColumn == uiColumnParam) //On ne considère pas la ligne (resp. colonne) s'il s'agit de la ligne (resp. colonne) que l'on veut exclure
				continue;
			this->ptValues[uiPosition / this->uiHeight][uiPosition % this->uiHeight] = oSMTXmatrixParam.MTXgetValue(uiRow, uiColumn); //Recopie dans la matrice en cours (avec uiPosition) les valeurs de celle en paramètre (avec uiRow et uiColumn)
			uiPosition++;
		}
}


template <class T>
CSquareMatrix<T>::CSquareMatrix(CMatrix<T> const& oMTXmatrixParam) : CMatrix<T>(oMTXmatrixParam)
{
	if(oMTXmatrixParam.MTXgetHeight() != oMTXmatrixParam.MTXgetWidth())
		throw CException(INCOMPATIBLE_MATRIX_EXCEPTION, "Not a square matrix");
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
			this->MTXsetValue(uiRow, uiRow, 1); //Affecte 1 à toutes les cases de la diagonale
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
		return this->ptValues[0][0]; //S'il s'agit d'une matrice 1;1 on renvoie son unique valeur
	else if(this->uiHeight == 2)
		return this->ptValues[0][0] * this->ptValues[1][1] - this->ptValues[1][0] * this->ptValues[0][1]; //S'il s'agit d'une matrice 2;2 on calcul et renvoie son déterminant
	else
	{
		//S'il s'agit d'une matrice de taille supérieure à 2
		double dDeterminant = 0;
		for(unsigned int uiRow = 0; uiRow < this->uiHeight; uiRow++)
		{
			// Pour chaque valeur de la première colonne, on calcul son déterminant par calcul du mineur
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
		CSquareMatrix<T> * poMTXmatrix = new CSquareMatrix<T>(SMTXgetSize(), (char *)"eye"); //Toute matrice à la puissance 0 renvoie l'identité
		return *poMTXmatrix;
	}
	return (this->SMTXpow(power - 1) *= (*this)); //Multiplication de la matrice actuelle par la matrice à la puisance power-1 par appel récursif de la méthode
}

template <class T>
CSquareMatrix<T>& CSquareMatrix<T>::SMTXcomatrix()
{
	CSquareMatrix<T> * poMTXcomatrix = new CSquareMatrix<T>(SMTXgetSize()); //Créé une nouvelle matrice
	for(unsigned int uiRow = 0; uiRow < this->uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < this->uiWidth; uiColumn++)
		{
			CSquareMatrix<T> oMTXmatrix = CSquareMatrix<T>(*this, uiRow, uiColumn);
			poMTXcomatrix->MTXsetValue(uiRow, uiColumn, (((uiRow + uiColumn) % 2 == 0 ? 1 : -1) * oMTXmatrix.SMTXgetDeterminant())); //Calcul et affecte à chaque case de la nouvelle matrice son cofacteur
		}
	return *poMTXcomatrix;
}

template <class T>
CSquareMatrix<T>& CSquareMatrix<T>::SMTXtranspose()
{
	CSquareMatrix<T> * poSMTXtrans = new CSquareMatrix(this->uiWidth); //Créé une nouvelle matrice
	for(unsigned int uiRow = 0; uiRow < this->uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < this->uiWidth; uiColumn++)
			poSMTXtrans->MTXsetValue(uiColumn, uiRow, this->MTXgetValue(uiRow, uiColumn)); //Recopie dans la nouvelle matrice les valeurs de l'originale en inversant lignes et colonnes
	
	return *poSMTXtrans;
}

template <class T>
CSquareMatrix<T>& CSquareMatrix<T>::SMTXinverse()
{
	CSquareMatrix<T> * poMTXinverse;
	CSquareMatrix<T> oMTXcomatrix = SMTXcomatrix(); //Calcul de la comatrie
	poMTXinverse = &oMTXcomatrix.SMTXtranspose(); //Transposée de la comatrice
	double dDet = SMTXgetDeterminant();
	if(dDet == 0)
		throw CException(NOT_INVERSIBLE_EXCEPTION, "Matrix not inversible");
	return (*poMTXinverse) /= SMTXgetDeterminant(); //Multiplication par l'inverse du déterminant
}

template <class T>
CSquareMatrix<T>& CSquareMatrix<T>::operator= (CSquareMatrix<T> const& oSMTXmatrixParam)
{
	if (this->uiHeight != oSMTXmatrixParam.MTXgetHeight() || this->uiWidth != oSMTXmatrixParam.MTXgetWidth())
		throw CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix don't have the same size");

	for (unsigned int uiRow = 0; uiRow < this->uiHeight; uiRow++)
		for (unsigned int uiColumn = 0; uiColumn < this->uiWidth; uiColumn++)
			this->ptValues[uiRow][uiColumn] = oSMTXmatrixParam.MTXgetValue(uiRow, uiColumn); //Recopie dans chaque case de la nouvelle matrice la valeur de la case correspondante de la matrice passée en paramètre

	return *this;
}

template <class T>
CSquareMatrix<T>& CSquareMatrix<T>::operator*= (CSquareMatrix<T> const& oSMTXmatrixParam)
{
	CSquareMatrix<T> oSMTXmatrix = CSquareMatrix<T>((*this) * oSMTXmatrixParam); //Multiplication des matrices par appel au constructeur
	if (this->uiHeight != oSMTXmatrix.MTXgetHeight() || this->uiWidth != oSMTXmatrix.MTXgetWidth())
		throw CException(INCOMPATIBLE_MATRIX_EXCEPTION, (char *) "The two matrix don't have the same size");
	(*this) = oSMTXmatrix; //Affection de la somme précèdement calculée dans la matrice en cours
	return *this;
}

template <class T>
CSquareMatrix<T>& CSquareMatrix<T>::operator*= (double dCoefficient)
{
	for(unsigned int uiRow = 0; uiRow < this->uiHeight; uiRow++)
		for(unsigned int uiColumn = 0; uiColumn < this->uiWidth; uiColumn++)
			this->MTXsetValue(uiRow, uiColumn, this->ptValues[uiRow][uiColumn] * dCoefficient); //Affecte à chaque case sa valeur multipliée par le coefficient passé en paramètre
	return *this;
}

template <class T>
CSquareMatrix<T>& CSquareMatrix<T>::operator/= (double dCoefficient)
{
	if(dCoefficient == 0)
		throw CException(DIVISION_BY_ZERO_EXCEPTION, "Division by zero");
	return (*this) *= (1/dCoefficient); //Appel de l'opérateur *= avec l'inverse du coefficient passé en paramètre
}