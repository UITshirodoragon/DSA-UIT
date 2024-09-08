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

    for(long i = b.length() - 1; i >= 0; i--)
    {
        sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        sum = sum % 10;
        c[i] = sum + '0';
    }


    while(c[0] == '0' && c.length() > 1) 
    {
        c.erase(c.begin());
    }
    return c;
}


BigInt BigMulwithLong(BigInt a, long b)
{
    // a + b = c
    BigInt c;
    int carry = 0;
    int tich = 0;

    for(long i = a.length() - 1; i >= 0; i--)
    {
        tich = (a[i] - '0') * b + carry;
        carry = tich / 10;
        tich = tich % 10;
        c = char(tich + 48) + c;
    }
    if(carry) c = char(carry + 48) + c;

    while(c[0] == '0' && c.length() > 1) 
    {
        c.erase(c.begin());
    }
    return c;
}

BigInt BigMul(BigInt a, BigInt b)
{
    BigInt c = "";
    BigInt tong = "0";
    BigInt tich = "";
    long n = 0;
    for(long i = b.length() - 1; i >= 0; i--)
    {
        tich = BigMulwithLong(a, (b[i] - 48));
        tich += string(n,'0');
        c = BigAdd(tong, tich);
        n++;
        tong = c;
        
   }


    while(tong[0] == '0' && tong.length() > 1) 
    {
        tong.erase(tong.begin());
    }
    return tong;
}


int main()
{

    BigInt a;
    BigInt b;
    getline(cin, a, '\n');
    getline(cin, b, '\n');

    cout << BigMul(a, b) << endl;

    
    return 0;
}