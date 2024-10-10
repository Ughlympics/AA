#include <iostream>
#include "Maingraph.h"
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include "WeightedGraph.h"

int main() {
    // Створення неорієнтованого графа на 5 вершинах
    UndirectedGraph ug(5);
    ug.addEdge(0, 1);
    ug.addEdge(0, 2);
    ug.printMatrix();

    std::cout << "====================\n";

    // Створення орієнтованого графа на 5 вершинах
    DirectedGraph dg(5);
    dg.addEdge(1, 2);
    dg.addEdge(3, 4);
    dg.printMatrix();

    std::cout << "====================\n";

 
    WeightedGraph wg(5);
    wg.addEdge(0, 1, 5);
    wg.addEdge(1, 2, 10);
    wg.printMatrix();

    return 0;
}
