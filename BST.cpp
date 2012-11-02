#include "BST.h"
#include <iostream>
#include <sstream>
#include <list>
#include <math.h>

using std::cout;
using std::endl;
using std::list;

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
    Node<T>* temp = *curr;

    // node is a leaf
    if ((*curr)->getLeftChild() == 0
        && (*curr)->getRightChild() == 0) {
      *curr = 0;
      delete temp;

    // node has one child
    } else if ((*curr)->getLeftChild() == 0
        || (*curr)->getRightChild() == 0) {
      if ((*curr)->getLeftChild() == 0) {
        *curr = (*curr)->getRightChild();
      } else {
        *curr = (*curr)->getLeftChild();
      }
      delete temp;

    // node has left and right child
    } else {

      // in-order successor
      Node<T>* IOS = (*curr)->getRightChild();
      while (IOS->getLeftChild() != 0) {
        IOS = IOS->getLeftChild();
      }
      IOS->setLeftChild(*((temp)->getLeftChild()));
      *curr = IOS;
      delete temp;

      /* in-order predecessor
      Node<T>* IOP = (*curr)->getLeftChild();
      while (IOP->getRightChild() != 0) {
        IOP = IOP->getRightChild();
      }
      IOP->setRightChild(*((temp)->getRightChild()));
      *curr = IOP;
      delete temp;
      */
    }
  }
}

template <typename T>
void BST<T>::print() {
  //traversalPrint(root);
  
  // get max depth of tree
  int maxDepth = getTreeDepth(root);
  // create print queue
  vector<string>* printQ = createPrintQ();
  int spaces;
  int numElements = 1;
  string currElement;
  string symbols;
  bool slash = true;
  
  for (int depth = maxDepth; depth > 0; --depth) {
    spaces = pow(2, depth);
    for (int i = 0; i < numElements; ++i) {
      currElement = (*printQ)[0];
      
      // spaces before each element
      for (int j = 0; j < spaces; ++j) {
        cout << " ";
      }
      
      // print elements
      if (currElement != "0") {
        cout << currElement;
      } else {
        cout << " ";
      }

      // print symbols
      for (int j = 0; j < spaces/3; ++j) {
        symbols += " ";
      }
      if (currElement != "0") {
        if (slash) {
          symbols += "/";
        } else {
          symbols += "\\";
        }
      }
      slash = !slash;
      
      // pop first element
      printQ->erase(printQ->begin());
    }
    cout << endl;
    cout << symbols << endl;
    numElements *= 2;
  }

  delete printQ;
}

template <typename T>
vector<string>* BST<T>::createPrintQ() {
  // queue of elements to print
  vector<string>* printQ = new vector<string>;
  // queue of nodes to traverse
  list< Node<T>* >* nodeQ = new list< Node<T>* >;

  Node<T>* curr = root;
  nodeQ->push_front(root);
  printQ->push_back(toString(root->getValue()));

  // while elements exist in tree, keep hunting
  while (!nodeQ->empty()) {
    curr = nodeQ->front();

    if (curr->getLeftChild() != 0) {
      printQ->push_back(toString(curr->getLeftChild()->getValue()));
      nodeQ->push_back(curr->getLeftChild());
    } else {
      // if no child exists, insert placeholder
      printQ->push_back("0");
    }

    if (curr->getRightChild() != 0) {
      printQ->push_back(toString(curr->getRightChild()->getValue()));
      nodeQ->push_back(curr->getRightChild());
    } else {
      // if no child exists, insert placeholder
      printQ->push_back("0");
    }

    nodeQ->pop_front();
  }
  delete nodeQ;

  // pass the created list
  return printQ;
}

template <typename T>
int BST<T>::getTreeDepth(Node<T>* n) {
  if (n == 0) {
    return 0;
  } else {
    int leftDepth = getTreeDepth(n->getLeftChild());
    int rightDepth = getTreeDepth(n->getRightChild());
    
    if (leftDepth > rightDepth) {
      return leftDepth + 1;
    } else {
      return rightDepth + 1;
    }
  }
}

template <typename T>
string BST<T>::toString(T v) {
  std::stringstream ss;
  ss << v;
  return ss.str();
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
