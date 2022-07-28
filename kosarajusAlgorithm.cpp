// kosaraju's algorithm for strongly connected components

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
		stack<int> topologicalSort(unordered_map<int,bool> &visited){
			stack<int> s;
			for(auto i : adj){
				int node = i.first;
				if(!visited[node]){
					topoSort(node, visited, s);
				}
			}
			return s;
		}
		
		unordered_map<int, vector<int>> transpose(){
			unordered_map<int, vector<int>> newAdj;
			for(auto i : adj){
				for(auto j : i.second){
					newAdj[j].push_back(i.first);
				}
			}
			return newAdj;
		}
		
		void revDfs(int node, unordered_map<int, vector<int>> newAdj, unordered_map<int,bool> &visited){
			visited[node] = 1;
			for(auto neighbour : newAdj[node]){
				if(!visited[neighbour]){
					revDfs(neighbour, newAdj, visited);
				}
			}
		}
		
		void kosaraju(){
			unordered_map<int,bool> visited;
			// step 1
			stack<int> s = topologicalSort(visited);
			// step 2
			unordered_map<int, vector<int>> newAdj;
			newAdj = transpose();
			// step 3
			for(auto i : visited) visited[i.first]=0;
			int count = 0;
			while(!s.empty()){
				int top = s.top();
				s.pop();
				if(!visited[top]){
					count++;
					revDfs(top, newAdj, visited);
				}
			}
			cout<<"count of strongly connected components "<<count;
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
	g.kosaraju();
	return 0;
}
