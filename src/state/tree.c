#include <stdlib.h>
#include <string.h>

#include "../utils/helpers.h"
#include "tree.h"

Node *insertNode(Node *root, char *name) {
    if (root == NULL) {
        root = createNode(name);
    } else if (strcmp(name, root->name) < 0) {
        root->left = insertNode(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertNode(root->right, name);
    } else {
        return root;
    }

    // New node has been added, let's balance the tree

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalanceFactor(root);

    if (balance > 1 && strcmp(name, root->left->name) < 0) {
        return rightRotate(root);
    } else if (balance < -1 && strcmp(name, root->right->name) > 0) {
        return leftRotate(root);
    } else if (balance > 1 && strcmp(name, root->left->name) > 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    } else if (balance < -1 && strcmp(name, root->right->name) < 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *createNode(char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node *deleteNode(Node *root, char *name) {
    if (root == NULL) {
        return root;
    }

    // name is smaller then root->name, we need to delete
    // from left subtree
    if (strcmp(name, root->name) < 0) {
        root->left = deleteNode(root->left, name);
        // name is greater then root->name, we need to delete
        // from right subtree
    } else if (strcmp(name, root->name) > 0) {
        root->right = deleteNode(root->right, name);
        // name is not in left or right subtree, we need to delete
        // this node
    } else {
        if (root->left == NULL && root->right == NULL) {
            Node *tmp = root;
            root = NULL;
            free(tmp);
        } else if (root->left == NULL) {
            Node *tmp = root->right;
            root = tmp;
            free(tmp);
        } else if (root->right == NULL) {
            Node *tmp = root->left;
            root = tmp;
            free(tmp);
        } else {
            Node *tmp = root->right;
            while (tmp->left != NULL) {
                tmp = tmp->left;
            }
            // Any additional values added to the Node struct
            // later needs to be copied here also
            strcpy(root->name, tmp->name);
            root->right = deleteNode(root->right, tmp->name);
        }
    }

    if (root == NULL) {
        return root;
    }

    // Re-balance after delete
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    } else if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    } else if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    } else if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *searchNode(Node *root, char *name) {
    if (root == NULL) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return searchNode(root->left, name);
    }
    if (strcmp(name, root->name) > 0) {
        return searchNode(root->right, name);
    }
    return root;
}

int height(Node *node) { return node == NULL ? 0 : node->height; }

int getBalanceFactor(Node *root) {
    return root == NULL ? 0 : height(root->left) - height(root->right);
}

Node *leftRotate(Node *root) {
    Node *newRoot = root->right;
    Node *tmp = newRoot->left;

    newRoot->left = root;
    root->right = tmp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

Node *rightRotate(Node *root) {
    Node *newRoot = root->left;
    Node *tmp = newRoot->right;

    newRoot->right = root;
    root->left = tmp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

void destroyTree(Node *root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}