#include <stddef.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *start1 = l1;
    ListNode *start2 = l2;
    ListNode *prevL1 = new ListNode();
    ListNode *prevL2 = new ListNode();
    prevL1->next = l1;
    prevL2->next = l2;
    int pc = 0;
    while (l1 != NULL && l2 != NULL) {
      int value = (l1->val + l2->val + pc) % 10;
      int carry = (l1->val + l2->val + pc) / 10;
      l1->val = value;
      l1 = l1->next;
      l2 = l2->next;
      prevL1 = prevL1->next;
      prevL2 = prevL2->next;
      pc = carry;
    } // at this point, atleast one of list is complete

    if (l2 == NULL) {
      while (l1 != NULL) {
        int carry = (l1->val + pc) / 10;
        int value = (l1->val + pc) % 10;
        l1->val = value;
        pc = carry;
        l1 = l1->next;
        prevL1 = prevL1->next;
      }
      if (pc) {
        ListNode *node = new ListNode(pc);
        prevL1->next = node;
        node->next = NULL;
      }
      return start1;
    }

    prevL1->next = l2;
    if (l1 == NULL) { // if l1 is complete
      while (l2 != NULL) {
        int carry = (l2->val + pc) / 10;
        int value = (l2->val + pc) % 10;
        l2->val = value;
        pc = carry;
        prevL2 = prevL2->next;
        l2 = l2->next;
      }
      if (pc) {
        ListNode *node = new ListNode(pc);
        prevL2->next = node;
        node->next = NULL;
      }
      return start1;
    }
    return start1;
  }
};
