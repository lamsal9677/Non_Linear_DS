#include "AVLTree.h"
#include <algorithm>

AVLTree::~AVLTree() {
    deleteTree(root);
}

void AVLTree::deleteTree(Node* node) {
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

void Node::updateHeight() {
    int leftHeight = -1;
    if (left != nullptr)
        leftHeight = left->height;
    int rightHeight = -1;
    if (right != nullptr)
        rightHeight = right->height;
    height = std::max(leftHeight, rightHeight) + 1;
}

void Node::setChild(bool setLeftChild, Node* newChild) {
    if (setLeftChild)
        left = newChild;
    else
        right = newChild;
    if (newChild != nullptr)
        newChild->parent = this;

    updateHeight();
}

bool Node::replaceChild(Node* currentChild, Node* newChild) {
    if (left == currentChild)
        setChild(true, newChild);
    else if (right == currentChild)
        setChild(false, newChild);
    else
        return false;

    return true;
}

int Node::balanceFactor() {
    int leftHeight = -1;
    if (left != nullptr)
        leftHeight = left->height;
    int rightHeight = -1;
    if (right != nullptr)
        rightHeight = right->height;
    return leftHeight - rightHeight;
}

void AVLTree::insertBST(Node* node) {
    // Check if tree is empty
    if (root == nullptr) {
        root = node;
        node->parent = nullptr;
        return;
    }

    Node* cur = root;
    while (cur != nullptr) {
        if (node->key < cur->key) {
            // If no left child exists, add the new node
            // here; otherwise repeat from the left child.
            if (cur->left == nullptr) {
                cur->left = node;
                node->parent = cur;
                cur = nullptr;
            }
            else
                cur = cur->left;
        }
        else {
            // If no right child exists, add the new node
            // here; otherwise repeat from the right child.
            if (cur->right == nullptr) {
                cur->right = node;
                node->parent = cur;
                cur = nullptr;
            }
            else
                cur = cur->right;
        }
    }
}

void AVLTree::insert(Node* node) {
    insertBST(node);

    node = node->parent;
    while (node != nullptr) {
        rebalance(node);
        node = node->parent;
    }
}

void AVLTree::insertWithoutRebalance(Node* node) {
    insertBST(node);

    // Update heights for all ancestor nodes
    node = node->parent;
    while (node != nullptr) {
        node->updateHeight();
        node = node->parent;
    }
}

Node* AVLTree::rotateRight(Node* node) {
    Node* leftRightChild = node->left->right;
    if (node->parent != nullptr)
        node->parent->replaceChild(node, node->left);
    else {  // node is root
        root = node->left;
        root->parent = nullptr;
    }

    node->left->setChild(false, node);
    node->setChild(true, leftRightChild);
    return node->parent;
}

Node* AVLTree::rotateLeft(Node* node) {
    Node* rightLeftChild = node->right->left;
    if (node->parent != nullptr)
        node->parent->replaceChild(node, node->right);
    else {  // node is root
        root = node->right;
        root->parent = nullptr;
    }

    node->right->setChild(true, node);
    node->setChild(false, rightLeftChild);
    return node->parent;
}

Node* AVLTree::rebalance(Node* node) {
    node->updateHeight();
    if (node->balanceFactor() == -2) {
        if (node->right->balanceFactor() == 1)
            rotateRight(node->right);   // Double rotation case
        return rotateLeft(node);
    }
    else if (node->balanceFactor() == 2) {
        if (node->left->balanceFactor() == -1)
            rotateLeft(node->left);     // Double rotation case
        return rotateRight(node);
    }

    return node;    // No need for rotation
}

Node* AVLTree::get_root() {
    return root;
}