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
        vector<int> BFS(int startingNode, int endingNode);
        //void Dijkstra();
        void FloydWar();
        vector<int> AStar(int startingNode, int endingNode);
        float Heuristic(int id1, int id2);
        
    private:
        vector<Node> nodes;
        vector<Edge> edges;

        //int startingNode;
        vector<vector<int>> adjMat; // Used for BFS traversal.
        int N;
        //int dist[N][N];
};