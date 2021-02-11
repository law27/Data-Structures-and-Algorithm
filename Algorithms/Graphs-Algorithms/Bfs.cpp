#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

void addNode(vector<int>* adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool bfs(vector<int>* adj, int startNode, int size) {
    deque<bool> visited(false, size);
    queue<int> q;
    q.push(startNode);

    visited[startNode] = true;
    while(! q.empty()) {
        startNode = q.front();
        cout << startNode << endl;
        q.pop();

        for(auto i : adj[startNode]) {
            if(!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return 0;
}

int main() {
    vector<int> *adj = new vector<int>[4];
    addNode(adj, 0, 1);
    addNode(adj, 0, 2);
    addNode(adj, 1, 2);
    addNode(adj, 2, 0);
    addNode(adj, 2, 3);
    addNode(adj, 3, 3);
    bfs(adj, 3, 4);
    return 0;
}



