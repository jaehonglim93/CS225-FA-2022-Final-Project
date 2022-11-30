#pragma once
#include <Node.h>
using namespace std;

class KDTree {
    public:
        KDTree(vector<Node> nodes);
    
        void insert(Node node);

        // constants
        const static int Dim = 2;
    private:
        // Node with a left and right.
        struct KDTreeNode {
            Node node;
            KDTreeNode *left, *right;

            KDTreeNode(const Node &node_) : node(node), left(NULL), right(NULL) {}
        };

        // Internal Variables
        KDTreeNode *root;
        size_t size;
};