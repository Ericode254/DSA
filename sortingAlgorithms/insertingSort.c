#include <stdio.h>

// NOTE: The algorithm can be used to sort any data type not only integers
void insertSort(int nums[], int size);

int main()
{
  int numbers[] = {5, 4, 3, 2, 1};
  int size = sizeof(numbers) / sizeof(int);

  insertSort(numbers, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }

  return 0;
}

// a function for sorting the items 
void insertSort(int nums[], int size) {
  for (int i = 1, j = 0; i < size; i++) {
    int temp = nums[i];

    for (int j = i; j > 0 && temp < nums[j-1]; j--) {
      nums[j] = nums[j-1];
    }

    nums[j] = temp;
  }
}
