/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *helper(ListNode *node, ListNode *prev) {
    ListNode *nextNode = node->next;
    if (nextNode == NULL) {
      node->next = prev;
      return node;
    }
    node->next = prev;
    return helper(nextNode, node);
  }

  ListNode *reverseList(ListNode *head) {
    if (head == NULL)
      return NULL;
    if (head->next == NULL)
      return head;
    ListNode *nextNode = head->next;
    head->next = NULL;
    return helper(nextNode, head);
  }
};
