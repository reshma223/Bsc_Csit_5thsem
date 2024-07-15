#include <stdio.h>
void heapify(int arr[], int size, int i) {
int largest = i; // Initialize largest as root
int left = 2 * i + 1; // Left child
int right = 2 * i + 2; // Right child

if (left < size && arr[left] > arr[largest])
largest = left;
if (right < size && arr[right] > arr[largest])
largest = right;
if (largest != i) {
int temp = arr[i];
arr[i] = arr[largest];
arr[largest] = temp;
heapify(arr, size, largest);
}
}
void heapSort(int arr[], int size) {
for (int i = size / 2 - 1; i >= 0; i--)
heapify(arr, size, i);
for (int i = size - 1; i > 0; i--) {
int temp = arr[0];
arr[0] = arr[i];
arr[i] = temp;
heapify(arr, i, 0);
}
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

heapSort(arr, size);
printf("Sorted array using Heap Sort:\n");
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
return 0;
}