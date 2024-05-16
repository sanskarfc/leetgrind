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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == NULL) {
      TreeNode *newNode = new TreeNode(val);
      return newNode;
    }
    TreeNode *node = root;
    bool check = false;
    while (!check) {
      if (val < node->val) { // go to left side of this node
        if (node->left == NULL) {
          TreeNode *newNode = new TreeNode(val);
          node->left = newNode;
          check = true;
        } else {
          node = node->left;
        }
      } else { // go to right side of this node
        if (node->right == NULL) {
          TreeNode *newNode = new TreeNode(val);
          node->right = newNode;
          check = true;
        } else {
          node = node->right;
        }
      }
    }
    return root;
  }
};
