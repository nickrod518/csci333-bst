#ifndef __BST_H__
#define __BST_H__

#include "Node.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

template <typename T>
class BST {
 private:
  Node<T>* root;
  vector<string>* createPrintQ();
  int getTreeDepth(Node<T>* n);
  string toString(T v);
  void traversalPrint(Node<T>* root);

 public:
  BST<T>();
  ~BST<T>();

  bool find(T v);
  void remove(T v);
  void insert(T v);
  void print();
};


#endif
