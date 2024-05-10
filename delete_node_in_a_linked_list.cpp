/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  void deleteNode(ListNode *node) {
    if (node == NULL) {
      return;
    }
    ListNode *prev = new ListNode();
    prev->next = node;
    while (node->next != NULL) {
      prev->val = node->val;
      prev = prev->next;
      node = node->next;
    }
    prev->val = node->val;
    prev->next = NULL;
  }
};
