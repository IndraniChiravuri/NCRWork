#include <bits/stdc++.h>
#include <climits>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
class AVL {

public:
    struct Node *root;
    AVL() {
        root = NULL;
    }

    struct Node* createNode(int );

    struct Node* insertNode(struct Node*, int );
    struct Node* deleteNode(struct Node*, int );

    struct Node* rotateLeft(struct Node* );
    struct Node* rotateRight(struct Node* );
    struct Node* rotateLR(struct Node* );
    struct Node* rotateRL(struct Node* );

    int balancingFactor(struct Node* );
    struct Node* balance(struct Node* );

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

    ~AVL() {
        deleteTree(root);
    }
};

struct Node* AVL::createNode(int x) {
    struct Node *temp = new Node;
    temp -> data = x;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
};

struct Node* AVL::insertNode(struct Node* root, int ele) {
    if (root == NULL) {
        return createNode(ele);
    }
    if (root->data > ele) {
        root->left = insertNode(root->left, ele);
    } else {
        root->right = insertNode(root->right, ele);
    }
    return balance(root);
}

struct Node* AVL::rotateLeft(struct Node* root) {
    struct Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp; // NEW ROOT.
}

struct Node* AVL::rotateRight(struct Node* root) {
    struct Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp; // NEW ROOT.
}

struct Node* AVL::rotateLR(struct Node* root) {
   // struct Node* temp = root->left;
    root->left = rotateLeft(root->left);
    root = rotateRight(root);
    return root;
}

struct Node* AVL::rotateRL(struct Node* root) {
    root->right = rotateRight(root->right);
    root = rotateLeft(root);
    return root;
}

int AVL::balancingFactor(struct Node* root) {
    return height(root->left) - height(root->right);
}

struct Node* AVL::balance(struct Node* root) {
    if (root != NULL) {
        if (balancingFactor(root) > 1) {
            if (root->left != NULL && balancingFactor(root->left) == 1)
                root = rotateRight(root);
            else
                root = rotateLR(root);
        }
        if (balancingFactor(root) < -1) {
            if (root -> right != NULL && balancingFactor(root->right) == 1)
                root = rotateRL(root);
            else
                root = rotateLeft(root);
        }
    }
    return root;
}

struct Node* AVL::deleteNode(struct Node* root, int ele) {
    if (root != NULL) {
        if (ele > root->data) // SEARCHING THE ELEMENT
            root->right = deleteNode(root->right, ele);
        else if (ele < root->data)
            root->left = deleteNode(root->left, ele);
        else { // ELEMENT FOUND
            if (root->left == NULL) { //CONTAINS ONLY RIGHT SUBTREE
                struct Node* temp = root->right;
                delete root;
                temp = balance(temp);
                return temp;
            } else if (root->right == NULL) { //CONTAINS ONLY LEFT SUBTREE
                struct Node* temp = root->left;
                delete root;
                temp = balance(temp);
                return temp;
            } else {
                struct Node* minNode = findMin(root->right);
                root->data = minNode->data;
                root->right = deleteNode(root->right, minNode->data);
            }
        }
    }
    root = balance(root);
    return root;
}

void AVL::preorder(struct Node* root) {
    if(root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void AVL::inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void AVL::postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

struct Node* AVL::findMax(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct Node* AVL::findMin(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    while(root->left != NULL)
        root = root->left;
    return root;
}

int AVL::height(struct Node* root) {
    if (root == NULL) return -1;
    return max(height(root->left),height(root->right)) + 1;
}

int AVL::numOfLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return (numOfLeafNodes(root->left) + numOfLeafNodes(root->right));
}

int AVL::numOfNonLeafNodes(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return numOfNonLeafNodes(root->left) + numOfNonLeafNodes(root->right) + 1;
}

int main() {
    AVL tree;
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