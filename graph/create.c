// 图的邻接表表示
#include <stdlib.h>
#include <stdio.h>

struct Vertex{
    int num;
    struct Vertex *next;
};


struct Graph{
    int vertexNum;
    struct Vertex *v;
};

typedef struct Vertex Vertex;
typedef struct Graph Graph;

Graph *G_create(int vertexNum) {
    int i;
    
    // 创建图结构
    Graph *G = (Graph *)malloc(sizeof(Graph));
    if (G == NULL) {
        printf("Create Graph error!");
        exit(1);
    } else {
        G->vertexNum = vertexNum;
        G->v = (Vertex *)malloc(sizeof(Vertex) * (vertexNum + 1));
        if (G->v == NULL) {
            printf("malloc error!");
            exit(1);
        }
    }
    
    // 创建定点数组
    for (i = 0; i < vertexNum + 1; i++) {
        G->v[i].num = -1;
        G->v[i].next = NULL;
    }
    return G;
}

void G_createEdge(int start, int end, Graph *G) {
    Vertex *v, *p;
    v = &G->v[start];
    p = v;
    while(p != NULL) {
        if(p->next == NULL)
            break;
        else
            p = p->next;
    }
    p->next = (Vertex*)malloc(sizeof(Vertex));
    if(p->next == NULL) {
        printf("Create edge error!");
    }
    p->next->num = end;
    p->next->next = NULL;
}

void G_print(int num, Graph *G) {
    int i;
    
    num += 1;
    for(i = 1; i < num; i++) {
        Vertex *v = &G->v[i];
        printf("%d:\t", i);
        while(v != NULL) {
            if(v->num != -1) {
                printf("%d\t", v->num);
            }
            v = v->next;
        }
        
        printf("\n");
    }
    
}

