#include "RedBlackTree.h"
#include <algorithm>
#include <iostream>

RedBlackTree::~RedBlackTree() {
    deleteTree(root);
}

void RedBlackTree::deleteTree(RBTNode* node) {
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

void RedBlackTree::insert(RBTNode* node) {
    if (root == nullptr) {
        root = node;
        node->parent = nullptr;
        return;
    }

    RBTNode* cur = root;
    while (cur != nullptr) {
        if (node->key < cur->key) {
            if (cur->left == nullptr) {
                cur->left = node;
                node->parent = cur;
                cur = nullptr;
            }
            else
                cur = cur->left;
        }
        else {
            if (cur->right == nullptr) {
                cur->right = node;
                node->parent = cur;
                cur = nullptr;
            }
            else
                cur = cur->right;
        }
    }
    /*
    refine(node);
    
    while (node!=nullptr) {
        if (node->left != nullptr && (node->left->red && node->red)) {
            refine(node);
        }

        if (node->right != nullptr && (node->right->red && node->red)) {
            refine(node);
        }
        node = node->parent;
    }
    */
    if (node != nullptr) {
        if (node==root){
            refine(node);
        }
        while (node->parent != nullptr) {
            RBTNode* temp = node->parent;
            if (node->parent->red && node->red) {
                refine(node);
            }
            node = temp;
        }
    }

}

void RedBlackTree::refine(RBTNode* node) {

    //Case 0 Change root node to black
    if (node == root) {
        node->red = false;
        return;
    }

    RBTNode* nodeParent = node->parent;
    RBTNode* grandparent = nodeParent->parent;
    RBTNode* uncle = nullptr;

    //if grandparent!= null
    if (grandparent != nullptr) {
        if (grandparent->left == nodeParent)
            uncle = grandparent->right;
        if (grandparent->right == nodeParent)
            uncle = grandparent->left;

        //Case 1 When the uncle is red
        //Change color of Parent, Grandparent and Uncle
        if (uncle != nullptr && uncle->red == true) {
            grandparent->red = true;
            nodeParent->red = false;
            uncle->red = false;
            //return;//or continue
        }

        //case when uncle is black
        else if ((uncle != nullptr && uncle->red == false) || uncle == nullptr) {

            //Case 2 When the uncle is black and triangle
            if (node->parent->left == node && nodeParent->parent->right == nodeParent) {
                //rotate node's parent in the right direction
                rightRotation(nodeParent);
                std::cout << "Parent is rotated right";
            }

            else if (node->parent->right == node && nodeParent->parent->left == nodeParent) {
                //rotate node's parent in the left direction
                leftRotation(nodeParent);
                std::cout << "Parent is rotated left";
            }

            //Case 3 When the uncle is black and line
            else if (node->parent->left == node && nodeParent->parent->left == nodeParent) {
                //rotate node's grandparent in the right direction
                std::cout << "grandparent is rotated right";
                rightRotation(grandparent);
                nodeParent->red = !nodeParent->red;//recolor the parent
                grandparent->red = !grandparent->red;//recolor the grandparent
            }

            else if (node->parent->right == node && nodeParent->parent->right == nodeParent) {
                //rotate node's grandparent in the left direction
                std::cout << "grandparent is rotated left";
                leftRotation(grandparent);
                nodeParent->red = !nodeParent->red;//recolor the parent
                grandparent->red = !grandparent->red;//recolor the grandparent
            }
            
        }
    }

    //Case 0 Change root node to black
    root->red = false;
}

void RedBlackTree::leftRotation(RBTNode* node) {
    RBTNode* temp = node->right;
    node->right = temp->left;
    
    if (temp->left != nullptr){
        temp->left->parent = node;
    }
    temp->parent = node->parent;

    if (node->parent == nullptr){
        root = temp;
    }
    else if (node == node->parent->left) {
        node->parent->left = temp;
    }
    else{
        node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}
void RedBlackTree::rightRotation(RBTNode* node) {
    
    RBTNode* temp = node->left;
    node->left = temp->right;

    if (temp->right != nullptr) {
        temp->right->parent = node;
    }
    temp->parent = node->parent;//bring stuff to the root

    
    //connecting to tree above
    if (node->parent == nullptr) {
        root = temp;
    }
    else if (node == node->parent->left) {
        node->parent->left = temp;
    }
    else {
        node->parent->right = temp;
    }
    //connecting to tree above

    temp->right = node;
    node->parent = temp;
    
}  