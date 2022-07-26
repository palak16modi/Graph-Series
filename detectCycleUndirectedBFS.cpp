// Detech cycle in an undirected graph using bfs

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
		
		void detectCycleUndirectedBFS(){
			int f=0;
			unordered_map<int,int> u;
			unordered_map<int,int> p;
			bool start = false;
			int st;
			for(auto e: edges){
				if(start == false) {
					st = e.first;
					start = true;
				}
				u[e.first] = 0;
			}
			queue<int> q;
			q.push(st);
			p[st] = -1;
			while(!q.empty()){
				int t = q.front();
				if(u[t]==0){
					u[t] = 1;
				}
				q.pop();
				for(auto x: edges[t]){
					if(x != p[t] && u[x]==0) {
						q.push(x);
						p[x] = t;
					}
					else if(x != p[t] && u[x]==1){
						cout<<"yes cycle is detected";
						// cout<<"x "<<x<<endl;
						f=1;
						break;
					}
				}
				if(f==1) break;	
			}
			if(f==0) cout<<"No cycle not detected"<<endl;
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
	g.printGraph();
	g.detectCycleUndirectedBFS();
	return 0;
}

