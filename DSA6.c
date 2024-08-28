#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

int getHeight(TreeNode* node);
TreeNode* createNode(int value);

int main() {
    
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
 
    int height = getHeight(root);
    
   
    printf("Height of the tree: %d\n", height);
  
    return 0;
}


int getHeight(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}