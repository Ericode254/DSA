#include <stdio.h>

// NOTE: The algorithm can be used to sort any data type not only integers
void bubbleSort(int nums[], int size);

int main()
{
  int numbers[] = {5, 3, 4, 1, 2};
  int size = sizeof(numbers) / sizeof(int);

  bubbleSort(numbers, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }

  return 0;
}

// a function for sorting the items in place
void bubbleSort(int nums[], int size) {
  if (size == 0) {
    printf("Nothing to sort");
    return;
  }

  for (int i = 0; i < size; i++) {
    for (int j = i+1; j < size; j++) {
      if (nums[i] > nums[j]) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
      }
    }
  }
}
