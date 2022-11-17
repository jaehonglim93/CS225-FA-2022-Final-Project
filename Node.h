#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

class Graph {
    public:
        
        
        

    private:

};

struct Node {
    Node(int id_, float x_, float y_) {
        id = id_;
        x = x_;
        y = y_;
    };

    float y; //longitude
    float x; //latitude
    int id;
};

struct Edge {
    Edge(Node source_, Node dest_, float weight_) {
        source = source_;
        dest = dest_;
        weight = weight_;
    };

    Node source;
    Node dest;
    float weight;
};
