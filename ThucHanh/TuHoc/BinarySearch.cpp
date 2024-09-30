#include <iostream>


using namespace std;

void InputArray(int *&arr, int &n)
{
    cin >> n;
    arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void OutputArray(int * arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        /* code */
    }
    cout << endl;
    
}

int BinarySearch(int *& arr, int n, int x)
{
    int left = 0, right = n - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] == x)
        {
            return mid;
        }
        else if(x > arr[mid]) // Hoac < neu mang tang dan
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int * arr;
    int n;
    

    InputArray(arr, n);
    int x;
    cin >> x;
    cout << "Index: " << BinarySearch(arr, n, x) << endl;

    return 0;
}