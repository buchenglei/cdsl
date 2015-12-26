// 简单的有向图的拓扑排序的算法
#include <stdio.h>
#include <stdlib.h>
#include "create.h"

#define VERTEXNUM 7
struct Vertex;
struct Graph;
typedef struct Vertex Vertex;
typedef struct Graph Graph;

void main() {
    Graph *G = G_create(VERTEXNUM);
    // 创建边与边的关系
    G_createEdge(1, 2, 1, G);
    G_createEdge(1, 3, 1, G);
    G_createEdge(1, 4, 1, G);
    G_createEdge(2, 4, 1, G);
    G_createEdge(2, 5, 1, G);
    G_createEdge(3, 6, 1, G);
    G_createEdge(4, 3, 1, G);
    G_createEdge(4, 6, 1, G);
    G_createEdge(4, 7, 1, G);
    G_createEdge(5, 4, 1, G);
    G_createEdge(5, 7, 1, G);
    G_createEdge(7, 6, 1, G);
    // 输出测试结果
    G_print(VERTEXNUM, G);
    
    int count,i;
    for(count = 1; count <= VERTEXNUM; count++) {
        for(i = 1; i < VERTEXNUM; i++) {
            if(G_isused(i, G) == 0 && (G_indegree(i, G) == 0)) {
                G_setUsed(i, G);
                printf("%d\t", i);
            }
        }
    }
}
