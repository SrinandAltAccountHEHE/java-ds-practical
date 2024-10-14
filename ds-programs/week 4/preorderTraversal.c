#include <stdio.h> 
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value) {
    struct node *new_node = malloc(sizeof(struct node *));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void preorderTraversal(struct node *root) {
    if (!root)
        return;
    printf("%d ", root->value);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    struct node *root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);

    root->left->left = createNode(5);
    root->left->right = createNode(15);

    root->right->left = createNode(25);
    root->right->right = createNode(35);

    preorderTraversal(root);
}