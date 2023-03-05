#include <iostream>
using namespace std;


// Node data structure.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


// Insert leaf at specified position.
Node* create_leaf(int data) {
    Node* node = new Node(data);
    return node;
}


// Print the contents of the tree in postorder traversal.
void postorder_traverse(Node* node) {
    if (node->left != NULL) {
        postorder_traverse(node->left);
    } 

    if (node->right != NULL) {
        postorder_traverse(node->right);
    }

    cout << node->data << endl;
}


// Print the contents of the tree in inorder traversal.
void inorder_traverse(Node* node) {
    if (node->left != NULL) {
        inorder_traverse(node->left);
    } 

    cout << node->data << endl;

    if (node->right != NULL) {
        inorder_traverse(node->right);
    }
}



// Print the contents of the tree in preorder traversal.
void preorder_traverse(Node* node) {
    cout << node->data << endl;

    if (node->left != NULL) {
        preorder_traverse(node->left);
    } 

    if (node->right != NULL) {
        preorder_traverse(node->right);
    }
}


int main() {
    Node* root = new Node(1);
    root->left = create_leaf(5);
    root->right = create_leaf(7);
    root->left->left = create_leaf(2);
    root->left->right = create_leaf(4);
    root->right->left = create_leaf(9);
    root->left->left->left = create_leaf(3);

    // should print 1, 5, 2, 3, 4, 7, 9
    cout << endl << "Pre order traversal:" << endl;
    preorder_traverse(root);

    // should print 3, 2, 4, 5, 9, 7, 1
    cout << endl << "Post order traversal:" << endl;
    postorder_traverse(root);

    // should print 3, 2, 5, 4, 1, 9, 7
    cout << endl << "In order traversal:" << endl;
    inorder_traverse(root);

    return 0;
}