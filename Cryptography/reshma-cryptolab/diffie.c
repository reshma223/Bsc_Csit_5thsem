#include <stdio.h>
#include <stdlib.h>
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
int main() {
long long int p, g; // Publicly known prime number 'p' and primitive root 'g'
long long int a, b; // Secret private keys for Alice and Bob
long long int A, B; // Public keys for Alice and Bob
long long int sharedSecretA, sharedSecretB; // Shared secret keys for Alice and Bob
// Step 1: Both parties agree on a prime number 'p' and a primitive root 'g'
printf("Enter a prime number (p): ");
scanf("%lld", &p);
printf("Enter a primitive root (g): ");
scanf("%lld", &g);
// Step 2: Both parties choose secret private keys 'a' and 'b'
printf("Alice: Enter a secret private key (a): ");
scanf("%lld", &a);
printf("Bob: Enter a secret private key (b): ");
scanf("%lld", &b);
// Step 3: Both parties calculate their public keys 'A' and 'B'
A = mod_pow(g, a, p);
B = mod_pow(g, b, p);
// Step 4: Both parties exchange their public keys 'A' and 'B'
// Step 5: Both parties calculate the shared secret key
sharedSecretA = mod_pow(B, a, p);
sharedSecretB = mod_pow(A, b, p);
// Step 6: Verify that both shared secret keys are the same
if (sharedSecretA == sharedSecretB) {
printf("Shared secret key: %lld\n", sharedSecretA);
printf("Key exchange successful!\n");
} else {
printf("Key exchange failed. Shared secrets do not match.\n");
}
return 0;
}
