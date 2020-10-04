#include <string>
#include <vector>
#include <iostream>

int main()
{
  // store each digit separately
  // input has 50 digits
  // highest digits might overflow and require a few extra digits
  // (I believe +2 would suffice, too)
  const unsigned int MinDigits = 50 + 10;
  // all digits are initially zero, least significant has index 0
  std::vector<unsigned int> sum(MinDigits, 0);
  // the resulting number will be sum[0] + 10*sum[1] + 100*sum[2] + ...

  unsigned int numbers = 100;

//#define ORIGINAL
#ifndef ORIGINAL
  std::cin >> numbers;
#endif

  while (numbers--)
  {
    // read a single number as a string
    std::string strAdd;
    std::cin >> strAdd;

    // convert to digits
    std::vector<unsigned int> add;
    // process string in reverse: least significant digits first
    for (auto i = strAdd.rbegin(); i != strAdd.rend(); i++)
      add.push_back(*i - '0'); // convert from ASCII
    // fill high/unused positions with zeros
    add.resize(sum.size(), 0);

    // add all digits
    for (unsigned int i = 0; i < add.size(); i++)
    {
      sum[i] += add[i];

      // overflow ? => sum[i] is 10 .. 18
      if (sum[i] >= 10)
      {
        sum[i + 1]++; // sum[i + 1] = sum[i] % 10
        sum[i] -= 10; // sum[i]    %= 10
      }
    }
  }

  // skip high zeros
  auto i = sum.rbegin();
  while (*i == 0)
    i++;

  // print first ten digits
  unsigned int numDigits = 10;
  while (numDigits-- > 0)
    std::cout << *i++;

  return 0;
}