#ifndef _CREATE_H
#define _CREATE_H

    struct Vertex{
		int num;
		int use;
		struct Vertex *next;
	};


	struct Graph{
		int vertexNum;
		struct Vertex *v;
	};

	typedef struct Vertex Vertex;
	typedef struct Graph Graph;

    Graph *G_create(int vertexNum);
    void G_createEdge(int start, int end, Graph *G);
    void G_print(int num, Graph *G);
    int G_indegree(int num, Graph *G);
    void G_setUsed(int num , Graph *G);
    int G_isused(int num, Graph *G);
#endif
