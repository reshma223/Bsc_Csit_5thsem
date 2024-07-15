#include <stdio.h>
int gcd(int a, int b);
int areCoprime(int num1, int num2);
int main() {
int num1, num2;
printf("Enter two integers: ");
scanf("%d %d", &num1, &num2);
if (areCoprime(num1, num2)) {
printf("%d and %d are coprime.\n", num1, num2);
} else {
printf("%d and %d are not coprime.\n", num1, num2);
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
// Function to check if two numbers are coprime
int areCoprime(int num1, int num2) {
return gcd(num1, num2) == 1;
}
