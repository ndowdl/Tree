#include "nbtrees.h"
#include <stdio.h>

void CreateDefaultTree(Isi_Tree X) {
    for (int i = 0; i <= jml_maks; i++) {
        X[i].info = 0;
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }

    X[1].info = 4; X[1].ps_fs = 2; X[1].ps_pr = nil;
    X[2].info = 1; X[2].ps_fs = 4; X[2].ps_nb = 3; X[2].ps_pr = 1;
    X[3].info = 2; X[3].ps_pr = 1;
    X[4].info = 3; X[4].ps_nb = 5; X[4].ps_pr = 2;
    X[5].info = 5; X[5].ps_pr = 2;
}

void PreOrder(Isi_Tree P, address root) {
    if (root == nil) return;
    printf("%d ", P[root].info);
    PreOrder(P, P[root].ps_fs);
    PreOrder(P, P[root].ps_nb);
}

void InOrder(Isi_Tree P, address root) {
    if (root == nil) return;
    InOrder(P, P[root].ps_fs);
    printf("%d ", P[root].info);
    address child = P[root].ps_fs;
    if (child != nil) {
        child = P[child].ps_nb;
        while (child != nil) {
            InOrder(P, child);
            child = P[child].ps_nb;
        }
    }
}

void PostOrder(Isi_Tree P, address root) {
    if (root == nil) return;
    PostOrder(P, P[root].ps_fs);
    PostOrder(P, P[root].ps_nb);
    printf("%d ", P[root].info);
}

void LevelOrder(Isi_Tree X, int Maks_node) {
    for (int i = 1; i <= Maks_node; i++) {
        if (X[i].info != 0) {
            printf("%d ", X[i].info);
        }
    }
}

void PrintTree(Isi_Tree P, int Maks_node) {
    printf("\nSeluruh Node pada Non Binary Tree:\n");
    for (int i = 1; i <= Maks_node; i++) {
        if (P[i].info != 0) {
            printf("\nIndex ke-%d\n", i);
            printf("info array ke %d         : %d\n", i, P[i].info);
            printf("first son array ke %d    : %d\n", i, P[i].ps_fs);
            printf("next brother array ke %d : %d\n", i, P[i].ps_nb);
            printf("parent array ke %d       : %d\n", i, P[i].ps_pr);
            printf("_________________________________\n");
        }
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

int nbDaun(Isi_Tree P, int Maks_node) {
    int count = 0;
    for (int i = 1; i <= Maks_node; i++) {
        if (P[i].info != 0 && P[i].ps_fs == nil) {
            count++;
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X, int Maks_node) {
    int level = 0;
    address current = nil;
    
    for (int i = 1; i <= Maks_node; i++) {
        if (P[i].info == X) {
            current = i;
            break;
        }
    }
    
    if (current == nil) return -1;
    
    while (P[current].ps_pr != nil) {
        level++;
        current = P[current].ps_pr;
    }
    
    return level;
}

int Depth(Isi_Tree P, int Maks_node) {
    int max_depth = 0;
    for (int i = 1; i <= Maks_node; i++) {
        if (P[i].info != 0) {
            int current_depth = Level(P, P[i].info, Maks_node);
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        }
    }
    return max_depth;
}

boolean IsTreeEqual(Isi_Tree P1, Isi_Tree P2, int Maks_node) {
    for (int i = 1; i <= Maks_node; i++) {
        if (P1[i].info != P2[i].info || 
            P1[i].ps_fs != P2[i].ps_fs || 
            P1[i].ps_nb != P2[i].ps_nb || 
            P1[i].ps_pr != P2[i].ps_pr) {
            return false;
        }
    }
    return true;
}