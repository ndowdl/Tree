#include "nbtrees.h"
#include <stdio.h>

void Create_tree(Isi_Tree X, int Jml_Node) {
    printf("Masukkan data tree dalam level order (info, parent, first son, next brother):\n");
    for (int i = 1; i <= Jml_Node; i++) {
        printf("Node %d: ", i);
        scanf(" %c %d %d %d", &X[i].info, &X[i].ps_pr, &X[i].ps_fs, &X[i].ps_nb);
    }
}

boolean IsEmpty(Isi_Tree P) {
    return (P[1].info == '\0');  // Asumsi root ada di indeks 1
}

void PreOrder(Isi_Tree P, address root) {
    if (root == nil) return;
    
    printf("%c ", P[root].info);  // Cetak parent
    PreOrder(P, P[root].ps_fs);   // Rekursi ke first son
    PreOrder(P, P[root].ps_nb);   // Rekursi ke next brother
}

void InOrder(Isi_Tree P, address root) {
    if (root == nil) return;
    
    InOrder(P, P[root].ps_fs);    // Rekursi ke first son
    printf("%c ", P[root].info);  // Cetak parent
    address child = P[root].ps_fs;
    if (child != nil) {
        child = P[child].ps_nb;
        while (child != nil) {
            InOrder(P, child);    // Rekursi ke sisa anak lain
            child = P[child].ps_nb;
        }
    }
}

void PostOrder(Isi_Tree P, address root) {
    if (root == nil) return;
    
    PostOrder(P, P[root].ps_fs);  // Rekursi ke first son
    PostOrder(P, P[root].ps_nb);  // Rekursi ke next brother
    printf("%c ", P[root].info);  // Cetak parent
}

void Level_order(Isi_Tree X, int Maks_node) {
    for (int i = 1; i <= Maks_node; i++) {
        if (X[i].info != '\0') {
            printf("%c ", X[i].info);
        }
    }
}

void PrintTree(Isi_Tree P, int Maks_node) {
    printf("Index\tInfo\tParent\tFirst Son\tNext Brother\n");
    for (int i = 1; i <= Maks_node; i++) {
        printf("%d\t%c\t%d\t%d\t\t%d\n", 
               i, P[i].info, P[i].ps_pr, P[i].ps_fs, P[i].ps_nb);
    }
}

boolean Search(Isi_Tree P, infotype X, int Maks_node) {
    for (int i = 1; i <= Maks_node; i++) {
        if (P[i].info == X) {
            return true;
        }
    }
    return false;
}

int nbElmt(Isi_Tree P, int Maks_node) {
    int count = 0;
    for (int i = 1; i <= Maks_node; i++) {
        if (P[i].info != '\0') {
            count++;
        }
    }
    return count;
}

int nbDaun(Isi_Tree P, int Maks_node) {
    int count = 0;
    for (int i = 1; i <= Maks_node; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == nil) {
            count++;
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X, int Maks_node) {
    int level = 0;
    address current = nil;
    
    // Cari node X
    for (int i = 1; i <= Maks_node; i++) {
        if (P[i].info == X) {
            current = i;
            break;
        }
    }
    
    if (current == nil) return -1;  // Tidak ditemukan
    
    // Hitung level dengan naik ke parent sampai root
    while (P[current].ps_pr != nil) {
        level++;
        current = P[current].ps_pr;
    }
    
    return level;
}

int Depth(Isi_Tree P, int Maks_node) {
    int max_depth = 0;
    for (int i = 1; i <= Maks_node; i++) {
        if (P[i].info != '\0') {
            int current_depth = Level(P, P[i].info, Maks_node);
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        }
    }
    return max_depth;
}

infotype Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}