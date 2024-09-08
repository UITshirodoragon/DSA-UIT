#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(10, 100);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for(int t : v)
    {
        cout  << t << " ";
    }
    cout << endl;

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    cout << endl;
    cout << v.back() << " " << v.at(2) << endl;
    return 0;
}