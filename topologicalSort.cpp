// Bellman Ford algorithm for shortest path
// also checking for negative cycle

#include <bits/stdc++.h>
using namespace std;

class Graph{
	public:
		vector<vector<int>> edges;
		void addEdges(int u, int v, int w){
			vector<int> t;
			t.push_back(u);
			t.push_back(v);
			t.push_back(w);
			edges.push_back(t);
		}
		
		void bellmanFord(int n, int src){
			unordered_map<int,int> dist;
			for(auto i: edges){
				dist[i[0]] = INT_MAX;
			}
			dist[src] = 0;
			for(int i=0; i<(n-1); i++){
				for(auto j : edges){
					int u = j[0];
					int v = j[1];
					int w = j[2];
					if(dist[u]<INT_MAX && (dist[u]+w < dist[v])){
						dist[v] = dist[u]+w;
					}
				}
			}
			// check for negative cycle
			int flag=0;
			for(auto j : edges){
				int u = j[0];
				int v = j[1];
				int w = j[2];
				if(dist[u]<INT_MAX && (dist[u]+w < dist[v])){
					// dist[v] = dist[u]+w;
					flag=1;
				}
			}
			if(flag == 0){
				cout<<"Shortest distance is "<<endl;
				for(auto i : dist){
					cout<<i.first<<"->"<<i.second<<" ";
				}
			}
			else{
				cout<<"negative cycle exists";
			}
		}
		
		
};

int main(int argc, char** argv) {
	Graph g;
	int n,m,u,v,w,src;
	cout<<"enter number of nodes ";
	cin>>n;
	cout<<"enter number of edges ";
	cin>>m;
	cout<<"enter edges"<<endl;
	for(int i=0; i<m; i++){
		cin>>u>>v>>w;
		g.addEdges(u,v,w);
	}
	cout<<"enter source node ";
	cin>>src;
	g.bellmanFord(n,src);
	return 0;
}
