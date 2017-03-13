#ifndef TP1_CEXCEPTION_H
#define TP1_CEXCEPTION_H

/**************************************************************
 * Classe représentant une exception, utilisee pour les throw.
 **************************************************************/
class CException
{
	private:
		unsigned int uiEXID;
		char * pcEXMessage;
	
	public:
		/**************************************************************
		 * Constructeur par defaut.
		 **************************************************************
		 *
		 * Entree:
		 * Sortie:
		 * PreCond:
		 * PostCond:
		 */
		CException();
	
	
		/**************************************************************
		 * Constructeur de recopie.
		 **************************************************************
		 *
		 * Entree:
		 *      oEXexception: Une référence sur un objet Cexception
		 * Sortie:
		 * PreCond:
		 * PostCond:
		 */
		CException(CException const& oEXexception);
	
		/**************************************************************
		 * Constructeur de comfort erreurID.
		 **************************************************************
		 *
		 * Entree:
		 *      uiEXIDParam: Le numero de l'erreur.
		 * Sortie:
		 * PreCond:
		 * PostCond:
		 */
		CException(unsigned int uiEXIDParam);
	
		/**************************************************************
		 * Constructeur de comfort erreurID & message.
		 **************************************************************
		 *
		 * Entree:
		 *      uiEXIDParam:        Le numero de l'erreur.
		 *      pcEXMessageParam:   Un message decrivant l'erreur
		 * Sortie:
		 * PreCond:
		 * PostCond:
		 */
		CException(unsigned int uiEXIDParam, char * pcEXMessageParam);
	
		/**************************************************************
		 * Destructeur.
		 **************************************************************
		 *
		 * Entree:
		 * Sortie:
		 * PreCond:
		 * PostCond:
		 */
		~CException();
		
		
		/**************************************************************
		 * Permet d'obtenir le numero de l'erreur.
		 **************************************************************
		 *
		 * Entree:
		 * Sortie: unsigned int etant le numero d'erreur.
		 * PreCond:
		 * PostCond:
		 */
		unsigned int EXlireExceptionID(){return uiEXID;};
	
		/**************************************************************
		* Permet d'obtenir le message d'erreur.
		**************************************************************
		*
		* Entree:
		* Sortie: char * etant le message d'erreur.
		* PreCond:
		* PostCond:
		*/
		char * EXlireExceptionMessage(){return pcEXMessage;};
	
		/**************************************************************
		* Permet de definir le numero de l'erreur.
		**************************************************************
		*
		* Entree:
		*       uiEXIDParam: Le numero d'erreur.
		* Sortie:
		* PreCond:
		* PostCond:
		*/
		void EXecrireExceptionID(unsigned int uiEXIDParam){uiEXID = uiEXIDParam;};
	
		/**************************************************************
		 * Permet de definir le message d'erreur.
		 **************************************************************
		 *
		 * Entree:
		 *      pcEXMessageParam: Le message d'erreur. Une copie en sera faite.
		 * Sortie:
		 * PreCond:
		 * PostCond:
		 */
		void EXecrireExceptionMessage(char * pcEXMessageParam);
	
		/**************************************************************
		 * Redefinition de l'operateur egal.
		 **************************************************************
		 *
		 * Entree:
		 *      oEXexception: Une référence sur un objet Cexception
		 * Sortie:
		 * PreCond:
		 * PostCond:
		 *      Objet actuel ayant des attributs identiques a celui passe en parametre.
		 */
		void operator=(CException &oEXexception);
};

#endif
