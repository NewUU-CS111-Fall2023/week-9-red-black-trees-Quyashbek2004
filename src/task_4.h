#include <iostream>
#include <stack>
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

    void fixInsertion(Node* newNode) {
        // Implementation of fixInsertion method to maintain Red-Black tree properties after insertion
        // ...
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != nullptr) {
            v->parent = u->parent;
        }
    }

    void deleteNode(Node* z) {
        // Implementation of deleteNode method to delete a node
        // ...
    }

    void deleteFix(Node* x) {
        // Implementation of deleteFix method to fix Red-Black tree after deletion
        // ...
    }

    void reverseTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;

        reverseTree(node->left);
        reverseTree(node->right);
    }

    void printTreeUtil(Node* root) const {
        if (root == nullptr) {
            return;
        }
        cout << "(" << root->data << (root->color == RED ? "(RED)" : "(BLACK)");
        printTreeUtil(root->left);
        cout << ")";
        printTreeUtil(root->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int data) {
        // Implementation of insert method to insert a node
        // ...
    }

    void printTree() const {
        printTreeUtil(root);
        cout << endl;
    }

    void deleteNodeWrapper(int data) {
        // Implementation of deleteNodeWrapper method to delete a node by value
        // ...
    }

    void reverse() {
        reverseTree(root);
    }

    // ... (Other methods)
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

    tree.reverse();
    tree.printTree();

    return 0;
}
//O(log(n)) 
