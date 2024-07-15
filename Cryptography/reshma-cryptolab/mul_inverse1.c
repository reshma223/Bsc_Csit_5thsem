#include <stdio.h>
int extendedGCD(int a, int b, int *x, int *y);
int multiplicativeInverse(int a, int m);
int main() {
int a, m;
printf("Enter an integer (a): ");
scanf("%d", &a);
printf("Enter the modulo (m): ");
scanf("%d", &m);
int inverse = multiplicativeInverse(a, m);
if (inverse == -1) {
printf("The multiplicative inverse does not exist.\n");
} else {
printf("The multiplicative inverse of %d modulo %d is %d\n", a, m, inverse);
}
return 0;
}
// Function to calculate the extended GCD of two integers a and b
int extendedGCD(int a, int b, int *x, int *y) {
if (a == 0) {
*x = 0;
*y = 1;
return b;
}
int x1, y1;
int gcd = extendedGCD(b % a, a, &x1, &y1);
*x = y1 - (b / a) * x1;
*y = x1;
return gcd;
}
// Function to compute the multiplicative inverse of 'a' modulo 'm'
int multiplicativeInverse(int a, int m) {
int x, y;
int gcd = extendedGCD(a, m, &x, &y);
if (gcd != 1) {
// The multiplicative inverse does not exist
return -1;
} else {
// Ensure the result is positive
int inverse = (x % m + m) % m;
return inverse;
}}
