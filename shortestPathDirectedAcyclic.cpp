// shortest path in a directed acyclic graph

#include <bits/stdc++.h>
using namespace std;

class Graph{
	public:
		unordered_map<int, vector<pair<int,int>>> adj;
		void addEdge(int u, int v, int weight){
			pair<int, int> p = make_pair(v, weight);
			adj[u].push_back(p);
		}
		
		void printAdj(){
			for(auto i : adj){
				cout<<i.first<<"->";
				for(auto j : i.second){
					cout<<"["<<j.first<<" "<<j.second<<"] ";
				}
				cout<<endl;
			}
		}
		
		void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s){
			visited[node] = 1;
			for(auto neighbour : adj[node]){
				if(visited[neighbour.first] == 0){
					dfs(neighbour.first, visited, s);
				}
			}
			s.push(node);
		}
		
		stack<int> topo(){
			unordered_map<int, bool> visited;
			stack<int> s;
			for(auto i : adj){
				int node = i.first;
				if(visited[node] == 0){
					dfs(node, visited, s);
				}
			}
			return s;
		}
		
		void shortestPath(int n, vector<int> allNode, int src){
			stack<int> s = topo();
			unordered_map<int, int> dist;
			for(auto i : allNode){
				dist[i] = INT_MAX;
			}
			dist[src] = 0;
			while(!s.empty()){
				int t = s.top();
				s.pop();
				if(dist[t] != INT_MAX){
					for(auto k : adj[t]){
						dist[k.first] = min(dist[k.first], dist[t]+k.second);
					}
				}
			}
			cout<<endl<<"shortest path from src node to all the nodes is:"<<endl;
			for(auto i : dist) {
				cout<<"node: "<<i.first<<"->"<<i.second<<endl;
			}
		}
};

int main(int argc, char** argv) {
	Graph g;
	int n,src,t,m;
	cout<<"enter number of nodes: ";
	cin>>n;
	cout<<"enter all nodes: ";
	vector<int> allNode;
	for(int i=0; i<n; i++){
		cin>>t;
		allNode.push_back(t);
	}
	cout<<"enter number of edges: ";
	cin>>m;
	int u,v,w;
	for(int i=0; i<m; i++){
		cin>>u>>v>>w;
		g.addEdge(u, v, w);
	}
	cout<<"enter source node: ";
	cin>>src;
	g.printAdj();
	g.shortestPath(n, allNode, src);
	return 0;
}
