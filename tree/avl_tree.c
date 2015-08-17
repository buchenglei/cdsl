/*
 * 带有平衡条件的二叉查找树
 * 测试使用的数据来自书上
 * 单旋转和双旋转都涉及到了
 * ps: 
 * 之前的代码风格一直都是按照书上来的
 * 但是，慢慢的发现自己很不喜欢，我也用其他编程语言
 * 还是把风格统一起来比较舒服
 */
#include <stdlib.h>
#include <stdio.h>
#include "avl_tree.h"

void main() {
    AvlTree T = NULL;
    printf("数据插入的顺序为：\n");
    printf("3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9\n");
    T = Insert(3, T);
    T = Insert(2, T);
    T = Insert(1, T);
    T = Insert(4, T);
    T = Insert(5, T);
    T = Insert(6, T);
    T = Insert(7, T);
    T = Insert(16, T);
    T = Insert(15, T);
    T = Insert(14, T);
    T = Insert(13, T);
    T = Insert(12, T);
    T = Insert(11, T);
    T = Insert(10, T);
    T = Insert(8, T);
    T = Insert(9, T);
    
    
    printf("后序遍历输出树：\n");
    PrintTree(T);
    printf("\n");
}

int Height(Position P) {
    if(P == NULL)
        return -1;
    else
        return P->Height;
}

AvlTree Insert(ElementType X, AvlTree T) {
    if(T == NULL) {
        // 如果T为空， 则创建并返回只有一个节点的树
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        if(T == NULL) {
            printf("Out of space!!!");
            exit(1);
        } else {
            T->Element = X;
            T->Height = 0; 
            T->Left = T->Right = NULL;
        }
    } else if(X < T->Element) {
        T->Left = Insert(X, T->Left);
        // 插入过程结束后执行旋转函数
        if(Height(T->Left) - Height(T->Right) == 2)
            if(X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        
    } else if(X > T-> Element) {
        T->Right = Insert(X, T->Right);
        // 插入过程结束后执行旋转函数
        if(Height(T->Right) - Height(T->Left) == 2)
            if(X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
    }
    // 以上结果都不满足，则X已经是树中的节点，什么也不做
    T->Height = MAX(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

Position SingleRotateWithLeft(Position K2) {
    Position K1;
    
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    
    K2->Height = MAX(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = MAX(Height(K1->Left), K2->Height) + 1;

    // 返回转换后的节点
    // 这是一个新的root
    return K1;
}

Position SingleRotateWithRight(Position K2) {
    Position K1;
    
    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;
    
    K2->Height = MAX(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = MAX(Height(K1->Right), K2->Height) + 1;
    
    return K1;
     
}

Position DoubleRotateWithLeft(Position K3) {
    K3->Left = SingleRotateWithRight(K3->Left);
    
    return SingleRotateWithLeft(K3);
}

Position DoubleRotateWithRight(Position K3) {
    K3->Right = SingleRotateWithLeft(K3->Right);
    
    return SingleRotateWithRight(K3);
}

// 后序遍历输出树
void PrintTree(AvlTree T) {
    if(T->Left != NULL)
        PrintTree(T->Left);
        
    if(T->Right != NULL)
        PrintTree(T->Right);
        
    printf("%d(H:%d)  ", T->Element, Height(T));
}