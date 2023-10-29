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

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}

void inorder(Node* root){
    //LNR
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

void preorder(Node* root){
    //NLR
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void postorder(Node* root){
    //LRN
    if(root==NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}
int main(){
    Node* root=NULL;
    root=buildBinaryTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Printing level order traversal output"<<endl;
    levelOrderTraversal(root);

    cout<<"Printing inorder traversal output"<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Printing preorder traversal output"<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Printing postorder traversal output"<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}