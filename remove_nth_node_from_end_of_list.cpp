#include <stddef.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *p1 = new ListNode();
    ListNode *p2 = new ListNode();
    ListNode *p3 = new ListNode();

    p3->next = head;
    p3->val = -1;

    p2 = head;
    p1 = head;

    for (int i = 0; i < n; i++) {
      p2 = p2->next;
    }

    while (p2 != NULL) {
      p3 = p3->next;
      p1 = p1->next;
      p2 = p2->next;
    }

    if (p1 == head) { // first node
      return p1->next;
    } else if (n == 1) { // last node
      p3->next = NULL;
    } else {
      p3->next = p1->next;
    }
    return head;
  }
};
