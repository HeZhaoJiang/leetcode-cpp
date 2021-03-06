/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
private:
    void exChange(TreeNode* x, TreeNode* y)
    {
        x->val = x->val ^ y->val;
        y->val = x->val ^ y->val;
        x->val = x->val ^ y->val;
    }
public:
    void recoverTree(TreeNode* root) {
        if (!root) return;
        TreeNode* cur = root;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pre = nullptr;
        while (cur)
        {
            if (cur->left) {
                /* 如果存在左子树，则需要设置索引 */
                TreeNode* index = cur->left;
                while (index->right && index->right != cur)
                    index = index->right;
                
                if (!index->right) {
                    /* 首次寻找到索引，设置索引，继续遍历左子树 */
                    index->right = cur;
                    cur = cur->left;
                }
                else {
                    /* 非首次寻找到索引，说明左子树遍历完成，根据索引去遍历右子树 */
                    if (pre && pre->val > cur->val) {
                        y = cur;
                        if(!x) x = pre;
                    }    
                    pre = cur;
                    cur = cur->right;
                    /* 恢复索引 */
                    index->right = nullptr;
                }
            }
            else {
                /* 没有左子树 遍历右子树 */
                if (pre && pre->val > cur->val) {
                    y = cur;
                    if(!x) x = pre;
                }
                pre = cur;
                cur = cur->right;
            }
        }
        exChange(x, y);
        return;
    }
};
// @lc code=end
int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.left = &c;
    c.right = &b;
    Solution solve;
    solve.recoverTree(&a);
    return 0;
}


