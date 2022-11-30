#include <queue>
#include <vector>
#include <iostream>

#include "Graph.h"

Graph::Graph(vector<Node> nodes_, vector<Edge> edges_){
    nodes = nodes_;
    edges = edges_;

    // For BFS traversal.
    //adjList = vector<vector<int>>(nodes.size(), 0);
    adjList = vector<vector<int>>(nodes.size());

    for(auto v : adjList) {
        v = vector<int>();
    }

    for(auto edge : edges) {
        adjList[edge.id1].push_back(edge.id2);
    }

    /* adjList print test
    for(auto i : adjList) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << "\n" << endl;
    }
    */
}

vector<int> Graph::getNeighbors(int id) {
    return adjList[id];
}

vector<int> Graph::BFS(int startingNode, int endingNode) {
    vector<int> output;
    
    vector<bool> visited(nodes.size(), false);
    queue<int> q;

    // enqueue starting node
    q.push(startingNode);
    //visited[startingNode] = true;
    
    while(!q.empty()) {
        // current node
        int curr = q.front();
        q.pop();

        // process current node
        visited[curr] = true; // visited curr node
        output.push_back(curr); //?

        if(curr == endingNode) {
            return output;
        }

        // add neighbors to queue
        for(auto neighbor : getNeighbors(curr)) {
            if(!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
        
    }

    return output;
}

void Graph::Dijkstra() {

}