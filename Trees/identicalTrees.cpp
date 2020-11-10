// Problem link- https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

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

// Function to check if two trees are identical or not (Their root pointers are given by node1 and node2)
bool isIdentical(struct Node *node1, struct Node *node2)
{
    // If no node is present in both trees -> return true (as they are identical)
    if (node1 == NULL && node2 == NULL)
        return true;

    // Only if some node is present in both trees -> Check if data of both are same and then recursively check for their left and right side.
    if (node1 != NULL && node2 != NULL)
        return (node1->data == node2->data && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right));

    // Case when one pointer points to a node while other is NULL -> Hence, return false.
    return false;
}
