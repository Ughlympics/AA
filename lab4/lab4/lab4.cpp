#include "UF.h"

int main() {
    int numVertices = 6;
    KruskalMST mst(numVertices);

    mst.addEdge(0, 1, 4);
    mst.addEdge(0, 2, 3);
    mst.addEdge(1, 2, 1);
    mst.addEdge(1, 3, 2);
    mst.addEdge(2, 3, 5);
    mst.addEdge(3, 4, 7);
    mst.addEdge(4, 5, 6);
    mst.addEdge(3, 5, 8);

    mst.findMST(); 

    return 0;
}

