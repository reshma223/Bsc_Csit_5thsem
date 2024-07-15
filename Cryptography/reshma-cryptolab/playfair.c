#include <stdio.h>
#include <string.h>

char plain_text[60] = {}, cipher_text[60] = {}, starting_key[60] = {}, key[60] = {};
int plain_text_value[60] = {}, cipher_text_value[60] = {};
int text_len = 0, key_len = 0;
int white_space_position[60] = {};
int white_space_len;
int case_status[60] = {};
char starting_square_elements[26] = {}, square_elements[25] = {};
char square[5][5];
char digraphs[60] = {};
char cipher_digraphs[60] = {};
int vowel_array_position[5] = {0, 4, 8, 14, 20};

void getPlainText(void);
void removeWhiteSpace(char[], char[]);
void displayPlainText(void);
void getKey(void);
void removeRedundantCharacter(char[], char[], char[]);
void processSquareElements(char[], char[], char[], char[]);
void createPolybiusSquare(void);
void displayKey(void);
void createSquareElements(void);
void createDigraphs(void);
void encrypt(void);
void displayCipherText(void);

int main() {
    getPlainText();
    text_len = strlen(plain_text);
    removeWhiteSpace(plain_text, "text");
    text_len = strlen(plain_text);
    displayPlainText();
    getKey();
    key_len = strlen(starting_key);
    removeWhiteSpace(starting_key, "key");
    removeRedundantCharacter(starting_key, key, "key");
    displayKey();
    createSquareElements();
    processSquareElements(key, starting_square_elements, square_elements, "square");
    createPolybiusSquare();
    createDigraphs();
    encrypt();
    displayCipherText();

    return 0;
}

void getPlainText() {
    printf("Enter the Plaintext:");
    fgets(plain_text, sizeof(plain_text), stdin);
}

void removeWhiteSpace(char text[60], char name[10]) {
    int i, k;
    char temp_text[60] = {};
    char temp_key[60] = {};

    if (strcmp(name, "text") == 0) {
        k = 0;
        for (i = 0; i < text_len; i++) {
            if (text[i] == ' ') {
                white_space_position[k] = i;
                k++;
            }
        }
        white_space_len = k;
        k = 0;
        for (i = 0; i < text_len; i++) {
            if (text[i] != ' ') {
                temp_text[k] = text[i];
                k++;
            }
        }
        strcpy(text, temp_text);
    } else if (strcmp(name, "key") == 0) {
        k = 0;
        for (i = 0; i < key_len; i++) {
            if (text[i] != ' ') {
                temp_key[k] = text[i];
                k++;
            }
        }
        strcpy(text, temp_key);
    }
}

void displayPlainText() {
    printf("\nPlain text: %s", plain_text);
}

void getKey() {
    printf("\nEnter the key in alphabet form:");
    fgets(starting_key, sizeof(starting_key), stdin);
}

void removeRedundantCharacter(char initial_characters[60], char final_characters[60], char name[15]) {
    int i, j, k = 0;
    printf("Initial %s Characters:\n", name);
    puts(initial_characters);
    int initial_characters_len = strlen(initial_characters);
    int final_characters_len = strlen(final_characters), found;

    for (i = 0; i < initial_characters_len; i++) {
        found = 0;

        if (initial_characters[i] == 'j') {
            initial_characters[i] = 'i';
        } else if (initial_characters[i] == 'J') {
            initial_characters[i] = 'I';
        }

        for (j = 0; j < final_characters_len; j++) {
            if (found == 0) {
                if (initial_characters[i] == final_characters[j]) {
                    found = 1;
                }
            }
        }

        if (found == 0) {
            final_characters[k] = initial_characters[i];
            final_characters_len++;
            k++;
        }
    }

    printf("\nOld %s Characters:", name);
    puts(initial_characters);
    printf("\nNew %s Characters:", name);
    puts(final_characters);

    int m, n;
    for (m = 0; m < final_characters_len; m++) {
        for (n = 0; n < 26; n++) {
            if (final_characters[m] == (n + 97)) {
                final_characters[m] -= 32;
            }
        }
    }
}

void processSquareElements(char final_key_elements[60], char initial_square[60], char final_square[60], char name[15]) {
    int i, j, k = 0;
    printf("Initial %s Characters:\n", name);
    puts(initial_square);
    int initial_characters_len = strlen(initial_square);
    int final_characters_len = strlen(final_key_elements), found;

    for (i = 0; i < initial_characters_len; i++) {
        found = 0;
        for (j = 0; j < final_characters_len; j++) {
            if (found == 0) {
                if ((initial_square[i] == final_key_elements[j])) {
                    found = 1;
                }
            }
        }

        if (found == 0) {
            final_square[k] = initial_square[i];
            k++;
        }
    }

    printf("\nNew %s Characters:", name);
    puts(final_square);
}

