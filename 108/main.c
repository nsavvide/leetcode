#include <math.h>
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

#include <stdlib.h>

struct TreeNode *create_node(int val) {
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  if (node == NULL) {
    return NULL;
  }

  node->val = val;
  node->left = NULL;
  node->right = NULL;

  return node;
}

struct TreeNode *build_tree(int *nums, int left, int right) {
  if (left > right) {
    return NULL;
  }

  int mid = floor(left + right) / 2;
  struct TreeNode *node = create_node(nums[mid]);

  node->left = build_tree(nums, left, mid - 1);
  node->right = build_tree(nums, mid + 1, right);

  return node;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize) {

  if (numsSize == 0) {
    return NULL;
  }

  return build_tree(nums, 0, numsSize - 1);
}
