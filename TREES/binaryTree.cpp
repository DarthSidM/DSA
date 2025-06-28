#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root = nullptr;

public:
    BinaryTree() = default;
    BinaryTree(Node* rootNode) : root(rootNode) {}

    Node* insert(Node* current) {
        cout << "Enter data: ";
        int data;
        cin >> data;

        if (data == -1) {
            return nullptr;
        }

        current = new Node(data);

        cout << "Enter data for the left node of " << data << endl;
        current->left = insert(current->left);

        cout << "Enter data for the right node of " << data << endl;
        current->right = insert(current->right);

        return current;
    }

    void buildTree() {
        root = insert(root);
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void levelorder(Node* root) {
        if (root == nullptr) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    void traverse() {
        cout << "\nPreorder Traversal: ";
        preorder(root);
        cout << "\nInorder Traversal: ";
        inorder(root);
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
    BinaryTree tree;
    tree.buildTree();
    tree.traverse();
    return 0;
}
