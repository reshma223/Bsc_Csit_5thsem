#include <stdio.h>
void selectionSort(int arr[], int size) {
int i, j, minIndex, temp;
for (i = 0; i < size - 1; i++) {
minIndex = i;
for (j = i + 1; j < size; j++) {
if (arr[j] < arr[minIndex]) {
minIndex = j;
}}
temp = arr[minIndex];
arr[minIndex] = arr[i];
arr[i] = temp;
}}
int main() {
int size;
printf("Enter the size of the array: ");
scanf("%d", &size);
int arr[size];
printf("Enter %d elements:\n", size);
for (int i = 0; i < size; i++) {
scanf("%d", &arr[i]);}
selectionSort(arr, size);
printf("Sorted array using Selection Sort:\n");
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);}
printf("\n");
return 0;
}