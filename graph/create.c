// 图的邻接表表示
#include <stdlib.h>
#include <stdio.h>

struct Vertex {
    int num;
    struct Vertex *next;
};


struct Graph {
    int vertexNum;
    struct Vertex *v;
};

struct Graph *G_create(int vertexNum) {
    int i;
    
    // 创建图结构
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    if (G == NULL) {
        printf("Create Graph error!");
        exit(1);
    } else {
        G->vertexNum = vertexNum;
        G->v = (struct Vertex *)malloc(sizeof(struct Vertex) * vertexNum);
        if (G->v == NULL) {
            printf("malloc error!");
            exit(1);
        }
    }
    
    // 创建定点数组
    for (i = 0; i < vertexNum; i++) {
        G->v[i].next = NULL;
    }
    return G;
}

void G_createEdge(int start, int end) {
    
}

void main() {
    
}

