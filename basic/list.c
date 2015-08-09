/*
 * 链表的基本实现
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void main(){
	List Header = CreateList();
	int i=0;
	for(;i <= 10;i++) {
		Append(i,Header);
	}
	PrintList(Header);
	Position P = Find(2, Header);
	printf("Find Element 2 next is %d\n",P->Next->Element);
	DeleteList(Header);

	
}

/* Return true(1) if L is empty */
int IsEmpty(List L){
	return L->Next == NULL;
}

/* Return True if P is last position in list */
int IsLast(Position P){
	return P->Next == NULL;
}

/* Return Position of x in L;NULL if not found */
Position Find(ElementType X, List L){
	Position P;
	P=L->Next;
	while(P != NULL && P->Element != X)
		P = P->Next;
	return P;
	
}

/* Create a new List */
List CreateList() {
	Position Header = malloc(sizeof(Position));
	Header->Element = -1;
	Header->Next = NULL;
	return Header;
}

/* Insert a new Node after P*/
void Insert(ElementType X, List L, Position P) {
	//Create a new Node
	Position Tmp = malloc(sizeof(Position));
	Tmp->Element = X;
	Tmp->Next = P->Next;
	P->Next = Tmp;
}

/* Append a new Node to tail of the List*/
void Append(ElementType X,List L) {
	Position Tmp = (Position)malloc(sizeof(struct Node));
	Tmp->Element = X;
	Tmp->Next = NULL;
	Position P = L;
	while(!IsLast(P)) {
		P = P->Next;
	}
	P->Next = Tmp;
}

void PrintList(List L) {
	Position Tmp = L;
	int index = 1;
	while((Tmp=Tmp->Next) != NULL) {
		printf("NO.%d Element is %d\n",index,Tmp->Element);
		index++;
	}
}

/* Delete List*/
void DeleteList(List L) {
	Position Tmp;
	Tmp = L->Next;
	free(L);
	while(Tmp != NULL) {
		free(Tmp);
		Tmp=Tmp->Next;
	}
}

