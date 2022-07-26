// DFS on graph

#include <bits/stdc++.h>
using namespace std;

class Graph{
	public:
		map<int, vector<int>> edges;
		addEdge(int u, int v, bool direction){
			edges[u].push_back(v);
			if(direction == 0){
				edges[v].push_back(u);
			}
		}
		printGraph(){
			for(auto e: edges){
				cout<<e.first<<" -> ";
				for(auto t: e.second){
					cout<<t<<", ";
				}
				cout<<endl;
			}
		}
		void solve(int node, unordered_map<int,int> &vis){
			vis[node] = 1;
			cout<<node<<" ";
			for(auto neighbour : edges[node]){
				if(vis[neighbour] == 0){
					solve(neighbour, vis);
				}
			}
		}
		void printDFS(){
			cout<<"DFS: ";
			unordered_map<int,int> vis;
			for(auto i : edges){
				int j = i.first;
				if(vis[j] == 0) solve(j, vis);
			}	
		}
};

int main(int argc, char** argv) {
	Graph g;
	int n;
	cout<<"enter number of edges ";
	cin>>n;
	int u,v;
	for(int i=0; i<n; i++){
		cin>>u>>v;
		g.addEdge(u,v,0);
	}
	g.printGraph();
	g.printDFS();
	return 0;
}

