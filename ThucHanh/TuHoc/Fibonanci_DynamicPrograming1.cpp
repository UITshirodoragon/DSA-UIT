// https://www.youtube.com/watch?v=oBt53YbR9Kk&list=PLUzvZMEoR0KvEthotRQR3qoJ5FJxkhvaP&index=4


#include <iostream>
#include <map>

using namespace std;

// time = O(2^n)
// space = O(n)
int FibWithRecursion(int n)
{
    if(n <= 2) return 1;
    else return FibWithRecursion(n - 1) + FibWithRecursion(n - 2);
}

// quy hoach dong
// time O(n); space: O(n)
long long FibWithDPRecursion(int n, map<int, long long> & fib_result )
{
    if(fib_result.find(n) != fib_result.end()) return fib_result[n];
    if(n <= 2) return 1;
    long long temp_fib = FibWithDPRecursion(n - 1, fib_result) + FibWithDPRecursion(n - 2, fib_result);
    fib_result.insert({n, temp_fib});
    return fib_result[n]; 
}

long long FibWithDPTable(int n)
{
    long long * arr = new long long [n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i  <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        // Hoac cach khac
        // arr[i + 1] += arr[i];
        // arr[i + 2] += arr[i];
    }
    return arr[n];
}

// time O(n) space O(1)
long long FibWithDP(int n)
{
    long fn = 1, f1 = 1, f2 = 1;
    for(int i = 3; i<= n; i++)
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
}

int main()
{
    map<int, long long> fib_result;
    int n = 0;
    cin >> n;
    cout << FibWithDPTable(n) << endl;
    return 0;
}