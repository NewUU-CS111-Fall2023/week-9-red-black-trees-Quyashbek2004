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

    int countChildren(Node* node) {
        int count = 0;
        if (node->left != nullptr) count++;
        if (node->right != nullptr) count++;
        return count;
    }

    void countChildrenUtil(Node* node) {
        if (node == nullptr) return;
        int childrenCount = countChildren(node);
        cout << node->data << " - " << childrenCount << endl;
        countChildrenUtil(node->left);
        countChildrenUtil(node->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    // ... (other methods like insert, printTree, etc.)

    void countChildrenForEachNode() {
        countChildrenUtil(root);
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

    tree.countChildrenForEachNode();

    return 0;
}
//O(n)
