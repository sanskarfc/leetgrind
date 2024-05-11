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
  // inorder traversal is sorted array
  vector<int> v1;
  void dfs(TreeNode *node) {
    if (node->left != NULL) {
      dfs(node->left);
    }
    v1.push_back(node->val);
    if (node->right != NULL) {
      dfs(node->right);
    }
  }

  int kthSmallest(TreeNode *root, int k) {
    v1.clear();
    dfs(root);
    return v1[k - 1];
  }
};
