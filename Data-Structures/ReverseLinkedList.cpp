#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

//Reverse the LL by using {3 pointer approach}..
node* reverseLL(node* head)
{
    node* prev=NULL, *curr=head, *nextptr;
    // node* curr=head;
    // node* nextptr;

    while(curr!=NULL)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    return prev;
}

//Reverse the LL by using {recursion}..
node* reverseRecursively(node* head)
{
    if(head->next==NULL || head==NULL)  return head;

    node* newhead=reverseRecursively(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

//Inserting a node to the last of linked list...
void insertAtTail(node* &head, int val)
{
    node* n=new node(val);
    if(head==NULL)  
    {
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;

}

void printLL(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

signed main()
{
    node* head=NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    printLL(head);
    // node* newhead=reverseLL(head);
    node* newhead=reverseRecursively(head);
    printLL(newhead);
}
