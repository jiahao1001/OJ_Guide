#include <cstdio>

int main() {
  int f[31];
  f[0] = 1;
  f[1] = 1;

// Compute fibonacci Sequence here
  for(int i = 2; i < 31; i++)
    f[i] = f[i - 1] + f[i - 2];

  // Print everything in the array
  for(int i = 0; i < 31; i++)
    printf("%d\n", f[i]);

  return 0;
}
