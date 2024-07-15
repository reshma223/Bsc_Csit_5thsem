#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shuffle(int arr[], int size) {
srand(time(NULL));
for (int i = size - 1; i > 0; i--) {
int j = rand() % (i + 1);
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}}
int partition(int arr[], int low, int high) {
int pivot = arr[high];
int i = (low - 1);
for (int j = low; j <= high - 1; j++) {
if (arr[j] <= pivot) {
i++;
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}}
int temp = arr[i + 1];
arr[i + 1] = arr[high];
arr[high] = temp;
return i + 1;
}
int randomizedQuickSelect(int arr[], int low, int high, int k) {
if (low <= high) {
shuffle(arr + low, high - low + 1);
int pivotIndex = partition(arr, low, high);
if (pivotIndex == k)
return arr[pivotIndex];
if (pivotIndex > k)
return randomizedQuickSelect(arr, low, pivotIndex - 1, k);
return randomizedQuickSelect(arr, pivotIndex + 1, high, k);
}
return -1;
}
int main() {
int size, k;
printf("Enter the size of the array: ");
scanf("%d", &size);
int arr[size];
printf("Enter %d elements:\n", size);
for (int i = 0; i < size; i++) {
scanf("%d", &arr[i]);
}
printf("Enter the value of k (0-based index): ");
scanf("%d", &k);
if (k >= 0 && k < size) {
int kthElement = randomizedQuickSelect(arr, 0, size - 1, k);
printf("The %dth smallest element is: %d\n", k + 1, kthElement);
} else {
printf("Invalid value of k.\n");
}
return 0;
}