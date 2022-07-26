// BFS on graph

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
		
		void BFS(){
			cout<<"BFS: ";
			unordered_map<int,int> vis;
			int st;
			for(auto i : edges){
				st = i.first;
				break;
			}
			queue<int> q;
			q.push(st);
			vis[st] = 1;
			while(!q.empty()){
				int t = q.front();
				cout<<t<<" ";
				for(auto x: edges[t]){
					if(vis[x]==0){
						q.push(x);
						vis[x] = 1;
					}
				}
				q.pop();
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
	g.BFS();
	return 0;
}

