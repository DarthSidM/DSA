#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root = nullptr;

    Node* insert(Node* node, int value) {
        if (node == nullptr) return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void levelorder(Node* node) {
        if (!node) return;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

public:
    void buildTree() {
        cout << "Enter values to insert into BST (-1 to stop):\n";
        int val;
        while (true) {
            cin >> val;
            if (val == -1) break;
            root = insert(root, val);
        }
    }

    void traverse() {
        cout << "\nInorder Traversal: ";
        inorder(root);
        cout << "\nPreorder Traversal: ";
        preorder(root);
        cout << "\nPostorder Traversal: ";
        postorder(root);
        cout << "\nLevel Order Traversal: ";
        levelorder(root);
        cout << endl;
    }

    Node* getRoot() const {
        return root;
    }
};

int main() {
    BinarySearchTree bst;
    bst.buildTree();
    bst.traverse();
    return 0;
}
