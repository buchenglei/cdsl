#ifndef _HashQuad_H
#define _HashQuad_H

typedef unsigned int Index;
typedef Index Position;
typedef char* ElementType;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
HashTable Rehash(HashTable H);

enum KindOfEntry {Legitimate, Empty, Deleted};

struct HashEntry {
    ElementType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl {
    int TableSize;
    Cell *TheCells;
};


#endif