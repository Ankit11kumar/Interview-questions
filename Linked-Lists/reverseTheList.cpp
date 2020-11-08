// Problem link - https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

// NOTE- It only contains logic part. Don't try to execute.

#include <bits/stdc++.h>

// Structure of single Node
struct Node
{
    int data;
    struct Node *next;
};

// Will reverse list and return new head.
struct Node *reverseList(struct Node *head)
{
    struct Node *prev, *curr, *next;
    prev = next = NULL;
    curr = head;

    // Reversing the links order using three pointers. (Better to visualize it or dry run it)
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // In the end, make the last node as head ('prev' will pointing to last node when loop will end)
    head = prev;
    return head;
}
