#include <stdio.h>
#include <stdlib.h>
#include "leftheap.h"

void PrintQueue(PriorityQueue H) {
    if(H->Left != NULL)
        PrintQueue(H->Left);
        
    if(H->Right != NULL)
        PrintQueue(H->Right);
        
    printf("%d  ", H->Element);
        
}

void main() {
    
    PriorityQueue Q;
    
    Q = Insert(3, Q);
    Q = Insert(10, Q);
    Q = Insert(8, Q);
    
    PrintQueue(Q);
}

int IsEmpty(PriorityQueue H) { return H == NULL; }

ElementType FindMin(PriorityQueue H) { return H->Element; }

// 合并左式堆的驱动例程
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2) {
    
    if(H1 == NULL)
        return H2;
    if(H2 == NULL)
        return H1;
        
    // 将根节点大的子树向根节点小的子树上合并
    if(H1->Element <= H2->Element)
        return Merge1(H1, H2);
    else
        return Merge1(H2, H1);

}

// 合并左式堆的实际例程
// 该函数只负责将H2合并到H1上，比较大小的操作在Merge中完成
PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2) {
    
    // 最是对的性质：
    // 对于堆中的每一个节点X，
    // 做儿子的Npl >= 右儿子的Npl
    // 由左式堆的性质可以知道：
    // 首先H1是左式堆，当期左节点为空的时候，有节点必然为空
    if(H1->Left == NULL)
        H1->Left = H2;
    else  {
        // 合并总是向右子树上合并
        H1->Right = Merge(H1->Right, H2);
        if(H1->Left->Npl < H1->Right->Npl) {
            // 交换左右子树
            PriorityQueue tmp;
            
            tmp = H1->Right;
            H1->Right = H1->Left;
            H1->Left = tmp;
        }
        H1->Npl = H1->Right->Npl + 1;
    }
    
    return H1;
    
}

PriorityQueue Insert(ElementType X, PriorityQueue H) {
    
    PriorityQueue SingleNode;
    
    SingleNode = (PriorityQueue)malloc(sizeof(struct TreeNode));
    if(SingleNode == NULL)
        printf("Out of space!");
    else {
        SingleNode->Element = X;
        SingleNode->Npl = 0;
        SingleNode->Left = SingleNode->Right = NULL;
        H = Merge(SingleNode, H);
    }
    
    return H;
    
}

PriorityQueue DeleteMin(PriorityQueue H) {
    
    PriorityQueue LeftHeap, RightHeap;
    
    if(IsEmpty(H)) {
        printf("Priority Queue is empty");
        return H;
    }
    
    LeftHeap = H->Left;
    RightHeap = H->Right;
    free(H);
    return Merge(LeftHeap, RightHeap);
}