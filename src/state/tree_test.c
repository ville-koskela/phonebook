#include "tree.h"
#include <CUnit/Basic.h>
#include <stdlib.h>

void test_createNode(void) {
    char *test_name = "Test";
    Node *node = createNode(test_name);

    CU_ASSERT_PTR_NOT_NULL(node);
    CU_ASSERT_STRING_EQUAL(node->name, test_name);
    CU_ASSERT_PTR_NULL(node->left);
    CU_ASSERT_PTR_NULL(node->right);

    free(node);
}

void test_insertNode(void) {
    Node *root = NULL;

    // Test adding a node to empty tree
    root = insertNode(root, "Test1");
    CU_ASSERT_PTR_NOT_NULL(root);
    CU_ASSERT_STRING_EQUAL(root->name, "Test1");
    CU_ASSERT_PTR_NULL(root->left);
    CU_ASSERT_PTR_NULL(root->right);

    // Test adding a node to the left
    root = insertNode(root, "Test0");
    CU_ASSERT_PTR_NOT_NULL(root->left);
    CU_ASSERT_STRING_EQUAL(root->left->name, "Test0");

    // Test adding a node to the right
    root = insertNode(root, "Test2");
    CU_ASSERT_PTR_NOT_NULL(root->right);
    CU_ASSERT_STRING_EQUAL(root->right->name, "Test2");

    // Clear dynamically allocated memory
    destroyTree(root);
}

void test_searchNode(void) {
    Node *root = NULL;

    // Add nodes to tree
    root = insertNode(root, "Test1");
    root = insertNode(root, "Test2");
    root = insertNode(root, "Test3");
    root = insertNode(root, "Test4");

    // Should find node
    CU_ASSERT_PTR_NOT_NULL(searchNode(root, "Test2"));

    // Should not find anything
    CU_ASSERT_PTR_NULL(searchNode(root, "Test10"));
}

void test_deleteNode() {
    // Create a root node
    Node *root = createNode("rootNode");

    // Add some nodes
    root = insertNode(root, "leftNode");
    root = insertNode(root, "rightNode");

    // Delete a node
    root = deleteNode(root, "leftNode");

    // Test that the node was deleted
    CU_ASSERT_PTR_NULL(searchNode(root, "leftNode"));

    // Delete another node
    root = deleteNode(root, "rightNode");

    // Test that the other node was deleted
    CU_ASSERT_PTR_NULL(searchNode(root, "rightNode"));
}
