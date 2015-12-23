// 无权最短路径算法实例
#include <stdio.h>
#include "create.h"

#define VertexNum 7
#define Infinity -1

int dist[VertexNum + 1];
int prev[VertexNum + 1];

// 这里计算无权最短路径
// 计算后dist和prev数组存储的是每一个顶点到start点的最短距离
// 如果要将start设为其他的值，则需要重新计算
void unweighted(int start, Graph *G) {
	int CurrDist, i;
	Vertex *V, *W;
	
	// 初始化用于计算无权最短路径的表
	for(i = 1; i <= VertexNum; i++) {
		dist[i] = Infinity;
		prev[i] = 0;
	}
	// 选取一个开始的顶点，并将其距离设为0
	dist[start] = 0;
	
	//for(CurrDist = 0, i = 1; CurrDist < VertexNum && i <= VertexNum; CurrDist++, i++) {
	for(CurrDist = 0; CurrDist < VertexNum; CurrDist++) {
		for(i = 1; i <= VertexNum; i++) {
			// 当前节点的dist==0并且该节点未使用
			if(dist[i] == CurrDist && G_isused(i, G) == 0) {
				// 将当前正在处理的节点设为已知
				G_setUsed(i, G);
				// 取得该节点的第一个邻接点
				W = &G->v[i];
				W = W->next;
				while(W != NULL) {
					// 只有当前的邻接点到起始点的距离为无穷大的时候，才需要处理
					// 如果当前邻接点的距离不为无穷大，很明显，在这之前，它已经被其他节点处理过了
					if(dist[W->num] == Infinity) {
						// 将该邻接点到起始点的距离设置为下一个待处理的距离
						dist[W->num] = CurrDist + 1;
						prev[W->num] = i;
					}
					W = W->next;
				}
			}
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

int main() {
	Graph *G = G_create(VertexNum);
	
	G_createEdge(1, 2, G);
	G_createEdge(1, 4, G);
	G_createEdge(2, 4, G);
	G_createEdge(2, 5, G);
	G_createEdge(3, 1, G);
	G_createEdge(3, 6, G);
	G_createEdge(4, 3, G);
	G_createEdge(4, 5, G);
	G_createEdge(4, 6, G);
	G_createEdge(4, 7, G);
	G_createEdge(5, 7, G);
	G_createEdge(7, 6, G);

	int start = 2;
	printf("The smallest path to V%d:\n", start);
	unweighted(start, G);
	printf("V%d -> V7:\n", start);
	smallPath(start, 7);
	printf("V%d -> V5:\n", start);
	smallPath(start, 5);
	
	// 如果要重新计算距离，则需要重置图结构!!!!!!!

	return 0;
}
