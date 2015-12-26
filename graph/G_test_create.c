#include "create.h"
void main() {
    Graph *G = G_create(5);
    G_createEdge(1, 4, 1, G);
    G_createEdge(1, 2, 1, G);
    G_createEdge(1, 5, 1, G);
    G_createEdge(2, 4, 1, G);
    G_createEdge(2, 3, 1, G);
    G_createEdge(2, 5, 1, G);
    G_createEdge(4, 1, 1, G);
    G_createEdge(5, 2, 1, G);
    G_createEdge(3, 2, 1, G);
    G_print(5, G);
}
