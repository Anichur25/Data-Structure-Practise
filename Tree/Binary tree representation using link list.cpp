#include<bits/stdc++.h>
using namespace std;

struct node{

    int data;
    node* left;
    node* right;
    node* next;
};

node* head = NULL;
node* current_root = NULL;
node* Last_node = NULL;

node* create_node(int data){

   node* newNode = new node();
   newNode -> left = NULL;
   newNode -> right = NULL;
   newNode -> data = data;
   newNode -> next = NULL;

   return newNode;
}

void Insert(int data){

    node* newNode = create_node(data);

    if(head == NULL){
        head = newNode;
        current_root = head;
        Last_node = head;
    }
    else if(current_root -> left == NULL){
        current_root -> left = newNode;
        Last_node -> next = newNode;
        Last_node = newNode;
    }
    else if(current_root -> right == NULL){
        current_root -> right = newNode;
        Last_node -> next = newNode;
        Last_node = newNode;
    }
    else
    {
        current_root = current_root -> next;
        Insert(data);
    }
}

void Inorder(node* root){

    if(root == NULL) return;

    Inorder(root -> left);
    printf("%d\n",root -> data);
    Inorder(root -> right);
}

int main(){

    Insert(36);
    Insert(30);
    Insert(25);
    Insert(15);
    Insert(12);
    Insert(10);
    Inorder(head);

    return 0;
}
