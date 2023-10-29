//searching
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
bool search(Node* root,int x){
    Node* temp=root;
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        else if(temp->data>x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    if(temp==NULL){
        return false;
    }
}
int main(){
    Node* root=NULL;
    takeInput(root);
    cout<<endl;
    int x;
    cout<<"Value to be searched : ";
    cin>>x;
    bool ans=search(root,x);
    cout<<ans;
return 0;
}