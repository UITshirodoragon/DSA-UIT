#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

struct Newtype
{
    int n, m;
    
    set<long long> ms1;
    set<long long> ms2;
    vector<long long> v1;
};

void input(Newtype *test, int t)
{
    for(int i = 0; i < t; i++)
    {
        cin >> test[i].n >> test[i].m;
        for(int j = 0; j < test[i].n; j++)
        {
            long long x; 
            cin >> x;
            test[i].ms1.insert(x);
            if(test[i].ms1.count(x) == 1) 
            {
                test[i].v1.push_back(x);
            }
        }
        for(int j = 0; j < test[i].m; j++)
        {
            long long x; 
            cin >> x;
            test[i].ms2.insert(x);
        }
    }
}

void output(Newtype *test, int t)
{
    for(int i = 0; i < t; i++)
    {
        for(long long x : test[i].v1)
        {
            if(test[i].ms2.count(x) == 0)
            {
                cout << x << endl;

            }
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

