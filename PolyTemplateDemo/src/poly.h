// Fichier poly.h
//---------------------------------------------------------------------------
#ifndef polyH
#define polyH
//---------------------------------------------------------------------------
#include <iostream>
#include <stdlib.h>
#include <math.h>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
const int DEGRE_DEFAUT = 10;
const double EPSILON = 1e-18; // un double de valeur absolue
// <= EPSILON est considéré nul.
/*
 L'opérateur [] utilisé avec un indice i supérieur au degré du polynôme
 mais inférieur ou égal au degré maximum entraîne la mise à 1.0
 du coefficient du terme de degré i (le polynôme aura donc le degré i).
 L'opérateur [] utilisé avec un indice i supérieur au degré maximum du
 polynôme entraîne un arrêt du programme.
 L'opérateur [] ne peut pas être utilisé pour mettre à 0 le coefficient
 du terme du degré du polynôme : il faut utiliser la fonction Zero().
 */

template<class T> class TPoly;
template<class T> ostream& operator<<(ostream& os, const TPoly<T>& poly);
template<class T> istream& operator>>(istream& is, TPoly<T>& poly);

template<class T> class TPoly {
public:
	TPoly(unsigned t = DEGRE_DEFAUT); // t doit être > 0
	TPoly(const TPoly& poly);
	~TPoly();
	TPoly& operator=(const TPoly& poly2);
	TPoly& operator+=(const TPoly& poly2);
	TPoly& operator-=(const TPoly& poly2);
	unsigned Degre() const;
	bool EstNul(unsigned i) const;
	unsigned Zero(unsigned i);
	const T& operator[](unsigned i) const;
	T& operator[](unsigned i);
	T operator()(T x) const;
	TPoly operator+(const TPoly& poly2) const;
	TPoly operator-(const TPoly& poly2) const;
	const TPoly& operator+() const;
	TPoly operator-() const;
private:
	T* pCoeff;
	unsigned degre;
	unsigned degre_max;
	friend ostream& operator<<<T>(ostream& os,const TPoly<T>& poly);
	friend istream& operator>><T>(istream& is,TPoly<T>& poly);
};
//---------------------------------------------------------------------------
template<class T>
TPoly<T>::TPoly(unsigned t) :
	pCoeff(0), degre(0), degre_max(t) {
	pCoeff = new T[degre_max + 1];
	pCoeff[0] = 0.0;
}
//---------------------------------------------------------------------------
template<class T>
TPoly<T>::TPoly(const TPoly& poly) :
	pCoeff(0), degre(poly.degre), degre_max(poly.degre_max) {
	pCoeff = new T[degre_max + 1];
	degre = poly.degre;
	T *p1, *p2;
	for (p1 = pCoeff, p2 = poly.pCoeff; p2 <= poly.pCoeff + poly.degre; ++p1, ++p2)
		*p1 = *p2;
}
//---------------------------------------------------------------------------
template<class T>
TPoly<T>::~TPoly() {
	delete[] pCoeff;
}
//---------------------------------------------------------------------------
template<class T>
TPoly<T>& TPoly<T>::operator=(const TPoly& poly2) {
	if ((this!=&poly2) && (degre_max>=poly2.degre)) {
		degre = poly2.degre;
		T *p1,*p2;
		for (p2=poly2.pCoeff,p1=pCoeff; p2<=poly2.pCoeff+poly2.degre; ++p1,++p2)
			*p1 = *p2;
	}
	return *this;
}
//---------------------------------------------------------------------------
template<class T>
TPoly<T>& TPoly<T>::operator+=(const TPoly& poly2) {
	unsigned i;
	if (degre==poly2.degre) {
		unsigned degre_nouv = 0;
		for (i=0; i<=degre; ++i)
			if (fabs(pCoeff[i]+=poly2.pCoeff[i])> EPSILON) degre_nouv = i;
		degre = degre_nouv;
	} else if (degre<poly2.degre) {
		for (i=0; i<=degre; ++i) pCoeff[i]+=poly2.pCoeff[i];
		for (; i<=poly2.degre && i<=degre_max; ++i) pCoeff[i]=poly2.pCoeff[i];
		degre = i-1;
	} else {
		for (i=0; i<=poly2.degre; ++i) pCoeff[i]+=poly2.pCoeff[i];
	}
	return *this;
}
//---------------------------------------------------------------------------
template<class T>
TPoly<T>& TPoly<T>::operator-=(const TPoly& poly2) {
	unsigned i;
	if (degre==poly2.degre) {
		unsigned degre_nouv = 0;
		for (i=0; i<=degre; ++i)
			if (fabs(pCoeff[i]-=poly2.pCoeff[i])> EPSILON) degre_nouv = i;
		degre = degre_nouv;
	} else if (degre<poly2.degre) {
		for (i=0; i<=degre; ++i) pCoeff[i]-=poly2.pCoeff[i];
		for (; i<=poly2.degre && i<=degre_max; ++i) pCoeff[i]=-poly2.pCoeff[i];
		degre = i-1;
	} else {
		for (i=0; i<=poly2.degre; ++i) pCoeff[i]-=poly2.pCoeff[i];
	}
	return *this;
}
//---------------------------------------------------------------------------
template<class T>
unsigned TPoly<T>::Degre() const {
	return degre;
}
//---------------------------------------------------------------------------
template<class T>
bool TPoly<T>::EstNul(unsigned i) const {
	if (i > degre)
		return true;
	else if (fabs(pCoeff[i]) <= EPSILON)
		return true;
	return false;
}
//---------------------------------------------------------------------------
template<class T>
unsigned TPoly<T>::Zero(unsigned i) {
	if (i < degre)
		pCoeff[i] = 0.0;
	else if (i == degre) {
		pCoeff[degre] = 0.0;
		if (degre > 0)
			--degre;
		for (; degre > 0 && fabs(pCoeff[degre]) <= EPSILON; --degre)
			;
	}
	return degre;
}
//---------------------------------------------------------------------------
template<class T>
const T& TPoly<T>::operator[](unsigned i) const {
	if (i>degre_max) exit(1);
	if (i>degre) pCoeff[i] = 0.0;
	return pCoeff[i];
}
//---------------------------------------------------------------------------
template<class T>
T& TPoly<T>::operator[](unsigned i) {
	if (i>degre_max) exit(1);
	if (i>degre) {
		for (unsigned j=degre+1; j<i; ++j) pCoeff[j]=0.0;
		pCoeff[i] = 1.0;
		degre = i;
	}
	return pCoeff[i];
}
//---------------------------------------------------------------------------
template<class T>
T TPoly<T>::operator()(T x) const {
	T v = pCoeff[0],px=1.0;
	for (unsigned i=1; i<=degre; ++i) {
		px*=x;
		v+=pCoeff[i]*px;
	}
	return v;
}
//---------------------------------------------------------------------------
template<class T>
TPoly<T> TPoly<T>::operator+(const TPoly& poly2) const {
	if (poly2.degre<=degre)
		return (TPoly<T>(*this)+=poly2);
	else {
		return (TPoly<T>(poly2)+=*this);
	}
}
//---------------------------------------------------------------------------
template<class T>
TPoly<T> TPoly<T>::operator-(const TPoly& poly2) const {
	if (poly2.degre<=degre)
		return (TPoly<T>(*this)-=poly2);
	else {
		return (TPoly<T>(poly2)-=*this);
	}
}
//---------------------------------------------------------------------------
template<class T>
const TPoly<T>& TPoly<T>::operator+() const {
	return (*this);
}
//---------------------------------------------------------------------------
template<class T>
TPoly<T> TPoly<T>::operator-() const {
	TPoly pt(*this);
	for (T* p=pt.pCoeff; p<=pt.pCoeff+degre; ++p) *p = -*p;
	return pt;
}
//---------------------------------------------------------------------------

