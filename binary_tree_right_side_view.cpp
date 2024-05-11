/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<int> dp;
  void dfs(TreeNode *node, int level) {
    if (node->left != NULL) {
      dfs(node->left, level + 1);
    }
    if (node->right != NULL) {
      dfs(node->right, level + 1);
    }
    dp[level] = node->val;
  }

  vector<int> rightSideView(TreeNode *root) {
    if (root == NULL) {
      return {};
    }
    dp.resize(101, -1);
    dfs(root, 0);
    vector<int> ans;
    for (auto val : dp) {
      if (val != -1) {
        ans.push_back(val);
      }
    }
    return ans;
  }
};
