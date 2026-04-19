/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
struct ListNode *deleteDuplicates(struct ListNode *head) {
  if (head == NULL) {
    return NULL;
  }

  struct ListNode *curr = head;

  while (curr->next != NULL) {
    if (curr->val == curr->next->val) {
      struct ListNode *tmp = curr->next;
      curr->next = curr->next->next;
      free(tmp);
    } else {
      curr = curr->next;
    }
  }

  return head;
}