void createPolybiusSquare() {
    int j, k, m = 0, n = 0;
    for (j = 0; j < 5; j++) {
        for (k = 0; k < 5; k++) {
            if (m < strlen(key)) {
                square[j][k] = key[m];
                m++;
            } else {
                square[j][k] = square_elements[n];
                n++;
            }
        }
    }

    printf("\n Polybius Square:\n");
    for (j = 0; j < 5; j++) {
        for (k = 0; k < 5; k++) {
            printf("%c\t", square[j][k]);
        }
        printf("\n");
    }
}

void displayKey() {
    printf("\nKey: %s", key);
}

void createSquareElements() {
    int i, k = 0;
    for (i = 0; i < 26; i++) {
        if (i != 9) {
            starting_square_elements[k] = (i + 65);
            k++;
        }
    }

    printf("\ninitial square elements:\n");
    puts(starting_square_elements);
}

void createDigraphs() {
    int i, j, k = 0, p, r, c;
    char temp_plaintext[60] = {};
    int vowel_status;
    int temp_case_status[60] = {};

    for (p = 0; p < strlen(plain_text); p++) {
        for (r = 0; r < 26; r++) {
            if (plain_text[p] == (r + 97)) {
                temp_plaintext[p] = plain_text[p] - 32;
                temp_case_status[p] = 0;
            } else if (plain_text[p] == (r + 65)) {
                temp_plaintext[p] = plain_text[p];
                temp_case_status[p] = 1;
            }
        }
    }

    for (i = 0; i < strlen(temp_plaintext); i++) {
        vowel_status = 0;
        digraphs[k] = temp_plaintext[i];
        case_status[k] = temp_case_status[i];

        if ((i + 1) != strlen(temp_plaintext)) {
            if (temp_plaintext[i] == temp_plaintext[i + 1]) {
                for (c = 0; c < 5; c++) {
                    if (vowel_status == 0) {
                        if (((temp_plaintext[i] + 2) % 26) == vowel_array_position[c]) {
                            vowel_status = 1;
                        }
                    }
                }

                if (vowel_status == 1) {
                    k++;
                    digraphs[k] = (((temp_plaintext[i] + 2) % 26) + 1) + 65;
                    case_status[k] = 1;
                } else {
                    k++;
                    digraphs[k] = ((temp_plaintext[i] + 2) % 26) + 65;
                    case_status[k] = 1;
                }

                k++;
                digraphs[k] = (temp_plaintext[i + 1]);
                case_status[k] = temp_case_status[i + 1];
            } else {
                k++;
                digraphs[k] = temp_plaintext[i + 1];
                case_status[k] = temp_case_status[i + 1];
            }
        }

        k++;
        i++;
    }

    if (strlen(digraphs) % 2 != 0) {
        digraphs[k] = ((digraphs[k - 1] + 2) % 26) + 65;
        case_status[k] = 1;
    }

    printf("\nDigraph Completed......\n");
    printf("\nDigraph:\n");
    puts(digraphs);
}

void encrypt() {
    int i, j, k, n;
    int row[60], column[60];

    for (i = 0; i < strlen(digraphs); i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                if (digraphs[i] == square[j][k]) {
                    row[i] = j;
                    column[i] = k;
                } else if (digraphs[i + 1] == square[j][k]) {
                    row[i + 1] = j;
                    column[i + 1] = k;
                }
            }
        }
        i++;
    }

    for (n = 0; n < strlen(digraphs); n++) {
        if (column[n] == column[n + 1]) {
            cipher_digraphs[n] = square[(row[n] + 1) % 5][column[n]];
            cipher_digraphs[n + 1] = square[(row[n + 1] + 1) % 5][column[n + 1]];
        } else if (row[n] == row[n + 1]) {
            cipher_digraphs[n] = square[row[n]][(column[n] + 1) % 5];
            cipher_digraphs[n + 1] = square[row[n]][(column[n + 1] + 1) % 5];
        } else {
            cipher_digraphs[n] = square[row[n]][column[n + 1]];
            cipher_digraphs[n + 1] = square[row[n + 1]][column[n]];
        }
        n++;
    }

    printf("\nEncryption complete....\n");

    int w = 0;
    while (w < strlen(cipher_digraphs)) {
        if (case_status[w] == 0) {
            cipher_text_value[w] = cipher_digraphs[w] + 32;
        } else {
            cipher_text_value[w] = cipher_digraphs[w];
        }
        w++;
    }
}

void displayCipherText() {
    int i, j, k;
    int temp[60] = {};

    for (i = 0; i < white_space_len; i++) {
        temp[white_space_position[i]] = ' ';
    }

    int m = 0;
    for (j = 0; j < (strlen(cipher_digraphs) + white_space_len); j++) {
        if (temp[j] != ' ') {
            temp[j] = cipher_text_value[m];
            m++;
        }
    }

    for (k = 0; k < (strlen(cipher_digraphs) + white_space_len); k++) {
        cipher_text[k] = temp[k];
    }

    printf("\n\nCiphertext:");
    puts(cipher_text);
}
