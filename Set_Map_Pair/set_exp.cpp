#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;



int main()
{
     // set ko luu cac phan tu giong nhau
    //multiset<int> ms; // luu duoc cac gia tri khac nhau
    // for(int i = 0; i < 10; i++)
    // {
    //     s.insert(i);
    // }

    // cout << s.size() << endl;
    // cout << s.count(2) << endl; // tim co hay khong return true false
    // cout << *s.rbegin() << endl;
    // s.erase(5);
    
    // for(set<int>::iterator i = s.begin(); i != s.end(); i++ )
    // {
    //     cout << *i << endl;
    // }
    set<int> s;
    multiset<int> ms;
    

    int n, k;
    cin >> n >> k;
    int list[n];
    for(int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    for(int i = 0; i < k; i++)
    {
        ms.insert(list[i]);
    }

    for(int i = k - 1; i < n ;i++)
    {
        cout << *ms.rbegin() << " ";
        ms.erase(ms.begin());
        ms.insert(list[i + 1]);
    }



    return 0;

}