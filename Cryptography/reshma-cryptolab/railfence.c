#include <stdio.h>
#include <string.h>
void railFenceEncrypt(char *plaintext, int rails, char *ciphertext);
void railFenceDecrypt(char *ciphertext, int rails, char *decryptedtext);
int main() {
    int rails;
    char plaintext[1000];
    char ciphertext[1000];
    char decryptedtext[1000];
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    printf("Enter the plaintext: ");
    scanf(" %[^\n]s", plaintext);
    railFenceEncrypt(plaintext, rails, ciphertext);
    printf("Encrypted: %s\n", ciphertext);
    railFenceDecrypt(ciphertext, rails, decryptedtext);
    printf("Decrypted: %s\n", decryptedtext);
    return 0;
}
void railFenceEncrypt(char *plaintext, int rails, char *ciphertext) {
    int len = strlen(plaintext);
    char railMatrix[rails][len];
    // Initialize railMatrix with zeros
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            railMatrix[i][j] = 0;
        } }
    // Fill the railMatrix with the plaintext characters
    int row = 0;
    int direction = 1; // Direction: 1 for downward, -1 for upward
    for (int i = 0; i < len; i++) {
        railMatrix[row][i] = plaintext[i];
        if (row == 0) {
            direction = 1;
        } else if (row == rails - 1) {
            direction = -1;
        }
        row += direction;
    }
    int k = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (railMatrix[i][j] != 0) {
                ciphertext[k++] = railMatrix[i][j];
            } } }
    ciphertext[k] = '\0';
}
void railFenceDecrypt(char *ciphertext, int rails, char *decryptedtext) {
    int len = strlen(ciphertext);
    char railMatrix[rails][len];
    // Initialize railMatrix with zeros
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            railMatrix[i][j] = 0;
        } }
    // Fill the railMatrix with placeholders
    int row = 0;
    int direction = 1; // Direction: 1 for downward, -1 for upward
    for (int i = 0; i < len; i++) {
        railMatrix[row][i] = -1; // Placeholder
        if (row == 0) {
            direction = 1;
        } else if (row == rails - 1) {
            direction = -1;
        }
        row += direction;
    }
    row = 0;
    for (int i = 0; i < len; i++) {
        railMatrix[row][i] = '*';
        if (row == 0) {
            direction = 1;
        } else if (row == rails - 1) {
            direction = -1;
        }

        row += direction;
    }
    int k = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (railMatrix[i][j] == '*' && ciphertext[k] != '\0') {
                railMatrix[i][j] = ciphertext[k++];
            }}}
    row = 0;
    direction = 1;
    for (int i = 0; i < len; i++) {
        decryptedtext[i] = railMatrix[row][i];
        if (row == 0) {
            direction = 1;
        } else if (row == rails - 1) {
            direction = -1;
        }
        row += direction;
    }
    decryptedtext[len] = '\0';
}
