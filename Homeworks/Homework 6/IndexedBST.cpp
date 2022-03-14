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
        //root->leftSize = 0; Just a refrence comment
        return;
    }

    Node* currNode = root;
    while (currNode != nullptr) {
        if (node->key <= currNode->key) {
            if (currNode->left == nullptr) {
                currNode->left = node;
                currNode->left->parent = currNode;
                currNode = currNode->left;
                //traverse up and see if it is left node and if it is then leftsize  += 1
                
                //from this point go up incrementing the left size
                while (currNode != root) {
                    if (currNode == currNode->parent->left) {
                        currNode->parent->leftSize += 1;
                    }
                    currNode = currNode->parent;
                }

                return;
            }
            else {
                currNode = currNode->left;
            }
        }
        else {
            if (currNode->right == nullptr) {
                currNode->right = node;
                currNode->right->parent = currNode;
                currNode = currNode->right;
               //traverse up and see if it is left node and if it is then leftsize  += 1
               
                while (currNode != root) {
                    if (currNode == currNode->parent->left) {
                        currNode->parent->leftSize += 1;
                    }
                    currNode = currNode->parent;
                }

                return;
            }
            else {
                currNode = currNode->right;
            }
        }
    }
 }

bool IndexedBST::remove(double key) {
;
    Node* test = root;

    if (root == nullptr) {
        return false;
    }

    if (key == root->key) {
        //..find the successor and replace with the successor
        return false;
    }

    Node* currNode = root;
    while (currNode != nullptr) {
        if (key == currNode->key){
            Node* traverseUp = currNode;
            //leaf node case   --- testing done
            if (currNode->left == nullptr && currNode->right == nullptr) {

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
                   

                    //logic to reduce the leftSize
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
            
            //case of a node where there is both left node and right node -- ytested
            else {
                
                Node* successor = currNode;
                successor = successor->right;
                while (successor->left != nullptr) {
                    
                    //if (successor->leftSize > 0) {
                    //    successor->leftSize -= 1;
                    //}
                     
                    
                    //reduce left size by one in every iteration
                    //we dont need to reduce by 1 since we are removing from right side left most element
                    successor = successor->left;
                }
                

                //logic to reduce the leftSize by traversing up
               
                
                /*
                while (traverseUp != root) {
                    if (traverseUp->parent->left = traverseUp) {
                        if (traverseUp->parent->leftSize > 0)
                            traverseUp->parent->leftSize -= 1;
                    }
                    traverseUp = traverseUp->parent;
                }
                */


                //at this point we have the successor
                double successorKey = successor->key;
                IndexedBST::remove(successorKey);
                currNode->key = successorKey;
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
