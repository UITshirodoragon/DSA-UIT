#include <iostream>

// online sort
// internal sort
// stable sort

// Time: O(n^2)
// Space: O(1)
using namespace std;

void InputArray(int*& arr, int& n)
{
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void OutputArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        /* code */
        if (i != n - 1) cout << ", ";
    }

}

void InsertionSort(int*& arr, int n)
{
    int count = 1;
    for (int i = 1; i < n; ++i) {
        int temp = arr[i];
        int j = i - 1;
        for (; j > -1; j--)
        {
            if (temp > arr[j])
            {
                arr[j + 1] = arr[j];

            }
            cout << count << ". A = {";
            OutputArray(arr, n);
            cout << "}, temp = " << temp << ", i = " << i << ", j = " << j << endl;
            count++;
            if (temp <= arr[j])
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}





int main()
{
    int* arr;
    int n;
    InputArray(arr, n);
    InsertionSort(arr, n);
    OutputArray(arr, n);
    return 0;
}