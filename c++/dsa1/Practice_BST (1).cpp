/* 01.  Implement Basic BST Operations.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* current, int value) {
        if (current == NULL) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insert(current->left, value);
        } else if (value > current->data) {
            current->right = insert(current->right, value);
        }

        return current;
    }

    bool search(Node* current, int value) {
        if (current == NULL) return false;

        if (current->data == value) return true;

        if (value < current->data)
            return search(current->left, value);
        else
            return search(current->right, value);
    }
};

int main() {

    BST tree;

    int insertValues[] = {50, 30, 70, 20, 40, 60, 80};
    int insertSize = sizeof(insertValues) / sizeof(insertValues[0]);

    for (int i=0; i<insertSize; i++) {
        tree.root = tree.insert(tree.root, insertValues[i]);
    }

    int searchValues[] = {40, 90};
    int searchSize = sizeof(searchValues) / sizeof(searchValues[0]);

    cout << "Search Result:\n";

    for (int i=0; i<searchSize; i++) {

        if (tree.search(tree.root, searchValues[i])) {
            cout << searchValues[i] << ": Found" << endl;
        } else {
            cout << searchValues[i] << ": Not Found" << endl;
        }
    }
    return 0;
}
*/







/* 02. Traversals in a BST

#include<iostream>
using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int value){

       data = value;
       left = NULL;
       right = NULL;
    }
};


class BST{

 public:
    Node* root;

    BST(){
      root = NULL;
    }


  Node* insert(Node* current, int value){

       if(current == NULL){
         return new Node(value);
       }


       if(value < current->data){
          current->left = insert(current->left, value);
       }

       if(value > current->data){
          current->right = insert(current->right, value);
       }
       return current;
    }


  void inorder(Node* current){

       if (current == NULL) return;

        inorder(current->left);
        cout << current->data << " ";

        inorder(current->right);
    }


  void preorder(Node* current){

       if (current == NULL) return;

        cout << current->data << " ";

        preorder(current->left);
        preorder(current->right);
    }


  void postorder(Node* current){

       if (current == NULL) return;

         postorder(current->left);
         postorder(current->right);
         cout << current->data << " ";
    }



  bool search(Node* current, int value){

      if(current == NULL){
        return false;
      }
      if(current->data == value){
        return true;
      }

      if(value < current->data){
        return search(current->left, value);
      }else{
        return search(current->right, value);
      }
   }
};

int main(){

  BST tree;

  tree.root = tree.insert(tree.root, 50);
  tree.insert(tree.root, 30);
  tree.insert(tree.root, 70);
  tree.insert(tree.root, 20);
  tree.insert(tree.root, 40);
  tree.insert(tree.root, 60);
  tree.insert(tree.root, 80);

  cout << "Inorder Traversal: ";
  tree.inorder(tree.root);
  cout << endl;

  cout << "Preorder Traversal: ";
  tree.preorder(tree.root);
  cout << endl;

  cout << "Postorder Traversal: ";
  tree.postorder(tree.root);
  cout << endl;
}
*/








/* 03. Find the Minimum and Maximum in a BST

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
 public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* current, int value) {
        if (current == NULL) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insert(current->left, value);
        } else if (value > current->data) {
            current->right = insert(current->right, value);
        }

        return current;
    }

    int findMin(Node* current) {
        if (current == NULL) {
            cout << "Tree is empty.\n";
            return -1;
        }

        while (current->left != NULL) {
            current = current->left;
        }

        return current->data;
    }

    int findMax(Node* current) {
        if (current == NULL) {
            cout << "Tree is empty.\n";
            return -1;
        }

        while (current->right != NULL) {
            current = current->right;
        }

        return current->data;
    }
};

int main() {
    BST tree;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int size = sizeof(values) / sizeof(int);

    for (int i=0; i<size; i++) {
        tree.root = tree.insert(tree.root, values[i]);
    }

    int minValue = tree.findMin(tree.root);
    int maxValue = tree.findMax(tree.root);

    cout << "Minimum Value: " << minValue << endl;
    cout << "Maximum Value: " << maxValue << endl;

    return 0;
}
*/








/* 04. Implement Deletion in a BST

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {

 public:

    Node* root;

    BST() {
        root = NULL;
    }


    Node* insert(Node* current, int value) {
        if (current == NULL) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insert(current->left, value);
        } else if (value > current->data) {
            current->right = insert(current->right, value);
        }

        return current;
    }


    void inorder(Node* current) {
        if (current == NULL) return;

        inorder(current->left);
        cout << current->data << " ";
        inorder(current->right);
    }


    Node* findMin(Node* current) {
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }


   Node* deleteNode(Node* current, int key) {

      if (current == NULL) return NULL;

       if (key < current->data) {
        current->left = deleteNode(current->left, key);

       }else if (key > current->data) {
        current->right = deleteNode(current->right, key);

       }else{

        if (current->left == NULL) {
            Node* temp = current->right;
            delete current;
            return temp;
        }

        if (current->right == NULL) {
            Node* temp = current->left;
            delete current;
            return temp;
        }

        Node* temp = findMin(current->right);
        current->data = temp->data;
        current->right = deleteNode(current->right, temp->data);
    }
    return current;
}

};

int main() {
    BST tree;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int size = sizeof(values) / sizeof(int);

    for (int i=0; i<size; i++) {
        tree.root = tree.insert(tree.root, values[i]);
    }

    tree.root = tree.deleteNode(tree.root, 70);

    cout << "Inorder Traversal after Deletion: ";
    tree.inorder(tree.root);

    return 0;
}
*/





