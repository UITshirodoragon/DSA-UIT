#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

struct Newtype
{
    int n;
    map<long long, int> mp;

};

void input(Newtype *test, int t)
{
    for(int i = 0; i < t; i++)
    {
        cin >> test[i].n;
        for(int j = 0; j < test[i].n; j++)
        {
            long long x; 
            cin >> x;
            test[i].mp[x]++;
        }
    }
}

void output(Newtype *test, int t)
{
    for(int i = 0; i < t; i++)
    {
        int max = 0;
        int num = 0;
        for(pair<long long, int> p : test[i].mp)
        {
            if(p.second > max)
            {
                max = p.second;
                num = p.first;
            }

        }
        cout << num << " " << max << endl;
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