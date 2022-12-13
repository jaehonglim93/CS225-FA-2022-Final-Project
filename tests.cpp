//#include <catch2/catch_test_macros.hpp>
#include "Graph.h"
#include "Node.h"
#include "Graph.cpp"
#include <cassert>

using namespace std;

void printVector(vector<int> vect) {
    cout << "Vector Printed" << endl;
    for(int i : vect) {
        cout << i << endl;
    }
    cout << "--------------\n" << endl;
}

void test_Small_BFS(Graph g) {
    cout << "Testing test_Small_BFS..." << endl;
    // BFS Test Cases:

    // Node 0 to 7 : expected {0, 1, 6, 7}
    vector<int> zeroToSeven = g.BFS(0, 7);
    vector<int> expected_07 = {0, 1, 6, 7};
    assert(zeroToSeven == expected_07);

    // Node 1 to 5 : expected {1, 6, 5}
    vector<int> oneToFive = g.BFS(1, 5);
    vector<int> expected_15 = {1, 6, 5};
    assert(oneToFive == expected_15);

    // Node 7 to 3 : expected {7, 6, 4, 3}
    vector<int> sevenToThree = g.BFS(7, 3);
    vector<int> expected_73 = {7, 6, 4, 3};
    assert(sevenToThree == expected_73);

    cout << "### FINISHED test_Small_BFS.\n------------------\n" << endl;
}

void test_Small_Floyd(Graph g) {
    // Test case for Floyd-Warshall:

    // Expected 1 as result
    vector<vector<int>> fWarshall = g.FloydWarshall();
    int expected = fWarshall[0][1];
    cout << expected << endl;
    assert(expected == 1);
}

void test_Small_AStar(Graph g) {
    cout << "Testing test_Small_AStar..." << endl;
    // Test Cases for A Star:

    // Node 0 to 2 : Expected {0, 1, 6, 4, 3, 2}
    vector<int> zeroToTwo = g.AStar(0, 2);
    vector<int> expected_02 = {0, 1, 6, 4, 3, 2};
    printVector(zeroToTwo);
    assert(zeroToTwo == expected_02);

    cout << "### FINISHED test_Small_AStar.\n------------------\n" << endl;
}

int main() {
    vector<Node> nodes;
    nodes.push_back(Node(0, 0, 1));
    nodes.push_back(Node(1, 0, 1));
    nodes.push_back(Node(2, 0, 1));
    nodes.push_back(Node(3, 0, 1));
    nodes.push_back(Node(4, 0, 1));
    nodes.push_back(Node(5, 0, 1));
    nodes.push_back(Node(6, 0, 1));
    nodes.push_back(Node(7, 0, 1));

    vector<Edge> edges;
    edges.push_back(Edge(0, 1, 1));
    edges.push_back(Edge(1, 2, 16));
    edges.push_back(Edge(2, 3, 2));
    edges.push_back(Edge(3, 4, 2));
    edges.push_back(Edge(4, 5, 1));
    edges.push_back(Edge(5, 6, 8));
    edges.push_back(Edge(4, 6, 4));
    edges.push_back(Edge(1, 6, 2));
    edges.push_back(Edge(6, 7, 1));

    Graph small_graph = Graph(nodes, edges);

    test_Small_BFS(small_graph);
    test_Small_Floyd(small_graph);


    // A Star Graph
    vector<Node> a_nodes;
    a_nodes.push_back(Node(0, 2, 0));
    a_nodes.push_back(Node(1, 1, 0));
    a_nodes.push_back(Node(2, 0, 1));
    a_nodes.push_back(Node(3, 0, 2));
    a_nodes.push_back(Node(4, 0, 3));
    a_nodes.push_back(Node(5, 1, 4));
    a_nodes.push_back(Node(6, 1, 2));
    a_nodes.push_back(Node(7, 2, 2));

    vector<Edge> a_edges;
    a_edges.push_back(Edge(0, 1, 1));
    a_edges.push_back(Edge(1, 2, 16));
    a_edges.push_back(Edge(2, 3, 2));
    a_edges.push_back(Edge(3, 4, 2));
    a_edges.push_back(Edge(4, 5, 1));
    a_edges.push_back(Edge(5, 6, 8));
    a_edges.push_back(Edge(4, 6, 4));
    a_edges.push_back(Edge(1, 6, 2));
    a_edges.push_back(Edge(6, 7, 1));
    Graph a_small_graph = Graph(a_nodes, a_edges);

    test_Small_AStar(a_small_graph);
    return 0;
}