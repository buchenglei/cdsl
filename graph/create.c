// 图的邻接表表示
#include <stdlib.h>
#include <stdio.h>
#include "create.h"

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
        G->v[i].use = 0; // 初始状态，该节点没有使用
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
        printf("%d(", i);
        if(v->use == 0)
            printf("unuse):\t");
        else
            printf("used):");
            
        while(v != NULL) {
            // -1代表头结点，不作处理
            if(v->num != -1) {
                printf("%d\t", v->num);
            }
            v = v->next;
        }
        
        printf("\n");
    }
    
}

// 计算节点的入度
int G_indegree(int num, Graph *G) {
    int i, indegree = 0;
    Vertex *v;
    
    for(i = 1; i <= G->vertexNum; i++) {
        v = &G->v[i];
        if(v->use == 1) 
            continue;
            
        while(v != NULL) {
            if(v->num == num )
                indegree++;
            v = v->next;
        }
    }
    
    return indegree;
}

void G_setUsed(int num , Graph *G) {
    G->v[num].use = 1;
}

int G_isused(int num, Graph *G) {
	// 0 - 未使用
	// 1 - 已被使用
    return G->v[num].use;
}
