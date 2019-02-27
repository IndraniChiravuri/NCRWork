#include <bits/stdc++.h>
#include <climits>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
class BST {

public:
    struct Node *root;
    BST() {
        root = NULL;
    }

    struct Node* createNode(int );

    struct Node* insertNode(struct Node*, int );
    struct Node* deleteNode(struct Node*, int );

    void preorder(struct Node* );
    void inorder(struct Node* );
    void postorder(struct Node* );

    struct Node* findMax(struct Node* );
    struct Node* findMin(struct Node* );
    int height(struct Node* );

    int numOfLeafNodes(struct Node* );
    int numOfNonLeafNodes(struct Node* );

    void deleteTree(struct Node* root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    ~BST() {
        deleteTree(root);
    }
};

struct Node* BST::createNode(int x) {
    struct Node *temp = new Node;
    temp -> data = x;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
};

struct Node* BST::insertNode(struct Node* root, int ele) {
    if (root == NULL) {
        return createNode(ele);
    }
    if (root->data > ele) {
        root->left = insertNode(root->left, ele);
    } else {
        root->right = insertNode(root->right, ele);
    }
    return root;
}

struct Node* BST::deleteNode(struct Node* root, int ele) {
    if (root != NULL) {
        if (ele > root->data) // SEARCHING THE ELEMENT
            root->right = deleteNode(root->right, ele);
        else if (ele < root->data)
            root->left = deleteNode(root->left, ele);
        else { // ELEMENT FOUND
            if (root->left == NULL) { //CONTAINS ONLY RIGHT SUBTREE
                struct Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) { //CONTAINS ONLY LEFT SUBTREE
                struct Node* temp = root->left;
                delete root;
                return temp;
            } else {
                struct Node* minNode = findMin(root->right);
                root->data = minNode->data;
                root->right = deleteNode(root->right, minNode->data);
            }
        }
    }
    return root;
}

void BST::preorder(struct Node* root) {
    if(root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BST::inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void BST::postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

struct Node* BST::findMax(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct Node* BST::findMin(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    while(root->left != NULL)
        root = root->left;
    return root;
}

int BST::height(struct Node* root) {
    if (root == NULL) return -1;
    return max(height(root->left),height(root->right)) + 1;
}

int BST::numOfLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return (numOfLeafNodes(root->left) + numOfLeafNodes(root->right));
}

int BST::numOfNonLeafNodes(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return numOfNonLeafNodes(root->left) + numOfNonLeafNodes(root->right) + 1;
}

int main() {
    BST tree;
    while(1) {
        cout << "1. Insert 2. Delete 3. Find Max 4. Find Min 5. Traverse 6. Number of leaf Nodes 7. Number of non-leaf nodes 8. Height of tree 9. Exit" << endl;
        int choice;
        cin >> choice;
        int ele;
        struct Node* node;
        switch(choice) {
            case 1:
                cout << "Enter element to be inserted: ";
                cin >> ele;
                tree.root = tree.insertNode(tree.root, ele);
            break;
            case 2:
                cout << "Enter element to be deleted: ";
                cin >> ele;
                tree.root = tree.deleteNode(tree.root, ele);
                break;
            case 3:
                node = tree.findMax(tree.root);
                if (node == NULL)
                    cout << "Empty tree! :(" << endl;
                else
                    cout << "Maximum element: " << node->data << endl;
                break;
            case 4:
                node = tree.findMin(tree.root);
                if (node == NULL)
                    cout << "Empty tree! :(" << endl;
                else
                    cout << "Minimum element: " << node->data << endl;
                break;
            case 5:
                int op;
                cout << "1. Preorder traversal 2. Inorder traversal 3. Postorder traversal" << endl;
                cin >>op;
                if (op == 1)
                    tree.preorder(tree.root);
                else if (op == 2)
                    tree.inorder(tree.root);
                else
                    tree.postorder(tree.root);
                cout << endl;
                break;
            case 6:
                cout << "Leaf Nodes Count: " << tree.numOfLeafNodes(tree.root) << endl;
                break;
            case 7:
                cout << "Non Leaf Nodes Count: " << tree.numOfNonLeafNodes(tree.root) << endl;
                break;
            case 8:
                cout << "Height of Tree: " << tree.height(tree.root) << endl;
                break;
            default:
                cout << "--EXITED--" << endl;
                exit(0);
        }
    }
    return 0;
}