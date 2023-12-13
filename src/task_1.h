#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left, *right, *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nullptr) {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (y->parent == nullptr) {
            root = x;
        } else if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
        x->right = y;
        y->parent = x;
    }

    void fixViolation(Node* newNode) {
        Node* parent = nullptr;
        Node* grandparent = nullptr;

        while (newNode != root && newNode->color == RED && newNode->parent->color == RED) {
            parent = newNode->parent;
            grandparent = parent->parent;

            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;

                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    newNode = grandparent;
                } else {
                    if (newNode == parent->right) {
                        rotateLeft(parent);
                        newNode = parent;
                        parent = newNode->parent;
                    }
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    newNode = parent;
                }
            } else {
                Node* uncle = grandparent->left;

                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    newNode = grandparent;
                } else {
                    if (newNode == parent->left) {
                        rotateRight(parent);
                        newNode = parent;
                        parent = newNode->parent;
                    }
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    newNode = parent;
                }
            }
        }

        root->color = BLACK;
    }

    void printTreeUtil(Node* root) const {
        if (root == nullptr) {
            return;
        }
        cout << "(" << root->data << "(" << (root->color == RED ? "RED" : "BLACK") << ")";
        printTreeUtil(root->left);
        cout << "(";
        printTreeUtil(root->right);
        cout << "))";
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        Node* parent = nullptr;
        Node* current = root;

        while (current != nullptr) {
            parent = current;
            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        newNode->parent = parent;
        if (parent == nullptr) {
            root = newNode;
        } else if (data < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        fixViolation(newNode);
    }

    void printTree() const {
        printTreeUtil(root);
        cout << endl;
    }
};

int main() {
    int N, value;
    cin >> N;
    RedBlackTree tree;

    for (int i = 0; i < N; ++i) {
        cin >> value;
        tree.insert(value);
    }

    tree.printTree();

    return 0;
}
/*
 * Author:
 * Date:
 * Name:
 */
