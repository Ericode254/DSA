#include <stdio.h>

// NOTE: The search can take any data type as a parameter to search, even user defined data types
int search(int nums[], int target, int size);

int main()
{
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(numbers) / sizeof(int);

  search(numbers, 10, size);

  return 0;
}

// a function for searching for the Item
int search(int nums[], int target, int size) {
  if (size == 0) {
    printf("Nothing to search for\n");
    return -1;
  }

  for (int i = 0; i < size; i++) {
    if (target == nums[i]) {
      printf("Item found");
      return nums[i];
    }
  }

  printf("Item not found");
  return -1;
}
