#ifndef _AVL_TREE_H
#define _AVL_TREE_H

#define MAX(a,b) ((a)>(b)?(a):(b))

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int ElementType;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
// 取回的dui'ying的对应的节点的值
ElementType Retrieve(Position P);
// 单旋转
Position SingleRotateWithLeft(Position K2);
// 双旋转
Position DoubleRotateWithLeft(Position K3);

void PrintTree(AvlTree T);
#endif

struct AvlNode {
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    // 树的高度
    // 每个节点都含有当前节点的高度
    int Height; 
};

