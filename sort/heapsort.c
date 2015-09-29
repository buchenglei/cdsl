#include <stdio.h>
#include "sort.h"

// 数组是从零下标开始的
// 和之前的二叉堆不一样，那是第一个元素从1开始
// 所以leftchild为2i
#define LeftChild(i) (2 * (i) + 1)

// 该堆排序的的过程是将二叉堆的根节点删除，并放在数组的尾部
// 这里的堆序性应该满足根节点要比其子节点大
// 每次执行类似DeleteMax的操作，将最大的根删除，放在数组的尾部
// 那么从下标0输出数组的时候就是从小到大输出整个数组的值
void PercDown(ElementType A[], int i, int N) {
    
    int Child;
    ElementType Tmp;
    
    for(Tmp = A[i]; LeftChild(i) < N; i = Child) {
        Child = LeftChild(i);
        if(Child != N -1 && A[Child + 1] > A[Child])
            Child++;
        if(Tmp < A[Child])
            A[i] = A[Child];
        else
            break;
    }
    
    A[i] = Tmp;
}

void HeapSort(ElementType A[], int N) {
    
    int i;
    ElementType Tmp;
    
    for(i = N / 2; i >= 0; i--)
        PercDown(A, i, N);
    for(i = N - 1; i > 0; i--) {
        Tmp = A[0];
        A[0] = A[i];
        A[i] = Tmp;
        PercDown(A, 0 , i);
    }
}