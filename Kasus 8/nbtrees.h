#ifndef NBTREES_H
#define NBTREES_H

#include <stdio.h>
#include "boolean.h"

#define jml_maks 20
#define nil 0

typedef int infotype;
typedef int address;

typedef struct {
    infotype info;
    address ps_fs;
    address ps_nb;
    address ps_pr;
} nbtree;

typedef nbtree Isi_Tree[jml_maks + 1];

void CreateDefaultTree(Isi_Tree X);
void PreOrder(Isi_Tree P, address root);
void InOrder(Isi_Tree P, address root);
void PostOrder(Isi_Tree P, address root);
void LevelOrder(Isi_Tree X, int Maks_node);
void PrintTree(Isi_Tree P, int Maks_node);
boolean Search(Isi_Tree P, infotype X, int Maks_node);
int nbDaun(Isi_Tree P, int Maks_node);
int Level(Isi_Tree P, infotype X, int Maks_node);
int Depth(Isi_Tree P, int Maks_node);
boolean IsTreeEqual(Isi_Tree P1, Isi_Tree P2, int Maks_node);

#endif