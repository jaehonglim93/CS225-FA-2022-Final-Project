#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Node.h"
#include "Graph.h"
#include "Graph.cpp"

using namespace std;

int main() {
    string nodeFile = "../data/test.cnode.txt"; //"../data/cal.cnode.txt";
    string edgeFile = "../data/test.cedge.txt"; //"../data/cal.cedge.txt";
    
    ifstream ifs(nodeFile);
    string line;
    
    // STORING NODES
    vector<Node> nodes;
    
    while(getline(ifs, line)) {
        // Read the line
        int id;
        float x, y;

        stringstream ss(line);
        ss >> id;
        ss >> x;
        ss >> y;

        // Store the line's data into a Node class
        nodes.push_back(Node(id, x, y));
    }

    ifstream ifs2(edgeFile);
    string line2;

    // STORING EDGES
    vector<Edge> edges;

    while(getline(ifs2, line2)) {
        // Read the line
        int dummy;
        int id1, id2;
        float weight;

        stringstream ss(line2);
        ss >> dummy;
        ss >> id1;
        ss >> id2;
        ss >> weight;

        // Store the line's data into a Node class
        edges.push_back(Edge(id1, id2, weight));
    }

    // output bfs
    Graph g(nodes, edges);

    vector<int> bfsOutput = g.BFS(1, 6);

    for(auto i : bfsOutput) {
        cout << i << endl;
    }

    g.FloydWar();

    return 0;
}