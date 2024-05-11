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
  map<TreeNode *, int> smallestNode;
  map<TreeNode *, int> biggestNode;
  map<TreeNode *, int> subtreeSum;
  map<TreeNode *, bool> isBst;
  int ans;

  void fillVals(TreeNode *node) {
    subtreeSum[node] = node->val;
    biggestNode[node] = node->val;
    smallestNode[node] = node->val;
    if (node->left != NULL) {
      fillVals(node->left);
      smallestNode[node] = min(smallestNode[node], smallestNode[node->left]);
      biggestNode[node] = max(biggestNode[node], biggestNode[node->left]);
      subtreeSum[node] += subtreeSum[node->left];
    }
    if (node->right != NULL) {
      fillVals(node->right);
      smallestNode[node] = min(smallestNode[node], smallestNode[node->right]);
      biggestNode[node] = max(biggestNode[node], biggestNode[node->right]);
      subtreeSum[node] += subtreeSum[node->right];
    }
  }

  void check(TreeNode *node) {
    if (node->left != NULL) {
      if (node->right != NULL) {
        check(node->left);
        check(node->right);
        if (smallestNode[node->right] > node->val &&
            biggestNode[node->left] < node->val) {
          isBst[node] = (isBst[node->left] && isBst[node->right]);
        } else {
          isBst[node] = false;
        }
      } else {
        check(node->left);
        if (biggestNode[node->left] < node->val) {
          isBst[node] = isBst[node->left];
        } else {
          isBst[node] = false;
        }
      }
    } else {
      if (node->right != NULL) {
        check(node->right);
        if (smallestNode[node->right] > node->val) {
          isBst[node] = isBst[node->right];
        } else {
          isBst[node] = false;
        }
      } else {
        isBst[node] = true;
      }
    }
  }

  void findAns(TreeNode *node) {
    if (isBst[node]) {
      ans = max(ans, subtreeSum[node]);
    }
    if (node->left != NULL) {
      findAns(node->left);
    }
    if (node->right != NULL) {
      findAns(node->right);
    }
  }

  int maxSumBST(TreeNode *root) {
    fillVals(root);
    check(root);
    ans = INT_MIN;
    findAns(root);
    return max(0, ans);
  }
};
