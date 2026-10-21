// clang-format off
#include <stdint.h>
#include <stdio.h>

uint16_t nondet_uint16_t(void);

// instrumented after foo, so its body is inlined uninstrumented
void zz_log(uint16_t n)
{
  printf("%d\n", n);
}

void foo(void)
{
  uint16_t n = nondet_uint16_t();
  int i;
  for(i = 0; i < 3; i++)
    __CPROVER_assigns(i)
    __CPROVER_loop_invariant(0 <= i && i <= 3)
  {
    // variadic calls with an integer variadic argument, direct and indirect
    printf("%d\n", n);
    zz_log(n);
  }
}

int main(void)
{
  foo();
  return 0;
}
// clang-format on
