#include <cstddef>

struct ListNode {
  int val;
  ListNode *next;
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == NULL) {
      return list2;
    }
    if (list2 == NULL) {
      return list1;
    }

    ListNode *ptr;
    if (list1->val < list2->val) {
      ptr = list1;
      list1 = list1->next;
    } else {
      ptr = list2;
      list2 = list2->next;
    }
    ListNode *cur = ptr;

    while (list1 && list2) {
      int val1 = list1->val;
      int val2 = list2->val;
      if (val1 < val2) {
        cur->next = list1;
        list1 = list1->next;
      } else {
        cur->next = list2;
        list2 = list2->next;
      }
      cur = cur->next;
    }

    if (!list1) {
      cur->next = list2;
    } else {
      cur->next = list1;
    }
  }
};
