#pragma once
#include <iostream>
using namespace std;

class BST {
public:
  struct Node {
    int data;
    Node *leftChild;
    Node *rightChild;
    Node *parent;
    int duplicateData = 0;
  };

  Node *Root = nullptr;
  int NumNodes = 0;
  void Add(int data);
  void recursiveAdd(Node *parent, int data);
  void Delete(int data, Node *node);
  void printTree(Node *root);
  void printPreorder(Node *root);
  Node *newNode(int data);
  Node *findMin(Node *node);
  bool isLeaf(Node *node);
};
BST::Node *BST::newNode(int data) {
  Node *node = new Node;
  node->data = data;
  node->leftChild = nullptr;
  node->rightChild = nullptr;
  node->parent = nullptr;
  return node;
}

void BST::Add(int data) {
  if (Root == nullptr) {
    Root = newNode(data);
    NumNodes++;
    return;
  }
  recursiveAdd(Root, data);
}
void BST::recursiveAdd(Node *root, int data) {
  if (data == root->data) {
    root->duplicateData++;
    NumNodes++;
    return;
  }
  if (data > root->data) {
    if (root->rightChild == nullptr) {
      Node *node = newNode(data);
      root->rightChild = node;
      node->parent = root;
      NumNodes++;

    } else {
      recursiveAdd(root->rightChild, data);
    }
  } else if (data < root->data) {
    if (root->leftChild == nullptr) {
      Node *node = newNode(data);
      root->leftChild = node;
      node->parent = root;
      NumNodes++;

    } else {
      recursiveAdd(root->leftChild, data);
    }
  }
}
void BST::Delete(int data, Node *node) {
  Node *temp;
  Node *parent;
  if (Root == nullptr) {
    return;
  }
  if (NumNodes == 1) {
    temp = Root;
    Root = nullptr;
    delete temp;
    NumNodes--;
    return;
  }
  if (node->data == data) {
    if (node->duplicateData > 0) {
      NumNodes--;
      return;
    }
    parent = node->parent;
    temp = node;

    if (isLeaf(node) == true) {
      if (parent->rightChild == node) {
        parent->rightChild = nullptr;
      } else {
        parent->leftChild = nullptr;
      }
      delete node;
      NumNodes--;

    } else if (node->leftChild != nullptr && node->rightChild == nullptr) {
      temp = node->leftChild;
      if (parent != nullptr) {
        if (parent->rightChild == node) {
          parent->rightChild = temp;
        } else {
          parent->leftChild = temp;
        }
      } else if (parent == nullptr) {

        Root = temp;
      }
      temp->parent = node->parent;

      delete node;
      NumNodes--;

    } else if (isLeaf(node) == false && node->leftChild == nullptr) {
      temp = node->rightChild;
      if (parent != nullptr) {
        if (parent->rightChild == node) {
          parent->rightChild = temp;
        } else {
          parent->leftChild = temp;
        }
      } else if (parent == nullptr) {
        Root = temp;
      }
      temp->parent = node->parent;
      delete node;
      NumNodes--;

    } else if (node->leftChild != nullptr && node->rightChild != nullptr) {
      Node *min = findMin(node->rightChild);
      temp = min->rightChild;
      node->data = min->data;

      Delete(min->data, min);
    }

  } else if (data > node->data) {
    Delete(data, node->rightChild);
  } else if (data < node->data) {
    Delete(data, node->leftChild);
  }
}

void BST::printTree(Node *root) {
  if (root != nullptr) {
    printTree(root->leftChild);
    std::cout << root->data << std::endl;
    printTree(root->rightChild);
  }
}
void BST::printPreorder(Node *node) {
  if (node == nullptr)
    return;

  cout << node->data << " ";
  printPreorder(node->leftChild);
  printPreorder(node->rightChild);
}
BST::Node *BST::findMin(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }
  if (node->leftChild == nullptr) {
    return node;
  }
  return findMin(node->leftChild);
}
bool BST::isLeaf(Node *node) {
  if (node->rightChild == nullptr && node->leftChild == nullptr) {
    return true;
  }
  return false;
}
