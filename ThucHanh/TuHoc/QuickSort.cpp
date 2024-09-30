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


void OutputArray(vector<int> arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        /* code */
        if (i != arr.size() - 1) cout << ", ";
    }

}

void QuickSort(vector<int>& arr, int begin, int end)
{
    if (begin >= end) return;
    int x = arr[(begin + end) / 2], i = begin, j = end; // cải thiện hiệu suất khi chọn pivot, tránh làm cây đệ quy bị lệch
    while (i < j)
    {
        /* code */
        while (arr[i] > x)
        {
            i++;
        }
        while (arr[j] < x)
        {
            j--;
        }
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    QuickSort(arr, begin, j);
    QuickSort(arr, i, end);
}



int main()
{
    vector<int> arr;
    int n;

    InputArray(arr, n);
    QuickSort(arr, 0, n - 1);
    OutputArray(arr);
    return 0;
}