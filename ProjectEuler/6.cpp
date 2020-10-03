#include <iostream>
using namespace std;
int main()
{
  unsigned int tests;
  cin >> tests;
  while (tests--)
  {
    unsigned long long x;
    cin >> x;

    unsigned long long sum        = 0; // 1   + 2   + ...
    unsigned long long sumSquared = 0; // 1^2 + 2^2 + ...

    for (unsigned long long i = 1; i <= x; i++)
    {
      sum        += i;
      sumSquared += i*i;
    }
    unsigned long long squaredSum = sum * sum;
    cout << (squaredSum - sumSquared) << endl;
  }
  return 0;
}