#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

struct Node {
    Node(int id_, float x_, float y_) {
        id = id_;
        x = x_;
        y = y_;
    };

    float x; //latitude
    float y; //longitude
    int id;
};

struct Edge {
    Edge(int source_, int dest_, float weight_) {
        id1 = source_;
        id2 = dest_;
        weight = weight_;
    };
    
    Edge(int source_, int dest_) {
        id1 = source_;
        id2 = dest_;
        weight = 1;
    }; 

    int id1;
    int id2;
    float weight;
};

// Special Node structure for a Priority Queue (used by A Star)
struct PriorityNode {
    PriorityNode(int _id, float _weight) {
        id = _id;
        priority = _weight;
    };

    bool operator< (const PriorityNode& other) const {
        return priority < other.priority;
    };

    bool operator> (const PriorityNode& other) const {
        return priority > other.priority;
    };

    int id;
    float priority;
};