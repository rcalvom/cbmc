#include <assert.h>
#include <stdio.h>

int main()
{
  // %p without its argument must not crash the trace output
  printf("PRINT p1 %p\n");
  assert(0);
}
