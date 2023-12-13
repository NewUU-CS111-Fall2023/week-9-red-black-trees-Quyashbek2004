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

    // ... (other methods and declarations)

    int calculateBlackHeight(Node* node) {
        int blackHeight = 0;
        while (node != nullptr) {
            if (node->color == BLACK) {
                blackHeight++;
            }
            node = node->left;
        }
        return blackHeight;
    }

    void calculateBlackHeightUtil(Node* node) {
        if (node == nullptr) return;
        int blackHeight = calculateBlackHeight(node);
        cout << node->data << " - " << blackHeight << endl;
        calculateBlackHeightUtil(node->left);
        calculateBlackHeightUtil(node->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    // ... (other methods like insert, printTree, etc.)

    void calculateBlackHeightForEachNode() {
        calculateBlackHeightUtil(root);
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

    tree.calculateBlackHeightForEachNode();

    return 0;
}
//O(n)
