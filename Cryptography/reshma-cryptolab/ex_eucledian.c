#include <stdio.h>
int extendedGCD(int a, int b, int *x, int *y);
int main() {
int a, b, x, y;
printf("Enter two integers (a and b): ");
scanf("%d %d", &a, &b);
int gcd = extendedGCD(a, b, &x, &y);
printf("GCD(%d, %d) = %d\n", a, b, gcd);
printf("Coefficients (x, y) of Bézout's identity: x = %d, y = %d\n", x, y);
return 0;
}
// Function to calculate the extended GCD using the Extended Euclidean Algorithm
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
