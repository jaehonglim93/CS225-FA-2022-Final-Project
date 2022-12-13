#include "Graph.h"


Graph::Graph(vector<Node> nodes_, vector<Edge> edges_){
    nodes = nodes_;
    edges = edges_;

    // For BFS traversal.
    //adjMat = vector<vector<int>>(nodes.size(), 0);
    adjMat = vector<vector<int>>(nodes.size());

    for(vector<int>& v : adjMat) {
        v = vector<int>(nodes.size(), 0);
    }

    for(auto edge : edges) {
        adjMat[edge.id1][edge.id2] = edge.weight;
        adjMat[edge.id2][edge.id1] = edge.weight;
    }
}

vector<int> Graph::getNeighbors(int id) {
    vector<int> output(adjMat.size());

    for(unsigned i = 0; i < adjMat.size(); i++) {
        if(adjMat[id][i] != 0) {
            output.push_back(i);
        }
    }
    return output;
}

float Graph::getDistance(int id1, int id2) {
    return adjMat[id1][id2];
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


vector<vector<int>> Graph::FloydWarshall() {
    int n = adjMat.size();

    vector<vector<int>> dist;

    for(vector<int> v : adjMat) {
        dist.push_back(v);
    }

    // outer loop to iterate over intermediate vertices
    for (int k = 0; k < n; k++)
    {
        // inner loop to iterate over source vertices
        for (int i = 0; i < n; i++)
        {
            // inner loop to iterate over destination vertices
            for (int j = 0; j < n; j++)
            {
                // if the path from i to j exists
                // and the path from i to k and k to j
                // is shorter than the existing path from i to j
                // then update the distance from i to j
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != 0 && dist[i][k] != 0)){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }           
            }
        }
    }
    
    return dist;
}

 vector<int> Graph::AStar(int startingNode, int endingNode) {
    vector<int> prev(nodes.size(), -1);
    vector<float> cost(nodes.size(), -1); // total cost (distance)

    // struct PriorityNode : int id, float priority
    priority_queue<PriorityNode> pq;

    prev[startingNode] = startingNode;
    cost[startingNode] = 0;
    pq.emplace(PriorityNode(startingNode, 0));

    while(!pq.empty()) {
        int curr = pq.top().id;
        pq.pop();
        
        if(curr == endingNode) {
            break;
        }

        for(auto neighbor : getNeighbors(curr)) {
            if(getDistance(curr, neighbor) == 0) {
                continue;
            }
            float new_cost = cost[curr] + getDistance(curr, neighbor);
            if(cost[curr] == -1) {
                new_cost += 1;
            }
            if((cost[neighbor] != -1) && (new_cost < cost[neighbor])) {
                cost[neighbor] = new_cost;
                prev[neighbor] = curr;
                
                float priority = new_cost+ Heuristic(curr, neighbor);
                pq.emplace(PriorityNode(neighbor, priority));
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
    return getDistance(node_id, end_id);
    //abs(node.x - end.x) + abs(node.y - end.y);
}
