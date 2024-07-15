#include <stdio.h>
int sequentialSearch(int arr[], int size, int key) {
for (int i = 0; i < size; i++) {
if (arr[i] == key) {
return i;
}
}
return -1;
}
int main() {
int size, key;
printf("Enter the size of the array: ");
scanf("%d", &size);
int arr[size];
printf("Enter %d elements:\n", size);
for (int i = 0; i < size; i++) {
scanf("%d", &arr[i]);
}
printf("Enter the element to search: ");
scanf("%d", &key);
int result = sequentialSearch(arr, size, key);
if (result != -1) {
printf("Element %d found at index %d.\n", key, result);
} else {
printf("Element %d not found in the array.\n", key);
}
return 0;
}