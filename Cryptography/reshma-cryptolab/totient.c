#include <stdio.h>
int gcd(int a, int b);
int totient(int n);
int main() {
int n;
printf("Enter a positive integer: ");
scanf("%d", &n);
if (n <= 0) {
printf("Please enter a positive integer.\n");
} else {
int phi = totient(n);
printf("The totient (φ) of %d is %d\n", n, phi);
}
return 0;
}
// Function to calculate the greatest common divisor (GCD) using Euclidean algorithm
int gcd(int a, int b) {
while (b != 0) {
int temp = b;
b = a % b;
a = temp;
}
return a;
}
// Function to compute the totient (φ) of a number n
int totient(int n) {
int result = 1; // Initialize result with 1 (for 1 itself)
for (int i = 2; i < n; i++) {
if (gcd(i, n) == 1) {
result++;
}}
return result;
}
