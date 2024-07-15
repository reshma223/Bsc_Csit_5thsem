#include <stdio.h>
void insertionSort(int arr[], int size) {
int i, key, j;
for (i = 1; i < size; i++) {
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}}
int main() {
int size;
printf("Enter the size of the array: ");
scanf("%d", &size);
int arr[size];
printf("Enter %d elements:\n", size);
for (int i = 0; i < size; i++) {
scanf("%d", &arr[i]);}
insertionSort(arr, size);
printf("Sorted array using Insertion Sort:\n");
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);}
printf("\n");
return 0;
}