template<class T>
ostream& operator<<(ostream& os, const TPoly<T>& poly) {
	T* p;
	unsigned i;
	for (p = poly.pCoeff, i = 0; i <= poly.degre; ++p, ++i)
		if (fabs(*p) <= EPSILON)
			os << "+0*x^" << i;
		else if (*p > EPSILON)
			os << "+" << *p << '*' << "x^" << i;
		else
			os << "-" << fabs(*p) << '*' << "x^" << i;
	return os;
}

//---------------------------------------------------------------------------
template<class T>
istream& operator>>(istream& is, TPoly<T>& poly) {
	poly.degre = 0;
	unsigned d, deg = 0;
	char c = '+';
	do {
		is >> poly.pCoeff[deg];
		if (c == '-')
			poly.pCoeff[deg] = -poly.pCoeff[deg];
		c = is.get();
		if (c != '*')
			is.clear(ios::failbit);
		c = is.get();
		if (c != 'x')
			is.clear(ios::failbit);
		c = is.get();
		if (c != '^')
			is.clear(ios::failbit);
		is >> d;
		if (d != deg)
			is.clear(ios::failbit);
		if (is) {
			if (fabs(poly.pCoeff[deg]) > EPSILON)
				poly.degre = deg;
			c = is.get();
		}
		++deg;
	} while (is && (c == '+' || c == '-') && poly.degre < poly.degre_max);
	return is;
}
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
