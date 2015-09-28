// 所有的排序算法会被分别写入不同的源文件中
// 这里做统一调用
#include <stdio.h>
#include <time.h>
#include "sort.h"

#define TEST_DATA_LEN 100

// 用于保存测试数据的数组
int TestData[TEST_DATA_LEN];
time_t start_ms, start_s, end_ms, end_s;

// 用于生成测试数据
void newRandArray() {
    int i;
    // 用于生成测试数据
    srand((int)time(0));
    for(i = 0; i < TEST_DATA_LEN; i++)
        TestData[i] = rand() % TEST_DATA_LEN;
     
}

// 输出数组
void printArray() {
    int i;
    
    for(i = 0; i < TEST_DATA_LEN; i++)
        printf("%d\n", TestData[i]);
}

void start() {
    start_ms = clock();
    start_s = time(NULL);
}

void end(char* name) {
    end_ms = clock();
    end_s = time(NULL);
    
    printf("%s   共用时 %f ms(%f s)\n", name, difftime(end_ms, start_ms), difftime(end_s, start_s));
    
}

// 检查排序是否正确
void checkSort(char* name) {
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
        printf("%s   共有 %d 处排序出错的地方\n", name, e);
    else
        printf("%s   排序结果正确\n", name);
}

void main() {
   
    newRandArray();
    
    // 测试插入排序
    start();
    InsertionSort(TestData, TEST_DATA_LEN);
    end("插入排序");
    //printArray();
    checkSort("插入排序");
    
    // 测试希尔排序
    start();
    ShellSort(TestData, TEST_DATA_LEN);
    end("希尔排序");
    checkSort("希尔排序");
    
}