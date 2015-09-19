/*
 * 二项队列
 */
#include <stdio.h>
#include <stdlib.h>
#include "binqueue.h"

void main() {
   BinQueue H = InitCollection(3);
   H = Insert(12, H);
   //H = Insert(24, H);
   //H = Insert(21, H);
   //H = Insert(65, H);
   // TODO 执行到这一句的时候Segment Fault
   PrintQueue(H);
    
}

BinQueue InitCollection(int size) {
 
    BinQueue H = (BinQueue)malloc(sizeof(struct Collection));
    
    if(H == NULL) {
        printf("Out of space!");
        return NULL;
    }
    
    // TODO 暂时还不能理解这玩意是干嘛用的
    H->CurrentSize = size;
    
    int i;
    for(i = 0; i< MaxTrees; i++) {
        H->TheTrees[i]= NULL;
    }
    
    return H;
    
}

BinTree InitBinNode(ElementType X) {
    
    BinTree N = (BinTree)malloc(sizeof(struct BinNode));
    
    if(N == NULL) {
        printf("Out of space!");
        return NULL;
    }
    
    N->Element = X;
    N->LeftChild = NULL;
    N->NextSibling = NULL;
    
    return N;
    
}

// 合并高度相同的二项树
BinTree CombineTree(BinTree T1, BinTree T2) {
    
    if(T1->Element > T2->Element)
        // 是要将根节点大的合并到根节点小的二项树上
        return CombineTree(T2, T1);
        
    // 待合并的二项树中根节点的NextSibling一定为NULL
    // 现在T1 < T2
    T2->NextSibling = T1->LeftChild;
    T1->LeftChild = T2;
    
    return T1;
    
}

// 合并两个二项队列
// H1包含合并的结果
BinQueue Merge(BinQueue H1, BinQueue H2) {
    
    BinTree T1, T2, Carry = NULL;
    int i, j;
    
    if((H1->CurrentSize + H2->CurrentSize) > MaxTrees) {
        printf("Merge would exceed capacity!");
        return NULL;
    }
    
    H1->CurrentSize += H2->CurrentSize;
    for(i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2) {
        T1 = H1->TheTrees[i];
        T2 = H2->TheTrees[i];
        
        switch(!!T1 + 2 * !!T2 + 4 * !!Carry){
            case 0: // nothing
            case 1: break; // only H1, do nothing
            case 2: // only H2
                H1->TheTrees[i] = T2;
                H2->TheTrees[i] = NULL;
                break;
            case 4: // only Carry
                H1->TheTrees[i] = Carry;
                Carry = NULL;
                break;
            case 3: // H1 and H2
                // 当合并两颗等高的二项树时
                // 新的二项式的树高会 +1
                // 这个新合并的二项树需要暂存起来，等待和下一个等高的二项树合并
                Carry = CombineTree(T1, T2);
                H1->TheTrees[i] = H2->TheTrees[i] = NULL;
                Carry = NULL;
                break;
            case 5: // H1 and Carry
                Carry = CombineTree(T1, Carry);
                H1->TheTrees[i] = NULL;
                break;
            case 6: // T2 and Carry
                Carry = CombineTree(T2, Carry);
                H2->TheTrees[i] = NULL;
                break;
            case 7: // T1, T2 and Carry
                H1->TheTrees[i] = Carry;
                Carry = CombineTree(T1, T2);
                H2->TheTrees[i] = NULL; 
                break;
        }
    }
    
    return H1;
    
}

ElementType DeleteMin(BinQueue H) {
    
    int i, j;
    int MinTree;
    BinQueue DeletedQueue;
    Position DeletedTree, OldRoot;
    ElementType MinItem;
    
    if(H->CurrentSize == 0) {
        printf("Empty binomial queue");
        return -Infinity;
    }
    
    MinItem = Infinity;
    // 寻找集合中根节点最小的二项树
    for(i = 0; i < MaxTrees; i++) {
        if(H->TheTrees[i] &&
                H->TheTrees[i]->Element < MinItem) {
            MinItem = H->TheTrees[i]->Element;
            MinTree = i;
        }
    }
    
    // 取出待删除的二项树
    DeletedTree = H->TheTrees[MinTree];
    OldRoot = DeletedTree;
    DeletedTree = DeletedTree->LeftChild;
    free(OldRoot);
    // TODO 这里CurrentSize的大小还没弄懂
    DeletedQueue = InitCollection((1 << MinTree) - 1);
    // 删除根节点以后，要将根节点LeftChild的中NextSibling全部拆开 
    for(j = MinTree - 1; j >= 0; j--) {
        DeletedQueue->TheTrees[j] = DeletedTree;
        DeletedTree = DeletedTree->NextSibling;
        DeletedQueue->TheTrees[j]->NextSibling = NULL;
    }
    // 将原来二项队列中包含最小根元素的二项树删除
    // 因为已经将其拆散后保存在新的空二项队列中了
    H->TheTrees[MinTree] = NULL;
    H->CurrentSize -= DeletedQueue->CurrentSize + 1;
    
    // 这里合并的是两个二项队列
    Merge(H, DeletedQueue);
    
    return MinItem;
    
}

// 书上并没有提供该函数的例程，也许可以有更好的写法
BinQueue Insert(ElementType X, BinQueue H1) {
    
    BinQueue H2 = InitCollection(1); 
    BinTree T = InitBinNode(X);
    
    H2->TheTrees[MaxTrees - 1] = T;
    // 二项队列的插入，可以理解为创建一个只包含一个
    // 新节点的集合，然后将已存在的二项队列与之合并
    return Merge(H1, H2);
    
}

// 测试用的输出数组中的每个二项树
void PrintTree(BinTree T) {
    
    if(T == NULL) {
        return;
    }
    
    printf("%d  ", T->Element);
    PrintTree(T->NextSibling);
    PrintTree(T->LeftChild);
    
}

// 测试用的输出二项队列
void PrintQueue(BinQueue H) {
    
    int i;
    
    if(H == NULL)
        return;
    
    for(i = 0; i < MaxTrees; i++) {
        if(H->TheTrees[i] == NULL) {
            continue;
        }
        
        PrintTree(H->TheTrees[i]);
    }
    
}