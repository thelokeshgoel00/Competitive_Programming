// C++ Program to find largest prime
// factor of number
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long maxPrimeFactors(long long n)
{

    long long maxPrime = -1;

    while (n % 2 == 0)
    {
        maxPrime = 2;
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            maxPrime = i;
            n = n / i;
        }
    }

    if (n > 2)
        maxPrime = n;

    return maxPrime;
}

int main()
{
    long long n = 15;
    cout << maxPrimeFactors(n) << endl;

    n = 25698751364526;
    cout << maxPrimeFactors(n);
}
// This code is contributed by Shivi_Aggarwal
