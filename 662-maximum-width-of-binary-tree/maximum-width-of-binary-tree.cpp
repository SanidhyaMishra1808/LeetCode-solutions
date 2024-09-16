class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        queue<pair<long long,TreeNode*>>q;
        q.push({0,root});

        while(!q.empty()){
            long long n=q.size();
            int start,end;
            int min_index=q.front().first;
            for(int i=0;i<n;i++){
                pair<long long,TreeNode*> temp = q.front();
                q.pop();
                long long index = temp.first-min_index;
                TreeNode* curr = temp.second;
                if(i==0) start=index;
                if(i==n-1) end=index;
                if(curr->left)
                    q.push({2*index+1,curr->left});
                if(curr->right)
                    q.push({2*index+2,curr->right});
            }
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};