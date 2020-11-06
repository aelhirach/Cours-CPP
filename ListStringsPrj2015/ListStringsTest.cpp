//---------------------------------------------------------------------------
// file ListNamesTest.cpp
//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "list.h"
#include "D:\User\Desktop\mattens\syllabus\InOut\src\inout.h"
#include "algo.h"
//-----------------------------------------------------------------------------
const int LONG_MAX_NAME = 80;

using namespace std;
using namespace StructInfoList;
using namespace StructInfoAlgo;
//---------------------------------------------------------------------------
// ... Definition de la classe LenEqual


class LenEqual: public StructInfoAlgo::Predicate {
	public:
	LenEqual(int l);
	bool operator()(const string& name) const;
	private:
	unsigned int len;
};


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void Erreur();
char Menu();
void AfficherListes(const list& l1, const list* pl2, list::const_iterator i1,
                    list::const_iterator i2, list::const_iterator i3);
// ... Declaration des fonctions LenCompare et LexicoCompare
//---------------------------------------------------------------------------

int LenCompare(const string& val1, const string& val2);
int LexicoCompare(const string& val1, const string& val2);

int main() {
	char choix;
	list l1;
	list* pl2=NULL;
	list::iterator i1(l1.begin()), i2(l1.end()), i3;
	list::value_type e1; // !!!

	//-----------------------------------------------------------------------

	while ((choix=Menu())!='0') {
		switch (choix) {
		case '1':
			ShowTitle("Definition de la position p1 dans liste1", '-');
			cout << "Nom ? ";
			cin >> ws >> e1;
			i1=find(l1.begin(), l1.end(), e1);
			break;
		case '2':
			ShowTitle("Definition de la position p2 dans liste1", '-');
			cout << "Nom ? ";
			cin >> ws >> e1;
			i2=find(i1, l1.end(), e1);
			break;
		case '3':
			ShowTitle("Insertion d'un nom devant la position p2 dans liste1",
			          '-');
			cout << "Nom ? ";
			cin >> ws >> e1;
			l1.insert(i2, e1);
			break;
		case '4':
			ShowTitle("Inversion des elements de p1 et p2 dans liste1", '-');
			reverse(i1, i2);
			i1=l1.begin();
			break;
		case '5':
			ShowTitle("Suppression de l'element a la position p1 dans liste1",
			          '-');
			if (i1==i2)
				i2=l1.end();
			if (i1!=l1.end())
				i1=l1.erase(i1); // !!!
			// i1=l1.begin();
			break;
		case '6':
			ShowTitle("Suppression des elements de p1 a p2 dans liste1", '-');
			if (i1!=l1.end())
				i1=l1.erase(i1, i2); // !!!
			// i1=l1.begin();
			break;
		case '7':
			ShowTitle("Tri alphabetique des elements de p1 a p2 dans liste1",
			          '-');
			bubbleSort(i1, i2, LexicoCompare);
			break;
		case '8':
			ShowTitle(
			    "Tri par longueur de nom des elements de p1 a p2 dans liste1",
			    '-');
			bubbleSort(i1, i2, LenCompare);
			break;
		case 'A':
			ShowTitle("Creation de liste2, copie de liste1", '-');
			if (pl2!=NULL)
				delete pl2;
			pl2=new list(l1);
			i3=pl2->end();
			break;
		case 'B':
			ShowTitle("Destruction de liste2", '-');
			if (pl2!=NULL) {
				delete pl2;
				pl2=NULL;
			} else
				Erreur();
			break;
		case 'C':
			ShowTitle("Definition de la position p3 dans liste2", '-');
			if (pl2!=NULL) {
				cout << "Nom ? ";
				cin >> ws >> e1;
				i3=find(pl2->begin(), pl2->end(), e1);
			} else
				Erreur();
			break;
		case 'D':
			ShowTitle(
			    "Insertion des elements de p1 a p2 devant p3 dans liste2",
			    '-');
			if (pl2!=NULL)
				pl2->insert(i3, i1, i2);
			else
				Erreur();
			break;
		case 'E':
			ShowTitle("Affectation de liste1 a liste2", '-');
			if (pl2!=NULL) {
				*pl2=l1;
				i3=pl2->end();
			} else
				Erreur();
			break;
		case 'F':
			ShowTitle(
			    "Insertion des noms de longueur donnee de liste1 devant p3 dans liste2",
			    '-');
			int l=ReadInt("Longueur ? ", 0, LONG_MAX_NAME);
			cout << endl;
			list::iterator i(l1.begin());
			while ((i=find_if(i, l1.end(), LenEqual(l))) != l1.end()) {
				pl2->insert(i3, *i);
				++i;
			}
			break;
		}
		AfficherListes(l1, pl2, i1, i2, i3);
	}
	return 0;
}
//---------------------------------------------------------------------------
char Menu() {
	cout << left;
	ShowTitle("MENU", '=');
	cout << endl;
	cout << setw(40) << "  <1> Determiner p1";
	cout << setw(39) << "  <2> Determiner p2" << endl;
	cout << setw(40) << "  <3> Inserer devant p2";
	cout << setw(39) << "  <4> Inverser p1 -> p2" << endl;
	cout << setw(40) << "  <5> Supprimer p1";
	cout << setw(39) << "  <6> Supprimer p1 -> p2" << endl;
	cout << setw(40) << "  <7> Trier ordre alphabetique p1 -> p2";
	cout << setw(39) << "  <8> Trier longueurs nom p1 -> p2" << endl;
	cout << endl;
	cout << setw(40) << "  <A> Creer copie liste1";
	cout << setw(39) << "  <B> Detruire liste2" << endl;
	cout << setw(40) << "  <C> Determiner p3";
	cout << setw(39) << "  <D> Inserer p1 -> p2 devant p3" << endl;
	cout << setw(40) << "  <E> Affecter liste1 a liste2";
	cout << setw(39) << "  <F> Inserer noms longueur donnee" << endl;
	cout << endl;
	cout << setw(40) << "  <0> Arreter";
	char c = ReadChar("  Votre Choix ? ", "012345678ABCDEF");
	cout << endl;
	return c;
}

