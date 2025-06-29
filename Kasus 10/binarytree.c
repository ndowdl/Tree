#include "binarytree.h"

// Tabel sandi Morse lengkap sesuai PDF
const MorseCode morseTable[] = {
    {'A', "."}, {'B', "-"}, {'C', ".."}, {'D', "-."}, {'E', "-."},
    {'F', "--"}, {'G', "..."}, {'H', "..-"}, {'I', ".-."}, {'J', ".--"},
    {'K', "-.."}, {'L', "-.-"}, {'M', "--."}, {'N', "---"}, {'O', "...."},
    {'P', "...-"}, {'Q', "--.-"}, {'R', "..--"}, {'S', ".-.."}, {'T', ".-.-"},
    {'U', ".--."}, {'V', ".---"}, {'W', "-..."}, {'X', "-..-"}, {'Y', "-.-."},
    {'Z', "--.."}, 
    {'1', "--.-"}, {'2', "---."}, {'3', "----"}, {'4', "...--"}, {'5', "..-.."},
    {'6', ".-.--"}, {'7', ".--.."}, {'8', "-...-"}, {'9', "-.--.."}, {'0', "--.--"},
    {' ', "--.."}
};

const int morseTableSize = sizeof(morseTable) / sizeof(morseTable[0]);

TreeNode* createNode(char character, const char *code) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->character = character;
    strncpy(newNode->code, code, MAX_CODE_LENGTH - 1);
    newNode->code[MAX_CODE_LENGTH - 1] = '\0';
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertMorseCode(TreeNode *root, const char *code, char character) {
    if (root == NULL) {
        root = createNode('\0', "");
    }
    
    TreeNode *current = root;
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '.') {
            if (current->left == NULL) {
                current->left = createNode('\0', "");
            }
            current = current->left;
        } else if (code[i] == '-') {
            if (current->right == NULL) {
                current->right = createNode('\0', "");
            }
            current = current->right;
        }
    }
    current->character = character;
    strcpy(current->code, code);
    
    return root;
}

TreeNode* buildFullMorseTree() {
    TreeNode *root = NULL;
    
    // Bangun pohon Morse dari tabel
    for (int i = 0; i < morseTableSize; i++) {
        root = insertMorseCode(root, morseTable[i].code, morseTable[i].character);
    }
    
    return root;
}

void inorderTraversal(TreeNode *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    if (root->character != '\0') {
        printf("%c: %s\n", root->character, root->code);
    }
    inorderTraversal(root->right);
}

const char* findMorseCode(TreeNode *root, char character) {
    if (root == NULL) return NULL;
    
    // Cari di tabel Morse terlebih dahulu
    for (int i = 0; i < morseTableSize; i++) {
        if (toupper(morseTable[i].character) == toupper(character)) {
            return morseTable[i].code;
        }
    }
    
    return NULL;
}

char findCharacterFromMorse(TreeNode *root, const char *code) {
    TreeNode *current = root;
    
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '.') {
            current = current->left;
        } else if (code[i] == '-') {
            current = current->right;
        }
        
        if (current == NULL) {
            return '\0';
        }
    }
    
    return current->character;
}

void textToMorse(TreeNode *root, const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            printf("/ ");
            continue;
        }
        
        const char *code = findMorseCode(root, text[i]);
        if (code != NULL) {
            printf("%s ", code);
        } else {
            printf("? "); // Untuk karakter yang tidak dikenal
        }
    }
    printf("\n");
}

void morseToText(TreeNode *root, const char *morse) {
    char tempCode[MAX_CODE_LENGTH] = {0};
    int codeIndex = 0;
    
    for (int i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == ' ') {
            if (codeIndex > 0) {
                tempCode[codeIndex] = '\0';
                char c = findCharacterFromMorse(root, tempCode);
                printf("%c", c != '\0' ? c : '?');
                codeIndex = 0;
            }
        } else if (morse[i] == '/') {
            printf(" ");
            i++; // Lewati spasi setelah slash
        } else {
            if (codeIndex < MAX_CODE_LENGTH - 1) {
                tempCode[codeIndex++] = morse[i];
            }
        }
    }
    
    // Handle kode terakhir jika ada
    if (codeIndex > 0) {
        tempCode[codeIndex] = '\0';
        char c = findCharacterFromMorse(root, tempCode);
        printf("%c", c != '\0' ? c : '?');
    }
    printf("\n");
}

void processFileToMorse(TreeNode *root, const char *inputFilename, const char *outputFilename) {
    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");
    
    if (inputFile == NULL || outputFile == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), inputFile)) {
        // Hapus newline di akhir
        line[strcspn(line, "\n")] = '\0';
        
        // Konversi ke Morse dan tulis ke output
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == ' ') {
                fprintf(outputFile, "/ ");
                continue;
            }
            
            const char *code = findMorseCode(root, line[i]);
            if (code != NULL) {
                fprintf(outputFile, "%s ", code);
            } else {
                fprintf(outputFile, "? ");
            }
        }
        fprintf(outputFile, "\n");
    }
    
    fclose(inputFile);
    fclose(outputFile);
    printf("File berhasil diproses. Hasil disimpan di %s\n", outputFilename);
}

void displayFullMorseTable() {
    printf("\nTabel Sandi Morse Lengkap:\n");
    printf("========================\n");
    printf("Huruf\tKode Morse\n");
    printf("========================\n");
    
    for (int i = 0; i < morseTableSize; i++) {
        if (morseTable[i].character == ' ') {
            printf("Spasi\t%s\n", morseTable[i].code);
        } else {
            printf("%c\t%s\n", morseTable[i].character, morseTable[i].code);
        }
        
        // Tampilkan 5 karakter per baris untuk angka
        if (i == 25 && morseTable[i].character == 'Z') {
            printf("\nAngka\tKode Morse\n");
            printf("========================\n");
        }
    }
}