#pragma once
#include <iostream>
using namespace std;
class AVL {
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

  int height(Node *node);
  void Add(int data);
  void recursiveAdd(Node *parent, int data);
  void checkBalance(Node *node);
  void rebalance(Node *node);
  Node *findMin(Node *node);
  void Delete(int data, Node *node);
  Node *rightRotate(Node *node);
  Node *leftRotate(Node *node);
  Node *rightLeftRotate(Node *node);
  Node *leftRightRotate(Node *node);
  void printTree(Node *root);
  void printPreorder(Node *node);
  Node *newNode(int data);
  bool isLeaf(Node *node);
};
AVL::Node *AVL::newNode(int data) {
  Node *node = new Node;
  node->data = data;
  node->parent = nullptr;
  node->leftChild = nullptr;
  node->rightChild = nullptr;
  return node;
}
AVL::Node *AVL::leftRotate(Node *node) {

  Node *temp = node->rightChild;
  node->rightChild = temp->leftChild;
  if (node->rightChild != nullptr) {
    node->rightChild->parent = node;
  }
  temp->leftChild = node;
  if (Root == node) {
    Root = temp;
    temp->parent = nullptr;
  } else {
    temp->parent = node->parent;
  }
  node->parent = temp;
  if (Root != temp) {
    if (temp->parent->rightChild == node) {
      temp->parent->rightChild = temp;
    } else if (temp->parent->leftChild == node) {
      temp->parent->leftChild = temp;
    }
  }

  return temp;
}
AVL::Node *AVL::rightRotate(Node *node) {

  Node *temp = node->leftChild;
  node->leftChild = temp->rightChild;
  if (node->leftChild != nullptr) {
    node->leftChild->parent = node;
  }
  temp->rightChild = node;
  if (Root == node) {
    Root = temp;
    temp->parent = nullptr;
  } else {
    temp->parent = node->parent;
  }
  node->parent = temp;
  if (Root != temp) {
    if (temp->parent->rightChild == node) {
      temp->parent->rightChild = temp;
    } else if (temp->parent->leftChild == node) {
      temp->parent->leftChild = temp;
    }
  }

  return temp;
}
AVL::Node *AVL::rightLeftRotate(Node *node) {
  node->rightChild = rightRotate(node->rightChild);
  return leftRotate(node);
}
AVL::Node *AVL::leftRightRotate(Node *node) {
  node->leftChild = leftRotate(node->leftChild);
  return rightRotate(node);
}

int AVL::height(Node *node) {
  if (node == nullptr) {
    return 0;
  }
  int leftHeight = height(node->leftChild);
  int rightHeight = height(node->rightChild);
  if (leftHeight > rightHeight) {
    return leftHeight + 1;
  }
  return rightHeight + 1;
}

void AVL::Add(int data) {

  if (Root == nullptr) {
    Root = newNode(data);
    NumNodes++;
    return;
  }
  recursiveAdd(Root, data);
}
void AVL::recursiveAdd(Node *root, int data) {
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
      checkBalance(node);
    } else {
      recursiveAdd(root->rightChild, data);
    }
  } else if (data < root->data) {
    if (root->leftChild == nullptr) {
      Node *node = newNode(data);
      root->leftChild = node;
      node->parent = root;
      NumNodes++;
      checkBalance(node);
    } else {
      recursiveAdd(root->leftChild, data);
    }
  }
}
void AVL::checkBalance(Node *node) {
  if (node == nullptr) {
    return;
  }
  if ((height(node->leftChild) - height(node->rightChild) > 1) ||
      (height(node->leftChild) - height(node->rightChild) < -1)) {

    rebalance(node);
  }
  if (node->parent == nullptr) {
    return;
  } else {

    checkBalance(node->parent);
  }
}
void AVL::rebalance(Node *node) {
  if (height(node->leftChild) - height(node->rightChild) > 1) {
    if (height(node->leftChild->leftChild) >
        height(node->leftChild->rightChild)) {
      node = rightRotate(node);
    } else {
      node = leftRightRotate(node);
    }
  } else {
    if (height(node->rightChild->rightChild) >
        height(node->rightChild->leftChild)) {
      node = leftRotate(node);
    } else {
      node = rightLeftRotate(node);
    }
  }
  if (node->parent == nullptr) {
    Root = node;
  }
}
AVL::Node *AVL::findMin(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }
  if (node->leftChild == nullptr) {
    return node;
  }
  return findMin(node->leftChild);
}
void AVL::Delete(int data, Node *node) {
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
      checkBalance(parent);
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
      checkBalance(temp);
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
      checkBalance(temp);
    } else if (node->leftChild != nullptr && node->rightChild != nullptr) {
      Node *min = findMin(node->rightChild);
      temp = min->rightChild;
      node->data = min->data;

      Delete(min->data, min);
      checkBalance(temp);
    }

  } else if (data > node->data) {
    Delete(data, node->rightChild);
  } else if (data < node->data) {
    Delete(data, node->leftChild);
  }
}
void AVL::printTree(Node *root) {
  if (root != nullptr) {
    printTree(root->leftChild);
    std::cout << root->data << std::endl;
    printTree(root->rightChild);
  }
}
void AVL::printPreorder(Node *node) {
  if (node == nullptr)
    return;

  cout << node->data << " ";
  printPreorder(node->leftChild);
  printPreorder(node->rightChild);
}
bool AVL::isLeaf(Node *node) {
  if (node->rightChild == nullptr && node->leftChild == nullptr) {
    return true;
  }
  return false;
}
