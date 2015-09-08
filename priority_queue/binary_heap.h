#ifndef _Binary_Heap_H
#define _Binary_Heap_H

struct Heap;
typedef struct Heap* PriorityQueue;
typedef int ElementType;

PriorityQueue Init(int MaxElements);
void Destory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

int getPosition

struct Heap {
    int Capacity;
    int Size;
    ElementType *Elements;
};

#endif