#include <iostream>
using namespace std;

int n;

void heapify(int *arr, int length, int parent)
{
    int dAry = 0;
    int *childs = new int[n];
    for (; dAry < n; dAry++)
    {
        childs[dAry] = (n * parent) + (dAry + 1);
    }
    int largest = parent;
    dAry = 0;
    for (; dAry < n; dAry++)
    {
        if (childs[dAry] < length && arr[childs[dAry]] > arr[largest])
            largest = childs[dAry];
    }
    if (parent != largest)
    {
        swap(arr[parent], arr[largest]);
        heapify(arr, length, largest);
    }
}

void buildHeap(int *arr, int length)
{
    for (int i = (length / n) - 1; i >= 0; i--)
    {
        heapify(arr, length, i);
    }
}

void printArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

int main()
{
    cin >> n;
    int num;
    cin >> num;
    int *arr = new int[num];
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    buildHeap(arr, num);
    printArray(arr, num);
    return 0;
}