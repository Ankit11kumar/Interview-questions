// Problem link- https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1

/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \ 
   20       30 */


// NOTE- Don't try to run it as only its logic part is implemented and tested. 

#include <bits/stdc++.h>

// Structure of a single node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

int countLeaves(Node *root)
{
    if (root == NULL)
        return 0;

    // If u find a leaf node, return 1;
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Else, recursively iterate over all the nodes of tree and add the number of leaf nodes from left and right sub-trees.
    else
        return countLeaves(root->left) + countLeaves(root->right);
}