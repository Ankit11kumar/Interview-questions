// Problem link- https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1

// Note- Don't try to run the code. It only contains logic part.

#include <bits/stdc++.h>

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;


// This function deletes node from linked list. The function
// assumes that node exists in linked list and is not last node
// node: reference to the node which is to be deleted

// Logic- Copy the value of next node to the given node and repeat the process until u reach the end of linked list.

void deleteNode(Node *node)
{
    Node *prev = node;
    Node *next = node->next;
    while (next != NULL)
    {
        node->data = next->data;
        prev = node;
        node = node->next;
        next = node->next;
    }
    prev->next = NULL;
}
