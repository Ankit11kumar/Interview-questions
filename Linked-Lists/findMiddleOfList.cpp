// Problem link - https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

// NOTE- It only contains logic part. Don't try to execute.

#include <bits/stdc++.h>
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Should return data of middle node.
int getMiddle(Node *head)
{
    Node *slow, *fast;
    slow = fast = head;

    // 'slow' pointer moves one step at a time while 'fast' moves two steps. So, when 'fast' will reach end of list
    //  'slow' will be at middle.

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}