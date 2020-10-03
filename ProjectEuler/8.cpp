#include <iostream>
#include <string>
using namespace std;
int main()
{
  unsigned int tests;
  cin >> tests;
  while (tests--)
  {
    // length of string
    unsigned int length;
    // number of relevant consecutive digits
    unsigned int span;
    // read number as a string
    string number;
    cin >> length >> span >> number;

    // results can be much bigger than 32 bits ... but 64 bits are enough, though
    unsigned long long best = 0;
    // loop ends when there are less than "span" digits left
    for (int start = 0; start + span < length; start++)
    {
      unsigned long long current = 1;
      // convert digits from ASCII to numbers and multiply
      for (unsigned int i = 0; i < span; i++)
        current *= number[start + i] - '0';

      // better than before ?
      if (best < current)
        best = current;
    }

    cout << best << endl;
  }
  return 0;
}