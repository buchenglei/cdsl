#ifndef _Stack_h
#define _Stack_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);
ElementType Top(Stack S);

#endif

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

