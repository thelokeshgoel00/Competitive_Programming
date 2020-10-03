#include <iostream>
#include <vector>
using namespace std;
int main()
{
  // compute the first 10001 primes
  vector<unsigned int> primes;
  primes.reserve(10001);
  primes.push_back(2);
  for (unsigned int x = 3; primes.size() <= 10000; x += 2)
  {
    bool isPrime = true;
    for (auto p : primes)
    {
      // found a divisor ? => abort
      if (x % p == 0)
      {
        isPrime = false;
        break;
      }

      // no larger prime factors possible ?
      if (p*p > x)
        break;
    }

    // yes, we have a new prime
    if (isPrime)
      primes.push_back(x);
  }

  // processing all test cases is now just a plain lookup
  unsigned int tests;
  cin >> tests;
  while (tests--)
  {
      unsigned int x;
      cin >> x;
      // just look up the x-th prime
      // with a little twist: vector's index is zero-based, therefore "off by one"
      x--;

      if (x < primes.size())
        cout << primes[x] << endl;
      else
        cout << "ERROR" << endl;
  }
  return 0;
}