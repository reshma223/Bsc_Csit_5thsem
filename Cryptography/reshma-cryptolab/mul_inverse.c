#include <stdio.h>

int isMultiplicativeInverse(int num1, int num2, int mod);

int main() {
    int num1, num2, mod;
    printf("Enter two integers and the modulus (mod): ");
    scanf("%d %d %d", &num1, &num2, &mod);

    int result = isMultiplicativeInverse(num1, num2, mod);

    if (result) {
        printf("%d is the multiplicative inverse of %d (mod %d)\n", num1, num2, mod);
    } else {
        printf("%d is not the multiplicative inverse of %d (mod %d)\n", num1, num2, mod);
    }

    return 0;
}

// Function to check if num1 is the multiplicative inverse of num2 modulo mod
int isMultiplicativeInverse(int num1, int num2, int mod) {
    int product = (num1 * num2) % mod;

    // If the product is 1, then num1 is the multiplicative inverse of num2 (mod mod)
    return product == 1;
}
