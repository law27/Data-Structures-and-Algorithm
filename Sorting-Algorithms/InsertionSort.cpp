/*
 Insertion Sort
 Running Time is O(N^2)
 */

/* Created by : J.Lawrance
   Date : 3/03/2020
*/

#include <iostream>
using namespace std;

void insertionSort(int *arr, int length)
{
    for (int i = 1; i < length; i++)
    {

        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) //Moves the elements to Place the key in Correct Place
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; //Places the Key in Correct place
    }
}

void printArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int *arr = new int[10]{5, 7, 3, 8, 2, 10, 21, 1, 4, 6};
    insertionSort(arr, 10);
    printArray(arr, 10);
    return 0;
}
