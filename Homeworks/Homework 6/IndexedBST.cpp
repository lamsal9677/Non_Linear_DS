#include "IndexedBST.h"
#include <iostream>

IndexedBST::~IndexedBST() {
    deleteTree(root);
}

void IndexedBST::deleteTree(Node* node) {
    // Recursively remove all nodes in the BST (used by the destructor). 
    // By doing this recursively, we start removing nodes from the bottom
    // of the tree (leaf nodes), which is most efficiently because it does
    // not require replacing any nodes.

    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

Node* IndexedBST::search(double desiredKey) {
    Node* cur = root;
    while (cur != nullptr) {
        // Return the node if the key matches
        if (cur->key == desiredKey) {
            return cur;
        }

        // Navigate to the left if the search key is 
        // less than the node's key.
        else if (desiredKey < cur->key) {
            cur = cur->left;
        }

        // Navigate to the right if the search key is 
        // greater than the node's key.
        else {
            cur = cur->right;
        }
    }

    // The key was not found in the tree.
    return nullptr;
}

Node* IndexedBST::at(int index) {
    Node* cur = root;
    while (cur != nullptr) {
        if (index == cur->leftSize)
            return cur;     // Found
        else if (index < cur->leftSize)
            cur = cur->left;    // index is in left subtree
        else {
            // index is in right subtree
            index = index - cur->leftSize - 1;
            cur = cur->right;
        }
    }

    return nullptr;
}

void IndexedBST::insert(Node* node) {
    
    //if the root node is null then insert the node into the root node
    if (root == nullptr) {
        root = node;
        return;
    }

    //assigning currNode = root node to prevent changing the root node
    Node* currNode = root;
    //loop until a null pointer is not found
    while (currNode != nullptr) {
        if (node->key <= currNode->key) {
            if (currNode->left == nullptr) {
                currNode->left = node;
                return;
            }
            else {
                currNode = currNode->left;
            }
        }
        else {
            if (currNode->right == nullptr) {
                currNode->right = node;
                return;
            }
            else {
                currNode = currNode->right;
            }
        }
    }
 }

bool IndexedBST::remove(double key) {
    return false;
}