class Solution {
public:
    unordered_map<TreeNode*, int>mp;
    int rob(TreeNode* root) {
        if(root == NULL) 
        return 0;
        if(mp.find(root) != mp.end()) 
        return mp[root];
        
        int total = 0;
        if(root->left) total += (rob(root->left->left) + rob(root->left->right));
        if(root->right) total += (rob(root->right->left) + rob(root->right->right));
        return mp[root] = max((root->val+total), (rob(root->left)+rob(root->right)));
    }
};
