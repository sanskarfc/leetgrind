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
  map<int, vector<pair<int, int>>> dp;
  void dfs(TreeNode *node, int ind, int lev) {
    dp[ind].push_back(make_pair(lev, node->val));
    if (node->left != NULL) {
      dfs(node->left, ind - 1, lev + 1);
    }
    if (node->right != NULL) {
      dfs(node->right, ind + 1, lev + 1);
    }
  }

  vector<vector<int>> verticalTraversal(TreeNode *root) {
    if (root == NULL)
      return {};
    dfs(root, 0, 0);
    vector<vector<int>> ans;
    for (auto p : dp) {
      vector<pair<int, int>> v = p.second;
      sort(v.begin(), v.end());
      vector<int> v2;
      for (auto x : v) {
        v2.push_back(x.second);
      }
      ans.push_back(v2);
    }
    return ans;
  }
};
