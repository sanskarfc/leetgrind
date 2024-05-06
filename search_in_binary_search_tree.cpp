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
  TreeNode *searchBST(TreeNode *node, int val) {
    if (node == NULL) {
      return NULL;
    }
    if (node->val < val) { // too low
      if (node->right != NULL) {
        return searchBST(node->right, val);
      }
    } else if (node->val == val) {
      return node;
    } else if (node->val > val) {
      if (node->left != NULL) {
        return searchBST(node->left, val);
      }
    }
    return NULL;
  }
};
