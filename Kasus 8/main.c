#include <stdio.h>
#include <stdlib.h>
#include "nbtrees.h"

void clearScreen() {
    system("cls || clear");
}

void waitForEnter() {
    printf("\nKlik apapun untuk melanjutkan!");
    getchar();
    getchar();
}

int main() {
    Isi_Tree tree1, tree2;
    int choice;
    int Maks_node = 5; 
    
    CreateDefaultTree(tree1);
    CreateDefaultTree(tree2);
    
    do {
        clearScreen();
        printf("ADT Non Binary Tree\n");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree\n");
        printf("6. Search node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencari Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &choice);
        
        clearScreen();
        switch(choice) {
            case 1:
                printf("Traversal PreOrder: ");
                PreOrder(tree1, 1);
                break;
            case 2:
                printf("Traversal InOrder: ");
                InOrder(tree1, 1);
                break;
            case 3:
                printf("Traversal PostOrder: ");
                PostOrder(tree1, 1);
                break;
            case 4:
                printf("Traversal Level Order: ");
                LevelOrder(tree1, Maks_node);
                break;
            case 5:
                PrintTree(tree1, Maks_node);
                break;
            case 6: {
                infotype X;
                printf("Masukkan nilai node yang dicari: ");
                scanf("%d", &X);
                if (Search(tree1, X, Maks_node)) {
                    printf("Node %d ditemukan di level %d\n", X, Level(tree1, X, Maks_node));
                } else {
                    printf("Node %d tidak ditemukan\n", X);
                }
                break;
            }
            case 7:
                printf("Jumlah daun: %d\n", nbDaun(tree1, Maks_node));
                break;
            case 8: {
                infotype X;
                printf("Masukkan nilai node: ");
                scanf("%d", &X);
                int level = Level(tree1, X, Maks_node);
                if (level != -1) {
                    printf("Node %d berada di level %d\n", X, level);
                } else {
                    printf("Node %d tidak ditemukan\n", X);
                }
                break;
            }
            case 9:
                printf("Kedalaman tree: %d\n", Depth(tree1, Maks_node));
                break;
            case 10:
                if (IsTreeEqual(tree1, tree2, Maks_node)) {
                    printf("Kedua tree sama\n");
                } else {
                    printf("Kedua tree tidak sama\n");
                }
                break;
            case 11:
                printf("Keluar dari program...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
        
        if (choice != 11) {
            waitForEnter();
        }
    } while (choice != 11);
    
    return 0;
}