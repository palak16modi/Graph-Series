// Minimum spanning tree using Prim's Algorithm

#include <bits/stdc++.h>
using namespace std;

class Graph{
	public:
		unordered_map<int, vector<pair<int,int>>> adj;
		void addEdge(int u, int v, int weight){
			pair<int, int> p = make_pair(v, weight);
			pair<int, int> q = make_pair(u, weight);
			adj[u].push_back(p);
			adj[v].push_back(q);
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
		
		void prims(int src, vector<int> allNodes){
			unordered_map<int,int> key;
			unordered_map<int,bool> mst;
			unordered_map<int,int> parent;
			for(auto i : allNodes){
				key[i] = INT_MAX;
				mst[i] = false;
				parent[i] = -1;
			}
			key[src] = 0;
			
			for(auto i : allNodes){
				int mini = INT_MAX;
				int u;
				for(auto k : allNodes){
					if(mst[k]==false && key[k]<mini){
						u = k;
						mini = key[k];
					}
				}
				mst[u] = true;
				for(auto neighbour: adj[u]){
					int node = neighbour.first;
					int weight = neighbour.second;
					if(mst[node] == false && weight < key[node]){
						parent[node] = u;
						key[node] = weight;
					}
				}
			}
			
			vector<pair<pair<int,int>,int>> result;
			for(auto i : allNodes){
				if(i!=src){
					result.push_back({{parent[i],i}, key[i]});
				}
			}
			for(auto i : result){
				auto j = i.first;
				int k = i.second;
				cout<<j.first<<" "<<j.second<<" "<<k<<endl;
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
	cout<<"enter edges: "<<endl;
	for(int i=0; i<m; i++){
		cin>>u>>v>>w;
		g.addEdge(u, v, w);
	}
	cout<<"enter source node: ";
	cin>>src;
	g.printAdj();
	g.prims(src, allNode);
	return 0;
}
