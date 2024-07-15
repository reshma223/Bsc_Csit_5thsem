#include <stdio.h>
int gcd(int a, int b);
int main() {
int num1, num2;
printf("Enter two integers: ");
scanf("%d %d", &num1, &num2);
int result = gcd(num1, num2);
printf("GCD of %d and %d is %d\n", num1, num2, result);
return 0;
}
// Function to calculate GCD using the Euclidean algorithm
int gcd(int a, int b) {
while (b != 0) {
int temp = b;
b = a % b;
a = temp;
}
return a;
} 