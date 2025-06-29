#include "binarytree.h"
#include <stdio.h>

void displayMenu() {
    printf("\nMenu Program Sandi Morse:\n");
    printf("1. Tampilkan tabel sandi Morse lengkap\n");
    printf("2. Tampilkan semua karakter dalam tree (Inorder Traversal)\n");
    printf("3. Konversi teks ke sandi Morse\n");
    printf("4. Konversi sandi Morse ke teks\n");
    printf("5. Proses file teks ke file Morse\n");
    printf("6. Keluar\n");
    printf("Pilih menu: ");
}

int main() {
    TreeNode *morseTree = buildFullMorseTree();
    int choice;
    char input[256];
    char inputFilename[100];
    char outputFilename[100];
    
    printf("Program Konversi Sandi Morse Lengkap\n");
    printf("===================================\n");
    
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Membersihkan newline
        
        switch (choice) {
            case 1:
                system("cls");
                displayFullMorseTable();
                break;
                
            case 2:
                system("cls");
                printf("\nKarakter dalam Morse Tree (Inorder):\n");
                inorderTraversal(morseTree);
                break;
                
            case 3:
                system("cls");
                printf("Masukkan teks: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                printf("Hasil konversi: ");
                textToMorse(morseTree, input);
                break;
                
            case 4:
                system("cls");
                printf("Masukkan kode Morse (contoh: .- -... -.-.): ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                printf("Hasil konversi: ");
                morseToText(morseTree, input);
                break;
                
            case 5:
                system("cls");
                printf("Masukkan nama file input: ");
                scanf("%99s", inputFilename);
                printf("Masukkan nama file output: ");
                scanf("%99s", outputFilename);
                processFileToMorse(morseTree, inputFilename, outputFilename);
                break;
                
            case 6:
                system("cls");
                printf("Keluar dari program.\n");
                break;
                
            default:
                printf("Pilihan tidak valid.\n");
        }
        
        if (choice != 6) {
            printf("\nTekan Enter untuk melanjutkan...");
            getchar();
        }
    } while (choice != 6);
    
    // TODO: Tambahkan fungsi untuk menghapus tree dan membersihkan memori
    return 0;
}