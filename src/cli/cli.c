#include <stdio.h>
#include <string.h>

#include "../state/tree.h"
#include "cli.h"
#include "input.h"

void printPerson(Node *);
void printTree(Node *);

int startCli(Node *root) {
    const int NAME_LENGTH = 40;
    int exit = 0;

    while (!exit) {

        char input[5];
        printf("\n\nMenu\n\n");
        printf("1) Add person\n");
        printf("2) Delete person\n");
        printf("3) Search person\n");
        printf("4) Print phonebook\n");
        printf("5) exit\n");

        char prompt[] = "> ";
        char name[NAME_LENGTH];
        getInput(input, 3, prompt);
        printf("\n\n");

        switch (input[0]) {

        case '1':
            getInput(name, NAME_LENGTH, "Enter name: ");
            root = insertNode(root, name);
            break;
        case '2':
            getInput(name, NAME_LENGTH, "Enter name: ");
            root = deleteNode(root, name);
            break;
        case '3':
            getInput(name, NAME_LENGTH, "Enter name: ");
            printPerson(searchNode(root, name));
            break;
        case '4':
            printTree(root);
            break;
        case '5':
            exit = 1;
            break;
        }
    }

    printTree(root);

    destroyTree(root);
    printf("\n");

    return 0;
}

void printPerson(Node *node) {
    printf("\n\n");
    printf("Name: %s\n", node->name);
}

void printTree(Node *root) {
    if (root == NULL)
        return;

    printTree(root->left);
#ifdef DEBUG
    printf("height: %d\t", root->height);
#endif
    printf("%s\n", root->name);
    printTree(root->right);
}
