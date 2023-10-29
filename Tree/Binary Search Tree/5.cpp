//deletion
#include<iostream>
#include<queue>
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
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
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
Node* deletion(Node* root,int x){
    if(root==NULL){
        return root;
    }
    if(root->data==x){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int min=minValue(root->right);
            root->data=min;
            root->right=deletion(root->right,min);
            return root;
        }
    }
    else if(root->data>x){
        root->left=deletion(root->left,x);
        return root;
    }
    else{
        root->right=deletion(root->right,x);
        return root;
    }
}

int main(){
    Node* root=NULL;
    takeInput(root);
    cout<<endl;
    levelOrderTraversal(root);
    int x;
    cout<<"Enter node to delete : ";
    cin>>x;
    Node* ans=deletion(root,x);
    levelOrderTraversal(ans);
return 0;
}