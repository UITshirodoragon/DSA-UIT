#include <iostream>
#include <string>
#include <vector>
#include <cstring>


using namespace std;

typedef string BigInt;

BigInt BigAdd(BigInt a, BigInt b)
{
    // a + b = c

    a = '0' + a;
    b = '0' + b;
    // Chuan hoa cung do dai
    long long diff = a.length() - b.length();
    if(diff > 0)
    {
        b = string(abs(diff), '0') + b;
    }
    else
    {
        a = string(abs(diff), '0') + a;
    }

    BigInt c = a;
    int carry = 0;
    int sum = 0;

    for(int i = b.length() - 1; i >= 0; i--)
    {
        sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        sum = sum % 10;
        c[i] = sum + '0';
    }

    if(c[0] == '0') c.erase(c.begin());
    return c;
}







int main()
{

    BigInt a;
    BigInt b;
    getline(cin, a, '\n');
    getline(cin, b, '\n');
    cout << BigAdd(a, b) << endl;

    
    return 0;
}