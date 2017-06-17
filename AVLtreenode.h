// AVL AVLtreenode.h
#ifndef AVLtreeNODE_H
#define AVLtreeNODE_H
#include <cstdlib>
#include <iostream>


using namespace std;

/* Class SBBSTNode */

struct sbbstNode
{
    int height, data;
    sbbstNode *left, *right;

    /* Constructor */
    sbbstNode(int n = 0);
};


#endif // AVLtreeNODE_H
