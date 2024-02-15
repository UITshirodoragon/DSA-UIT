#include <iostream>
#include <set>
#include <map>
#include <vector>
#define ll long long
using namespace std;


// dem so luong khac nhau trong mang so nguyen 

/*
input:
2
5
1 2 2 2 1
4
1 2 3 4
*/
struct Newtype
{
    int n;
    multiset<long long> ms;
    
};

int find = 0;
vector<long long> v;

void input(Newtype *list, int t)
{
    for(int i = 0; i < t; i++)
    {
        cin >> list[i].n;
        for(int j = 0; j < list[i].n; j++)
        {
            long long x;
            cin >> x;
            list[i].ms.insert(x);
        }
    }
    // find
    

    
    
}

void output(Newtype *list, int t)
{
    for(int i = 0; i < ::find; i++)
    {
        if(list[0].ms.count(v.at(i)))
        {
            cout << "YES\n";
        } 
        else cout << "NO\n";
    }
}

int main()
{
    int t;
    cin >> t;
    Newtype *data = new Newtype[t];
    input(data, t);
    cin >> ::find;
    for(int j = 0; j < ::find; j++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    output(data, t);


    return 0;

}