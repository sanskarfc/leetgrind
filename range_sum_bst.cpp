#include <cmath>
#include <stddef.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int ans;
  void recur(TreeNode *node, int low, int high) {
    if (node->val < low) { // value is too low
      if (node->right != NULL) {
        recur(node->right, low, high);
      }
    } else if (node->val >= low && node->val <= high) {
      ans += node->val;
      if (node->left != NULL) {
        recur(node->left, low, high);
      }
      if (node->right != NULL) {
        recur(node->right, low, high);
      }
    } else if (node->val > high) { // value is too high
      if (node->left != NULL) {
        recur(node->left, low, high);
      }
    }
  }

  int rangeSumBST(TreeNode *root, int low, int high) {
    ans = 0;
    if (root == NULL) {
      return 0;
    }
    recur(root, low, high);
    return ans;
  }
};
