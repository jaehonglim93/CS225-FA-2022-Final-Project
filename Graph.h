#include "Node.h"

#include <list>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

#pragma once

using namespace std;

class Graph {
    public:
        Graph(vector<Node> nodes_, vector<Edge> edges_);
        vector<int> getNeighbors(int id);
        float getDistance(int id1, int id2);

        // BFS Traversal
        vector<int> BFS(int startingNode, int endingNode);
        
        // Floyd Warshall
        vector<vector<int>> FloydWarshall();

        // A Star
        vector<int> AStar(int startingNode, int endingNode);
        float Heuristic(int id1, int id2);
        
        // Public Variables
        vector<vector<int>> dist;
        vector<vector<int>> adjMat; // Used for BFS traversal.
    private:
        vector<Node> nodes;
        vector<Edge> edges;
        
};