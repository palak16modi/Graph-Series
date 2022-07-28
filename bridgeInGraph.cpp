// Finding bridges in a graph

#include <bits/stdc++.h>
using namespace std;

class Graph{
	public:
		unordered_map<int, vector<int>> adj;
		void addEdges(int u, int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		void dfs(int node, int parent, unordered_map<int, int> &disc, unordered_map<int, int> &low,
		 unordered_map<int, bool> &vis , int timer, vector<vector<int>> &result){
			
			vis[node] = 1;
			low[node] = disc[node] = timer++;
			
			for(auto neighbour : adj[node]){
				if(neighbour == parent) continue;
				if(!vis[neighbour]){
					dfs(neighbour, node, disc, low, vis, timer, result);
					low[node] = min(low[node], low[neighbour]);
					// check if bridge
					if(low[neighbour] > disc[node]){
						vector<int> ans;
						ans.push_back(node);
						ans.push_back(neighbour);
						result.push_back(ans);
					}
				}
				else{
					 // back edge case
					 low[node] = min(low[node], disc[neighbour]);
				}
			}
			 
		}
		
		void findBridges(vector<int> allNodes){
			int timer = 0;
			unordered_map<int, int> disc;
			unordered_map<int, int> low;
			int parent = -1;
			unordered_map<int, bool> vis;
			for(auto i : allNodes){
				disc[i] = -1;
				low[i] = -1;
			}
			vector<vector<int>> result;
			for(auto i : allNodes){
				if(!vis[i]){
					dfs(i, parent, disc, low, vis, timer, result);
				}
			}
			cout<<"Bridges are: ";
			for(auto i: result) cout<<i[0]<<"-"<<i[1]<<" ";
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
	g.findBridges(allNodes);
	return 0;
}