void AfficherListes(const list& l1, const list* pl2, list::const_iterator i1,
                    list::const_iterator i2, list::const_iterator i3) {
	ShowTitle("Listes", '-');
	list::const_iterator i;
	cout << "Liste1 (" << setw(3) << l1.size() << " el.)" << endl;
	for (i=l1.begin(); i!=l1.end(); ++i) {
		cout << *i;
		if (i==i1)
			cout << "(p1)";
		if (i==i2)
			cout << "(p2)";
		cout << " \t";
	}
	cout << "END";
	if (i==i1)
		cout << "(p1)";
	if (i==i2)
		cout << "(p2)";
	cout << endl;
	if (!pl2)
		cout << "Liste2 INDEFINIE" << endl;
	else {
		cout << "Liste2 (" << setw(3) << pl2->size() << " el.)" << endl;
		for (i=pl2->begin(); i!=pl2->end(); ++i) {
			cout << *i;
			if (i==i3)
				cout << "(p3)";
			cout << " \t";
		}
		cout << "END";
		if (i==i3)
			cout << "(p3)";
		cout << endl;
	}
}

void Erreur() {
	cerr << "Erreur : liste2 non existante" << endl;
}

// ... Definitions des fonctions LenCompare et LexicoCompare
int LenCompare(const string& val1, const string& val2){
	if (strlen(val1.c_str())==strlen(val2.c_str())){
		return 0;
	}
	else if(strlen(val1.c_str())>strlen(val2.c_str())){
		return 1;
	}
	else return -1;
}
	
int LexicoCompare(const string& val1, const string& val2){
	return strcmp(val1.c_str(),val2.c_str());	
	}

LenEqual::LenEqual(int l){
	len = l;
}

bool LenEqual::operator()(const string& val) const{
	if(strlen(val.c_str()) == len){
		return true;
	}else return false;
}


