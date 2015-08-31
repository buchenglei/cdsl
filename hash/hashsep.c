#include <stdio.h>
#include <stdlib.h>
#include "hashsep.h"

// 一个不错的散列函数
Index Hash(const char *Key, int TableSize) {
    unsigned int HashVal = 0;
    
    while(*Key != '\0')
        HashVal = (HashVal << 5) + *Key++;
        
    return HashVal % TableSize;
}

void main() {
    HashTable H = InitTable(7);
    Insert("aaa", H);
    Insert("BBB", H);
    Position P = Find("aaa", H);
    printf("Finded Element is %s\n ", P->Element);
}

Position Find(ElementType Key, HashTable H) {
    Position P;
    List L;
    
    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;    // 头指针不包含数据
    while(P != NULL && P->Element != Key)
        P = P->Next;
        
    return P;
}


HashTable InitTable(int TableSize) {
    HashTable H;
    int i;
    
    if(TableSize <= 3) {
        printf("Table size too small");
        return NULL;
    }
    // allocate Table
    H = (HashTable)malloc(sizeof(struct HashTbl));
    if(H == NULL) {
        printf("out of space!");
        return NULL;
    }
    H->TableSize = NextPrime(TableSize);
    
    // allocate array of lists
    H->TheLists = (List *)malloc(sizeof(List) * H->TableSize);
    if(H->TheLists == NULL) {
        printf("out of space!");
        return NULL;
    }
    // allocate list headers
    for(i = 0; i < H->TableSize; i++) {
        H->TheLists[i] = (Position)malloc(sizeof(struct ListNode));
        if(H->TheLists[i] == NULL) {
            printf("out of space!");
            return NULL;
        } else {
            H->TheLists[i]->Next = NULL;
        }
    }
    
    return H;
}


void Insert(ElementType Key, HashTable H) {
    Position Pos, NewCell;
    List L;
    
    
    Pos = Find(Key, H);
    if(Pos == NULL) {
        NewCell = (Position)malloc(sizeof(struct ListNode));
        if(NewCell == NULL) {
            printf("out of space!");
        } else {
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            L->Next = NewCell;  // 将新建的节点插入链表的头部
        }
    }
}

// TODO 待完善！
int NextPrime(int TableSize) {
    return TableSize;
}