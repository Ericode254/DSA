#include <stdio.h>

// NOTE: The search function can be modified to sustain any other data type including user defined
int search(int nums[], int target, int low, int high);

int main()
{
 int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

 search(numbers, 9, 0, 9);

  return 0;
}

// a function for searching for the item
// NOTE: For the function to work as expected the array of items must be sorted
int search(int nums[], int target, int low, int high) {
  int medium = (low + high) / 2;

  if (target == nums[medium]) {
    printf("Item found");
    return nums[medium];
  } else if (target < medium) {
    return search(nums, target, low, medium);
  } else {
    return search(nums, target, medium, high);
  }
}
