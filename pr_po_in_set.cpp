#include <iostream>
using namespace std;

class S {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->key) node->left = insertNode(node->left, value);
        else if (value > node->key) node->right = insertNode(node->right, value);
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->key << " ";
    }


    void preorder(Node* node) {
        if (!node) return;
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }

public:
    S() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }
};

int main() {
    S s;
    s.insert(5);
    s.insert(3);
    s.insert(2);
    s.insert(6);
    s.insert(7);
    s.insert(8);

    cout << "Preorder: ";
    s.preorder();   

    cout << "Inorder: ";
    s.inorder();     

    cout << "Postorder: ";
    s.postorder();    

    return 0;
}
