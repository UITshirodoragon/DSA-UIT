#include <iostream>
#include <map>

#include <vector>
#include <set>
#include <utility>
using namespace std;


int main()
{
    map<int, int> mp;
    multimap<int, int> mmp;
    
    

    mp.insert({100,300});
    mp.insert({200, 400});

    for(pair<int, int> x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }

    cout << mp.size() << endl;
    cout << mp.count(100) << endl;

    return 0;
}