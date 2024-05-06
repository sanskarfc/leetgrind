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
  void dfs(TreeNode *node, int level) {
    if (ans < level) {
      ans = level;
    }
    if (node->left != NULL) {
      dfs(node->left, level + 1);
    }
    if (node->right != NULL) {
      dfs(node->right, level + 1);
    }
  }

  int maxDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    ans = 1;
    dfs(root, 1);
    return ans;
  }
};
