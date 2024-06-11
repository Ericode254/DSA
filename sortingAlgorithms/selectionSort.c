#include <stdio.h>

void selectionSort(int nums[], int size);

int main()
{
  int numbers[] = {5, 4, 3, 2, 1};
  int size = sizeof(numbers) / sizeof(int);

  selectionSort(numbers, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }

  return 0;
}

// a function for sorting the items
void selectionSort(int nums[], int size) {
  for (int i = 0, j = 0, least = 0; i < size - 1; i++) {
    for (j = i+1, least = i; j < size; j++) {
      if (nums[j] < nums[least]) {
        least = j;
      }
    }

    int temp = nums[least];
    nums[least] = nums[i];
    nums[i] = temp;
  }
}
