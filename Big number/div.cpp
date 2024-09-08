#include <iostream>
#include <string>
#include <vector>
#include <cstring>


using namespace std;

typedef string BigInt;
// số lơn trừ số bé thôi

BigInt BigSub(BigInt a, BigInt b)
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
    int sub = 0;

    for(int i = b.length() - 1; i > 0; i--)
    {
        if(a[i] < b[i])
        {
            sub = 10 + (a[i] - '0') - (b[i] - '0') - carry;
            carry = 1;
        }
        else
        {
            sub = (a[i] - '0') - (b[i] - '0') - carry;
            carry = 0;
        }
        
        c[i] = sub + '0';
    }

    while(c[0] == '0' && c.length() > 1) 
    {
        c.erase(c.begin());
    }
    return c;
}







int main()
{

    BigInt a;
    BigInt b;
    getline(cin, a, '\n');
    getline(cin, b, '\n');
    cout << BigSub(a, b) << endl;

    
    return 0;
}