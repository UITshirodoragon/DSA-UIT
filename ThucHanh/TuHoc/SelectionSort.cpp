#include <iostream>

// the default is not stable but it have own stable version
// offline sort
// internal sort
// unstable sort
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

void SelectionSort(int*& arr, int n)
{
    int count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        /* code */
        int max_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            /* code */
            if (arr[j] > arr[max_idx])
            {
                max_idx = j;
            }
            cout << count << ". A = {";
            OutputArray(arr, n);
            cout << "}, max_int = " << max_idx << ", i = " << i << ", j = " << j << endl;
            count++;
        }
        if (max_idx != i)
        {
            swap(arr[max_idx], arr[i]);
        }
    }
}

int main()
{
    int* arr;
    int n;
    InputArray(arr, n);
    SelectionSort(arr, n);
    OutputArray(arr, n);
    return 0;
}