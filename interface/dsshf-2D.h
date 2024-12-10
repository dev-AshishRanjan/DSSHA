#include <stdio.h>
#include <math.h>
// #include "murmur.h"
// #include "constants.h"
// #include "hexa.h"
// #include "prime.h"

int getDim2d(unsigned int seed)
{
  unsigned int t = seed % 9973; // 9781//9769;//
  unsigned int dim;
  dim = sqrt(t);
  return ((dim < 16) ? (dim + 16) : dim);
}

unsigned int getSeedValue2d(char *key, int l, unsigned int seed)
{
  int i;
  for (i = 0; i < 32; i++)
    seed = (unsigned int)murmur3(key, l, seed);
  return seed;
}

void genHash2d(char *key, unsigned int seed, int bit_size, char *hash_value)
{

  int s, t, r, c, X, Y;
  int i = 0, j = 0, k = 0, l = 0, counter = 0;
  int pos, bit;
  char *hash_bits = (char *)malloc(bit_size * sizeof(char) + 1);
  for (l = 0; key[l] != '\0'; l++)
    ;
  seed = (unsigned int)getSeedValue2d(key, l, seed);
  seed = tab[seed % 2293];
  seed = getSeedValue2d(key, l, seed);
  r = getDim2d(seed);
  while (1)
  {
    seed = (unsigned int)murmur3(key, l, seed);
    c = getDim2d(seed);
    if (r != c)
      break;
  }
  X = prime[r]; // X!=Y, i.e., X cannot be equal to Y
  Y = prime[c];
  printf("Vector dimensions are X:%d  Y:%d\n", X, Y);
  char **vector = (char **)malloc(X * sizeof(char *));

  if (vector == NULL)
  {
    printf("Unable to allocate!\n");
    return;
  }
  for (i = 0; i < X; i++)
  {
    vector[i] = (char *)malloc(Y * sizeof(char));
    if (vector == NULL)
    {
      printf("Unable to allocate!\n");
      return;
    }
  }
  seed = seed ^ bit_size;
  // Filling the vector with 0s and 1s.
  for (i = 0; i < X; i++)
  {
    for (j = 0; j < Y; j++)
    {
      seed = (unsigned int)murmur3(key, l, seed); // hash function calls for bit value.
      pos = seed % 31;
      bit = (seed & (1 << pos)) >> pos;
      vector[i][j] = bit;
      seed = (unsigned int)murmur3(key, l, seed); // hash function calls for seed value.
    }
  }

  for (k = 0; k < bit_size; k++)
  {
    seed = (unsigned int)getSeedValue2d(key, l, seed);
    i = seed % X;
    seed = (unsigned int)getSeedValue2d(key, l, seed);
    j = seed % Y;
    hash_bits[k] = vector[i][j];
  }
  conIntoHex(hash_bits, bit_size, hash_value);
}