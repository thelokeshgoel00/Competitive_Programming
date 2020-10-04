#include <iostream>
#include <vector>
#include <map>

// memoize all paths length for n up to 5000000
const size_t MaxN = 5000000 + 2;
// we could change MaxN at will:
// it just affects performance, not the result

// identify chain lengths we haven't computed so far
const int Unknown = -1;
// store chain lengths
std::vector<short> cache(MaxN, Unknown);

// recursively count steps of Collatz sequence
unsigned short steps(unsigned long long x)
{
  // finished recursion ?
  if (x == 1)
    return 1;

  // try to use cached result
  if (x < cache.size() && cache[x] != Unknown)
    return cache[x];

  // next step
  long long next;
  if (x % 2 == 0)
    next = x / 2;
  else
    next = 3 * x + 1;

  // deeper recursion
  auto result = 1 + steps(next);
  if (x < cache.size())
    cache[x] = result;

  return result;
}

int main()
{
  // [smallest number] => [chain length]
  std::map<unsigned int, unsigned int> longest;
  // highest number analyzed so far
  unsigned int maxTested = 1;
  longest[maxTested] = 1; // obvious case

  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int x;
    std::cin >> x;

    // compute remaining chain lengths
    for (; maxTested <= x; maxTested++)
    {
      // get chain length
      auto length = steps(maxTested);
      // at least as long as anything we have seen before ?
      if (length >= longest.rbegin()->second)
        longest[maxTested] = length;
    }

    // find next longest chain for numbers bigger than x
    auto best = longest.upper_bound(x);
    // and go one step back
    best--;

    std::cout << best->first << std::endl;
  }
  return 0;
}