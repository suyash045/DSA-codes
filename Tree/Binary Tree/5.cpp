//Q. Build tree from level order.
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
void buildBinaryTree(Node* &root){
    queue<Node*> q;
    cout<<"Enter data for root: ";
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        
        int leftdata;
        cout<<"Enter left node for "<<temp->data<<endl;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }

        int rightdata;
        cout<<"Enter right node for "<<temp->data<<endl;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }
    }
    return;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            if(!q.empty()){
                cout<<endl;
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
int main(){
    Node* root=NULL;
    buildBinaryTree(root);
    levelOrderTraversal(root);
    return 0;
}