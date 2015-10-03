// 所有的排序算法会被分别写入不同的源文件中
// 这里做统一调用
#include <stdio.h>
#include <time.h>
#include "sort.h"

#ifndef TEST_DATA_LEN
#define TEST_DATA_LEN 100
#endif
// 用于保存测试数据的数组
int TestData[TEST_DATA_LEN];
// 用于测试的原始数据，保证多次测试的数据一致
int rawData[TEST_DATA_LEN];
time_t start_ms, start_s, end_ms, end_s;

// 用于生成测试数据
void newRandArray() {
    int i;
    // 用于生成测试数据
    srand((int)time(0));
    for(i = 0; i < TEST_DATA_LEN; i++)
        rawData[i] = rand() % TEST_DATA_LEN;
     
}

// 输出数组
void printArray() {
    int i;
    
    for(i = 0; i < TEST_DATA_LEN; i++)
        printf("%d\n", TestData[i]);
}

void start() {
    int i;
    // 恢复待排序的数据
    for(i = 0; i < TEST_DATA_LEN; i++)
        TestData[i] = rawData[i];
    
    start_ms = clock();
    start_s = time(NULL);
}

void end(char* name) {
    end_ms = clock();
    end_s = time(NULL);
    
    int i, e = 0;
    
    for(i = 0; i < TEST_DATA_LEN; i++) {
        if(i == TEST_DATA_LEN - 1)
            break;
            
        if(TestData[i] > TestData[i + 1]) {
            printf("Find error position: %d-(%d) and %d-(%d)\n",
                                            i, TestData[i], i + 1, TestData[i + 1]);
            e++;
        }
    }
    
    if(e != 0 )
        printf("'%s' 共有 %d 处排序出错的地方\t", name, e);
    else
        printf("'%s' 排序结果正确\t", name);
        
    printf("共用时 %f ms(%f s)\n", difftime(end_ms, start_ms), difftime(end_s, start_s));
    
}

void main() {
   
    newRandArray();
    
    // 测试插入排序
    start();
    InsertionSort(TestData, TEST_DATA_LEN);
    end("插入排序");
    
    // 测试希尔排序
    start();
    ShellSort(TestData, TEST_DATA_LEN);
    end("希尔排序");
    
    // 堆排序测试
    start();
    HeapSort(TestData, TEST_DATA_LEN);
    end("堆排序");
    
    // 归并排序
    start();
    MergeSort(TestData, TEST_DATA_LEN);
    end("归并排序");
    
    // 快速排序
    start();
    QuickSort(TestData, TEST_DATA_LEN);
    end("快速排序");
}