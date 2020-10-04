#include <iostream>

int main()
{
  // always a 20x20 matrix
  const unsigned int Size = 20;
  unsigned int matrix[Size][Size];

  // read from console
  for (unsigned int y = 0; y < Size; y++)
    for (unsigned int x = 0; x < Size; x++)
      std::cin >> matrix[x][y];

  unsigned int best = 0;
  // walk through all cells of the matrix
  for (unsigned int y = 0; y < Size; y++)
    for (unsigned int x = 0; x < Size; x++)
    {
      // three more horizontal cells (right)
      if (x + 3 < Size)
      {
        unsigned int current = matrix[x][y] * matrix[x+1][y] * matrix[x+2][y] * matrix[x+3][y];
        if (best < current)
          best = current;
      }
      // three more vertical cells available (down)
      if (y + 3 < Size)
      {
        unsigned int current = matrix[x][y] * matrix[x][y+1] * matrix[x][y+2] * matrix[x][y+3];
        if (best < current)
          best = current;
      }
      // three more diagonal cells (right-down)
      if (x + 3 < Size && y + 3 < Size)
      {
        unsigned int current = matrix[x][y] * matrix[x+1][y+1] * matrix[x+2][y+2] * matrix[x+3][y+3];
        if (best < current)
          best = current;
      }
      // three more diagonal cells (left-down)
      if (x + 3 < Size && y >= 3)
      {
        unsigned int current = matrix[x][y] * matrix[x+1][y-1] * matrix[x+2][y-2] * matrix[x+3][y-3];
        if (best < current)
          best = current;
      }
    }

  std::cout << best << std::endl;
  return 0;
}