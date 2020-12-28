#include <iostream>
using namespace std;

void maxHeap(int *arr, int parent, int length)
{
    int left = (2 * parent) + 1;
    int right = (2 * parent) + 2;

    int largest = parent;
    if (left < length && arr[left] > arr[largest])
        largest = left;
    if (right < length && arr[right] > arr[largest])
        largest = right;

    if (largest != parent)
    {
        swap(arr[largest], arr[parent]);
        maxHeap(arr, largest, length);
    }
}

void minHeap(int *arr, int parent, int length)
{
    int left = (2 * parent) + 1;
    int right = (2 * parent) + 2;

    int smallest = parent;
    if (left < length && arr[left] < arr[smallest])
        smallest = left;
    if (right < length && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != parent)
    {
        swap(arr[smallest], arr[parent]);
        minHeap(arr, smallest, length);
    }
}

void buildMaxHeap(int *arr, int length)
{
    for (int i = (length / 2) - 1; i >= 0; i--)
    {
        maxHeap(arr, i, length);
    }
}

void buildMinHeap(int *arr, int length)
{

    for (int i = (length / 2) - 1; i >= 0; i--)
    {
        minHeap(arr, i, length);
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
    int num;
    cin >> num;
    int *arr = new int[num];
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    cout << "Normal Array" << endl;
    printArray(arr, num);
    buildMaxHeap(arr, num);
    cout << "After Max Heapify" << endl;
    printArray(arr, num);
    buildMinHeap(arr, num);
    cout << "After Min Heapify" << endl;
    printArray(arr, num);
    return 0;
}