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
        Node* buildTree(vector<int>& nodes){
            if(nodes.size()==0 || nodes[0]==-1) return nullptr;
            queue<Node*> q;
            Node* root=new Node(nodes[0]);
            q.push(root);
            int i=1;
            while(i<nodes.size() && !q.empty()){
                Node* curr=q.front();
                q.pop();

                if(i<nodes.size() && nodes[i]!=-1){
                    curr->left=new Node(nodes[i]);
                    q.push(curr->left);
                }
                i++;
                if(i<nodes.size() && nodes[i]!=-1){
                    curr->right=new Node(nodes[i]);
                    q.push(curr->right);
                }
                i++;
            }
            return root;

        }
        int maxPathSum(Node* root) {
            if(!root) return 0;
            int sum=INT_MIN;
            dfs(root,sum);
            return sum;
        }
        int dfs(Node* root,int& sum){
            if(!root) return 0;
            int ls=max(0,dfs(root->left,sum));
            int rs=max(0,dfs(root->right,sum));
            sum=max(sum,ls+rs+root->data);
            return root->data+max(ls,rs);
        }
};

int main(){
    Solution sol;
    int n;
    cin>>n;
    vector<int> nodes(n);
    for(int i=0;i<n;i++) cin>>nodes[i];
    Node* root=sol.buildTree(nodes);
    cout<<"Max Sum is "<<sol.maxPathSum(root)<<endl;
    return 0;
}