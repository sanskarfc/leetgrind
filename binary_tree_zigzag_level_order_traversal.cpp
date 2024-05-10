#include <vector>

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
  map<int, vector<int>> level;

  void dfs(TreeNode *node, int lev) {
    level[lev].push_back(node->val);
    if (node->left != NULL) {
      dfs(node->left, lev + 1);
    }
    if (node->right != NULL) {
      dfs(node->right, lev + 1);
    }
  }

  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == NULL)
      return {};
    dfs(root, 1);
    vector<vector<int>> ans;
    for (auto v : level) {
      vector<int> v1 = v.second;
      int lev = v.first;
      if (v.first % 2 == 1) {
        ans.push_back(v1);
      } else {
        reverse(v1.begin(), v1.end());
        ans.push_back(v1);
      }
    }
    return ans;
  }
};
