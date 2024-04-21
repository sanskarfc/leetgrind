#include <cstddef>

struct ListNode {
  int val;
  ListNode *next;
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == NULL) {
      return head;
    }
    if (head->next == NULL) {
      return head;
    }
    ListNode *cur = head->next;
    ListNode *prev = head;
    prev->next = NULL;
    while (true) {
      if (cur->next == NULL) {
        cur->next = prev;
        break;
      }
      ListNode *nextNode = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nextNode;
    }
    return cur;
  }
};
