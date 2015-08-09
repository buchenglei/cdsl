/*
 * 栈结构的链表实现
 */
#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack()
{
	Stack S;

	S = malloc(sizeof(struct Node));
	if(S == NULL)
		printf("Out of Space!!!\n");
	else
	{
		S->Next = NULL;
		MakeEmpty(S);
		return S;
	}
}

void MakeEmpty(Stack S)
{
	if(S == NULL)
		printf("Please CreateStack first!!!\n");
	else
		while(!IsEmpty(S))
			Pop(S);
}

void Push(ElementType X, Stack S)
{
	PtrToNode TmpCell;//创建一个临时节点
	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		printf("Out of Space!!!\n");
	else
	{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

ElementType Top(Stack S)
{
	if(!IsEmpty(S))
		return S->Next->Element;	
	else
		return 0;
}

void Pop(Stack S)
{
	PtrToNode TmpCell;
	if(!IsEmpty(S))
	{
		TmpCell = S->Next;
		S->Next = TmpCell->Next;
		free(TmpCell);
	}
}

ElementType TopAndPop(Stack S)
{
	ElementType TmpValue = -1;
	Stack TmpCell;

	if(!IsEmpty(S))
	{
		TmpCell = S->Next;
		TmpValue = TmpCell->Element;
		S->Next = TmpCell->Next;
		free(TmpCell);
		return TmpValue;
	}
	else
		return -1;
}

void PrintStack(Stack S)
{
	if(IsEmpty(S))
		printf("The Stack is empty,nothing need to be print!\n");
	else
	{
		Stack TmpCell = S->Next;
		int i = 0;
		while(TmpCell != NULL)
		{
			printf("index is %d, value is %d\n", i, TmpCell->Element);
			i++;
			TmpCell = TmpCell->Next;
		}

	}
}

void main()
{
	Stack S;

	S = CreateStack();
	Push(1, S);
	Push(2, S);
	Push(3, S);
	Push(4, S);
	Push(5, S);
	Push(6, S);
	Push(7, S);
	Push(8, S);
	Push(9, S);
	PrintStack(S);
	printf("-----POP-----\n");
	printf("%d has been Pop\n", TopAndPop(S));
	printf("%d has been Pop\n", TopAndPop(S));
	printf("%d has been Pop\n", TopAndPop(S));
	
	PrintStack(S);
}
