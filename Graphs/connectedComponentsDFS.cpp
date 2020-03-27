#include<iostream>
using namespace std;

const int noOfNode = 13;
int components[noOfNode] ;

void dfs(int currentNode ,int graph[noOfNode][noOfNode], bool *visited, int count)
{
    if(visited[currentNode] != true)
    {
        visited[currentNode] = true;
        components[currentNode] = count ;
        int *neighbours = *(graph+currentNode);
        for(int i = 0 ; i < noOfNode; i++)
        {
            if(neighbours[i] != 0)
            {
                dfs( i , graph , visited, count );
            }
        }
    }
}


int noOfConnectedComponents(int graph[noOfNode][noOfNode])
{
    bool *visited = new bool[noOfNode];
    for(int i = 0 ; i < noOfNode ; i++)
    {
        visited[i] = false ;
    }
    int count = 0 ;
    for(int i = 0 ; i < noOfNode ; i++)
    {
        if( visited[i] != true )
        {
            dfs(i , graph , visited, count );
            count++;        
        }
    }
    return count ;
}

int main()
{                                     //1   2   3   4   5   6   7   8   9   10  11  12  13 
    int graph[noOfNode][noOfNode] = { { 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0  },
                                      { 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0  },
                                      { 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0  },
                                      { 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0  },
                                      { 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0  },
                                      { 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0  },
                                      { 1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0  },
                                      { 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 0  },
                                      { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 0  },
                                      { 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0  },
                                      { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0  },
                                      { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 1  },
                                      { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0  }
                                    };
    cout << noOfConnectedComponents(graph) << endl;
    for(int i = 0 ; i < noOfNode ; i++)
        cout << components[i] << " ";
    return 0 ;
}

