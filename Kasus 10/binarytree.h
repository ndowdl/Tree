#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_CODE_LENGTH 10
#define MAX_CHARACTERS 40

typedef struct TreeNode {
    char character;
    char code[MAX_CODE_LENGTH];
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct {
    char character;
    char code[MAX_CODE_LENGTH];
} MorseCode;

// Fungsi untuk membuat node baru
TreeNode* createNode(char character, const char *code);

// Fungsi untuk membangun pohon Morse lengkap
TreeNode* buildFullMorseTree();

// Fungsi traversal inorder
void inorderTraversal(TreeNode *root);

// Fungsi untuk mencari kode Morse berdasarkan karakter
const char* findMorseCode(TreeNode *root, char character);

// Fungsi untuk mencari karakter berdasarkan kode Morse
char findCharacterFromMorse(TreeNode *root, const char *code);

// Fungsi untuk mengkonversi teks ke sandi Morse
void textToMorse(TreeNode *root, const char *text);

// Fungsi untuk mengkonversi sandi Morse ke teks
void morseToText(TreeNode *root, const char *morse);

// Fungsi untuk memproses file input ke output Morse
void processFileToMorse(TreeNode *root, const char *inputFilename, const char *outputFilename);

// Fungsi untuk menampilkan tabel Morse lengkap
void displayFullMorseTable();

#endif