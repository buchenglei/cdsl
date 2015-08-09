/*
 * 实现队列数据结构
 *
 */
 
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void main()
{
    Queue Q = CreateQueue(5);
    Enqueue(1, Q);
    Enqueue(2, Q);
    Enqueue(3, Q);
    Enqueue(4, Q);
    Enqueue(5, Q);
    printf("%d has been out\n", FrontAndDequeue(Q));
    printf("%d has been out\n", FrontAndDequeue(Q));
    Enqueue(10, Q);
    
    PrintQueue(Q);
    DisposeQueue(Q);
        
}

void PrintQueue(Queue Q)
{
    if(IsEmpty(Q))
        printf("The Queue is nothing to print\n");
    else
    {
        int i;
        int f = Q->Front;
        printf("The Quee has:\n");
        for(i = 0; i < Q->Size; i++, f++)
        {
            if(f == Q->Capacity)
                f = 0;
            printf("%d\t", Q->Array[ f ]);
        }   
        printf("\n");
            
    }
}

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 0;
    Q->Rear = 0;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q;
    
    Q = (Queue)malloc(sizeof(struct QueueRecord));
    if(Q == NULL)
    {
        printf("out of space\n");
        exit(1);
    }
    
    Q->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if(Q->Array == NULL)
    {
        printf("out of space!!!");
        exit(1);
    }
    
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
    return Q;
}

void DisposeQueue(Queue Q)
{
    free(Q->Array);
    free(Q);
}

//这是一个容易出错的函数
void Enqueue(ElementType X, Queue Q)
{
    //判断队列是否满了
    if(IsFull(Q))
        printf("Queue is full, %d can't put in the Queue\n", X);
    else
    {
        Q->Size++;
        
        if(Q->Rear == Q->Capacity)
        {
            //当Rear == Capacity的时候，需要见Rear重置为0
            Q->Rear = 0;
        }
        Q->Array[ Q->Rear ] = X;
        Q->Rear++;
        
    }
}

void Dequeue(Queue Q)
{
    if(IsEmpty(Q))
        printf("The Queue is empty\n");
    else
    {
        Q->Size--;
        if(Q->Front == Q->Capacity)
            Q->Front = 0;
        else
            Q->Front++;
    }
}

ElementType Front(Queue Q)
{
    if(IsEmpty(Q))
    {
        printf("The Queue is empty\n");
        return -1;
    }
    return Q->Array[ Q->Front ];
}

ElementType FrontAndDequeue(Queue Q)
{
    ElementType Tmp = Front(Q);
    Dequeue(Q);
    return Tmp;
}
