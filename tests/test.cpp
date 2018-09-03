#include <cassert>

#include "square.hpp"

int main()
{
  assert(my_square(0) == 0);
  assert(my_square(2) == 4);
  assert(my_square(-2) == 4);
  return 0;
}
