#ifndef _HashSep_H
#define _HashSep_H

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef char* ElementType;
typedef unsigned int Index;

HashTable InitTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable);
void Insert(ElementType Key, HashTable);
ElementType Retrieve(Position P);
void MakeEmpty(HashTable H);
void Delete(ElementType Key, HashTable H);
int NextPrime(int TableSize);

struct ListNode {
    ElementType Element;
    Position Next;
};

typedef Position List;

struct HashTbl {
    int TableSize;
    List *TheLists;
};
// TheLists是一个指向ListNode结构的指针的指针

#endif
