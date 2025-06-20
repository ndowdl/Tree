#ifndef NBTREES_H
#define NBTREES_H

#include <stdio.h>
#include "boolean.h"

// Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

// Arah traversal
#define kebawah 1
#define kestas 2
#define kekanan 3
#define nil 0

// Type data
typedef char infotype;
typedef int address;

typedef struct { 
    infotype info;
    address ps_fs;  // posisi first son
    address ps_nb;  // posisi next brother
    address ps_pr;  // posisi parent
} nbtree;

typedef nbtree Isi_Tree[jml_maks + 1];  // Indeks 0 tidak dipakai

/********************************************/
/* SPESIFIKASI */
/********************************************/

void Create_tree(Isi_Tree X, int Jml_Node);
// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola Level Order
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input

boolean IsEmpty(Isi_Tree P);
/* Mengirimkan true jika Isi_Tree KOSONG */

/***** Traversal *****/
void PreOrder(Isi_Tree P, address root);
/* Traversal PreOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent, fs, nb */

void InOrder(Isi_Tree P, address root);
/* Traversal InOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent, Sisa anak lain */

void PostOrder(Isi_Tree P, address root);
/* Traversal PostOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PostOrder : fs, nb, Parent */

void Level_order(Isi_Tree X, int Maks_node);
/* Traversal LevelOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level Order */

void PrintTree(Isi_Tree P, int Maks_node);
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */

/***** Search *****/
boolean Search(Isi_Tree P, infotype X, int Maks_node);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/***** Fungsi Lain *****/
int nbElmt(Isi_Tree P, int Maks_node);
/* Mengirimkan banyak elemen (node) di pohon non biner P */

int nbDaun(Isi_Tree P, int Maks_node);
/* Mengirimkan banyak daun (node) pohon non biner P */

int Level(Isi_Tree P, infotype X, int Maks_node);
/* Mengirimkan level dari node X yang merupakan salah satu simpul */
/* dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */

int Depth(Isi_Tree P, int Maks_node);
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
/* Basis : Pohon Kosong, tingginya Nol */

infotype Max(infotype Data1, infotype Data2);
/* Mengirimkan Nilai terbesar dari dua data */

#endif