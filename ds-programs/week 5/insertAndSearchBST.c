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

struct node* insert(struct node *root, int value) {
    if (!root)
        return createNode(value);

    if (value < root->value) 
        root->left = insert(root->left, value);
        
    else if (value > root->value)
        root->right = insert(root->right, value);

    return root;
}

struct node *search(struct node *root, int value) {
    if (!root)
        return NULL;

    if (root->value == value)
        return root;
        
    if (value < root->value)
        return search(root->left, value);

    if (value > root->value)
        return search(root->right, value);
}

struct node *inorderSuccessor(struct node *root) {
    struct node *curr = root->right;

    while (curr->left)
        curr = curr->left;

    return curr;
}

struct node *delete(struct node *root, int value) {
    if (!root)
        return NULL;

    if (value > root->value)
        root->right = delete(root->right, value);
    
    else if (value < root->value)
        root->left = delete(root->left, value);
    
    else { // root->value == value

        if (!root->left) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        else if (!root->right) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *succ = inorderSuccessor(root);
        root->value = succ->value;
        root->right = delete(root->right, succ->value);
    }
    return root;
}

int main() {
    struct node* root = createNode(20);

    root = insert(root, 10);
    root = insert(root, 30);

    root = insert(root, 5);
    root = insert(root, 15);

    root = insert(root, 25);
    root = insert(root, 35);

    struct node *searched_node = search(root, 25);
    if (searched_node)
        printf("Node found with value: %d\n", searched_node->value);
    else
        printf("Node not found\n");

    root = delete(root, 25);
    searched_node = search(root, 25);
    if (searched_node)
        printf("Node found with value: %d\n", searched_node->value);
    else
        printf("Node not found\n");
    

}