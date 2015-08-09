#ifndef _List_H

#define ElementType int

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(List L);
Position Find(ElementType Element, List L);
void Delete(ElementType X, List L, Position P);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

List CreateList();
void PrintList(List L);
void Append(ElementType X, List L);

#endif

struct Node
{
	ElementType Element;
	Position Next;
};
