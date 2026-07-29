#include<bits/stdc++.h>
using namespace std;

    struct Node{
        int data;
        Node* left;
        Node* right;

        Node(int value){
             data = value;
             left = NULL;
             right = NULL;
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

    bool search(Node* root, int key){
        if(root == NULL){
            return false;
        }
        if(root->data == key){
            return true;
        }
        if(key < root->data){
            return search(root->left,key);
        }
        else{
            return search(root->right,key);
        }
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
        int key;
        cout<<"Enter key:";
       
        return 0;
}

