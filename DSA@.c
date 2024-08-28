#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;            
    struct Node *left;  
    struct Node *right;  
} Node;


Node* create(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; 
}


void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = create(data);
        return;
    }

    Node* queue[100];
    int front = 0;
    int rear = 0;

    queue[rear++] = *root;


    while (front < rear) {
        Node* current = queue[front++];

        if (current->left == NULL) {
            current->left = create(data);
            return;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = create(data);
            return;
        } else {
            queue[rear++] = current->right;
        }
    }
}


void printn(Node* node) {
    if (node != NULL) {
        printn(node->left);
        printf("%d ", node->data);
        printn(node->right);
    }
}

int main() {
    Node* root = NULL; 

    
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 7);

    printf("In-order traversal of the binary tree:\n");
    printn(root);
    printf("\n");

    return 0;
}
