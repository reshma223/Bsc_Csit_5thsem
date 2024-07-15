#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
// Function to calculate (base^exponent) % mod
long long int mod_pow(long long int base, long long int exponent, long long int mod) {
long long int result = 1;
base = base % mod;
while (exponent > 0) {
if (exponent % 2 == 1) {
result = (result * base) % mod;
}
base = (base * base) % mod;
exponent = exponent / 2;
}
return result;
}
// Miller-Rabin primality test
bool isPrimeMillerRabin(long long int num, int k) {
if (num <= 1 || num == 4) {
return false;
}
if (num <= 3) {
return true;
}
// Find r and d such that num-1 = 2^r * d
long long int d = num - 1;
int r = 0;
while (d % 2 == 0) {
d /= 2;
r++;
}
// Witness loop
for (int i = 0; i < k; i++) {
long long int a = 2 + rand() % (num - 4);
long long int x = mod_pow(a, d, num);
if (x == 1 || x == num - 1) {
continue;
}
for (int j = 0; j < r - 1; j++) {
x = mod_pow(x, 2, num);
if (x == num - 1) {
break;
}
if (x == 1) {
return false;
}}
if (x != num - 1) {
return false;
}}
return true;
}
int main() {
long long int num;
int k = 10; // Number of iterations (adjust as needed for desired accuracy)
printf("Enter a positive integer: ");
scanf("%lld", &num);
if (isPrimeMillerRabin(num, k)) {
printf("%lld is likely a prime number.\n", num);
} else {
printf("%lld is not a prime number.\n", num);
}
return 0;
}
