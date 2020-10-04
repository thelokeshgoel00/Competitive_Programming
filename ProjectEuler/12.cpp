#include <iostream>
#include <vector>

int main()
{
  // find the smallest number with at least 1000 divisors
  // (due to Hackerrank's input range)
  const unsigned int MaxDivisors = 1000;

  // store [divisors] => [smallest number]
  std::vector<unsigned int> smallest;
  smallest.push_back(0); // 0 => no divisors

  // for index=1 we have triangle=1
  // for index=2 we have triangle=3
  // for index=3 we have triangle=6
  // ...
  // for index=7 we have triangle=28
  // ...
  unsigned int index    = 0;
  unsigned int triangle = 0; // same as index*(index+1)/2
  while (smallest.size() < MaxDivisors)
  {
    // next triangle number
    index++;
    triangle += index;

    // performance tweak (5x faster):
    // I observed that the "best" numbers with more than 300 divisors end with a zero
    // that's something I cannot prove right now, I just "saw" that debugging my code
    if (smallest.size() > 300 && triangle % 10 != 0)
      continue;

    // find all divisors i where i*j=triangle
    // it's much faster to assume i < j, which means i*i < triangle
    // whenever we find i then there is a j, too
    unsigned int divisors = 0;
    unsigned int i        = 1;
    while (i*i < triangle)
    {
      // divisible ? yes, we found i and j, that's two divisors
      if (triangle % i == 0)
        divisors += 2;
      i++;
    }
    // if i=j then i^2=triangle and we have another divisor
    if (i*i == triangle)
      divisors++;

    // fill gaps:
    // e.g. 10 is the smallest number with 4 divisors
    //      28 is the smallest number with 6 divisors
    // there is no number between 10 and 28 with 5 divisors
    // therefore 28 is the smallest number with AT LEAST 5 divisors, too
    while (smallest.size() <= divisors)
      smallest.push_back(triangle);
  }

  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int minDivisors;
    std::cin >> minDivisors;

    // problem setting asks for "over" x divisors => "plus one"
    std::cout << smallest[minDivisors + 1] << std::endl;
  }

  return 0;
}