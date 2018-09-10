#include<bits/stdc++.h>
using namespace std;

struct Binary_tree{

   int data;
   Binary_tree* left;
   Binary_tree* right;
};

queue<Binary_tree*> tree;

void Insert(Binary_tree*& root,int data){

    Binary_tree* newNode = new Binary_tree();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    if(root == NULL){
        root = newNode;
        tree.push(root);
        return;
    }

    while(!tree.empty()){

        if(tree.front() -> left && tree.front() -> right){
            tree.pop();
        }

        Binary_tree* temp = tree.front();

        if(temp -> left == NULL){
            temp -> left = newNode;
            tree.push(temp -> left);
            return;
        }
        else if(temp -> right == NULL){
            temp -> right = newNode;
            tree.push(temp -> right);
            return;
        }
    }


}

void Inorder(Binary_tree* root){

   if(root == NULL) return;
   else{
      Inorder(root -> left);
      printf("%d\n",root -> data);
      Inorder(root -> right);
   }
}

int main(){

 Binary_tree* root = NULL;
 Insert(root,56);
 Insert(root,78);
 Insert(root,89);
 Insert(root,84);
 Insert(root,66);
 Inorder(root);

 return 0;
}
