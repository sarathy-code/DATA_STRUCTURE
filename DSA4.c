#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


void findMinMax(TreeNode* node, int* min, int* max);
TreeNode* createNode(int value);

int main() {
   
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(1);
    root->left->right = createNode(8);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    int min = INT_MAX;
    int max = INT_MIN;
    
    findMinMax(root, &min, &max);
  
    printf("Minimum value in the tree: %d\n", min);
    printf("Maximum value in the tree: %d\n", max);
  
    return 0;
}

void findMinMax(TreeNode* node, int* min, int* max) {
    if (node == NULL) {
        return;
    }
    
    
    if (node->value < *min) {
        *min = node->value;
    }
    if (node->value > *max) {
        *max = node->value;
    }
    
   
    findMinMax(node->left, min, max);
    findMinMax(node->right, min, max);
}

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}