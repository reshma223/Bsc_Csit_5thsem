#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Function to calculate modular exponentiation (base^exponent % mod)
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
// Function to calculate the greatest common divisor (GCD) using Euclidean algorithm
long long int gcd(long long int a, long long int b) {
while (b != 0) {
long long int temp = b;
b = a % b;
a = temp;
}
return a;
}
// Function to calculate modular inverse using Extended Euclidean Algorithm
long long int mod_inverse(long long int a, long long int m) {
long long int m0 = m, t, q;
long long int x0 = 0, x1 = 1;
while (a > 1) {
// q is quotient
q = a / m;
t = m;
// m is remainder now; process same as Euclid's Algorithm
m = a % m;
a = t;
t = x0;
x0 = x1 - q * x0;
x1 = t;
}
// Make x1 positive
if (x1 < 0) {
x1 += m0;
}
return x1;
}
// Function to check if a number is prime
int is_prime(long long int num) {
if (num <= 1) {
return 0; // Not prime
}
if (num <= 3) {
return 1; // Prime
}
if (num % 2 == 0 || num % 3 == 0) {
return 0; // Not prime
}
for (long long int i = 5; i * i <= num; i += 6) {
if (num % i == 0 || num % (i + 2) == 0) {
return 0; // Not prime
}
}
return 1; // Prime
}
int main() {
long long int p, q, n, phi, e, d;
long long int plaintext, ciphertext;
// Step 1: Choose two large prime numbers 'p' and 'q'
printf("Enter prime number p: ");
scanf("%lld", &p);
printf("Enter prime number q: ");
scanf("%lld", &q);
if (!is_prime(p) || !is_prime(q)) {
printf("Both p and q must be prime numbers.\n");
return 1;
}
// Step 2: Compute 'n' as the product of 'p' and 'q'
n = p * q;
// Step 3: Compute Euler's totient function 'phi(n)'
phi = (p - 1) * (q - 1);
// Step 4: Choose an integer 'e' such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
e = 2; // Initial guess for 'e'
while (e < phi) {
if (gcd(e, phi) == 1) {
break;
}
e++;
}
// Step 5: Compute the modular multiplicative inverse 'd' of 'e' modulo 'phi(n)'
d = mod_inverse(e, phi);
printf("Public key (n, e): (%lld, %lld)\n", n, e);
printf("Private key (d): %lld\n", d);
// Step 6: Encryption
printf("Enter plaintext (integer): ");
scanf("%lld", &plaintext);
ciphertext = mod_pow(plaintext, e, n);
printf("Ciphertext: %lld\n", ciphertext);
// Step 7: Decryption
long long int decrypted = mod_pow(ciphertext, d, n);
printf("Decrypted: %lld\n", decrypted);
return 0;
}
