// finding shortes path in an undirected graph

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
		
		void shortestPath(int start, int end){
			unordered_map<int,int> vis;
			unordered_map<int,int> p;
			int st;
			for(auto i: edges){
				st = i.first;
				break;
			}
			queue<int> q;
			q.push(st);
			p[st] = -1;
			while(!q.empty()){
				int node = q.front();
				q.pop();
				for(auto neighbour: edges[node]){
					if(vis[neighbour]==0){
						q.push(neighbour);
						vis[neighbour] = 1;
						p[neighbour] = node;
					}
				}
			}
			cout<<endl;
			vector<int> ans;
			int temp = end;
			while(temp != start){
				ans.push_back(temp);
				temp = p[temp];
			}
			ans.push_back(temp);
			reverse(ans.begin(), ans.end());
			for(auto i: ans) cout<<i<<" ";
		}
};

int main(int argc, char** argv) {
	Graph g;
	int n;
	cout<<"enter number of edges ";
	cin>>n;
	int u,v;
	cout<<"Enter edges"<<endl;
	for(int i=0; i<n; i++){
		cin>>u>>v;
		g.addEdge(u,v,0);
	}
	g.printGraph();
	int s,e;
	cout<<"enter start and end node ";
	cin>>s>>e;
	g.shortestPath(s,e);
	return 0;
}
