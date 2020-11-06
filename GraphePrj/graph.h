#ifndef GRAPH_H_
#define GRAPH_H_
//---------------------------------------------------------------------------
const double INFINITY = 10e100;
//---------------------------------------------------------------------------
/// on déclare TGraph car TDest a besoin de TGraph et TGraph a besoin de TDest ( besoin ciculaire)
class TGraph;
//---------------------------------------------------------------------------
class TDest {
	//TODO
public:
    TDest(); 
	TDest(int n);
	~TDest();
    double& operator[](int j);           
    const double& operator[](int j) const; 
    private : 
        double* pValues;
		friend class TGraph;
};

//---------------------------------------------------------------------------

class TGraph {
public:
    //TGraph& operator=(const TGraph& m);
	TGraph(int n);
	~TGraph();
	int Dim() const;
    TDest& operator[](int i);
	const TDest& operator[](int i) const; 

private:
	int dim;
	TDest* ppDest;

};

//---------------------------------------------------------------------------
class TPath {
public:
	TPath(int _lengthMax);
	TPath(const TPath& _path);
	~TPath();
	TPath& operator=(const TPath& _path);
	int LengthMax() const;
	int Length() const;
	void Erase();
	bool Add(int _s);
	bool Remove();
	int Last() const;
	int& operator[](int _i);
	const int& operator[](int _i) const;
private:
	int* pNodes;
	int lengthMax;
	int length;
};
//---------------------------------------------------------------------------
bool ComputeShortestPath(const TGraph& _graph, int _start, int _end, TPath& _path,
		double& _length);
//---------------------------------------------------------------------------
#endif /*GRAPH_H_*/
