int w(int *p, ...)
{
  *p = 1;
  return 0;
}

void foo(int *p, int x)
  // clang-format off
  __CPROVER_requires(__CPROVER_is_fresh(p, sizeof(int)))
  __CPROVER_assigns()
// clang-format on
{
  w(p, x);
}

int main(void)
{
  int a, x;
  foo(&a, x);
  return 0;
}
