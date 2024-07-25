#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }

        return node;
    }

    Node* search(Node* node, int data) {
        if (node == nullptr || node->data == data) {
            return node;
        }

        if (data < node->data) {
            return search(node->left, data);
        } else {
            return search(node->right, data);
        }
    }

    Node* deleteNode(Node* root, int data) {
        if (root == nullptr) return root;

        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        } else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;

        while (current && current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    bool search(int data) {
        return search(root, data) != nullptr;
    }

    void deleteNode(int data) {
        root = deleteNode(root, data);
    }

    void inOrderTraversal() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal: ";
    bst.inOrderTraversal();

    std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 25: " << (bst.search(25) ? "Found" : "Not Found") << std::endl;

    bst.deleteNode(20);
    std::cout << "Inorder traversal after deleting 20: ";
    bst.inOrderTraversal();

    bst.deleteNode(30);
    std::cout << "Inorder traversal after deleting 30: ";
    bst.inOrderTraversal();

    bst.deleteNode(50);
    std::cout << "Inorder traversal after deleting 50: ";
    bst.inOrderTraversal();

    return 0;
}
