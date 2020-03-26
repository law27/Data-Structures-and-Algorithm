#include<iostream>
using namespace std;

void dfsTraversal(int currentNode, int **graph, bool *visited, int noOfNodes)
{
    if(visited[currentNode]) return ;
    else
    {
        visited[currentNode] = true ;
        int *neighbours = *(graph+currentNode);
        for(int i = 0; i < noOfNodes ; i++)
        {
            if( neighbours[i] != 0)
            {
                dfsTraversal(i, graph , visited, noOfNodes);
            }
        }
    }
}

int main()
{
    int noOfNodes;
    cin >> noOfNodes ;
    int **graph = new int*[noOfNodes];
    for(int i = 0 ; i < noOfNodes ; i++)
    {
        graph[i] = new int[noOfNodes];
    }
    for(int i = 0 ; i < noOfNodes ; i++)
    {
        for(int j = 0 ; j < noOfNodes ;j++)
        {
            cin >> graph[i][j];
        }
    }
    bool visited[noOfNodes];
    for(int i = 0 ; i < noOfNodes ; i++)
        visited[i] = false;
    dfsTraversal(0,graph,visited,noOfNodes);
    for(int i = 0 ; i < noOfNodes ; i++)
        cout << visited[i] << " ";
    return 0;
}

