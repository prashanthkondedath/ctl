#include <stdio.h>
#include <stdlib.h>
#include "../include/ctl.h"

// Define the structure for a binary tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Define a queue for TreeNode pointers
CTL_DEFINE_QUEUE_TYPE(TreeNode*, TreeNode)
CTL_DEFINE_QUEUE_FUNCTIONS(TreeNode*, TreeNode)

// Function to create a new tree node
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform BFS traversal
void bfs(TreeNode* root) {
    if (root == NULL) return;

    Queue_TreeNode* queue = Queue_TreeNode_create();
    Queue_TreeNode_enqueue(queue, root);

    while (!Queue_TreeNode_is_empty(queue)) {
        TreeNode* node = Queue_TreeNode_dequeue(queue);
        printf("%d ", node->value);

        if (node->left != NULL) {
            Queue_TreeNode_enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            Queue_TreeNode_enqueue(queue, node->right);
        }
    }

    Queue_TreeNode_destroy(queue);
}

int main() {
    // Create a sample binary tree
    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(7);

    printf("BFS Traversal: ");
    bfs(root);
    printf("\n");

    // Clean up
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
