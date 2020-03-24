/* MergeSort Algorithm
   Runs in O(n * log(n))
*/

/* Created by : J.Lawrance
   Date : 3/03/2020
*/

#include <iostream>
using namespace std;

void mergeSortUtility(int *arr, int left, int middle, int right)
{
    int leftArraySize = (middle - left) + 1;
    int rightArraySize = right - middle;
    int *arr_1 = new int[leftArraySize];
    int *arr_2 = new int[rightArraySize];
    int k = left;
    for (int i = 0; i < leftArraySize; i++)
        arr_1[i] = arr[k++];
    int m = middle + 1;
    for (int i = 0; i < rightArraySize; i++)
        arr_2[i] = arr[m++];
    k = 0;
    m = 0;
    int num = left;
    while (k < leftArraySize && m < rightArraySize)
    {
        if (arr_1[k] >= arr_2[m])
        {
            arr[num++] = arr_2[m++];
        }
        else
        {
            arr[num++] = arr_1[m++];
        }
    }
    while (k < leftArraySize)
    {
        arr[num++] = arr_1[k++];
    }
    while (m < rightArraySize)
    {
        arr[num++] = arr_2[k++];
    }
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int middleElement = (right + left) / 2;
        mergeSort(arr, left, middleElement);
        mergeSort(arr, middleElement + 1, right);
        mergeSortUtility(arr, left, middleElement, right);
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
    int *arr = new int[10]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    mergeSort(arr, 0, 9);
    printArray(arr, 10);
    return 0;
}