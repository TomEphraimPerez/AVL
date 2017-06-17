// AVL sbbst.cpp
#include "AVLtree.h"


/*
 * Class AVLtree
 */

/* Constructor */
AVLtree::AVLtree()
{
    root = NULL;
}

/* Function to check if tree is empty */
bool AVLtree::isEmpty()
{
    return !root;
}

/* Make the tree logically empty */
void AVLtree::makeEmpty()
{
    root = NULL;
}

/* Function to insert data */
void AVLtree::insert(int data)
{
    root = insert(data, root);
}

/* Function to get height of node */
int AVLtree::height(sbbstNode *t)
{
    return !t ? -1 : t->height;
}

/* Function to max of left/right node */
int AVLtree::max(int lhs, int rhs)
{
    return lhs > rhs ? lhs : rhs;
}

/* Function to insert data recursively */
sbbstNode* AVLtree::insert(int x, sbbstNode *t)
{
    if (!t)
        t = new sbbstNode(x);
    else if (x < t->data)
    {
        t->left = insert(x, t->left);
        if (height(t->left) - height(t->right) == 2)
            if (x < t->left->data)
                t = rotateWithLeftChild(t);
            else
                t = doubleWithLeftChild(t);
    }
    else if (x > t->data)
    {
        t->right = insert(x, t->right);
        if (height(t->right) - height(t->left) == 2)
            if (x > t->right->data)
                t = rotateWithRightChild(t);
            else
                t = doubleWithRightChild(t);
    }
    t->height = max(height(t->left), height(t->right)) + 1;
    return t;
}


/* Rotate binary tree node with left child. For a straight line of "heaviness". */
sbbstNode* AVLtree::rotateWithLeftChild(sbbstNode* k2)
{
    sbbstNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    return k1;
}

/* Rotate binary tree node with right child. For a straight line of "heaviness". */
sbbstNode* AVLtree::rotateWithRightChild(sbbstNode *k1)
{
    sbbstNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    return k2;
}




/* For a zigzag line of "heaviness."
 * Double rotate binary tree node: first left child
 * with its right child; then node k3 with new left child
 */
sbbstNode* AVLtree::doubleWithLeftChild(sbbstNode *k3)
{
    k3->left = rotateWithRightChild(k3->left);
    return rotateWithLeftChild(k3);
}

/* For a zigzag line of "heaviness."
 * Double rotate binary tree node: first right child
 * with its left child; then node k1 with new right child
 */
sbbstNode* AVLtree::doubleWithRightChild(sbbstNode *k1)
{
    k1->right = rotateWithLeftChild(k1->right);
    return rotateWithRightChild(k1);
}




/* Functions to count number of nodes */
int AVLtree::countNodes()
{
    return countNodes(root);
}

int AVLtree::countNodes(sbbstNode *r)
{

 return r ? 1 + countNodes(r->right) + countNodes(r->left) : 0;

}

/* Functions to search for an element */
bool AVLtree::search(int val)
{
    return search(root, val);
}

bool AVLtree::search(sbbstNode *r, int val)
{
    bool found = false;
    while (r && !found)
    {
        int rval = r->data;
        if (val < rval)
            r = r->left;
        else if (val > rval)
            r = r->right;
        else
        {
            found = true;
            break;
        }
        found = search(r, val);
    }
    return found;
}

/* Function for inorder traversal */
void AVLtree::inorder()
{
    inorder(root);
}

void AVLtree::inorder(sbbstNode *r)
{
    if (r)
    {
        inorder(r->left);
        cout<<r->data<<"  ";
        inorder(r->right);
    }
}

/* Function for preorder traversal */
void AVLtree::preorder()
{
    preorder(root);
}
void AVLtree::preorder(sbbstNode *r)
{
    if (r)
    {
        cout<<r->data<<"  ";
        preorder(r->left);
        preorder(r->right);
    }
}

/* Function for postorder traversal */
void AVLtree::postorder()
{
    postorder(root);
}
void AVLtree::postorder(sbbstNode *r)
{
    if (r)
    {
        postorder(r->left);
        postorder(r->right);
        cout<<r->data<<"  ";
    }
}


