/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>

bool hasCycle(struct ListNode *head) {
  if (head == NULL) {
    return false;
  }

  struct ListNode *fast = head;
  struct ListNode *slow = head;
  while (slow != NULL && fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return true;
    }
  }

  return false;
}
