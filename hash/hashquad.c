#include <stdio.h>
#include <stdlib.h>
#include "hashquad.h"

#define MiniTableSize 10

Index Hash(const char *Key, int TableSize) {
    unsigned int HashVal = 0;
    
    while(*Key != '\0')
        HashVal = (HashVal << 5) + *Key++;
        
    return HashVal % TableSize;
}

void main() {
    
}

HashTable InitTable(int TableSize) {
    HashTable H;
    int i;
    
    // 标的大小不能过小
    if (TableSize < MiniTableSize) {
        printf("Table size too small!");
        return NULL;
    }
    
    // allocate Table
    H = (HashTable)malloc(sizeof(struct HashTbl));
    if(H == NULL) {
        printf("Out of space!");
        return NULL;
    }
    
    // 书中的原型是这样的:
    // H->TableSize = NextPrime(TableSize);
    // 该操作将hash标的大小设为指定大小的下一个素数
    H->TableSize = TableSize;
    
    // allocate array of Cells
    H->TheCells = (Cell *)malloc(sizeof(Cell) * H->TableSize);
    if(H->TheCells == NULL) {
        printf("Out of space!");
        // 我觉得这里如果内存分配失败的话，应该释放上面分配的内存
        
        free(H);
        return NULL;
    }
    
    for(i = 0; i < H->TableSize; i++)
        H->TheCells[i].Info = Empty;
        
    return H;
    
}

Position Find(ElementType Key, HashTable H) {
    Position CurrentPos;
    int CollisionNum;
    
    CollisionNum = 0;
    CurrentPos = Hash(Key, H->TableSize);
    while(H->TheCells[CurrentPos].Info != Empty &&
            H->TheCells[CurrentPos].Element != Key) {
        CurrentPos += 2 * ++CollisionNum - 1;
        if(CurrentPos >= H->TableSize)
            CurrentPos -= H->TableSize;
    }
    return CurrentPos;
}

void Insert(ElementType Key, HashTable H) {
    Position Pos;
    
    Pos = Find(Key, H);
    if(H->TheCells[Pos].Info != Legitimate) {
        // ok to insert here
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}