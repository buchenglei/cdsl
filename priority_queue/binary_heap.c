/*
 * 数组实现的完全二叉树(二叉堆);
 */
#include <stdio.h>
#include <stdlib.h>
#include "binary_heap.h"

#define MinPQSzie 5

void main() {
    PriorityQueue H = Init(15, -1);
    Insert(13, H);
    Insert(21, H);
    Insert(16, H);
    Insert(24, H);
    Insert(31, H);
    Insert(19, H);
    Insert(68, H);
    Insert(65, H);
    Insert(26, H);
    Insert(32, H);
    Insert(14, H);
    PrintPriorityQueue(H);
    printf("Will delete: %d\n", DeleteMin(H));
    printf("cruuent Min is: %d\n", FindMin(H));
    PrintPriorityQueue(H);
    Destory(H);
    
}

// 初始化二叉堆，需要将MinData设置成一个比待处理的所有值都小的最小值
PriorityQueue Init(int MaxElements, ElementType MinData) {
    
    PriorityQueue H;
    
    if(MaxElements <= MinPQSzie) {
        printf("Priority Queue size is too small");
        return NULL;
    }
    
    H = (PriorityQueue)malloc(sizeof(struct Heap));
    if(H == NULL) {
        printf("Out of space!");
        return NULL;
    }
    
    // Allocate the array plus one extra for sentinel
    // Index start with 1
    H->Elements = (ElementType *)malloc((MaxElements + 1) * sizeof(ElementType));
    if (H->Elements == NULL) {
        printf("Out of space!");
        free(H);
        return NULL;
    }
    
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;
    
    return H;
}

int IsFull(PriorityQueue H) { return H->Size == H->Capacity; }

int IsEmpty(PriorityQueue H) { return H->Size == 0; }

void Insert(ElementType X, PriorityQueue H) {
    
    int i;
    
    if(IsFull(H)) {
        printf("The PriorityQueue is full!");
        return;
    }
    
    // 从已有数据个数的下一个位置开始
    for(i = ++H->Size; H->Elements[i/2] > X; i /= 2)
        // 如果空穴的父节点比待插入的数据X要大
        // 则需要将空穴上移一层
        // i指的是空穴节点， i/2则是空穴的父节点
        H->Elements[i] = H->Elements[i / 2];
        
    H->Elements[i] = X;
}

// 删除优先队列中最小的值，并将其返回
ElementType DeleteMin(PriorityQueue H) {
    
    int i, Child;
    ElementType MinElement, LastElement;
    
    if(IsEmpty(H))
        return H->Elements[0];
        
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];
    
    for(i = 1; i * 2 <= H->Size; i = Child) {
        
        // find smaller cChild
        Child = i * 2;
        if(Child != H->Size && H->Elements[Child + 1] 
                                        < H->Elements[Child])
            // 如果右边的节点比左边的节点更小，则将child指向右边
            Child++;
            
        // percolate one level
        if(LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
        
    }
    H->Elements[i] = LastElement;
    return MinElement;
    
    
}

void Destory(PriorityQueue H) {
    
   free(H->Elements);
   free(H);
}

ElementType FindMin(PriorityQueue H) { return H->Elements[1]; }

void PrintPriorityQueue(PriorityQueue H) {
    
    int i;
    
    for(i = 1; i <= H->Size; i++)
        printf("%d ", H->Elements[i]);
    
    printf("\n");
}