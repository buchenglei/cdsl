#ifndef _Cursor_H
#define _Cursor_H

#define ElementType int

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace( void );

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast( Position P, List L);
Position Find(ElementType Element, List L);
void Delete(ElementType X, List L);
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

