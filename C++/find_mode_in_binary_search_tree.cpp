/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, map<int, int>& hashmap, int& mx) {
        if(!root) return;
        mx = max(mx, ++hashmap[root->val]);
        dfs(root->left, hashmap, mx);
        dfs(root->right, hashmap, mx);
    }
                    
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        int max_frequency = 0;
        map<int, int> hashmap;
        dfs(root, hashmap, max_frequency);
             
        for(auto e : hashmap)
            if(e.second == max_frequency) result.push_back(e.first);
        
        return result;
    }
};
