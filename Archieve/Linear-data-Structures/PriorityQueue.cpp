/* Created by : Lawrance.J
   Date : 4.03.2020
*/

#include <iostream>
using namespace std;

class PriorityQueue
{
public:
    PriorityQueue(int);
    void heapInsert(int key);
    int extractMax(void);
    inline int maximum(void)
    {
        int num;
        (heapSize == 0) ? throw("UnderFlow") : num = arr[0];
        return num;
    }
    void printHeap(void);
    void heapify(int);

private:
    int *arr;
    int capacity;
    int heapSize;
};

PriorityQueue::PriorityQueue(int capacity)
{
    this->capacity = capacity;
    arr = new int[capacity];
    heapSize = 0;
}

void PriorityQueue::heapInsert(int key)
{
    if (heapSize == capacity)
    {
        throw("OverFlow");
    }
    else
    {
        heapSize++;
        int i = heapSize - 1;
        while (i != 0 && arr[(i - 1) / 2] < key)
        {
            arr[i] = arr[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        arr[i] = key;
    }
}

void PriorityQueue::heapify(int parent)
{
    int left = (2 * parent) + 1;
    int right = (2 * parent) + 2;
    int largest = parent;
    if (left < heapSize && arr[left] > arr[largest])
        largest = left;
    if (right < heapSize && arr[right] > arr[largest])
        largest = right;
    if (parent != largest)
    {
        swap(arr[parent], arr[largest]);
        heapify(largest);
    }
}

int PriorityQueue::extractMax()
{
    if (heapSize != 0)
    {
        int num = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        heapify(0);
        return num;
    }
    else
    {
        throw("UnderFlow");
    }
}

void PriorityQueue::printHeap()
{
    for (int i = 0; i < heapSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    PriorityQueue pQ(6);
    pQ.heapInsert(10);
    pQ.heapInsert(12);
    pQ.heapInsert(30);
    pQ.heapInsert(20);
    pQ.heapInsert(27);
    pQ.heapInsert(40);
    pQ.printHeap();
    cout << pQ.extractMax() << endl;
    pQ.heapInsert(500);
    pQ.printHeap();
    return 0;
}