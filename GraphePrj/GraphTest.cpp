# include <iostream>
# include <iomanip>
#include "graph.h"
#include <stack>
#include<conio.h>
#include<stdlib.h>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
TGraph* CreateGraph1(int dim);
TGraph* CreateGraph2(int dim);
TGraph* CreateGraph3(int dim);
TGraph* CreateGraph4(int dim);
void ShowGraph(const TGraph& graph);
void ShowPath(const TGraph& graph, const TPath& path, double length);
bool FindNewPath(void);
void Dfs(const TGraph& graph, int  root, TPath& achievableVertex, bool visited[] );
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
        //////// ////////////////// Graphe 1 circulaire   /////////////// 
	TGraph* pGraph;
    pGraph= CreateGraph1(1000);
	TPath achievableVertex(pGraph->Dim()-1);  
	int start, V;
    V= pGraph->Dim();
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
	do {
		cout <<  "Sommet de départ : ";
		cin >> start;
        } while(start<0 || start >V);
        Dfs(*pGraph,start,achievableVertex,visited);
         for (int i=0; i<achievableVertex.Length() ; i++) cout << achievableVertex[i] << " ";
         
     cout << endl; 

	delete pGraph;
    delete visited; 
    achievableVertex.Erase();
    
    //////// ////////////////// Graphe 2 circulaire avec un sommet coupé  /////////////// 
    pGraph = CreateGraph2(1000);
    V= pGraph->Dim();
     visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
	do {
		cout <<  "Sommet de départ : ";
		cin >> start;
        } while(start<0 || start >V);
        Dfs(*pGraph,start,achievableVertex,visited);
        for (int i=0; i<achievableVertex.Length() ; i++) cout << achievableVertex[i] << " ";
     cout << endl; 
	delete pGraph;
    delete visited; 
    achievableVertex.Erase();
    
    //////// ////////////////// Graphe dense  /////////////// 
    pGraph = CreateGraph3(1000);
  
    V= pGraph->Dim();
     visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
	do {
		cout <<  "Sommet de départ : ";
		cin >> start;
        } while(start<0 || start >V);
        Dfs(*pGraph,start,achievableVertex,visited);
        for (int i=0; i<achievableVertex.Length() ; i++) cout << achievableVertex[i] << " ";
    cout << endl; 
	delete pGraph;
    delete visited; 
    achievableVertex.Erase();
    
    //////// ////////////////// Graphe 4 dense avec un sommet coupé  /////////////// 
    pGraph = CreateGraph4(1000);
    V= pGraph->Dim();
     visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
	do {
		cout <<  "Sommet de départ : ";
		cin >> start;
        } while(start<0 || start >V);
        Dfs(*pGraph,start,achievableVertex,visited);
        for (int i=0; i<achievableVertex.Length() ; i++) cout << achievableVertex[i] << " ";
        cout << endl; 
    /////////////////// 
	return 0;
}
//---------------------------------------------------------------------------
TGraph* CreateGraph1(int dim) {
	
	TGraph* pGraph = new TGraph(dim);
	double d;
    for (int i=1; i<dim; ++i) 
         {  d = rand() % 10+ 1;
            (*pGraph)[i-1][i] = d;
            if (i==(dim-1))  (*pGraph)[dim-1][0] = d;
         }
	return pGraph;
}

TGraph* CreateGraph2(int dim) {
	TGraph* pGraph = new TGraph(dim);
	double d;
    for (int i=1; i<dim; ++i) 
         {   
             d = rand() % 10+ 1;
             (*pGraph)[i-1][i] = d;
             if (i==100)  (*pGraph)[i-1][i] = INFINITY; 
         }
	return pGraph;
}

TGraph* CreateGraph3(int dim) {
	TGraph* pGraph = new TGraph(dim);
	double d1,d2;
    for (int i=1; i<dim; ++i) 
         {   
             for (int j=0;j<dim;++j) {
                  if (i !=j) {
                        d1 = rand() % 10+ 1;
                        d2 = rand() % 10+ 1;
                        (*pGraph)[i-1][j] = d1;
                        (*pGraph)[j][i-1] = d2;
                        }
                  }
         }
        
	return pGraph;
}

TGraph* CreateGraph4(int dim) {
	TGraph* pGraph = new TGraph(dim);
	double d1,d2;
    for (int i=1; i<dim; ++i) 
         {   
             for (int j=0;j<dim;++j) {
                  if (i !=j) {
                        d1 = rand() % 10+ 1;
                        d2 = rand() % 10+ 1;
                        (*pGraph)[i-1][j] = d1;
                        (*pGraph)[j][i-1] = d2;
                        }
                  }
         }
        for (int i=0; i<dim; ++i) 
            (*pGraph)[i][300] = INFINITY; 
	return pGraph;
}
//---------------------------------------------------------------------------
void ShowGraph(const TGraph& graph) {

	cout << "   |";
	for (int i = 0; i < graph.Dim(); ++i) {
		cout << "    " << "s" << i;
	}

	cout << endl << "---+";
	for (int i = 0; i < graph.Dim(); ++i) {
		cout << "------";
	}
	cout << endl;

	for (int i = 0; i < graph.Dim(); ++i) {
		cout << "s" << setw(1) << i << " |";
		for (int j = 0; j < graph.Dim(); ++j)
			if (graph[i][j] < INFINITY)
				cout << setw(6) << graph[i][j];
			else
				cout << setw(6) << ".";
		cout << endl;
	}
}
//---------------------------------------------------------------------------
void ShowPath(const TGraph& graph, const TPath& path, double length) {
	if (length == INFINITY)
		cout << "Aucun chemin n'a été trouvé!" << endl;
	else {
		cout << "Un chemin de longueur " << length << " a été trouvé: ";
		int s = 0;
		double len = 0.0;
		for (int i = 0, sPrec = path[0]; i < path.Length(); ++i) {
			s = path[i];
			len += graph[sPrec][s];
			if (i != 0)
				cout << " ,";
			cout << " " << s << " (" << len << ")";
			sPrec = s;
		}
		cout << endl;
	}
}
//---------------------------------------------------------------------------
bool FindNewPath(void) {
	char findAnother;
	do {
		cout << endl
				<< "Voulez-vous rechercher un autre chemin (<O>ui/<N>on) ? ";
		cin >> findAnother;
		findAnother = (char) toupper(findAnother);
	} while ((findAnother != 'O') && (findAnother != 'N'));
	return (findAnother == 'O');
}
//---------------------------------------------------------------------------
void Dfs(const TGraph& graph, int  root, TPath& achievableVertex, bool visited[] )
        {
                visited[root]=true;
                int n = graph.Dim();
                for (int i=0; i<n; ++i) {
                    double childCost = graph [root][i];
                    if (!visited[i] && childCost !=INFINITY)
                    {    
                        achievableVertex.Add(i);
                        Dfs(graph,i,achievableVertex,visited);
                    }
                }

        } 