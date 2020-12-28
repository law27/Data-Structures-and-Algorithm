#include <iostream>
using namespace std;

int *countingSort(int *arr, int length, int max)
{
    int temp[max];
    int output[max];
   
    for (int i = 0; i < max; i++)
    {
        temp[i] = 0;
    }
    for (int i = 0; i < length; i++)
    {
        temp[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        temp[i] = temp[i] + temp[i - 1];
    }
    for (int i = 0; i < length; i++)
    {
        output[temp[arr[i]] - 1] = arr[i];
        temp[arr[i]]--;
    }
    return output;
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
    int max = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int *output = countingSort(arr, num, max);
    printArray(output, num);
    return 0;
}
