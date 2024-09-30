#include <iostream>
#include <vector>

using namespace std;
void InputArray(vector<int>& arr, int& n)
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;

        cin >> temp;
        arr.push_back(temp);
    }
}

void OutputArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        /* code */
        if (i != n - 1) cout << ", ";
    }

}

void heapify(vector<int>& arr, int i, int n)
{
    // heap structure
    int largest = i;
    int left = 2 * i + 1;
    int right;

    while (left < n)
    {
        right = left + 1;
        if (right < n && arr[left] < arr[right])
        {
            left = right;
        }
        if (arr[largest] >= arr[left])
        {
            break;
        }
        swap(arr[largest], arr[left]);
        largest = left;
        left = 2 * largest + 1;
    }
}
void bulidHeap(vector<int>& arr, int n)
{

    int i = (n - 1) / 2; // after i  
    while (i >= 0)
    {
        heapify(arr, i, n);
        i--;
    }
}



void HeapSort(vector<int>& arr, int n)
{
    bulidHeap(arr, n);
    while (n > 0)
    {
        /* code */
        n--;
        swap(arr[0], arr[n]);
        heapify(arr, 0, n);

    }

}

int main()
{
    vector<int> arr;
    int n;

    InputArray(arr, n);
    HeapSort(arr, n);
    OutputArray(arr, n);

    return 0;
}