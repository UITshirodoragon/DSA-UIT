#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <sstream>


using namespace std;



void input(map<string, int> &mp,vector<string> &v, int t)
{
    for(int i = 0; i < t; i++)
    {
        string tmp;
        getline(cin, tmp);
        mp[tmp]++; 
        if(mp[tmp] == 1)
        {
            v.push_back(tmp);
        }
        else
        {
            v.push_back(tmp + to_string(mp[tmp] - 1));
        }
    }
}

void output(vector<string> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }
}
int main()
{
    int t = 0;
    map<string, int> mp_hoten;
    vector<string> v_hoten;
    cin >> t;
    cin.ignore();
    input(mp_hoten,v_hoten, t);
    output(v_hoten);
    return 0;
}