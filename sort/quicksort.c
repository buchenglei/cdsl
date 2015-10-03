#include <stdio.h>
#include "sort.h"

#define Cutoff (3)

// 交换两数的值
void Swap(int *a, int *b) {
    int Tmp;
    Tmp = *a;
    *a = *b;
    *b = Tmp;
}

// 实现三个数中值分割方法的函数
// 也就是在数组中取出3个数按从小到大的顺序排列
// 返回中间值，影响实际的数组
ElementType Median3(ElementType A[], int Left, int Right) {
    
    int Center = (Left + Right) / 2;
    
    if(A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if(A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if(A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);
    
    Swap(&A[Center], &A[Right - 1]);
    return A[Right - 1];
}
    

// 快速排序的主函数
void Qsort(ElementType A[], int Left, int Right) {
    int i, j;
    ElementType Pivot;
    
    if(Left + Cutoff <= Right) {
        Pivot = Median3(A, Left, Right);
        i = Left;
        j = Right - 1;
        
        // 去掉了两个之前用Median3函数处理的数据
        for(;;) {
            while(A[++i] < Pivot) {}
            while(A[--j] > Pivot) {}
            if(i < j)
                Swap(&A[i], &A[j]);
            else
                break;
        }
        
        Swap(&A[i], &A[Right - 1]);
        // 此时 i 在数组中的位置即为Pivot
        // 对Pivot的左半部分执行快速排序
        Qsort(A, Left, i - 1);
        // 对Pivot的右半部分执行快速排序
        Qsort(A, i + 1, Right);
    } else {
        // 如果待排序的数组长度过短，则直接使用插入排序
        InsertionSort(A + Left, Right - Left + 1);
    }
}

// 快速排序的主函数
void QuickSort(ElementType A[], int N) {
    
    Qsort(A, 0, N - 1);
    
}