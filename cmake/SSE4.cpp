#include <immintrin.h>
#include <stdio.h>

int main() {
  __m128i a{1, 4};
  __m128i b{4, 1};
  __m128i r = _mm_mul_epi32(a, b);
  if (r[0] == r[1])
    printf("r0: %lli\tr1: %lli\n", r[0], r[1]);
  return 0;
  return -1;
}