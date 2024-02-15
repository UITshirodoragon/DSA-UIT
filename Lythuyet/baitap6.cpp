#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstring>


using namespace std;

struct Newtype
{
    string str;
    map<char, int> mp;

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
        for(char x: test[i].str)
        {
            x = tolower(x);
            test[i].mp[x]++;
        }
        if(test[i].mp.size() == 26)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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