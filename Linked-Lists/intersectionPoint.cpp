// Problem Link- https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#

/* Should return data of intersection point of two linked
   lists head1 and head2. 
   If there is no intersecting point, then return -1. */

// NOTE- It only contains logic part. Don't try to execute.

#include <bits/stdc++.h>

//Linked List Node
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Logic- Bring both headers at same level of starting point so that when we move both by one, they will reach the intersection at the same time. To bring both headers at same level, find difference(say 'diff') in length of both lists and move the header of longer list by 'diff'. Try visualizing it for better understanding.

int intersectPoint(Node *head1, Node *head2)
{
    Node *temp1, *temp2;
    temp1 = head1, temp2 = head2;
    int l1, l2;
    l1 = l2 = 0;

    // Calculating length of first list
    while (temp1 != NULL)
    {
        l1++;
        temp1 = temp1->next;
    }
    // Calculating length of second list
    while (temp2 != NULL)
    {
        l2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    int diff = abs(l1 - l2);

    // Moving the head of longer list by 'diff'
    while (diff--)
    {
        if (l1 > l2)
            temp1 = temp1->next;
        else
            temp2 = temp2->next;
    }

    // Now both temp1 and temp2 will be at same level. So, incrementing both by one until they intersect.
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // If they didn't, return -1
    if (temp1 == NULL)
    {
        return -1;
    }

    // Else, they did intersect. So, return data part of anyone of temp1 or temp2 as they both will be pointing to same node.
    else
    {
        return temp1->data;
    }
}