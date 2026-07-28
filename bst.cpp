#include<bits/stdc++.h>
using namespace std;

    struct Node{
        int data;
        Node* left;
        Node* right;

        Node(int value){
             data = value;
             left = nullptr;
             right = nullptr;
        }
    };

    Node* insert(Node* root, int value){
        if(root ==NULL){
            return new Node(value);
        }
        if(value < root->data){
            root->left = insert(root->left,value);
        }
        else{
            root->right = insert(root->right,value);
        }
        return root;
    }

    void inorder(Node* root){
        if(root == NULL)
            return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    int main(){
        Node* root = NULL;
        int n, value;
        cout<<"Enter number of nodes: ";
        cin>>n;

        cout<<"Enter values: ";

        for(int i = 0 ; i< n ; i++){
            cin>>value;
            root = insert(root,value);
        }
        cout<<"Inorder Traversal: ";
        inorder(root);
        return 0;
    }

