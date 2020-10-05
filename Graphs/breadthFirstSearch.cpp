#include<iostream>
#include<list>
using namespace std;

const int noOfNode = 4 ;             


void BFS(int graph[noOfNode][noOfNode] , int start)
{
    list<int>helperQueue ;
    bool *visited = new bool[noOfNode] ;
    for(int i = 0; i < noOfNode; i++)
        visited[i] = false ;
    visited[start] = true ;
    helperQueue.push_back(start);

    while(!helperQueue.empty())
    {
        int currentNode = helperQueue.front()  ;
        cout << currentNode << " --> " ;
        helperQueue.pop_front();
        int *neighbours = graph[currentNode];
        for(int i = 0 ; i < noOfNode ; i++)
        {
            if( !visited[i] && neighbours[i] != 0 )
            {
                visited[i] = true ;
                helperQueue.push_back(i);
            }
        }
    }

}


int main()
{                                   //  1   2   3   4
    int graph[noOfNode][noOfNode] = { { 0 , 1 , 1 , 0 } ,
                                      { 1 , 0 , 1 , 0 } ,
                                      { 1 , 1 , 0 , 1 } ,
                                      { 0 , 0 , 1 , 0 }
                                    };
   BFS(graph , 3);
   return 0;
}
