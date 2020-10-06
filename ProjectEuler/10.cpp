#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
  // prime numbers beyond this are not relevant for the problem
  const unsigned int MaxPrime = 2000000;

  // precompute all relevant prime numbers
  vector<unsigned int> primes;
  // the only even prime
  primes.push_back(2);
  // now check all odd numbers for primality
  for (unsigned int i = 3; i <= MaxPrime; i += 2)
  {
    bool isPrime = true;
    for (auto p : primes)
    {
      // no larger prime factor possible ?
      if (p*p > i)
        break;

      // no prime number ?
      if (i % p == 0)
      {
        isPrime = false;
        break;
      }
    }

    // yes, we have a new prime
    if (isPrime)
      primes.push_back(i);
  }

  // prime numbers were found in ascending order,
  // let's add their value and store in a map such that
  // [prime number] => [sum of all prime numbers up to the current]
  // note: long long is required to avoid overflows
  map<unsigned int, unsigned long long> sums;
  unsigned long long sum = 0;
  for (auto p : primes)
  {
    sum += p;
    sums[p] = sum;
  }

  // the test cases are more or less "smart" lookups
  unsigned int tests;
  cin >> tests;
  while (tests--)
  {
    unsigned int x;
    cin >> x;

    // find the closest prime number which is bigger than the input
    auto i = sums.upper_bound(x);
    // go back to the closest prime number which is smaller than the input
    i--;

    // show the sum associated to that prime number
    cout << i->second << endl;
  }
  return 0;
}