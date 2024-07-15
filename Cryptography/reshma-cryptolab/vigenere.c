#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenere_encrypt(char *plain_text, char *key) {
int text_length = strlen(plain_text);
int key_length = strlen(key);
for (int i = 0; i < text_length; i++) {
if (isalpha(plain_text[i])) {
int shift = toupper(key[i % key_length]) - 'A';
if (isupper(plain_text[i])) {
plain_text[i] = ((plain_text[i] - 'A' + shift) % 26) + 'A';
} else {
plain_text[i] = ((plain_text[i] - 'a' + shift) % 26) + 'a';
}}}}
void vigenere_decrypt(char *encrypted_text, char *key) {
int text_length = strlen(encrypted_text);
int key_length = strlen(key);
for (int i = 0; i < text_length; i++) {
if (isalpha(encrypted_text[i])) {
int shift = toupper(key[i % key_length]) - 'A';
if (isupper(encrypted_text[i])) {
encrypted_text[i] = ((encrypted_text[i] - 'A' - shift + 26) % 26) + 'A';
} else {
encrypted_text[i] = ((encrypted_text[i] - 'a' - shift + 26) % 26) + 'a';
}}}}
int main() {
char plain_text[1000];
char key[100];
printf("Enter the plain text: ");
fgets(plain_text, sizeof(plain_text), stdin);
printf("Enter the key: ");
scanf("%s", key);
vigenere_encrypt(plain_text, key);
printf("Encrypted Text: %s\n", plain_text);
vigenere_decrypt(plain_text, key);
printf("Decrypted Text: %s\n", plain_text);
return 0;
}
