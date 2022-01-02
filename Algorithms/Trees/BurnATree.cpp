/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void createTree(TreeNode* A, map<int, vector<int>> &tree){
    if(A == NULL) return;
    int cur = A->val;
    if(A->left){
        int left = A->left->val;
        tree[cur].push_back(left);
        tree[left].push_back(cur);
    }
    if(A->right){
        int right = A->right->val;
        tree[cur].push_back(right);
        tree[right].push_back(cur);
    }
    // call on left and right
    createTree(A->left, tree);
    createTree(A->right, tree);
    return;
}
int Solution::solve(TreeNode* A, int B) {
    map<int,vector<int>> tree;
    createTree(A, tree);
    // for(auto ele:tree){
    //     cout<<ele.first<<": ";
    //     for(auto v:ele.second){
    //         cout<<v<<" ";
    //     }
    //     cout<<endl;
    // }
    int n = tree.size();
    map<int, int> dist;
    dist[B] = 0;
    queue<int> q;
    q.push(B);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto ele:tree[cur]){
            if(dist.find(ele) == dist.end()){
                dist[ele] = dist[cur] + 1;
                q.push(ele);
            }
        }
    }
    int maxi = 0;
    for(auto ele:dist){
        maxi = max(maxi, ele.second);
    }
    return maxi;
}

int solve2(TreeNode* A,int B,int &curr)
{
    if(A==NULL) return 0;
    if(!A->left&&!A->right&&A->val==B) return 1000000000;
    int l=solve2(A->left,B,curr);
    int r=solve2(A->right,B,curr);
    int ans=1+max(l,r);
    curr=max(curr,max(l+r+1,ans));
    return ans;
}
int Solution::solve(TreeNode* A, int B) 
{
    int diameter=0;
    solve2
    (A,B,diameter);
    return diameter-1000000000;
}

// https://www.interviewbit.com/problems/burn-a-tree/