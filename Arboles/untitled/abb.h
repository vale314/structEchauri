#ifndef ABB_H
#define ABB_H
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class ABB
{
public:
    ABB<T>() : root(nullptr) {}
    ABB<T>(const T& elem,
           const ABB& left = ABB(),
           const ABB& right = ABB()) :
        root(new NodoABB(elem, left.root, right.root)) {}

    bool isNull() const;
    bool isLeaf() const;
    ABB<T> getLeftSubtree() const;
    ABB<T> getRightSubtree() const;
    const T& getData() const;
    const T* find(const T& elem) const;
    bool insert(const T& elem);
    void inOrder();
    bool erase(const T& elem);

private:
#include "nodoabb.h"
    ABB<T>(NodoABB* newRoot) : root(newRoot) {}

    const T* find(NodoABB* localRoot, const T& elem) const;
    bool insert(NodoABB*& localRoot, const T& elem);
    void inOrder(NodoABB *localRoot);
    bool erase(NodoABB*& localRoot, const T& elem);
    void replaceParent(NodoABB*& oldRoot, NodoABB*& localRoot);
    NodoABB* root;
};

template<typename T>
bool ABB<T>::isNull() const
{
    return root == nullptr;
}

template<typename T>
bool ABB<T>::isLeaf() const
{
    if (!isNull())
        return root->izq == nullptr && root->der == nullptr;

    return true;
}

template<typename T>
ABB<T> ABB<T>::getLeftSubtree() const
{
    if (isNull())
        throw invalid_argument("getLeftSubtree() on empty tree");

    return ABB(root->izq);
}

template<typename T>
ABB<T> ABB<T>::getRightSubtree() const
{
    if (isNull())
        throw invalid_argument("getRightSubtree() on empty tree");

    return ABB(root->der);
}

template<typename T>
const T& ABB<T>::getData() const
{
    if (isNull())
        throw invalid_argument("getData() on empty tree");

    return root->dato;
}

template<typename T>
const T* ABB<T>::find(const T &elem) const
{
    return find(root, elem);
}

template<typename T>
const T* ABB<T>::find(NodoABB *localRoot, const T &elem) const
{
    if (localRoot == nullptr)
        return nullptr;
    else if (elem < localRoot->dato)
        return find(localRoot->izq, elem);
    else if (elem > localRoot->dato)
        return find(localRoot->der, elem);
    else
        return &(localRoot->dato);
}

template<typename T>
bool ABB<T>::insert(const T &elem)
{
    return insert(root, elem);
}

template<typename T>
bool ABB<T>::insert(NodoABB *&localRoot, const T &elem)
{
    if (localRoot == nullptr)
    {
        localRoot = new NodoABB(elem);
        return true;
    }
    else if (elem < localRoot->dato)
        return insert(localRoot->izq, elem);
    else if (elem > localRoot->dato)
        return insert(localRoot->der, elem);
    else
        return false;
}

template<typename T>
void ABB<T>::inOrder()
{
    inOrder(root);
}

template<typename T>
void ABB<T>::inOrder(NodoABB *localRoot)
{
    if (localRoot == nullptr)
        return;
    inOrder(localRoot->izq);
    cout<< localRoot->dato <<endl;
    inOrder(localRoot->der);
}

template<typename T>
bool ABB<T>::erase(const T &elem)
{
    return erase(root, elem);
}

template<typename T>
bool ABB<T>::erase(NodoABB *&localRoot, const T &elem)
{
    if (localRoot == nullptr)
        return false;
    else if (elem < localRoot->dato)
        return erase(localRoot->izq, elem);
    else if (elem > localRoot->dato)
        return erase(localRoot->der, elem);
    else
    {
        NodoABB* oldRoot = localRoot;
        if (localRoot->izq == nullptr)
            localRoot = localRoot->der;
        else if (localRoot->der == nullptr)
            localRoot = localRoot->izq;
        else
            replaceParent(oldRoot, oldRoot->izq);
        delete oldRoot;
        return true;
    }
}

template<typename T>
void ABB<T>::replaceParent(NodoABB *&oldRoot, NodoABB *&localRoot)
{
    if (localRoot->der != nullptr)
        replaceParent(oldRoot, localRoot->der);
    else
    {
        oldRoot->dato = localRoot->dato;
        oldRoot = localRoot;
        localRoot = localRoot->izq;
    }
}

#endif // ABB_H
