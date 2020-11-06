//-----------------------------------------------------------------------------
// File name.cpp
//-----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string.h>
#include "inout.h"
#include "name.h"
//-----------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------
// TODO ...
TName::TName():pName(0){
	//pName = 0; => mieux d'utiliser construction par defaut
	//Attention au dimenssionnement du tableau pname...
}

TName::TName(const TName& name){
	pName = new char[strlen(name.Name())+1];
	strcpy(pName, name.Name()); 
}

TName::~TName(){
	delete[] pName;
}

const char* TName::Name() const{
	return pName;
}

TName& TName::operator=(const TName& name){
	if(&name != this){
		delete[] pName;
		pName = new char[strlen(name.Name())+1];
		strcpy(pName, name.Name());
		return *this;
	}
	else{
		return *this;
	}
}

bool TName::operator==(const TName& name) const{
	if(strcmp(Name(),name.Name()) == 0){
		return true;
	}else{
		return false;
	}
}

bool TName::operator<(const TName& name) const{
	if(strcmp(Name(),name.Name()) < 0){
		return true;
	}else return false;
}

std::ostream& operator<<(std::ostream& os, const TName& name){
	return os << name.Name();
}

std::istream& operator>>(std::istream& is, TName& name){
	char tabtemp[LONG_MAX_NAME+1];
	is.getline(tabtemp, LONG_MAX_NAME+1);
	cout << (void*)name.pName;
	delete[] name.pName;
	name.pName = new char[strlen(tabtemp)+1];
	strcpy(name.pName, tabtemp);
	return is;
}

//-----------------------------------------------------------------------------

