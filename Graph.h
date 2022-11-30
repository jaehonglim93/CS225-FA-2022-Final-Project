#include "Node.h"

#include <list>
#pragma once

using namespace std;

class Graph {
    public:
        Graph(vector<Node> nodes_, vector<Edge> edges_);
        vector<int> getNeighbors(int id);
        vector<int> BFS(int startingNode, int endingNode);
        void Dijkstra();
        

    private:
        vector<Node> nodes;
        vector<Edge> edges;

        //int startingNode;
        vector<vector<int>> adjList; // Used for BFS traversal.

};