#include "Graph.h"

Graph::Graph(vector<Node> nodes_, vector<Edge> edges_){
    nodes = nodes_;
    edges = edges_;

    // For BFS traversal.
    //adjMat = vector<vector<int>>(nodes.size(), 0);
    adjMat = vector<vector<int>>(nodes.size());

    for(auto v : adjMat) {
        v = vector<int>();
    }

    for(auto edge : edges) {
        adjMat[edge.id1].push_back(edge.id2);
        adjMat[edge.id2].push_back(edge.id1);
    }

    /* adjList print test
    for(auto i : adjList) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << "\n" << endl;
    }
    */
    // Initialize the distance array with the original graph
    N = adjMat.size();
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            //dist[i][j] = adjMat[i][j];
        }
    }
}

vector<int> Graph::getNeighbors(int id) {
    return adjMat[id];
}

float Graph::getDistance(int id1, int id2) {
    for(auto edge : edges) {
        if(edge.id1 == id1 && edge.id2 == id2)
            return edge.weight;
        else if(edge.id2 == id1 && edge.id1 == id2)
            return edge.weight;
    }
    return -1;
}

vector<int> Graph::BFS(int startingNode, int endingNode) {
    vector<int> output;
    
    vector<bool> visited(nodes.size(), false);
    vector<int> prev(nodes.size(), -1);
    queue<int> q;

    // enqueue starting node
    q.push(startingNode);
    visited[startingNode] = true;
    
    while(!q.empty()) {
        // current node
        int curr = q.front();

        q.pop();

        // process current node
        //visited[curr] = true; // visited curr node
        //output.push_back(curr); //?

        if(curr == endingNode) {
            break;
        }

        // add neighbors to queue
        for(auto neighbor : getNeighbors(curr)) {
            if(!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                prev[neighbor] = curr;
            }
        }
    }

    // Retrace Route from End to Start
    int curr = endingNode;
    while(curr != -1) {
        output.push_back(curr);
        curr = prev[curr];
    }
    reverse(output.begin(), output.end());
    return output;
}

/*
void Graph::Dijkstra() {
    vector<float> result;
    priority_queue<Node, vector<Node>> pq;
    
}
*/

void Graph::FloydWar(){

    // Loop through each intermediate node
    for (int k = 0; k < N; k++)
    {
        // Loop through each pair of nodes
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // Update the distance if the path through the intermediate node is shorter
                //if (dist[i][k] + dist[k][j] < dist[i][j])
                   // dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}


vector<int> Graph::AStar(int startingNode, int endingNode) {
    vector<int> prev(nodes.size(), -1);
    vector<float> cost(nodes.size(), -1); // total cost (distance)
    priority_queue<int, vector<int>, float> pq;

    prev[startingNode] = startingNode;
    cost[startingNode] = 0;
    pq.emplace(startingNode, (float)0);

    while(!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        
        if(curr == endingNode) {
            break;
        }

        for(auto neighbor : getNeighbors(curr)) {
            float new_cost = cost[curr] + getDistance(curr, neighbor);

            if((cost[neighbor] != -1) && (new_cost < cost[neighbor])) {
                cost[neighbor] = new_cost;
                prev[neighbor] = curr;
                
                float priority = new_cost + Heuristic(curr, neighbor);
                pq.emplace(neighbor, priority);
            }
        }
    }

    // Retrace Route from End to Start
    vector<int> output;
    int curr = endingNode;
    while(curr != -1) {
        output.push_back(curr);
        curr = prev[curr];
    }
    reverse(output.begin(), output.end());
    return output;
}

float Graph::Heuristic(int node_id, int end_id) {
    Node node = nodes[node_id];
    Node end = nodes[end_id];
    return abs(node.x - end.x) + abs(node.y - end.y);
}