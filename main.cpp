#include <iostream>
#include "bst.h"
#include "type.h"

using namespace std;

int main()
{
  CBinaryTree<T1> bst;
  
  bst.insert(50);
  bst.insert(30);
  bst.insert(70);
  bst.insert(90);
  bst.insert(10);
  bst.insert(40);
  bst.insert(100);

  cout << "Postorder ..." << endl;
  bst.Postorder();
  cout << "Preorder ..." << endl;
  bst.Preorder();
  cout << "Inorder ..." << endl;
  bst.Inorder();

  cout << "Ascendente iterador ..." << endl;
  CBinaryTree<T1>::Iterator iter = bst.begin();
  for(; !iter.empty(); ++iter)
    cout << *iter << endl;
}