#include <iostream>
#include <math.h>
using namespace std;

inline int leftChild(int parent)
{
    return 2 * parent + 1;
}

inline int rightChild(int parent)
{
    return (2 * parent) + 2;
}

void heapify(int *arr, int parent, int length)
{
    int left = leftChild(parent);
    int right = rightChild(parent);
    int largest = 0;
    if (left < length && (arr[left] > arr[parent]))
    {
        largest = left;
    }
    else
    {
        largest = parent;
    }
    if (right < length && (arr[right] > arr[largest]))
    {
        largest = right;
    }
    if (largest != parent)
    {
        int temp = arr[largest];
        arr[largest] = arr[parent];
        arr[parent] = temp;
        heapify(arr, largest, length);
    }
}

void buildHeap(int *arr, int length)
{
    for (int i = (length / 2) - 1; i >= 0; i--)
    {
        heapify(arr, i, length);
    }
}

void heapSort(int *arr, int length)
{
    buildHeap(arr, length);
    for (int i = length - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        int size = i;
        heapify(arr, 0, size);
    }
}

void printArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

int main()
{
    int length;
    cin >> length;
    int *arr = new int[length];
    for (int i = 0; i < length; i++)
        cin >> arr[i];
    heapSort(arr, length);
    printArray(arr, length);
    return 0;
}