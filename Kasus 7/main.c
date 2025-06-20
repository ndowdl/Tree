#include <stdio.h>
#include "nbtrees.h"

int main() {
    Isi_Tree tree;
    int jumlah_node;
    
    printf("Masukkan jumlah node: ");
    scanf("%d", &jumlah_node);
    
    // Inisialisasi tree
    for (int i = 0; i <= jml_maks; i++) {
        tree[i].info = '\0';
        tree[i].ps_pr = nil;
        tree[i].ps_fs = nil;
        tree[i].ps_nb = nil;
    }
    
    Create_tree(tree, jumlah_node);
    
    printf("\nStruktur Tree:\n");
    PrintTree(tree, jumlah_node);
    
    printf("\nTraversal PreOrder: ");
    PreOrder(tree, 1);  // Asumsi root ada di indeks 1
    printf("\n");
    
    printf("Traversal InOrder: ");
    InOrder(tree, 1);
    printf("\n");
    
    printf("Traversal PostOrder: ");
    PostOrder(tree, 1);
    printf("\n");
    
    printf("Traversal LevelOrder: ");
    Level_order(tree, jumlah_node);
    printf("\n");
    
    printf("\nJumlah elemen: %d\n", nbElmt(tree, jumlah_node));
    printf("Jumlah daun: %d\n", nbDaun(tree, jumlah_node));
    printf("Depth tree: %d\n", Depth(tree, jumlah_node));
    
    char cari;
    printf("\nMasukkan karakter yang ingin dicari: ");
    scanf(" %c", &cari);
    if (Search(tree, cari, jumlah_node)) {
        printf("Karakter %c ditemukan di level %d\n", cari, Level(tree, cari, jumlah_node));
    } else {
        printf("Karakter %c tidak ditemukan\n", cari);
    }
    
    return 0;
}