// Minimum spanning tree using kruskals algorithm

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
		
		static bool cmp(vector<int> &a, vector<int> &b){
			if(a[2] < b[2]) return true;
			else return false;
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
		
		int kruskals(vector<int> allNodes){
			sort(edges.begin(), edges.end(), cmp);
			unordered_map<int,int> rank;
			unordered_map<int,int> parent;
			makeSet(rank, parent, allNodes);
			int minWeight = 0;
			for(auto i : edges){
				int u = findParent(parent, i[0]);
				int v = findParent(parent, i[1]);
				int w = i[2];
				if(u != v){
					minWeight += w;
					unionSet(u,v,parent,rank);
					cout<<"edge taken "<<i[0]<<" "<<i[1]<<" "<<w<<endl;
				}
			}
			return minWeight;
		}
};

int main(int argc, char** argv) {
	Graph g;
	int n,m,u,v,t,w;
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
		cin>>u>>v>>w;
		g.addEdges(u,v,w);
	}
	cout<<g.kruskals(allNodes);
	return 0;
}

/*
5 4 9
5 1 4
4 3 5
3 6 8
6 2 7
1 2 2
4 1 1
3 2 3
4 2 3
*/
