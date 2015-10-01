// 包含各种排序方式的函数声明
// 所有的排序函数都是从小到大进行排序
#ifndef _SORT_H
#define _SORT_H

typedef int ElementType;

// 插入排序函数
void InsertionSort(ElementType A[], int N);

// 希尔排序
void ShellSort(ElementType A[], int N);

// 堆排序
void HeapSort(ElementType A[], int N);

// 归并排序
void MergeSort(ElementType A[], int N);

#endif