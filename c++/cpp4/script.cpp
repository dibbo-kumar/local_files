#include <iostream>
using namespace std;

// Node structure for BST
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// BST Class
class BST
{
private:
    Node *root;

    // Helper function to insert a node recursively
    Node *insertNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Helper function for inorder traversal
    void inorderHelper(Node *node)
    {
        if (node != nullptr)
        {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

    // Helper function for preorder traversal
    void preorderHelper(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }

    // Helper function for postorder traversal
    void postorderHelper(Node *node)
    {
        if (node != nullptr)
        {
            postorderHelper(node->left);
            postorderHelper(node->right);
            cout << node->data << " ";
        }
    }

    // Helper function to search for a value
    bool searchHelper(Node *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (node->data == value)
        {
            return true;
        }
        else if (value < node->data)
        {
            return searchHelper(node->left, value);
        }
        else
        {
            return searchHelper(node->right, value);
        }
    }

    // Helper function to find minimum value node
    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a node
    Node *deleteNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (value < node->data)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            // Node with only one child or no child
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Helper function to find height
    int heightHelper(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftHeight = heightHelper(node->left);
        int rightHeight = heightHelper(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

public:
    BST()
    {
        root = nullptr;
    }

    // Insert a value into the BST
    void insert(int value)
    {
        root = insertNode(root, value);
    }

    // Inorder traversal (Left -> Root -> Right)
    void inorder()
    {
        cout << "Inorder Traversal: ";
        inorderHelper(root);
        cout << endl;
    }

    // Preorder traversal (Root -> Left -> Right)
    void preorder()
    {
        cout << "Preorder Traversal: ";
        preorderHelper(root);
        cout << endl;
    }

    // Postorder traversal (Left -> Right -> Root)
    void postorder()
    {
        cout << "Postorder Traversal: ";
        postorderHelper(root);
        cout << endl;
    }

    // Search for a value
    bool search(int value)
    {
        return searchHelper(root, value);
    }

    // Delete a value from the BST
    void remove(int value)
    {
        root = deleteNode(root, value);
    }

    // Get height of the tree
    int height()
    {
        return heightHelper(root);
    }
};

int main()
{
    BST tree;

    // Insert elements
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Display traversals
    tree.inorder();
    tree.preorder();
    tree.postorder();

    // Search for elements
    cout << "\nSearching for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;

    // Display height
    cout << "\nHeight of tree: " << tree.height() << endl;

    // Delete a node
    cout << "\nDeleting 20..." << endl;
    tree.remove(20);
    tree.inorder();

    cout << "\nDeleting 30..." << endl;
    tree.remove(30);
    tree.inorder();

    cout << "\nDeleting 50..." << endl;
    tree.remove(50);
    tree.inorder();

    return 0;
}
