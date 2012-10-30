#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  BST<int>* bst = new BST<int>();

  bst->insert(4);
  bst->insert(6);
  bst->insert(5);
  bst->insert(3);
  bst->insert(2);
  bst->insert(7);
  bst->insert(12);
  bst->insert(1);

  bst->print();
  cout << "-----" << endl;

  bst->remove(2);
  bst->remove(1);
  bst->remove(7);
  bst->remove(6);
  bst->remove(4);

  bst->print();
  cout << "-----" << endl;

  bst->insert(10);
  bst->insert(1);
  
  bst->print();
  cout << "-----" << endl;
}
