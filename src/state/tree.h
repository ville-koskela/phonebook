#ifndef TREE_H
#define TREE_H

// Define our node
typedef struct Node {
    char name[50];
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Define insert prototype
Node *insertNode(Node *, char *);

// Define createNode prototype
Node *createNode(char *);

// Define deleteNode prototype
Node *deleteNode(Node *, char *);

// Define searchNode prototype
Node *searchNode(Node *, char *);

// Define leftRotate prototype
Node *leftRotate(Node *);

// Define rightRotate prototype
Node *rightRotate(Node *);

// Gets the height of the node
int height(Node *);

// Calculate balance factor for given node
int getBalanceFactor(Node *);

// Destroy tree and free all memory
void destroyTree(Node *);

#endif