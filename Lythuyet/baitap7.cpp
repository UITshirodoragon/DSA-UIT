#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <sstream>


using namespace std;

struct Newtype
{
    string str;
    map<string, int> mp;

};

void input(Newtype *test, int t)
{
    for(int i = 0; i < t; i++)
    {
        cin.ignore();
        getline(cin, test[i].str);
    }
}

void output(Newtype *test, int t)
{
    for(int i = 0; i < t; i++)
    {
        
        string tmp;
        int max = 0;
        stringstream ss(test[i].str);
        while(ss >> tmp)
        {
            test[i].mp[tmp]++;
        }
        for(auto x: test[i].mp)
        {
            if(x.second > max)
            {
                tmp = x.first;
                max = x.second;
            }
        }
        cout << tmp << ": " << max << endl;
    }
}
int main()
{
    int t = 0;
    cin >> t;
    Newtype *data = new Newtype[t];

    input(data, t);
    output(data, t);
    return 0;
}