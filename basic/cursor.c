/*
 * 链表的游标实现
 */
#include <stdio.h>
#include <stdlib.h>
#include "cursor.h"

#define SpaceSize 11

struct Node
{
	ElementType Element;
	Position Next;
};

struct Node CursorSpace[ SpaceSize ];

/*模拟malloc函数*/
static Position CursorAlloc()
{
	Position P;

	P = CursorSpace[ 0 ].Next;
	CursorSpace[ 0 ].Next = CursorSpace[ P ].Next;

	return P;
}

/*模拟free函数*/
static void CursorFree( Position P )
{
	CursorSpace[ P ].Next = CursorSpace[ 0 ].Next;
	CursorSpace[ 0 ].Next = P;
}

void InitializeCursorSpace()
{
	int i;

	for( i = 0; i < SpaceSize; i++)
	{
		CursorSpace[ i ].Element = 0;
		if( i == ( SpaceSize - 1 ) )
			CursorSpace[ i ].Next = 0;
		else
			CursorSpace[ i ].Next = i + 1;
	}
}

void PrintList(List L)
{
	int i;

	for( i = 0; i < SpaceSize; i++ )
	{
		printf( "No.%d Element is %d, Next is %d\n", i, 
				CursorSpace[ i ].Element, CursorSpace[ i ].Next );
	}
}

int IsEmpty( List L )
{
	return CursorSpace[ L ].Next == 0;
}

int IsLast( Position P, List L)
{
	return CursorSpace[ P ].Next == 0;
}

void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	//分配一个新的节点
	TmpCell = CursorAlloc();
	if( TmpCell == 0 )
		printf("Error: Out of space!!!\n");

	CursorSpace[ TmpCell ].Element = X;
	CursorSpace[ TmpCell ].Next = CursorSpace[ P ].Next;
	if( TmpCell != P)
		CursorSpace[ P ].Next = TmpCell;

}

Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = CursorSpace[ L ].Next;
	P++;
	while( P && CursorSpace[ CursorSpace[ P ].Next ].Element != X )
		P = CursorSpace[ P ].Next;
	printf(" In FindPrevious P is %d \n", P);
	return P;
}

Position Find(ElementType Element,List L)
{
	Position P;
   
	P = CursorSpace[ L ].Next;
	while( P && CursorSpace[ P ].Element != Element )
		P = CursorSpace[ P ].Next;
	printf("in FindPrevious P is $d\n", P);
	return P;
}

void Delete( ElementType X, List L ){
	Position P, TmpCell;

	P = FindPrevious(X, L);
	printf("FindPrevious is %d \n", P);
	if( !IsLast( P, L ) )
	{
		TmpCell = CursorSpace[ P ].Next;//取出待释放的元素
		CursorSpace[ P ].Next = CursorSpace[ TmpCell ].Next;
		CursorSpace[ TmpCell ].Element = 0;
		CursorFree( TmpCell );
	}
}

void Append(ElementType X, List L)
{
	
}

void main()
{
	InitializeCursorSpace();
	Insert(100, 0, 1);
	Insert(100, 0, 2);
	Insert(100, 0, 3);
	Insert( 25, 0, 4);
	Insert(100, 0, 5);
	Insert(100, 0, 6);
	Insert(100, 0, 7);
	Insert(100, 0, 8);
	Insert(100, 0, 9);
	Insert(100, 0, 10);
	Delete( 25, 0 );

	PrintList( 0 );
}

