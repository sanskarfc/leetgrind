#include <stddef.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *node = headA;
    while (node->next != NULL) {
      node = node->next;
    }
    node->next = headB;
    // now find cycle starting from headA
    ListNode *slow = headA;
    ListNode *fast = headA;
    while (slow != fast) {
      fast = fast->next->next;
      slow = slow->next;
    }
    slow = headA;
    while (slow != fast) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};
