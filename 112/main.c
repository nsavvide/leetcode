/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdbool.h>

bool try_path(struct TreeNode *node, int current_sum, const int targetSum) {
  if (node == NULL) {
    return false;
  }

  current_sum += node->val;
  if (current_sum == targetSum && node->left == NULL && node->right == NULL) {
    return true;
  }

  return try_path(node->left, current_sum, targetSum) ||
         try_path(node->right, current_sum, targetSum);
}

bool hasPathSum(struct TreeNode *root, int targetSum) {
  return try_path(root, 0, targetSum);
}
