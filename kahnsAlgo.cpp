// Topological sort in a graph using Kahn's algorithm (BFS)

#include <bits/stdc++.h>
using namespace std;

class Graph{
	public:
		unordered_map<int, vector<int>> adj;
		void addEdges(int u, int v){
			adj[u].push_back(v);
		}
	
		void topologicalSort(int v){
			unordered_map<int,int> indegree;
			queue<int> q;
			vector<int> ans;
			for(auto i : adj){
				for(auto node : i.second){
					indegree[node]++;
				}
			}
			
			for(auto i : adj){
				int node = i.first;
				if(indegree[node] == 0){
					q.push(node);
				}	
			}
			while(!q.empty()){
				int front = q.front();
				q.pop();
				ans.push_back(front);
				
				for(auto neighbour : adj[front]){
					indegree[neighbour]--;
					if(indegree[neighbour] == 0){
						q.push(neighbour);
					}
				}
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
