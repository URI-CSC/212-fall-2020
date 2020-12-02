#include "adjacency-matrix.h"
#include "adjacency-list.h"

void test_matrix(std::string fname);
void test_list(std::string fname);

int main(int argc, char* argv[]){
    test_matrix(std::string(argv[1]));
    //test_list(std::string(argv[1]));
}

void test_matrix(std::string fname){
    AdjMatrix g;

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 7);
    g.addEdge(1, 3, 15);
    g.addEdge(1, 4, 10);
    g.addEdge(1, 5, 12);
    g.addEdge(2, 4, 15);
    g.addEdge(2, 5, 7);
    g.addEdge(3, 6, 9);
    g.addEdge(3, 7, 13);
    g.addEdge(4, 6, 12);
    g.addEdge(4, 7, 8);
    g.addEdge(5, 6, 12);
    g.addEdge(5, 7, 15);
    g.addEdge(6, 8, 9);
    g.addEdge(7, 8, 5);

    g.printGraph();
    g.outputGraph(fname);

    // Should display 1
    std::cout << g.isAdjacent(0, 1) << std::endl;

    // Should display 0
    std::cout << g.isAdjacent(0, 3) << std::endl;
}

void test_list(std::string fname){
    AdjList g;

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 7);
    g.addEdge(1, 3, 15);
    g.addEdge(1, 4, 10);
    g.addEdge(1, 5, 12);
    g.addEdge(2, 4, 15);
    g.addEdge(2, 5, 7);
    g.addEdge(3, 6, 9);
    g.addEdge(3, 7, 13);
    g.addEdge(4, 6, 12);
    g.addEdge(4, 7, 8);
    g.addEdge(5, 6, 12);
    g.addEdge(5, 7, 15);
    g.addEdge(6, 8, 9);
    g.addEdge(7, 8, 5);

    // Should display 1
    std::cout << g.isAdjacent(0, 1) << std::endl;

    // Should display 0
    std::cout << g.isAdjacent(0, 3) << std::endl;

    g.outputGraph(fname);
    g.problem1(fname);
    g.problem2(fname);
    g.problem3(fname);
    g.problem4(fname);
}