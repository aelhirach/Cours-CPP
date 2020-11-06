//---------------------------------------------------------------------------
#include "graph.h"
#include "vector"
# include <iostream>
using namespace std;
//---------------------------------------------------------------------------
class TWork {
private:
	// TODO
	TWork(const TGraph& _graph, int _begin, int _end, TPath& _path, double _length);
	~TWork();
	void DoWork();
    int begin;
    int end;
   /// reference members 
   const TGraph& graph;
   TPath& path;
    double bestLength;
	friend bool ComputeShortestPath(const TGraph& _graph, int _begin, int _end, TPath& _path, double& _length);
};
//---------------------------------------------------------------------------
// TODO definitions for TDest
    TDest::TDest(int n): pValues(0) { }
    TDest::TDest(): pValues(0) {}
	TDest::~TDest() {
        delete[] pValues;
    }
     double& TDest::operator[](int j) {
			return pValues[j];
		}
    const double& TDest::operator[](int j) const {
			return pValues[j];
     }
    
// TODO definitions for TGraph  //---------------------------------------------------------------------------
    TGraph::TGraph(int n) : dim(n) , ppDest(0){
		ppDest = new TDest [n];
        for (int i = 0; i < n; ++i) {
					ppDest[i].pValues = new double[n]; //
                    for (int j =0; j<n; ++j) {
                            if (i==j) 	ppDest[i].pValues[j]=0;
                            else ppDest[i].pValues[j]= INFINITY;
                        }
                    }
        }
	TGraph::~TGraph() {
            delete[] ppDest;
        }
	int TGraph::Dim() const {
        return dim;
        }
    TDest& TGraph::operator[](int i) {
        return ppDest[i];
        }
	const TDest& TGraph::operator[](int i) const {
        return ppDest[i];
        }
   
//---------------------------------------------------------------------------
// TODO definitions for TPath
    TPath::TPath(int _lengthMax) : lengthMax( _lengthMax ) {
           length = 0;
           pNodes = new int[lengthMax];
            for (int i = 0; i < lengthMax; ++i)
                    pNodes[i] = -1;
        }
	TPath::TPath(const TPath& _path) : length(_path.length), lengthMax(_path.lengthMax) {
           pNodes = new int[lengthMax];
           for (int i = 0; i < lengthMax; ++i)
                    pNodes[i] = _path.pNodes[i];
        }
	TPath::~TPath(){
        delete [] pNodes;
        }
	TPath& TPath::operator=(const TPath& _path){
        if (this != &_path){
           lengthMax = _path.lengthMax;
           length = _path.length;
           pNodes = new int[lengthMax];
           for (int i = 0; i < lengthMax; ++i)
                pNodes[i] = _path.pNodes[i];
            }
        return *this;
        }
	int TPath::LengthMax() const{ 
        return lengthMax;
        }
	int TPath::Length() const{ return length;}
	bool TPath::Add(int _s){ 
         if (length==lengthMax) 
             return false; 
        pNodes[length]=_s;
        ++length;
        return true; 
        
        }
	bool TPath::Remove(){
        if (length==0) 
                    return false;
        pNodes[length]=-1;
                --length;
            return true; 
        }
	void TPath::Erase() {  
                while (Remove());
               /* for (int i = 0; i < lengthMax; ++i)
               Remove(); */
        }
    int TPath::Last() const{return  pNodes[length]; }
	int& TPath::operator[](int _i){
            return pNodes[_i];
        }
	const int& TPath::operator[](int _i) const{   
            return pNodes[_i];
        }
//---------------------------------------------------------------------------
// TODO definitions for TWork
TWork::TWork(const TGraph& _graph, int _begin, int _end, TPath& _path, double _length) :
   graph(_graph),  path(_path), bestLength(_length), begin (_begin), end(_end) 
{ }
TWork::~TWork() {
}
void TWork::DoWork() {
    path.Erase();
    int V = graph.Dim(); 
     double dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
     int pathIndex [V]; 
     bool isPicked[V]; // isPicked[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
     // Initialize all distances as INFINITE and isPicked[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INFINITY, isPicked[i] = false, pathIndex[i]=-1;
     
     // Distance of source vertex from itself is always 0
     dist[begin] = 0;
     pathIndex[begin]=0;
     // Find shortest path for all vertices
     for (int iter = 0; iter < V; iter++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. v is always equal to src in first iteration.
       
       double min = INFINITY;
       int min_index;
            for (int v = 0; v < V; v++)
                if (isPicked[v] == false && dist[v] <= min)
                    min = dist[v], min_index = v;
       
        if (min_index== end) break; 
        
       // Mark the picked vertex as processed
       
       isPicked[min_index] = true;
     
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++){
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!isPicked[v] && graph[min_index][v] && dist[min_index] != INFINITY && dist[min_index]+graph[min_index][v] < dist[v]) {
            dist[v] = dist[min_index] + graph[min_index][v];
             pathIndex[v]= min_index;
         }
         }

     }
  
  bestLength = dist[end];
   int value = end;
    while(value!=begin){
        path.Add(pathIndex[value]) ;
        value = pathIndex[value];
    }
  int n =  path.Length(); 
  for (int i=0; i<n/2;++i)
    {   int temp = path[i];
        path[i]= path[n-i-1];
        path[n-i-1]=temp; 
     }
     path.Add(end);
      
 }
//---------------------------------------------------------------------------
bool ComputeShortestPath(const TGraph& _graph, int _begin, int _end, TPath& _path, double& _length) {
	if (_begin >= _graph.Dim() || _end >= _graph.Dim() || _path.LengthMax() < _graph.Dim())
		return false;
	TWork t(_graph, _begin, _end, _path, _length);
	t.DoWork();
	_length = t.bestLength;
	if (_length < INFINITY)
		return true;
	else
		return false;
}
//---------------------------------------------------------------------------

