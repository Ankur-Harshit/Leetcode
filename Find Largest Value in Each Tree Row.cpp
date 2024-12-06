class Solution {
    public:
// for the dfs
    void dfs(TreeNode* root, int lvl, map<int,int> &mp){
        if(root== NULL) return;
        if (mp.find(lvl) == mp.end()) {
            mp[lvl] = root->val; // Initialize with the first encountered value
        }
        else
        mp[lvl] = max(mp[lvl],root->val);

        dfs(root->left,lvl+1,mp);
        dfs(root->right,lvl+1,mp);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        map<int,int> mp;
        dfs(root,0,mp);
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
// BFS approach //
vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int maxi = INT_MIN;
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                maxi = max(maxi,front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(maxi);
        }
        return ans;
};
// DFS approach have a very high T.C so better use the BFS approach. //
