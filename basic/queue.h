#ifndef _Queue_h

    struct QueueRecord;
    typedef struct QueueRecord *Queue;
    typedef int ElementType;
    
    int IsEmpty(Queue Q);
    int IsFull(Queue Q);
    Queue CreateQueue(int MaxElements);
    void DisposeQueue(Queue Q);
    void MakeEmpty(Queue Q);
    void Enqueue(ElementType X, Queue Q);
    ElementType Front(Queue Q);
    void Dequeue(Queue Q);
    ElementType FrontAndDequeue(Queue Q);
    void PrintQueue(Queue Q);
    
#endif

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};