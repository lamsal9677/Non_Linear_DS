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
        root->leftSize = 0; //Not necessary but to remove any issues
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
        return;
    }

    Node* currNode = root;
    while (currNode != nullptr) {
        //if provided node's key is <= the current key in tree
        if (node->key <= currNode->key) {
            //if the current node is null, insert
            if (currNode->left == nullptr) {
                currNode->left = node;
                currNode->left->parent = currNode;
                currNode = currNode->left;
               
                //traverse up and see if it is left node and if it is then leftsize  += 1
                while (currNode != root) {
                    if (currNode == currNode->parent->left) 
                        currNode->parent->leftSize += 1;
                    currNode = currNode->parent;
                }

                return;
            }
            //if the current node is not null, go to left
            else {
                currNode = currNode->left;
            }
        }
        //if provided node's key is > the current key in tree
        else{
            //if null then insert
            if (currNode->right == nullptr) {
                currNode->right = node;
                currNode->right->parent = currNode;
                currNode = currNode->right;
               
                //traverse up and see if it is left node and if it is then leftsize  += 1
                while (currNode != root) {
                    if (currNode == currNode->parent->left) 
                        currNode->parent->leftSize += 1;
                    currNode = currNode->parent;
                }

                return;
            }
            //move to the right
            else {
                currNode = currNode->right;
            }
        }
    }
 }

bool IndexedBST::remove(double key) {

    //if there is no element in the tree
    if (root == nullptr) {
        return false;
    }
    
    //check whether the node to be removed is root node
    bool rootChanged = false;
    if (key == root->key) {
       rootChanged = true;
    }

    Node* currNode = root; //making a copy of root node to complete the computation in the tree
    while (currNode != nullptr) {
        //if a match is found between the provided key and key in the tree
        if (key == currNode->key){
            Node* traverseUp = currNode;
            //Node having no left or right node - leaf node --tested
            if (currNode->left == nullptr && currNode->right == nullptr) {
                
                //if current node is root node 
                //this means that the root node is the one where key is found and there is no left and right node to it
                //hence root = nullptr and tree can be destroyed
                if (rootChanged) {
                    root = nullptr;
                    return true;
                }

                if (currNode->parent->left == currNode) {
                    
                    //logic to reduce the leftSize
                    while (traverseUp != root) {
                        if (traverseUp->parent->left == traverseUp) {
                            if (traverseUp->parent->leftSize > 0)
                                traverseUp->parent->leftSize -= 1;
                        }
                        traverseUp = traverseUp->parent;
                    }

                    currNode->parent->left = nullptr;
                    currNode = nullptr;
                    return true;
                }

                else if (currNode->parent->right == currNode) {
                   
                    //logic to reduce the leftSize
                    while (traverseUp != root) {
                        if (traverseUp->parent->left == traverseUp) {
                            if (traverseUp->parent->leftSize > 0)
                                traverseUp->parent->leftSize -= 1;
                        }
                        traverseUp = traverseUp->parent;
                    }
                    
                    currNode->parent->right = nullptr;
                    currNode = nullptr;
                    return true;
                }
            }
            //node having only left node  -- tested
            else if (currNode->right == nullptr) {
                if (currNode->parent == nullptr) {
                    currNode = currNode->left;
                    currNode->left = nullptr;
                    currNode->right = nullptr;
                    currNode->leftSize = 0;
                    root = currNode;
                    return true;
                }
                if (currNode->parent->left == currNode) {
                    //logic to reduce the leftSize
                    while (traverseUp != root) {
                        if (traverseUp->parent->left == traverseUp) {
                            if (traverseUp->parent->leftSize > 0)
                                traverseUp->parent->leftSize -= 1;
                        }
                        traverseUp = traverseUp->parent;
                    }
                    
                    currNode->parent->left = currNode->left;
                    currNode = nullptr;
                    return true;
                }
                else if (currNode->parent->right == currNode) {
                    //reduce leftsize
                    while (traverseUp != root) {
                        if (traverseUp->parent->left == traverseUp) {
                            if (traverseUp->parent->leftSize > 0)
                                traverseUp->parent->leftSize -= 1;
                        }
                        traverseUp = traverseUp->parent;
                    }
                    
                    currNode->parent->right = currNode->left;
                    currNode = nullptr;
                    return true;
                }
            }
            //node having only right node   -- tested 
            else if (currNode->left == nullptr) {
                if (currNode->parent == nullptr) {
                    currNode = currNode->right;
                    currNode->left = nullptr;
                    currNode->right = nullptr;
                    currNode->leftSize = 0;
                    root = currNode;
                    return true;
                }
                if (currNode->parent->left == currNode) {
                    
                    //logic to reduce the leftSize
                    while (traverseUp != root) {
                        if (traverseUp->parent->left == traverseUp) {
                            if (traverseUp->parent->leftSize > 0)
                                traverseUp->parent->leftSize -= 1;
                        }
                        traverseUp = traverseUp->parent;
                    }
                    currNode->parent->left = currNode->right;
                    currNode = nullptr;
                    return true;
                }
                else if (currNode->parent->right == currNode) {
                    

                    //logic to reduce the leftSize
                    while (traverseUp != root) {
                        if (traverseUp->parent->left == traverseUp) {
                            if (traverseUp->parent->leftSize > 0)
                                traverseUp->parent->leftSize -= 1;
                        }
                        traverseUp = traverseUp->parent;
                    }

                    
                    currNode->parent->right = currNode->right;
                    currNode = nullptr;
                    return true;
                }
            }
            //node having left and right node -- tested
            else {
                Node* successor = currNode;
                successor = successor->right;
                while (successor->left != nullptr) {
                    successor = successor->left;
                }
                double successorKey = successor->key;
                IndexedBST::remove(successorKey);
                currNode->key = successorKey;
                if (rootChanged) {
                    root->key = successorKey;
                }
                return true;
            }
        }
        //move left if the key <= current key
        else if (key <= currNode->key){
            currNode = currNode->left;
        }
        //move right if the key > current key
        else {
            currNode = currNode->right;
        }
    }
    return false;
}