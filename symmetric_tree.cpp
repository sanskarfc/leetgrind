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
  bool check(TreeNode *node1, TreeNode *node2) {
    cout << "node1: " << node1->val << endl;
    cout << "nodee2: " << node2->val << endl;
    cout << endl;
    if (node1->val != node2->val) {
      return false;
    }
    // give 0 if both are different
    // give 1 if both are same

    if ((node1->left == NULL) ^ (node2->right == NULL)) {
      return false;
    }
    if ((node1->right == NULL) ^ (node2->left == NULL)) {
      return false;
    }

    bool l = true;
    bool r = true;
    if (node1->left != NULL) {
      l = check(node1->left, node2->right);
    }
    if (node1->right != NULL) {
      r = check(node1->right, node2->left);
    }
    return (l && r);
  }

  bool isSymmetric(TreeNode *root) {
    if (root == NULL)
      return true;

    if ((root->left == NULL) ^ (root->right == NULL)) {
      return false;
    }

    if (root->left == NULL) {
      return true;
    }

    return check(root->left, root->right);
  }
};
