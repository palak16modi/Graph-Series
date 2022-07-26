// detect cycle in directed graph using DFS

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
		
		bool isCyclicDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){
		 	visited[node] = true;
		 	dfsVisited[node] = true;
		 	
		 	for(auto neighbour: edges[node]){
		 		if(!visited[neighbour]){
		 			bool isCyclic = isCyclicDFS(neighbour, visited, dfsVisited);
		 			if(isCyclic) return true;
				 }
				 else if(dfsVisited[neighbour]){
				 	return true;
				 }
			 }
			 dfsVisited[node] = false;
			 return false;
		 }
		
		bool detectCycle(int n){
			unordered_map<int, bool> visited;
			unordered_map<int, bool> dfsVisited;
			for(int i=0; i<n; i++){
				if(!visited[i]){
					bool cycleFound = isCyclicDFS(i, visited, dfsVisited);
					if(cycleFound) return true;
				}
			}
			return false;
		}
};

int main(int argc, char** argv) {
	Graph g;
	int n,m,d;
	cout<<"enter number of nodes";
	cin>>m;
	cout<<"enter number of edges ";
	cin>>n;
	int u,v;
	cout<<"is directed graph(0/1)? ";
	cin>>d;
	for(int i=0; i<n; i++){
		cin>>u>>v;
		g.addEdge(u,v,d);
	}
	g.printGraph();
	bool cycleDetect = g.detectCycle(m);
	if(cycleDetect) cout<<"cycle detected"<<endl;
	else cout<<"cycle not detected"<<endl;
	return 0;
}

