// Topological sort in a graph using DFS

#include <bits/stdc++.h>
using namespace std;

class Graph{
	public:
		unordered_map<int, vector<int>> adj;
		void addEdges(int u, int v){
			adj[u].push_back(v);
		}
		void topoSort(int node, unordered_map<int,bool> &visited, stack<int> &s){
			visited[node] = 1;
			for(auto neighbour: adj[node]){
				if(!visited[neighbour]){
					topoSort(neighbour, visited, s);
				}
			}
			s.push(node);
		}
		void topologicalSort(int v){
			unordered_map<int,bool> visited;
			stack<int> s;
			for(auto i : adj){
				int node = i.first;
				if(!visited[node]){
					topoSort(node, visited, s);
				}
			}
			vector<int> ans;
			while(!s.empty()){
				ans.push_back(s.top());
				s.pop();
			}
			for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
		}
};

int main(int argc, char** argv) {
	Graph g;
	int n,m,u,v;
	cout<<"enter number of nodes ";
	cin>>n;
	cout<<"enter number of edges ";
	cin>>m;
	cout<<"enter edges"<<endl;
	for(int i=0; i<m; i++){
		cin>>u>>v;
		g.addEdges(u,v);
	}
	g.topologicalSort(n);
	return 0;
}
