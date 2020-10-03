#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
  // precompute all pairs a<b<c where a+b+c <= 3000
  const int MaxPerimeter = 3000;
  // -1 means "no triplets" for that perimeter
  const int NoSolution   =   -1;

  // cache[0] remains unused
  vector<int> cache(MaxPerimeter + 1, NoSolution);

  // scan all pairs a<b
  for (int a = 1; a < MaxPerimeter; a++)
    for (int b = a + 1; b < MaxPerimeter - a; b++)
    {
      // find c
      int c2 = a*a + b*b;
      // approximate square root as integer
      int c = sqrt(c2);
      // was it the correct square root ?
      if (c*c != c2)
        continue;

      // check summing condition
      int sum = a + b + c;
      if (sum > MaxPerimeter)
        break;

      // better solution than before ?
      if (cache[sum] < a*b*c)
        cache[sum] = a*b*c;
    }

  unsigned int tests;
  cin >> tests;
  while (tests--)
  {
    unsigned int n;
    cin >> n;
    // just lookup results (-1 if no solution)
    cout << cache[n] << endl;
  }
  return 0;
}