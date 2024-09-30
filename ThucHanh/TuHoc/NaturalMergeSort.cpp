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
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        /* code */
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]";

}

void mergeSort(vector< int >& num) {
    // divide sequence
    vector< int > sub[2];
    for (int i = 0, cur = num[0], p = 0; i < num.size(); ++i) {
        // if next element is decreasing, put to another part.
        if (num[i] < cur)
            p = ++p % 2;
        sub[p].push_back(cur = num[i]);
    }
    if (sub[1].empty())
        return;
    // sort sub-sequence
    mergeSort(sub[0]);
    mergeSort(sub[1]);
    // merge
    // i point to origin, j point to left, k point to right
    for (int i = 0, j = 0, k = 0; i < num.size(); ++i) {
        // if left is less than right or right part is end.
        if ((j != sub[0].size() && sub[0][j] < sub[1][k]) || k == sub[1].size())
            num[i] = sub[0][j++];
        // if right is less than or equal to left or left part is end.
        else
            num[i] = sub[1][k++];
    }
}


void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp;  // Mảng tạm thời để lưu trữ kết quả hợp nhất
    int i = left, j = mid + 1;

    // Hợp nhất hai mảng con
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    // Copy phần còn lại của mảng trái 
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    // Copy phần còn lại của mảng phải
    while (j <= right)
    {
        temp.push_back(arr[j++]);
    }

    // Copy lại từ temp vào arr
    for (int k = left; k <= right; ++k)
    {
        arr[k] = temp[k - left];
    }
}

// Hàm tìm các đoạn con đã sắp xếp (natural runs) và hợp nhất chúng
void naturalMergeSort(std::vector<int>& arr) {
    int n = arr.size();
    while (true)
    {
        int left = 0;
        bool merged = false;

        while (left < n)
        {
            // Tìm phần cuối của dãy con đầu tiên đã sắp xếp
            int mid = left;
            while (mid < n - 1 && arr[mid] <= arr[mid + 1])
            {
                ++mid;
            }

            if (mid == n - 1) break;  // Nếu dãy đã được sắp xếp hoàn toàn

            // Tìm phần cuối của dãy con tiếp theo đã sắp xếp
            int right = mid + 1;
            while (right < n - 1 && arr[right] <= arr[right + 1])
            {
                ++right;
            }

            // Hợp nhất hai dãy con đã sắp xếp
            merge(arr, left, mid, right);
            merged = true;

            left = right + 1;
        }

        if (!merged) break;  // Nếu không có gì được hợp nhất, dừng thuật toán
    }
}


int main()
{
    vector<int> arr;
    int n;
    InputArray(arr, n);
    naturalMergeSort(arr);
    OutputArray(arr);
    return 0;
}