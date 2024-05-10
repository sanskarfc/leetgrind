#include <stddef.h>
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
  TreeNode *makeBST(vector<int> &nums, int lo, int hi) {
    if (hi < lo) {
      return NULL;
    }
    if (hi == lo) {
      TreeNode *node = new TreeNode(nums[lo]);
      return node;
    }
    int mid = lo + (hi - lo) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = makeBST(nums, lo, mid - 1);
    node->right = makeBST(nums, mid + 1, hi);
    return node;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int n = nums.size();
    TreeNode *root = makeBST(nums, 0, n - 1);
    return root;
  }
};
