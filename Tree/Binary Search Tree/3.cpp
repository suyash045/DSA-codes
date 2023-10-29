//min and max value
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insertNode(Node* &root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(root->data>data){
        root->left=insertNode(root->left,data);
    }
    else{
        root->right=insertNode(root->right,data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertNode(root,data);
        cin>>data;
    }
    return;
}
int minValue(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}
int maxValue(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}
int main(){
    Node* root=NULL;
    takeInput(root);
    cout<<endl;
    cout<<minValue(root);
    cout<<endl;
    cout<<maxValue(root);
    
return 0;
}