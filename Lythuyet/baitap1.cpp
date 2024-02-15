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
    vector<long long> v;
    multiset<long long> ms;
};

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
            
            if(list[i].ms.count(x) == 1)
            {
                list[i].v.push_back(x);
            }
        }
    }
}

void output1(Newtype *list, int t)
{
    for(int i = 0; i < t; i++)
    {

        for(auto j = list[i].v.begin(); j != list[i].v.end(); j++)
        {
            cout << *j << ": " << list[i].ms.count(*j) << endl;
        }
        cout << endl;
        cout << list[i].v.size() << endl;
        
    }
}

int main()
{
    int t;
    cin >> t;
    Newtype *data = new Newtype[t];
    input(data, t);
    output1(data, t);


    return 0;

}