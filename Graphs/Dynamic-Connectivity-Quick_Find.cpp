/********************************************************************************************
*    Title: Quick Find Soure Code                                                           *
*    Author: Lawrance J                                                                     *
*    Date: 21.11.2019                                                                       *
*    Availability: http://github.com/LawranceMichaelite/Data-Structures-and-Algorithm.git   *
*********************************************************************************************/


#include<iostream>
using namespace std;

int *Create(int N)
{
    int *arr = new int[N];
    for(int i = 0 ; i < N ; i++)
    {
        arr[i] = i ;
    }
    return arr;
}

void Union(int *arr,int p, int q)
{
    int pid = arr[p];
    int qid = arr[q];
    for(int i = 0 ; i < 10 ; i++)
    {
        if( arr[i] == pid )
        {
            arr[i] = qid;
        }
    }
}

bool Check(int *arr,int p,int q)
{
    if(arr[p]==arr[q])
        return true;
    else
    {
        return false;
    }

}
int main()
{
    int *arr = Create(10);
    Union(arr,1,3);
    Union(arr,2,5);
    Union(arr,5,6);
    Union(arr,5,2);
    Union(arr,2,3);
    Union(arr,7,5);
    if(Check(arr,7,2))
        cout << "Connected" << endl;
    else
    {
        cout << "Not Connected" << endl;
    }

    if(Check(arr,1,7))
        cout << "Connected" << endl;
    else
    {
        cout << "Not Connected" << endl;
    }

    if(Check(arr,1,8))
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
