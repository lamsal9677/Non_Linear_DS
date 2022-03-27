// Homework8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RedBlackTree.h"

int main()
{
    /* Test red-black tree inserts */
    RedBlackTree a;
/*
    RBTNode* aRoot = new RBTNode(22);
    a.insert(aRoot);
    a.insert(new RBTNode(11));
    a.insert(new RBTNode(33));
    a.insert(new RBTNode(55));
    a.insert(new RBTNode(44));
*/

    RBTNode* aRoot = new RBTNode(1);
    a.insert(aRoot);
    a.insert(new RBTNode(2));
    a.insert(new RBTNode(3));
    a.insert(new RBTNode(4));
    a.insert(new RBTNode(5));
    a.insert(new RBTNode(6));






    //a.insert(new RBTNode(7));
    //std::cout << aRoot->key << std::endl;
    //std::cout << aRoot->left->key << " " << aRoot->right->key << std::endl;
    //std::cout << aRoot->right->left->key << " " << aRoot->right->right->key
    //    << std::endl;



}
