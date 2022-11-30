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

    int id1;
    int id2;
    float weight;
};