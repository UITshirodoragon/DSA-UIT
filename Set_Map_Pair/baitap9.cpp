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
    vector<string> v;

};

void input(Newtype *test, int t)
{
    for(int i = 0; i < t; i++)
    {
        cin.ignore();
        getline(cin, test[i].str);
        string tmp;
        stringstream ss(test[i].str);
        while(ss >> tmp)
        {
            test[i].mp[tmp]++;
            if(test[i].mp[tmp] >= 2)
            {
                test[i].v.push_back(tmp);
            }
        }
    }
}

void output(Newtype *test, int t)
{
    for(int i = 0; i < t; i++)
    {
        cout << test[i].v.at(0) << endl;

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