#include <iostream>
#include "bst.h"
#include "type.h"
/* para la tarea hacer el pull request en GitHub y enviar el enlace
a su proyecto en Replit para poder probarlo*/
using namespace std;

//Trabajo realizado por Maizo Diego y De lama Kevin
int main()
{
  CBinaryTree<T1> bst;
  
  bst.insert(50);//root
  bst.insert(30);//nivel 1
  bst.insert(70);//nivel 1
  bst.insert(90);//nivel 2
  bst.insert(10);//nivel 2
  bst.insert(40);
  bst.insert(100);

  /*cout << "Postorder ..." << endl;
  bst.Postorder();
  cout << "Preorder ..." << endl;
  bst.Preorder();
  cout << "Inorder ..." << endl;
  bst.Inorder();
  */

  cout<<"\nIterator InOrder"<<endl; 
  CBinaryTree<T1>::Iterator iter = bst.begin();
  CBinaryTree<T1>::Iterator iter2 = bst.end();//Maizo Diego
  for(; iter != iter2; ++(iter)) //Maizo Diego (iter)
    cout << *iter << endl;

  cout<<"\nIterator PreOrder"<<endl; 
  //Se intento varias veces modificar los operadores ++ y -- con el fin de poder implementar el iterator en el pre-order; sin embargo, dado que ninguna de las opciones funcionarón se opto por una forma más primitiva de realizarlo
  CBinaryTree<T1>::Iterator iter3 = bst.beginroot();
  CBinaryTree<T1>::Iterator iter4 = bst.end();
  CBinaryTree<T1>::Iterator iter5 = bst.lbegin();
  CBinaryTree<T1>::Iterator iter6 = bst.derlbegin();

  for(; iter3!=iter4; --(iter3)) 
    cout<<*iter3<<endl;
  cout<<*iter6<<endl; 
  for(; iter5!=iter4; ++(iter5)) 
    cout<<*iter5<<endl; 
    
  cout<<"\nIterator PostOrder"<<endl; 
}
