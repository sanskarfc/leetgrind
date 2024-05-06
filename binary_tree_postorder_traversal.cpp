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
  vector<int> ans;

  void preorder(TreeNode *node) {
    if (node->left != NULL) {
      preorder(node->left);
    }
    if (node->right != NULL) {
      preorder(node->right);
    }
    ans.push_back(node->val);
  }

  vector<int> postorderTraversal(TreeNode *root) {
    if (root == NULL) {
      return {};
    }
    preorder(root);
    return ans;
  }
};
