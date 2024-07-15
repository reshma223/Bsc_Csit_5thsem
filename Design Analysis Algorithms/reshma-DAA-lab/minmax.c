#include <stdio.h>
struct MinMax {
int min;
int max;
};
struct MinMax findMinMax(int arr[], int low, int high) {
struct MinMax result, left, right;
int mid;
if (low == high) {
result.min = arr[low];
result.max = arr[low];
return result;
}
if (high == low + 1) {
if (arr[low] > arr[high]) {
result.max = arr[low];
result.min = arr[high];
} else {
result.min = arr[low];
result.max = arr[high];
}
return result;
}
mid = (low + high) / 2;
left = findMinMax(arr, low, mid);
right = findMinMax(arr, mid + 1, high);
result.min = (left.min < right.min) ? left.min : right.min;
result.max = (left.max > right.max) ? left.max : right.max;
return result;
}
int main() {
int size;
printf("Enter the size of the array: ");
scanf("%d", &size);

int arr[size];
printf("Enter %d elements:\n", size);
for (int i = 0; i < size; i++) {
scanf("%d", &arr[i]);
}
struct MinMax result = findMinMax(arr, 0, size - 1);
printf("Minimum element: %d\n", result.min);
printf("Maximum element: %d\n", result.max);
return 0;
}