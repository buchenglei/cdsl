/*
 * 二项队列
 */
#include <stdio.h>
#include <stdlib.h>
#include "binqueue.h"

void main() {
    
}

BinQueue InitCollection() {
 
    BinQueue H = (BinQueue)malloc(sizeof(struct Collection));
    
    if(H == NULL) {
        printf("Out of space!");
        return NULL;
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
    
}