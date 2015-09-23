#include "sort.h"

// 插入排序例程
void InsertionSort(ElementType A[], int N) {
    
    int j, p;
    ElementType Tmp;
    
    // 第一个数不用排序，所以p的初始值为1
    for(p = 1; p < N; p++) {
        
        Tmp = A[p];
        for(j = p; j > 0 && A[j - 1] > Tmp; j--)
            A[j] = A[j - 1];
        
        A[j] = Tmp;
    }
    
}