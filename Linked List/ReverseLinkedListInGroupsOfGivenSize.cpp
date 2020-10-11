// LINK:https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1/?category[]=Linked%20List&problemStatus=solved&page=1&query=category[]Linked%20ListproblemStatussolvedpage1
// PROBLEM STATEMENT:Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.
// Input:
// LinkedList: 1->2->2->4->5->6->7->8
// K = 4
// Output: 4 2 2 1 8 7 6 5
// Expected Time Complexity : O(n)
// Expected Auxilliary Space : O(1)


#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* UTILITY FUNCTIONS */
/* Function to push a node */

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

     int t;
     cin>>t;
     
     while(t--)
     {
         struct node* head = NULL;
         struct node* temp = NULL;
         int n;
         cin >> n;
         
         for(int i = 0;i<n;i++){
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
         }
        
        int k;
        cin>>k;
        head = reverse(head, k);

        printList(head);
    
     }
     
     return(0);

}

// } Driver Code Ends


/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

node *reverse (struct node *head, int k)
{ 
    node* curr=head;
    node* prev=NULL;
    node* n=NULL;
    int ctr=k;
    while(ctr--&&curr){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    if(n!=NULL)
    head->next=reverse(n,k);
    return prev;
}
