#include <iostream>
#include <map>

using namespace std;

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
  map<TreeNode *, int> dp1; // left side max path (including current)
  map<TreeNode *, int> dp2; // right side max path (including current)
  int maxm;

  void dfs(TreeNode *node) {
    dp1[node] = node->val;
    dp2[node] = node->val;
    if (node->left != NULL) {
      dfs(node->left);
      dp1[node] += max(0, max(dp1[node->left], dp2[node->left]));
    }
    if (node->right != NULL) {
      dfs(node->right);
      dp2[node] += max(0, max(dp1[node->right], dp2[node->right]));
    }
  }

  void findMax(TreeNode *node) {
    maxm = max({maxm, dp1[node], dp2[node], dp1[node] + dp2[node] - node->val});
    if (node->left != NULL) {
      findMax(node->left);
    }
    if (node->right != NULL) {
      findMax(node->right);
    }
  }

  int maxPathSum(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    maxm = INT_MIN;
    dfs(root);
    findMax(root);
    return maxm;
  }
};
