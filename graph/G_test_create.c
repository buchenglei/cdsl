#include "create.h"
void main() {
    Graph *G = G_create(5);
    G_createEdge(1, 4, G);
    G_createEdge(1, 2, G);
    G_createEdge(1, 5, G);
    G_createEdge(2, 4, G);
    G_createEdge(2, 3, G);
    G_createEdge(2, 5, G);
    G_createEdge(4, 1, G);
    G_createEdge(5, 2, G);
    G_createEdge(3, 2, G);
    G_print(5, G);
}