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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right) {
      return head;
    }

    ListNode *ptrL = head;
    ListNode *ptrR = head;
    ListNode *ptrL_prev;
    ListNode *ptrR_next;

    for (int i = 0; i < left - 1; i++) {
      if (i == left - 2) {
        ptrL_prev = ptrL;
      }
      ptrL = ptrL->next;
    }
    for (int i = 0; i < right - 1; i++) {
      ptrR = ptrR->next;
    }
    ptrR_next = ptrR->next;

    ListNode *prev = ptrL;
    ListNode *cur = ptrL->next;

    while (cur != ptrR) {
      ListNode *nextNode = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nextNode;
    }

    ListNode *nextNode = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nextNode;

    if (left != 1) {
      ptrL_prev->next = ptrR;
    }
    ptrL->next = ptrR_next;

    // in case whole list is reversed, we need to return the new head

    if (left == 1) { // a new head
      return ptrR;
    } else {
      return head;
    }
  }
};
