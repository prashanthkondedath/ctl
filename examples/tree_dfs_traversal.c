#include <stdio.h>
#include <stdlib.h>
#include "../include/ctl.h"

// Define the structure for a binary tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Define a stack for TreeNode pointers
CTL_DEFINE_STACK_TYPE(TreeNode*, TreeNode)
CTL_DEFINE_STACK_FUNCTIONS(TreeNode*, TreeNode)

// Function to create a new tree node
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform DFS traversal
void dfs(TreeNode* root) {
    if (root == NULL) return;

    Stack_TreeNode* stack = Stack_TreeNode_create();
    Stack_TreeNode_push(stack, root);

    while (!Stack_TreeNode_is_empty(stack)) {
        TreeNode* node = Stack_TreeNode_pop(stack);
        printf("%d ", node->value);

        // Push right child first so that left child is processed first
        if (node->right != NULL) {
            Stack_TreeNode_push(stack, node->right);
        }
        if (node->left != NULL) {
            Stack_TreeNode_push(stack, node->left);
        }
    }

    Stack_TreeNode_destroy(stack);
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

    printf("DFS Traversal: ");
    dfs(root);
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
