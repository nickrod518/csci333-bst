#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}

template <typename T>
bool BST<T>::find(T v) {
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    } else {
      return true;
    }
  }
  return false;
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
  Node<T>** curr = &root;

  // find the node
  while (*curr != 0 && (*curr)->getValue() != v) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }

  // the node doesn't exist, so exit
  if ((*curr)->getValue() != v) {
    return;

  // remove node...
  } else {

    // node is a leaf
    if ((*curr)->getLeftChild() == 0 &&
        (*curr)->getRightChild() == 0) {
      Node<T>* temp = *curr;
      *curr = 0;
      cout << "deleting leaf node" << endl;
      delete temp;

    // node has one right child
    } else if ((*curr)->getLeftChild() == 0) {
      Node<T>* temp = *curr;
      *curr = (*curr)->getRightChild();
      delete temp;
      cout << "deleting node with right child" << endl;

    // node has one left child
    } else if ((*curr)->getLeftChild() == 0) {
      Node<T>* temp = *curr;
      *curr = (*curr)->getLeftChild();
      delete temp;
      cout << "deleting node with left child" << endl;

    // node has left and right child
    // do in-order predecessor swap
    } else {
      Node<T>** temp = &((*curr)->getLeftChild());
      while ((*temp)->getRightChild() != 0) {
        temp = &((*temp)->getRightChild());
      }
      *curr = *temp;
      delete temp;
      cout << "deleting node with two children" << endl;
    }
  }
}

template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}

template class BST<int>;
template class BST<double>;
template class BST<string>;
