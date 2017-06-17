// AVL AVLtree.h
#ifndef AVLtree_H
#define AVLtree_H
#include <iostream>
#include <cstdlib>
#include "AVLtreenode.h"

using namespace std;

/*
 * Class AVLtree
 */

class AVLtree
{


private:
    sbbstNode *root;

    int countNodes(sbbstNode *r);                               // chk.
    void inorder(sbbstNode *r);                                 // chk.
    void preorder(sbbstNode *r);                                // chk.
    void postorder(sbbstNode *r);                               // chk.
    int height(sbbstNode *t);                                   // chk.
    sbbstNode *insert(int x, sbbstNode *t);                     // chk.
    sbbstNode *rotateWithLeftChild(sbbstNode* k2);              // chk.
    sbbstNode *rotateWithRightChild(sbbstNode *k1);             // chk.
    sbbstNode *doubleWithLeftChild(sbbstNode *k3);              // chk.
    sbbstNode *doubleWithRightChild(sbbstNode *k1);             // chk.
    bool search(sbbstNode *r, int val);                         // chk.


public:
    /* Constructor */
    AVLtree();


    //--------------------------------------
    /* Function for inorder traversal */
    void inorder();
//  void inorder(sbbstNode *r);                                   // Moved to pvt.

    /* Function for preorder traversal */
    void preorder();
//  void preorder(sbbstNode *r);                                  // Moved to pvt.

    /* Function for postorder traversal */
    void postorder();
//  void postorder(sbbstNode *r);                                 // Moved to pvt.
    //--------------------------------------



    /* Functions to count number of nodes */
    int countNodes();
//  int countNodes(sbbstNode *r); //O                               // Moved to pvt.

    /* Function to check if tree is empty */
    bool isEmpty();

    /* Make the tree logically empty */
    void makeEmpty();

    /* Function to insert data */
    void insert(int data);

    /* Function to get height of node */
//  int height(sbbstNode *t);                                       // Moved to pvt.

    /* Function to max of left/right node */
    int max(int lhs, int rhs);

    /* Function to insert data recursively */
//  sbbstNode *insert(int x, sbbstNode *t);                         // Moved to pvt.





    /* Rotate binary tree node with left child */
//  sbbstNode *rotateWithLeftChild(sbbstNode* k2);                  // Moved to pvt.

    /* Rotate binary tree node with right child */
//  sbbstNode *rotateWithRightChild(sbbstNode *k1);                 // Moved to pvt.



    /*
     * Double rotate binary tree node: first left child
     * with its right child; then node k3 with new left child
     */
//  sbbstNode *doubleWithLeftChild(sbbstNode *k3);                  // Moved to pvt.

    /*
     * Double rotate binary tree node: first right child
     * with its left child; then node k1 with new right child
     */
//  sbbstNode *doubleWithRightChild(sbbstNode *k1);                 // Moved to pvt.



    /* Functions to search for an element */
    bool search(int val);

//  bool search(sbbstNode *r, int val);                             // Moved to pvt.



};

#endif // AVLtree_H
