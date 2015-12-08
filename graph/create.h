#ifndef _CREATE_H
#define _CREATE_H

    typedef struct Vertex Vertex;
    typedef struct Graph Graph;
    Graph *G_create(int vertexNum);
    void G_createEdge(int start, int end, Graph *G);
    void G_print(int num, Graph *G);
    
#endif