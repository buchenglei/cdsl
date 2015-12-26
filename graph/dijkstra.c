// dijkstra算法寻找赋权图的最短路径
#include <stdio.h>
#include <stdlib.h>
#include "create.h"

#define VertexNum 7
#define Infinity 99999

// 这个dist保存的始终是从某一点到起点的距离
int dist[VertexNum + 1];
int prev[VertexNum + 1];

void dijkstra(int start, Graph *G) {
	int i;
	Vertex *v, *w;
	
	for(i = 1; i <= VertexNum; i++) {
		dist[i] = Infinity;
		prev[i] = 0;
	}
	
	dist[start] = 0;
	/* 如果start点没有邻接点，那么这个点就不能作为起始点
	if(v->next == NULL) {
		printf("Can't use this vertex as start!");
		exit(1);
	}*/

	int minV;
	int numOfUsed = 0;

	while(1) {
		minV = VertexNum;
		
		if(numOfUsed == VertexNum) {
			break;
		}
		// 寻找距离最短，并且没有被处理的点
		for(i = 1; i <= VertexNum; i++) {
			if(dist[i] != Infinity && G_isused(i, G) == 0 && dist[i] <= dist[minV]) {
				minV = i;
			}
		}
		
		v = &G->v[minV];
		G_setUsed(minV, G);
		numOfUsed ++;
		w = v->next;
		while(w != NULL) {
			if(dist[w->num] == Infinity) {
				dist[w->num] = dist[v->num] + w->weight;
				prev[w->num] = v->num;
			} else if((dist[v->num] + w->weight) < dist[w->num]) {
				// 如果某一点的距离加上到其邻接点边的权值小于该邻接点的权值
				// 则根更新该邻接点的距离信息
				dist[w->num] = dist[v->num] + w->weight;
				prev[w->num] = v->num;
			}
		
			w = w->next;
		}
	}
	
	
}

// 寻找从初始点到终点的最短路径
void smallPath(int start, int end) {
	int p = end;

	while(p != start) {
		printf("%d <- ", p);
		p = prev[p];
	}
	printf("%d\n", start);
}

void main() {
	Graph *G = G_create(VertexNum);
	
	G_createEdge(1, 2, 2, G);
	G_createEdge(1, 4, 1, G);
	G_createEdge(2, 4, 3, G);
	G_createEdge(2, 5, 10, G);
	G_createEdge(3, 1, 4, G);
	G_createEdge(3, 6, 5, G);
	G_createEdge(4, 3, 2, G);
	G_createEdge(4, 5, 2, G);
	G_createEdge(4, 6, 8, G);
	G_createEdge(4, 7, 4, G);
	G_createEdge(5, 7, 6, G);
	G_createEdge(7, 6, 1, G);
	
	dijkstra(1, G);
	int i = 0;
	//smallPath(1,7);
	for(; i <= VertexNum; i++) {
		printf("dist[%d]=%d\n", i, dist[i]);
	}
	
	//G_print(VertexNum, G);
}
