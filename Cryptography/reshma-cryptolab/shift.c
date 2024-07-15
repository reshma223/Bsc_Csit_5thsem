#include <stdio.h>
#include <string.h>
#include <ctype.h>
void shiftCipherEncrypt(char plaintext[], int shift) {
int length = strlen(plaintext);
for (int i = 0; i < length; i++) {
char currentChar = plaintext[i];
if (isalpha(currentChar)) {
char base = (isupper(currentChar)) ? 'A' : 'a';
char encryptedChar = ((currentChar - base + shift) % 26) + base;
plaintext[i] = encryptedChar;
}}}
int main() {
char plaintext[100];
int shift;
printf("Enter the plaintext: ");
gets(plaintext);
printf("Enter the shift value: ");
scanf("%d", &shift);
shiftCipherEncrypt(plaintext, shift);
printf("Encrypted text: %s\n", plaintext);
return 0;
}
