#include <iostream>
using namespace std;

int *Creating(int N)
{
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = i;
    }
    return arr;
}

int *Size(int N)
{
    int *size_arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        size_arr[i] = 1;
    }
    return size_arr;
}

int Root(int i, int *arr)
{
    while (i != arr[i])
    {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

void Union(int p, int q, int *arr, int *size_arr)
{
    int i = Root(p, arr);
    int j = Root(q, arr);

    if (size_arr[i] > size_arr[j])
    {
        arr[i] = j;
        size_arr[j] += size_arr[i];
    }
    else
    {
        arr[j] = i;
        size_arr[i] += size_arr[j];
    }
}

bool Finding(int *arr, int p, int q)
{
    if (Root(p, arr) == Root(q, arr))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int *arr = Creating(10);
    int *size_arr = Size(10);

    Union(0, 2, arr, size_arr);
    Union(0, 7, arr, size_arr);
    Union(1, 2, arr, size_arr);
    Union(7, 6, arr, size_arr);
    Union(6, 0, arr, size_arr);

    if (Finding(arr, 6, 2))
    {
        cout << "Connected" << endl;
    }
    else
    {
        cout << "Not Connected" << endl;
    }
    if (Finding(arr, 7, 1))
    {
        cout << "Connected" << endl;
    }
    else
    {
        cout << "Not Connected" << endl;
    }
    if (Finding(arr, 7, 8))
    {
        cout << "Connected" << endl;
    }
    else
    {
        cout << "Not Connected" << endl;
    }

    return 0;
}