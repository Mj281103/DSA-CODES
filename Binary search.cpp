#include <stdio.h>

int binarySearch(int arr[], int target, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
      return mid;
    if (arr[mid] > target)
      return binarySearch(arr, target, low, mid - 1);
    return binarySearch(arr, target, mid + 1, high);
  }

  return -1;
}

int main(void) {
  int numElements;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &numElements);

  int arr[numElements];
  printf("Enter the elements in ascending order: ");
  for (int i = 0; i < numElements; i++) {
    scanf("%d", &arr[i]);
  }

  int searchElement;
  printf("Enter the element to search: ");
  scanf("%d", &searchElement);

  int result = binarySearch(arr, searchElement, 0, numElements - 1);
  if (result == -1)
    printf("Element not found");
  else
    printf("Element found at index: %d\n",result);
}

