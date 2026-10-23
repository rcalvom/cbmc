int main()
{
  char a[16];
  unsigned n;
  if(n < 16)
    __CPROVER_assert(
      __CPROVER_exists {
        unsigned k;
        n <= k && k < 16 && a[k] == 0
      },
      "a zero at or after n");
  __CPROVER_assert(n != 3, "n is not 3");
  return 0;
}
