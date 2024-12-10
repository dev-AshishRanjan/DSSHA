#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../murmur.h"
#include "../constants.h"
#include "../hexa.h"
#include "../prime.h"

#include "dsshf-1D.h"
#include "dsshf-2D.h"
#include "dsshf-3D.h"

#define DEFAULT_KEY "DSSHF"
#define DEFAULT_SEED 198899
#define DEFAULT_BIT_SIZE 512

void getUserInput(char *key, unsigned int *seed, int *bit_size)
{
  printf("Enter a key (or press Enter to use default \"%s\"): ", DEFAULT_KEY);
  fgets(key, 1024, stdin);
  if (key[0] == '\n')
  { // No input provided
    strcpy(key, DEFAULT_KEY);
  }
  else
  {
    key[strcspn(key, "\n")] = 0; // Remove newline character
  }

  char buffer[128];
  printf("Enter a seed (or press Enter to use default %u): ", DEFAULT_SEED);
  fgets(buffer, 128, stdin);
  if (buffer[0] == '\n')
  {
    *seed = DEFAULT_SEED;
  }
  else
  {
    *seed = (unsigned int)atoi(buffer);
  }

  printf("Enter a bit size (or press Enter to use default %d): ", DEFAULT_BIT_SIZE);
  fgets(buffer, 128, stdin);
  if (buffer[0] == '\n')
  {
    *bit_size = DEFAULT_BIT_SIZE;
  }
  else
  {
    *bit_size = atoi(buffer);
  }
}

int main()
{
  char key[1024];
  unsigned int seed;
  int bit_size;
  int choice;

  // welcome message
  printf("\n######\nDSSHF: Dynamic-Sized Secure Hash Function\n######\n");

  // Get user inputs
  getUserInput(key, &seed, &bit_size);

  // Choose hashing function
  printf("\nChoose the hashing function:\n");
  printf("1. DSSHF-1D\n");
  printf("2. DSSHF-2D\n");
  printf("3. DSSHF-3D\n");
  printf("Enter your choice (1, 2, or 3): ");
  scanf("%d", &choice);

  char *hash_value = (char *)malloc((bit_size / 4 + 2) * sizeof(char) + 1);
  if (!hash_value)
  {
    printf("Memory allocation failed!\n");
    return 1;
  }

  switch (choice)
  {
  case 1:
    genHash1d(key, seed, bit_size, hash_value);
    break;
  case 2:
    genHash2d(key, seed, bit_size, hash_value);
    break;
  case 3:
    genHash3d(key, seed, bit_size, hash_value);
    break;
  default:
    printf("Invalid choice! Please restart the program.\n");
    free(hash_value);
    return 1;
  }

  // Display the hash value
  printf("\nThe generated hash value is:\n%s\n", hash_value);

  // Clean up and exit
  free(hash_value);
  printf("\nSuccessfully completed...\n");
  return 0;
}
