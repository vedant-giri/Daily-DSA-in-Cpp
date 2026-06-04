#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

class Solution{
    public:
        Node* buildTree(){
            int val;
            cin>>val;
            if (val == -1) return nullptr;
            
            Node* root=new Node(val);
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* curr=q.front();
                q.pop();
                
                int leftVal,rightVal;

                if(!(cin>>leftVal)) break;
                if(!(cin>>rightVal)) break;

                if((leftVal!=-1)){
                    curr->left=new Node(leftVal);
                    q.push(curr->left);
                }
                if((rightVal!=-1)){
                    curr->right=new Node(rightVal);
                    q.push(curr->right);
                }

            }
            return root;
        }
        void Inorder(Node* root){
            if(!root) return;

            Inorder(root->left);
            cout<<root->data<<" ";
            Inorder(root->right);
        }
        void Preorder(Node* root){
            if(!root) return;

            cout<<root->data<<" ";
            Preorder(root->left);
            Preorder(root->right);
        }
        void Postorder(Node* root){
            if(!root) return;

            Postorder(root->left);
            Postorder(root->right);
            cout<<root->data<<" ";
        }
};

int main(){
    Solution sol;
    Node* root=sol.buildTree();
    cout<<"Inorder ";
    sol.Inorder(root);
    cout<<endl;
    cout<<"Preorder ";
    sol.Preorder(root);
    cout<<endl;
    cout<<"Inorder ";
    sol.Postorder(root);
    cout<<endl;
    return 0;
}