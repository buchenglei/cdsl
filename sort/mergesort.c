#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// 将两个数组中的元素按排序规则合并到一个数组过程中
// Lpos = start of left half
// Rpos = start of right half
void Merge(ElementType A[], ElementType TmpArray[], 
                int Lpos, int Rpos, int RightEnd) {
                    
    int i, LeftEnd, NumElements, TmpPos;
    
    LeftEnd =  Rpos - 1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;
    
    // main loop
    while(Lpos <= LeftEnd && Rpos <= RightEnd)
        if(A[Lpos] <= A[Rpos])
            // 将两个数组中较小的元素放入TmpArray
            // 并将其指针向后移动一位，另外一个数组的指针则不动
            TmpArray[TmpPos++] = A[Lpos++];
        else
            // 道理同上
            TmpArray[TmpPos++] = A[Rpos++];
    
    // 如果左边数组还有剩余则将剩余元素拷贝至TmpArray
    while(Lpos <= LeftEnd)
        TmpArray[TmpPos++] = A[Lpos++];
        
    // 如果右边数组还有剩余则将剩余元素拷贝至TmpArray
    while(Rpos <= RightEnd)
        TmpArray[TmpPos++] = A[Rpos++];
             
    // 将TmpArray数组的元素拷贝回A指向的原数组
    for(i = 0; i < NumElements; i++, RightEnd--)
        // 只有RightEnd在上述处理过程中没有发生改变
        A[RightEnd] = TmpArray[RightEnd];
}

// Left = first of array;
// Right = end of array;
void MSort(ElementType A[], ElementType TmpArray[],
                int Left, int Right) {

    int Center;
    
    if(Left < Right) {
        Center = (Left + Right) / 2;
        MSort(A, TmpArray, Left, Center);
        MSort(A, TmpArray, Center + 1, Right);
        Merge(A, TmpArray, Left, Center + 1, Right);
    }
                    
}

void MergeSort(ElementType A[], int N) {
    
    ElementType *TmpArray;
    
    TmpArray = (ElementType*)malloc(N * sizeof(ElementType));
    if(TmpArray != NULL) {
        MSort(A, TmpArray, 0, N - 1);
        free(TmpArray);
    } else {
        printf("No space for tmp array!");
    }
    
}