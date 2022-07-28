// concept of disjoin set

#include <bits/stdc++.h>
using namespace std;

class Graph{
	public:
		unordered_map<int, vector<int>> adj;
		void addEdges(int u, int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		void makeSet(unordered_map<int,int> &rank, unordered_map<int,int> &parent, vector<int> allNodes){
			for(auto i : allNodes){
				rank[i] = 0;
				parent[i] = i;
			}
		}
		
		int findParent(unordered_map<int,int> &parent, int node){
			if(parent[node] == node)
			return parent[node];
			return parent[node] = findParent(parent, parent[node]);
		}
		
		void unionSet(int u, int v, unordered_map<int,int> &parent, unordered_map<int,int> &rank){
			u = findParent(parent, u);
			v = findParent(parent, v);
			if(rank[u] < rank[v]) parent[u] = v;
			else if(rank[u] > rank[v]) parent[v] = u;
			else {
				parent[v] = u;
				rank[u]++;
			}
		}
		
		void disjoinSets(vector<int> allNodes){
			unordered_map<int,int> rank;
			unordered_map<int,int> parent;
		}
		
};

int main(int argc, char** argv) {
	Graph g;
	int n,m,u,v,t;
	vector<int> allNodes;
	cout<<"enter number of nodes ";
	cin>>n;
	cout<<"enter all the nodes ";
	for(int i; i<n; i++){
		cin>>t;
		allNodes.push_back(t);
	}
	cout<<"enter number of edges ";
	cin>>m;
	cout<<"enter edges"<<endl;
	for(int i=0; i<m; i++){
		cin>>u>>v;
		g.addEdges(u,v);
	}
	g.disjoinSets(allNodes);
	return 0;
}
