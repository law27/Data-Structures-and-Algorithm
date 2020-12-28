#include <bits/stdc++.h>
using namespace std;

void addEdge(int u , int v, list<int>*adj) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(list<int>*adj,int count,int *connected,bool *visited ,int node) {
	if(!visited[node]) {
		connected[node] = count;
		visited[node] = true;
		for(auto i = adj[node].begin() ; i != adj[node].end() ; i++) {
			if(!visited[*i]) {
				dfs(adj,count,connected,visited,*i);
			}
		}
	}
}

int numberOfConnectedComponents(int *connected, list<int>*adj,int noOfNode) {
	int count = 0;
	bool visited[noOfNode];
	for(int i = 0 ; i < noOfNode ; i++) {
		visited[i] = false;
	}
	for(int i = 0 ; i < noOfNode ; i++) {
		if(!visited[i]) {
			dfs(adj,count,connected,visited,i);
			count++;
		}
	}
	return count;

}

int main() {
	freopen("output.txt" , "w" , stdout);
	int noOfNode = 6;
	list<int>*adj = new list<int>[noOfNode];
	addEdge(0,1,adj);
	addEdge(0,2,adj);
	addEdge(1,3,adj);
	addEdge(3,2,adj);
	addEdge(4,5,adj);
	addEdge(0,3,adj);
	int *connected = new int[noOfNode];
	for(int i = 0 ;i < noOfNode ; i++)
		connected[i] = 0;
	cout << numberOfConnectedComponents(connected,adj,noOfNode) << endl;
	for(int i = 0; i < noOfNode ; i++)
		cout << connected[i] << " ";
	return 0;

}
