#ifndef __BST_H__ //Maizo Diego
#define __BST_H__  //kevin de lama

#include <iostream> //Maizo
#include <cassert>  // de Lama
#include "type.h" //Maizo

using namespace std;

template <typename T>
class CBinaryTree
{
    struct Node
    {
      T data;//Maizo
      Node *m_pChild[2];
      Node *m_pParentNode;
      Node(const T &_data, Node *pParentNode, Node *pLeft=nullptr, Node *pRight=nullptr) //Maizo agregado const
        : data(_data)
      {   m_pChild[0] = pLeft;  m_pChild[1] = pRight;  m_pParentNode = pParentNode; }
      T getData()             { return data; } //Maizo
      void setData (T &_data) { data=_data; }  //Maizo
      Node *getParent()       { return m_pParentNode; }
    };
public:
    class Iterator
    {
          Node *m_pNode;
          Node *getNode() { return m_pNode;  }
          void setNode(Node *pNode) { m_pNode = pNode;  }
      public:    
          Iterator(Node *pNode=nullptr): m_pNode(pNode) {};
          Iterator(Iterator &other) : m_pNode(other.getNode())  {}
          T operator *() { assert(getNode() != nullptr); return getNode()->getData(); }
          Iterator operator++();
          bool operator==(Iterator &other)  {return getNode() == other.getNode(); }
          bool operator!=(Iterator &other)  {return !(*this == other); }

          bool empty() {
            return getNode() == nullptr;
          }
    };
    Iterator begin()
    {
      Node *pNode = getRoot();
      while(pNode->m_pChild[0])
        pNode = pNode->m_pChild[0];
      return Iterator(pNode);
    }
    Iterator end()  { return Iterator(nullptr); }
private:
    Node *m_pRoot = nullptr;
    Node *getRoot() { return m_pRoot; }
public:
    CBinaryTree() {}
    void insert_old(const T &dato) //Maizo agregado const
    {   
        Node **ppNode = &m_pRoot;
        while(*ppNode != nullptr)      
        { if(dato > (*ppNode)->getData())
            ppNode = &ppNode->m_pChild[1];
          else
            ppNode = &ppNode->m_pChild[0];
        }
        *ppNode = new Node(dato);
    }
    void insert(const T &dato) //Maizo agregado const
    {   internal_insert(m_pRoot, nullptr, dato);   }

    void Preorder()
    { PreOrden(m_pRoot, 0, 1, "", "",cout);  }
    
    void Postorder()
    { PostOrden(m_pRoot, 1, 0, "", "",cout);  }

    void Inorder()
    { InOrden(m_pRoot, 1, 0, "", "",cout); }
    
private:
    void internal_insert(Node *&rParentPointer, Node *rParentNode, const T &dato); //Maizo agregado const
    void InOrden(Node *rParent, size_t c1, size_t c2, string space, string flecha, ostream &os);
    void PreOrden(Node *rParent, size_t c1, size_t c2, string space, string flecha, ostream &os);
    void PostOrden(Node *rParent, size_t c1, size_t c2, string space, string flecha, ostream &os);
};

template <typename T>
void CBinaryTree<T>::internal_insert(Node *&rParentPointer, Node *rParentNode, const T &dato) // kevin de lama y Maizo agregado const
{
  if(!rParentPointer)
  {   rParentPointer = new Node(dato, rParentNode);
      return;
  }
  internal_insert(rParentPointer->m_pChild[ dato > rParentPointer->getData() ], rParentPointer, dato);
}

template <typename T>
void CBinaryTree<T>::InOrden(Node *pNode, size_t c1, size_t c2, string space, string flecha, ostream &os)
{
  if(pNode)
  {
    InOrden(pNode->m_pChild[c1], c1, c2, space+"  ", "/", os);
    os << space <<flecha<< pNode->getData();
    if( pNode->getParent() )
      os << "(" << pNode->getParent()->getData() << ")";
    else
      os << "(*)";
    os << endl;
    InOrden(pNode->m_pChild[c2], c1, c2, space+"  ", "\\", os);
  }
}

template <typename T>
void CBinaryTree<T>::PreOrden(Node *rParent, size_t c1, size_t c2, string space, string flecha, ostream &os)
{
  if(rParent)
  {
    os << space <<flecha<< rParent->getData() << endl;
    PreOrden(rParent->m_pChild[c1], c1, c2, space+"  ", "/", os);
    PreOrden(rParent->m_pChild[c2], c1, c2, space+"  ", "\\", os);
  }
}

template <typename T>
void CBinaryTree<T>::PostOrden(Node *rParent, size_t c1, size_t c2, string space, string flecha, ostream &os)
{
  if(rParent)
  {
    PostOrden(rParent->m_pChild[c1], c1, c2, space+"  ", "/", os);
    PostOrden(rParent->m_pChild[c2], c1, c2, space+"  ", "\\", os);
    os << space <<flecha<< rParent->getData() << endl;
  }
}

template <typename T>
typename CBinaryTree<T>::Iterator CBinaryTree<T>::Iterator::operator++()
{
    Node *pNode = getNode();
    if(pNode->m_pChild[1]) // Tiene hijo derecho?
    {
      pNode = pNode->m_pChild[1];
      while(pNode->m_pChild[0])
        pNode = pNode->m_pChild[0];
      setNode(pNode);
      return *this;
    }
    Node *pParent = pNode->getParent();
    while(pParent && pParent->m_pChild[1] == pNode) // Mientras venga por el lado derecho => subir
    {
      pNode = pParent;
      pParent = pParent->getParent();
    }
    if(pParent && pParent->m_pChild[0] == pNode) // Soy el hijo izquierdo
    { setNode(pParent);
      return *this;
    }
    setNode(nullptr);
    return *this;
}

#endif //Maizo Diego  