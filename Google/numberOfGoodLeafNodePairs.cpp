/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    vector<int> getCount(TreeNode* root, int distance,int &ans){

        if(!root) return {0};

        if(!root->left&&!root->right) return {1};

        auto left = getCount(root->left,distance,ans);
        auto right = getCount(root->right,distance,ans);

        for(int x: left){
            for(int y: right){
                if(x>0&&y>0&&x+y<=distance){
                    ans++;
                }
            }
        }

        vector<int> res;

        for(int x: left){
            if(x>0&&x<distance){
                res.push_back(x+1);
            }
        }    

        
        for(int x: right){
            if(x>0&&x<distance){
                res.push_back(x+1);
            }
        }    

        return res;
    }


public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        getCount(root,distance,ans);
        return ans;
    }
};