/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode *root) {
  if (root == NULL) {
    return 0;
  }

  struct TreeNode **queue =
      (struct TreeNode **)malloc(100005 * sizeof(struct TreeNode *));
  int tail = 0;
  int head = 0;

  queue[tail++] = root;
  int depth = 1;

  while (head < tail) {
    int level = tail - head;
    for (size_t i = 0; i < level; i++) {
      struct TreeNode *current = queue[head++]; // pop

      if (current->left == NULL && current->right == NULL) {
        free(queue);
        return depth;
      }

      if (current->left != NULL) {
        queue[tail++] = current->left;
      }

      if (current->right != NULL) {
        queue[tail++] = current->right;
      }
    }

    depth++;
  }

  free(queue);
  return 0;
}
