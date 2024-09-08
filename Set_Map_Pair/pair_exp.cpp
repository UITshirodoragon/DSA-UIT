#include <iostream>
#include <vector>


using namespace std;


int main()
{
    pair<int,int> p = {100, 200};
    tuple<int, int, int> t = {100, 200, 300};

    cout << p.first << endl;
    cout << p.second << endl;
    cout << get<0>(t) << endl;
    cout << get<2>(t) << endl;
    cout << get<1>(t) << endl;





}