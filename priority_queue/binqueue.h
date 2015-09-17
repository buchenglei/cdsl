#ifndef _BinQueue_H
#define _BinQueue_H

// 定义用于存储二项树的数组大小
#define MaxTrees 5
// 定义一个在待处理的数据中正负不可能达到值
#define Infinity 10000

struct BinNode;
struct Collection;
typedef struct BinNode *Position;
typedef Position BinTree;
typedef struct Collection *BinQueue;
typedef int ElementType;

BinTree CombineTrees(BinTree T1, BinTree T2);
BinQueue Merge(BinQueue H1, BinQueue H2);
ElementType DeleteMin(BinQueue H);
BinQueue InitCollection(int size);
Position InitBinNode(ElementType X);
BinQueue Insert(ElementType X, BinQueue H);

struct BinNode {
    ElementType Element;
    Position LeftChild;
    Position NextSibling;
};

struct Collection {
    int CurrentSize;
    BinTree TheTrees[MaxTrees];
};

#endif