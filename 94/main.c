struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

#include <stdlib.h>

void traversal(struct TreeNode *curr, int *returnSize, int *node_list) {
  if (curr == NULL) {
    return;
  }

  // left ptr
  traversal(curr->left, returnSize, node_list);

  // root ptr
  node_list[*returnSize] = curr->val;
  (*returnSize)++;

  // right ptr
  traversal(curr->right, returnSize, node_list);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
  if (root == NULL) {
    *returnSize = 0;
    return NULL;
  }

  int *node_list = (int *)malloc(100 * sizeof(int)); // # nodes is [0, 100]
  *returnSize = 0;
  traversal(root, returnSize, node_list);

  return node_list;
}
