#ifndef __BST_H__
#define __BST_H__

#include "Node.h"
#include <string>
#include <list>

using std::string;
using std::list;

template <typename T>
class BST {
 private:
  Node<T>* root;
  list<T>* createPrintQ();
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
