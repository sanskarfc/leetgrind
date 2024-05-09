class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void dfs(Node* node) {
        if(node->left != NULL && node->right != NULL) {
            node->left->next = node->right;
            if(node->next != NULL) {
                node->right->next = node->next->left;
            }
            dfs(node->left);
            dfs(node->right);
        }
    }

    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        dfs(root);
        return root;
    }
};
