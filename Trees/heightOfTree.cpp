// Problem link- https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

// Below code is just implementation of logic part of question. Don't try to run it. HeHe !!

#include <bits/stdc++.h>

// Structure of a single node of tree.
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Function to calculate height of tree
int height(struct Node *node)
{
    // If no node is there -> height = 0
    if (node == NULL)
        return 0;
    int left = 0, right = 0;

    // Recursively calculating height of left side of tree.
    left = 1 + height(node->left);

    // Recursively calculating height of right side of tree.
    right = 1 + height(node->right);

    // Returning whichever is greater. Simple isn't it?
    if (left > right)
        return left;
    else
        return right;
}
