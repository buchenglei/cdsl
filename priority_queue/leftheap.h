#ifndef _LeftHeap_H
#define _LeftHeap_H

struct TreeNode;
typedef struct TreeNode *PriorityQueue;
typedef int ElementType;

// 不同于二叉堆，左式堆不再使用数组存储数据
PriorityQueue Init();
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2);

PriorityQueue Insert(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin(PriorityQueue H);

struct TreeNode {
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;    // 零路径长度
};

#endif