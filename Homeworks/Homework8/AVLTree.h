#ifndef AVLTREE_H
#define AVLTREE_H

// A node in the AVL tree that stores a double
class Node {
public:
    double key;
    int height = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;

    Node(double nodeKey) {
        key = nodeKey;
    }

    /* Added member functions below */
    void updateHeight();
    // Set a child to specified new child node. The parameter left should be set to
    // false to specify right child.
    void setChild(bool setLeftChild, Node* newChild);
    // Replace specified current child node with new child node. Return false if
    // neither left nor right child match specified current child node.
    bool replaceChild(Node* currentChild, Node* newChild);
    // Get balance factor
    int balanceFactor();
};

// An AVL tree that can insert with and without rebalancing
class AVLTree
{
public:
    AVLTree() {};
    ~AVLTree();

    // Insert a new element and rebalance the tree
    void insert(Node* node);
    // Insert a new element without rebalancing the tree
    void insertWithoutRebalance(Node* node);

    /* Added member functions below */
    // Rotate right at specified node and return subtree's new parent
    Node* rotateRight(Node* node);
    // Rotate left at specified node and return subtree's new parent
    Node* rotateLeft(Node* node);
    // Rebalance tree at specified node
    Node* rebalance(Node* node);
    // Return pointer to root
    Node* get_root();

private:
    Node* root = nullptr;
    void deleteTree(Node* node);

    /* Added member functions below */
    // Regular BST insert (no height update or rebalance)
    void insertBST(Node* node);
};

#endif // !AVLTREE_H