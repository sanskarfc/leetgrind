#include <map>
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
  map<int, vector<int>> levelList;

  void dfs(TreeNode *node, int level) {
    if (node->left != NULL) {
      dfs(node->left, level + 1);
    }
    levelList[level].push_back(node->val);
    if (node->right != NULL) {
      dfs(node->right, level + 1);
    }
  }

  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == NULL) {
      return {};
    }
    dfs(root, 1);
    for (auto v : levelList) {
      ans.push_back(v.second);
    }
    return ans;
  }
};
