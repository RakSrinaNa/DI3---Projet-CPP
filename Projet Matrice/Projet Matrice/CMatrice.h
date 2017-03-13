
template <T> class CMatrix
{
protected :
	unsigned int uiHeight;
	unsigned int uiWidth;
	T[][] ptBody;

public:
	CMatrix();
	CMatrix(CMatrix const&);
	CMatrix(unsigned int, unsigned int);
	~CMatrix();

	unsigned int MTXgetHeight() {return uiHeight;};
	unsigned int MTXgetWidth() {return uiWidth;};
	inline T MTWgetValue (unsigned int, unsigned int);

	inline void MTXsetValue(unsigned int, unsigned int, T);

	void MTXdisplay();


};