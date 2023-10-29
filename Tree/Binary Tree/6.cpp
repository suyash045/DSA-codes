//Q. Count no. of leaf node.
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildBinaryTree(Node* root){
    cout<<"Enter data : ";
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildBinaryTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;    
    root->right=buildBinaryTree(root->right);
    return root;
}

void inorder(Node* root,int &count){
    //LNR
    if(root==NULL){
        return;
    }
    
    inorder(root->left,count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    inorder(root->right,count);
    return;
}

int noOfLeafNodes(Node* root){
    int count=0;
    inorder(root,count);
    return count;
}
int main(){
    Node* root=NULL;
    root=buildBinaryTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    int x;
    x=noOfLeafNodes(root);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<x;
    return 0;
}