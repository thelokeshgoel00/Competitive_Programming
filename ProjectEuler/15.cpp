     #include <vector>
#include <deque>
#include <utility>
#include <iostream>

int main()
{
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int width, height;
    std::cin >> width >> height;

    // create a 2D array which contains the number of paths
    // from the current lattice point to the lower-right corner
    // there are (width + 1) * (height + 1) such points
    // for the original problem, i.e. 21x21 numbers must be found
    const unsigned long long Unknown = 0;
    std::vector<std::vector<unsigned long long>> grid(width + 1);
    for (auto& column : grid)
      column.resize(height + 1, Unknown);

    // one route if we are already at the goal
    grid[width][height] = 1;

    // enqueue the next unprocessed lattice points: left and upper neighbor of the lower-right corner
    std::deque<std::pair<unsigned int, unsigned int>> next;
    next.push_back(std::make_pair(width - 1, height));
    next.push_back(std::make_pair(width, height - 1));

    // as long as there are unprocessed points
    while (!next.empty())
    {
      // get next point
      auto current = next.front();
      next.pop_front();

      // I prefer names which are easier to read ...
      auto x = current.first;
      auto y = current.second;

      // already solved ?
      if (grid[x][y] != Unknown)
        continue;

      // sum of all path when going right plus when going down
      unsigned long long routes = 0;
      if (x < width)  // can go right ?
        routes += grid[x + 1][y];
      if (y < height) // can go down ?
        routes += grid[x][y + 1];

#define ORIGINAL
#ifndef ORIGINAL
      routes %= 1000000007; // Hackerrank wants the result MOD 10^9 + 7
#endif
      // solved number for current lattice point
      grid[x][y] = routes;

      // add left and upper neighbors for further processing
      if (x > 0)
        next.push_back(std::make_pair(x - 1, y));
      if (y > 0)
        next.push_back(std::make_pair(x, y - 1));
    }

    // we are done !
    std::cout << grid[0][0] << std::endl;
  }
  return 0;
}