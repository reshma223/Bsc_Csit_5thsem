#include <stdio.h>
#define MAX_SIZE 100
int isSubsetSum(int set[], int n, int sum) {
if (sum == 0) {
return 1;
}
if (n == 0 && sum != 0) {
return 0;
}
if (set[n - 1] > sum) {
return isSubsetSum(set, n - 1, sum);
}
return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}
int main() {
int set[] = {3, 34, 4, 12, 5, 2};
int n = sizeof(set) / sizeof(set[0]);
int sum = 9;
if (isSubsetSum(set, n, sum)) {
printf("Subset with sum %d exists.\n", sum);
} else {
printf("Subset with sum %d does not exist.\n", sum);
}return 0;
}