#include<iostream>
using namespace std;

int *Create(int N)
{
    int *arr = new int[N];
    for(int i=0; i<N ; i++)
    {
        arr[i] = i;
    }
    return arr;
}

int Find_Root(int *arr,int i)
{
    while( i != arr[i])
        i = arr[i];
    
    return i;
}
void Union(int p,int q,int *arr)
{
    int i = Find_Root(arr,p);
    int j = Find_Root(arr,q);
    arr[i] = j ;
}

bool Find_Connection(int p, int q,int *arr)
{
    if(Find_Root(arr,p) == Find_Root(arr,q))
        return true;
    else
        return false;
}

int main()
{
    int *arr = Create(10);
    Union(1,3,arr);
    Union(3,2,arr);
    Union(2,5,arr);
    Union(5,6,arr);
    Union(6,2,arr);

    if(Find_Connection(6,1,arr))
        cout << "Connected" << endl;
    else
    {
        cout << "Not Connected" << endl;
    }

    if(Find_Connection(1,7,arr))
        cout << "Connected" << endl;
    else
    {
        cout << "Not Connected" << endl;
    }
    
    for(int i=0; i<10 ; i++)
    {
        cout << i << " --> " << arr[i] << endl;
    }
    
    return 0;
}