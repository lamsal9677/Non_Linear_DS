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


void AVLTree::insertWithoutRebalance(Node* node) {

    //if the root node is null then insert the node into the root node
    if (root == nullptr) {
        root = node;
        return;
    }

    Node* currNode = root;

    while (currNode != nullptr) {

        if (node->key <= currNode->key) {

            if (currNode->left == nullptr) {

                //insert the node
                currNode->left = node;
                currNode->left->parent = currNode;
                currNode = currNode->left;
                return;
            }

            //if the currNode is not null
            else {
                currNode = currNode->left;
            }
        }

        else {

            if (currNode->right == nullptr) {
                //insert the node
                currNode->right = node;
                currNode->right->parent = currNode;
                currNode = currNode->right;
                return;

            }

            //if the currNode is not null
            else {
                currNode = currNode->right;
            }
        }
    }
}



void AVLTree::insert(Node* node) {

    //if the root node is null then insert the node into the root node
    if (root == nullptr) {
        root = node;
        return;
    }

    Node* currNode = root;

    while (currNode != nullptr) {

        if (node->key <= currNode->key) {

            if (currNode->left == nullptr) {

                //insert the node
                currNode->left = node;
                currNode->left->parent = currNode;
                currNode = currNode->left;

                Node* currUpNode = currNode->parent;
                while (currUpNode != nullptr) {
                    rebalance(currUpNode);
                    currUpNode = currUpNode->parent;
                }

                return;
            }

            //if the currNode is not null
            else {
                currNode = currNode->left;
            }
        }

        else {

            if (currNode->right == nullptr) {
                //insert the node
                currNode->right = node;
                currNode->right->parent = currNode;
                currNode = currNode->right;

                Node* currUpNode = currNode->parent;
                while (currUpNode != nullptr) {
                    rebalance(currUpNode);
                    currUpNode = currUpNode->parent;
                }
                return;

            }

            //if the currNode is not null
            else {
                currNode = currNode->right;
            }
        }
    }
}



//old
void AVLTree::updateHeight(Node* node) {

    int leftHeight = -1;
    if (node->left != nullptr) {
        leftHeight = node->left->height;
    }
    int rightHeight = -1;
    if (node->right != nullptr) {
        rightHeight = node->right->height;
    }
    node->height =  (leftHeight > rightHeight) ? leftHeight+1 : rightHeight+1;
}

//new
int AVLTree::updateHeight2(Node* node) {

    int leftHeight = -1;
    if (node->left != nullptr) {
        leftHeight = updateHeight2(node->left);
    }
    int rightHeight = -1;
    if (node->right != nullptr) {
        rightHeight = updateHeight2(node->right);
    }
    node->height = (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    return node->height;
}



int AVLTree::getBalanceFactor(Node* node) {
    int leftHeight = -1;
    if (node->left != nullptr) {
        leftHeight = node->left->height;
    }
    int rightHeight = -1;
    if (node->right != nullptr) {
        rightHeight = node->right->height;
    }
    return leftHeight - rightHeight;
}




void AVLTree::rebalance(Node* node) {
    
    updateHeight(node);
    
    if (getBalanceFactor(node) == -2) {
        if (getBalanceFactor(node->right) == 1) {
            rotateRight(node->right);
        }

        // A left rotation will now make the subtree balanced.
        return rotateLeft(node);
    }
    else if (getBalanceFactor(node) == 2) {
        if (getBalanceFactor(node->left) == -1) {
            rotateLeft(node->left);
        }

        // A right rotation will now make the subtree balanced.
        return rotateRight(node);
    }
    return;
}

void AVLTree::rotateLeft(Node* node) {

    Node* rightLeftChild = node->right->left;
    Node* backupNode = node;

    if (node->parent != nullptr) {
            //find left or right and replace node.right with it
        if (node == node->parent->left){
            node->parent->left = node->right;
        }
        if (node == node->parent->right){
            node->parent->right = node->right;
        }
    }
    else { // node is root
        root = node->right;
        root->parent = nullptr;
    }

    node->right->left = node;
    node->right = rightLeftChild;
    updateHeight(node);
    //rightLeftChild->parent = node;

}
void AVLTree::rotateRight(Node* node) {

    Node* leftRightChild = node->left->right;

    if (node->parent != nullptr) {
        if (node == node->parent->left) {
            node->parent->left = node->left;
        }
        if (node == node->parent->right) {
            node->parent->right = node->left;
        }
    
    }
    else { // node is root
        root = node->left;
        root->parent = nullptr;
    }
    node->left->right = node;
    node->left = leftRightChild;

    updateHeight(node);
}

int AVLTree::getTotalHeight() {
    updateHeight2(root);
    return root->height;
}
