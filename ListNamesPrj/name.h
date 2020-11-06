//-----------------------------------------------------------------------------
// File name.h
//-----------------------------------------------------------------------------
#ifndef NAME_H_
#define NAME_H_
//-----------------------------------------------------------------------------
#include <fstream> 
//-----------------------------------------------------------------------------
const int LONG_MAX_NAME = 80;
//-----------------------------------------------------------------------------
class TName {
public:
	TName();
	TName(const TName& name);
	~TName();
	const char* Name() const;
	TName& operator=(const TName& name);
	bool operator==(const TName& name) const;
	bool operator<(const TName& name) const;
private:
	char* pName;
	friend std::ostream& operator<<(std::ostream& os, const TName& name);// !!!
	friend std::istream& operator>>(std::istream& is, TName& name); // !!!
};
//-----------------------------------------------------------------------------
#endif /*NAME_H_*/
//-----------------------------------------------------------------------------