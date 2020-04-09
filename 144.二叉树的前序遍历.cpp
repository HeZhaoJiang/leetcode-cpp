/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
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
private:
    vector<int> result;
public:
    void midOrder(TreeNode* root)
    {
        if(!root) return;
        result.push_back(root->val);
        midOrder(root->left);
        midOrder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        /* 递归 */
        midOrder(root);
        // TODO：非递归版本
        return result;
    }
};
// @lc code=end

