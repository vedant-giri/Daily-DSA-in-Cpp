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
            if(val==-1) return nullptr ;
            Node* root=new Node(val);
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* curr=q.front();
                q.pop();

                int leftVal,rightVal;

                if(!(cin>>leftVal)) break;
                if(!(cin>>rightVal)) break;

                if(leftVal!=-1){
                    curr->left=new Node(leftVal);
                    q.push(curr->left);
                }
                if(rightVal!=-1){
                    curr->right=new Node(rightVal);
                    q.push(curr->right);
                }
            }
            return root;
        }
        vector<int> solve(Node* root,int targetVal){
            vector<int> ans;
            if(!root) return ans;

            path(root,ans,targetVal);

            return ans;
        }

        bool path(Node* root,vector<int>& ans,int targetVal){
            if(!root) return false;

            ans.push_back(root->data);

            if(root->data == targetVal) return true;

            if(path(root->left,ans,targetVal) || path(root->right,ans,targetVal)) return true;

            ans.pop_back();
            return false;
        }

};

int main(){
    Solution sol;
    Node* root=sol.buildTree();
    int targetVal=7;
    vector<int> path=sol.solve(root,targetVal);
    for(int it:path){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}