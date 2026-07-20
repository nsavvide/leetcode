/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

#include <stdbool.h>
#include <stdlib.h>

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
  if (p == NULL && q == NULL) {
    return true;
  }

  if (p == NULL && q != NULL) {
    return false;
  }

  if (q == NULL && p != NULL) {
    return false;
  }

  bool left_path = isSameTree(p->left, q->left);

  if (p->val != q->val) {
    return false;
  }

  bool right_path = isSameTree(p->right, q->right);

  return left_path && right_path;
}
