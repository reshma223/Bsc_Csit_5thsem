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
void randomizedQuickSort(int arr[], int low, int high) {
if (low < high) {
shuffle(arr + low, high - low + 1);
int pivotIndex = partition(arr, low, high);
randomizedQuickSort(arr, low, pivotIndex - 1);
randomizedQuickSort(arr, pivotIndex + 1, high);
}}
int main() {
int size;
printf("Enter the size of the array: ");
scanf("%d", &size);
int arr[size];
printf("Enter %d elements:\n", size);
for (int i = 0; i < size; i++) {
scanf("%d", &arr[i]);
}
randomizedQuickSort(arr, 0, size - 1);
printf("Sorted array using Randomized Quick Sort:\n");
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
return 0;
}