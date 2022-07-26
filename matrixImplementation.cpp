// adjacency matrix representation of graph

#include <bits/stdc++.h>
#define n 4
using namespace std;

class Graph{
	public:
		int edges[n][n];
		
		Graph(){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					edges[i][j]=0;
				}
			}
    	}
		
		void addEdge(int u, int v, bool direction){
			edges[u][v] = 1;
			if(direction == 0){
				edges[v][u] = 1;
			}
		}
		
		void printGraph(){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					cout<<edges[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};

int main(int argc, char** argv) {
	Graph g;
	g.addEdge(0,1,0);
	g.addEdge(0,2,0);
	g.addEdge(1,3,0);
	g.addEdge(2,3,0);
	g.addEdge(1,2,0);
	g.printGraph();
	return 0;
}
