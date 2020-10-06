#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  unsigned int tests = 1;

//#define ORIGINAL
#ifndef ORIGINAL
  std::cin >> tests;
#endif

  while (tests--)
  {
    unsigned int numRows = 15;
#ifndef ORIGINAL
    std::cin >> numRows;
#endif

    // process input row-by-row
    // each time a number is read we add it to the two numbers above it
    // choose the bigger sum and store it
    // if all rows are finished, find the largest number in the last row

    // read first line, just one number
    std::vector<unsigned int> last(1);
    std::cin >> last[0];

    // read the remaining lines
    for (unsigned int row = 1; row < numRows; row++)
    {
      // prepare array for new row
      unsigned int numElements = row + 1;
      std::vector<unsigned int> current;

      // read all numbers of current row
      for (unsigned int column = 0; column < numElements; column++)
      {
        unsigned int x;
        std::cin >> x;

        // find sum of elements in row above (going a half step to the left)
        unsigned int leftParent = 0;
        // only if left  parent is available
        if (column > 0)
          leftParent = last[column - 1];

        // find sum of elements in row above (going a half step to the right)
        unsigned int rightParent = 0;
        // only if right parent is available
        if (column < last.size())
          rightParent = last[column];

        // add larger parent to current input
        unsigned int sum = x + std::max(leftParent, rightParent);
        // and store this sum
        current.push_back(sum);
      }

      // row is finished, it become the "parent" row
      last = current;
    }

    // find largest sum in final row
    std::cout << *std::max_element(last.begin(), last.end()) << std::endl;
  }

  return 0;
}