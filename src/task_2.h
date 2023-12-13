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

    void leftRotate(Node* x) {
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

    void rightRotate(Node* y) {
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
        // Implementation of fixViolation method is unchanged from the previous code snippet
        // ...
    }

    void printTreeUtil(Node* root) const {
        // Implementation of printTreeUtil method is unchanged from the previous code snippet
        // ...
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int data) {
        // Implementation of insert method is unchanged from the previous code snippet
        // ...
    }

    void printTree() const {
        // Implementation of printTree method is unchanged from the previous code snippet
        // ...
    }

    void leftRotateWrapper(int data) {
        Node* x = search(data);
        if (x != nullptr) {
            leftRotate(x);
        }
    }

    void rightRotateWrapper(int data) {
        Node* x = search(data);
        if (x != nullptr) {
            rightRotate(x);
        }
    }

    Node* search(int data) {
        Node* current = root;
        while (current != nullptr) {
            if (data == current->data) {
                return current;
            } else if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return nullptr;
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
