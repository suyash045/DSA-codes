#include<iostream>
#include<queue>
#include<stack>
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

    if(data==-1){
        return NULL;
    }

    root =new Node(data);
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildBinaryTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildBinaryTree(root->right);
    return root;
}

void reverseLevelOrder(Node* root){
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    s.push(root);
    q.push(NULL);
    s.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            if(!q.empty()){
                q.push(NULL);
                s.push(NULL);
            }
        }
        else{
            if(temp->left){
                q.push(temp->left);
                s.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
                s.push(temp->right);
            }
        }
    }

    while(!s.empty()){
        Node*temp=s.top();
        s.pop();
        if(temp==NULL){
            cout<<endl;
        }
        else{
            cout<<temp->data<<" ";
        }
    }

    return;
}
int main(){
    Node* root=NULL;
    root=buildBinaryTree(root);
    cout<<"Printing revrse level order traversal "<<endl;
    reverseLevelOrder(root);
    return 0;
}