#include <iostream>

struct Node {
    int data;
    Node* left_child;
    Node* right_child;

    Node(int value) {
        data = value;
        left_child = nullptr;
        right_child = nullptr;
    }
};

Node* find_node_at_position(int i, Node* root) {
    Node* current_node = root;
    int current_position = 1;

    while (current_position != i) {
        if (i % 2 == 1) {
            current_node = current_node->left_child;
        } else {
            current_node = current_node->right_child;
        }

        if (i % 2 == 1) {
            current_position = 2 * current_position;
        } else {
            current_position = 2 * current_position + 1;
        }
    }

    return current_node;
}