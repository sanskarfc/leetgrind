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
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL) {
      return NULL;
    }
    ListNode *ind = new ListNode();
    ind = head;
    int count = 0;
    while (ind != NULL) {
      count++;
      ind = ind->next;
    }
    k = k % count;
    if (k == 0) {
      return head;
    }

    ListNode *p1 = new ListNode();
    ListNode *p2 = new ListNode();
    ListNode *p3 = new ListNode();
    ListNode *p4 = new ListNode();
    p1 = head;
    p2 = head;
    p3->next = p1; // p3 just behind p1
    p4->next = p2; // p4 just behind p2
    for (int i = 0; i < k; i++) {
      p2 = p2->next;
      p4 = p4->next;
    }
    while (p2 != NULL) {
      p1 = p1->next;
      p2 = p2->next;
      p3 = p3->next;
      p4 = p4->next;
    }
    p4->next = head;
    p3->next = NULL;
    return p1;
  }
};
