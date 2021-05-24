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

  //Correccion Daniel Chicana
  //Error: invalids operands to binary expression
  //Se define cada iterador por separado para evitar el error del compilador
  //que los considera tipos no compatibles
  auto iter = bst.begin(), end = bst.end();
  //Se pone delante el operador de incremento (++)
  //No era considerado por el compilador la definicion de este operador en la clase Iterator 
  for(; iter != end; ++iter)
    cout << *iter << endl;
}
