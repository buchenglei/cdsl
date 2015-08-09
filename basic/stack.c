/*
 * 用数组实现的stack数据结构
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int IsEmpty(Stack S)
{

	return S->TopOfStack == EmptyTOS;
}

Stack CreateStack(int MaxElements)
{
	Stack S;//指向结构体的指针

	if(MaxElements < MinStackSize)
		printf("Stack size is too small\n");
	
	S = malloc(sizeof(struct StackRecord));

	if( S == NULL)
		printf("Out of space!!!\n");

	S->Array = malloc(sizeof(ElementType) * MaxElements);

	if( S->Array == NULL)
		printf("Out of space!!!\n");

	S->Capacity = MaxElements;
	MakeEmpty(S);
	return S;

}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void DisposeStack(Stack S)
{
	if(S != NULL)
	{
		//注意释放顺序
		free(S->Array);
		free(S);
	}
}

void Push(ElementType X, Stack S)
{
	if(IsFull(S))
		printf("Full Stack\n");
	else
		S->Array[++S->TopOfStack] = X;
}


int IsFull(Stack S)
{
	if(S->TopOfStack == S->Capacity)
		return 1;
	else
		return 0;
}

void Pop(Stack S)
{
	if(IsEmpty(S))
		printf("Empty Stack\n");
	else
		//只需将索引-1即可，栈顶的数据会被下一次push覆盖
		S->TopOfStack--;
}


ElementType TopAndPop(Stack S)
{
	if(IsEmpty(S))
		printf("The stack is empty!\n");
	else
	{
		S->TopOfStack--;
		return S->Array[S->TopOfStack + 1];
	}
}

void PrintStack(Stack S)
{
	if(IsEmpty(S))
		printf("There is nothing to print\n");
	else
	{
		int i;

		for(i = 0; i <= S->TopOfStack; i++)
		{
			printf("index is %d, value is %d\n", i, S->Array[i]);	
		}
	}
}

void main()
{
	Stack S;

	S = CreateStack(8);
	Push(1,S);
	Push(2,S);
	Push(3,S);
	Push(4,S);
	Push(5,S);
	Push(6,S);
	Push(7,S);
	Push(7,S);
	printf("pop is %d \n", TopAndPop(S));
	printf("pop is %d \n", TopAndPop(S));
	Push(7,S);
	Push(7,S);
	PrintStack(S);
	DisposeStack(S);
}

