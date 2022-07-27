// dijkstra's algorithm

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
		
		void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s){
			visited[node] = 1;
			for(auto neighbour : adj[node]){
				if(visited[neighbour.first] == 0){
					dfs(neighbour.first, visited, s);
				}
			}
			s.push(node);
		}
		
		void dijkstraAlgorithm(vector<int> allNode, int src){
			set<pair<int,int>> distNode;
			unordered_map<int,int> dist;
			for(auto i : allNode){
				dist[i] = INT_MAX;
			}
			cout<<endl;
			dist[src] = 0;
			distNode.insert(make_pair(0,src));
			while(!distNode.empty()){
				auto top = *(distNode.begin());
				int nodeDist = top.first;
				int topNode = top.second;
				distNode.erase(distNode.begin());
				for(auto i : adj[topNode]){
					int j = i.first;
					int k = i.second;
					if(nodeDist + k < dist[j]){
						auto record = distNode.find(make_pair(dist[j],j));
						if(record != distNode.end()){
							distNode.erase(record);
						}
						dist[j] = nodeDist + k;
						distNode.insert(make_pair(dist[j], j));
					}	
				}
			}
			cout<<"{";
			for(auto i : dist){
				cout<<"{"<<i.first<<"->"<<i.second<<"} ";
			}
			cout<<"}";
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
	g.dijkstraAlgorithm(allNode, src);
	return 0;
}
