#include <stdio.h>
int find_gcd(int a, int b) {
int temp;
while (b != 0) {
temp = b;
b = a % b;
a = temp;
}
return a;
}
int main() {
int num1, num2;
printf("Enter the first number: ");
scanf("%d", &num1);
printf("Enter the second number: ");
scanf("%d", &num2);
int gcd_result = find_gcd(num1, num2);
printf("The GCD of %d and %d is: %d\n", num1, num2, gcd_result);
return 0;
}