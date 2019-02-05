#ifndef LSL_H
#define LSL_H
#include <iostream>
using namespace std;

template<typename T>
class LSL
{
  private:
    #include "nodolsl.h"
    size_t listSize;
    NodoLSL* listFront;
    NodoLSL* listBack;

  public:
    LSL()
    {
        listSize = 0;
        listFront = nullptr;
        listBack = nullptr;
    }
    ~LSL(){
        clear();
    }

    LSL(const LSL& other){
        listFront=nullptr;
        listBack=nullptr;
        listSize=0;

        for(size_t i=0;i<other.size();i++)
            push_back(other[i]);
    }

    const bool empty() const;
    const size_t size() const;
    void  push_front(const T& elem);
    void push_back(const T& elem);
    const T& front() const;
    const T& back() const;
    void pop_front();
    void pop_back();
    void insert(size_t position, const T& elem);
    void erease(size_t position);
    void clear();
    void  remove(const T &value);
    T &operator[](size_t idx) const;

    LSL& operator =(const LSL& other){
        listFront = nullptr;
        listBack = nullptr;
        listSize= 0;
        for(size_t i=0;i<other.size();i++){
            push_back(other[i]);
            return this;
        }
    }
};


template<typename T>
//regresa un constante          //el segundo constate significa que no se puede modificar listSize
const bool LSL<T>::empty() const
{
    return listSize == 0;
}

template <typename T>
const size_t LSL<T>::size() const
{
    return listSize;
}

template <typename T>
void LSL<T>::push_front(const T &elem){
    if(empty()){
        listFront = new NodoLSL(elem);
        listBack=listFront;
    }
    else{
        NodoLSL* temp = new NodoLSL(elem,listFront);
        listFront=temp;
    }
    listSize++;
}

template <typename T>
void LSL<T>::push_back(const T& elem){
    if(empty())
    {
        listFront = new NodoLSL(elem);
        listBack = listFront;
    }else{
        NodoLSL* temp = new NodoLSL(elem);
        listBack->siguiente = temp;
        listBack = temp;
    }
    listSize++;
}

template<typename T>
const T &LSL<T>::front() const
{
    if(empty())
        throw invalid_argument(" front() on empty list");
    return listFront->dato;
}

template<typename T>
const T &LSL<T>::back() const
{
    if(empty())
        throw  invalid_argument("back() on emty list");
    return listBack->dato;
}

template<typename T>
void LSL<T>::pop_front()
{
    if(empty())
        throw invalid_argument("Pop_front() on empty list");

    NodoLSL* temp=listFront;
    listFront = listFront->siguiente;
    delete temp;
    temp= nullptr;
    listSize--;
}

template<typename T>
void LSL<T>::pop_back()
{
    if(empty())
        throw invalid_argument("Pop_Back() on empty list");
    NodoLSL* temp=listFront;
    while(temp->siguiente !=nullptr && temp->siguiente != listBack)
        temp= temp->siguiente;
    NodoLSL* eliminar = listBack;
    delete eliminar;
    eliminar = nullptr;
    listBack=temp;
    listBack->siguiente = nullptr;
    listBack--;
}

template<typename T>
void LSL<T>::insert(size_t position, const T &elem)
{
    if(empty())
        throw  invalid_argument("Insert() on empty list");
    else if(position > listSize)
        throw invalid_argument("Insert() on non valid position");
    else if(position == 0)
        push_front(elem);
    else if(position == listSize)
        push_back(elem);
    else{
        NodoLSL* temp = listFront;
        for(size_t i=0; i< position-1; i++)
            temp= temp->siguiente;
        NodoLSL* nuevo = new NodoLSL(elem, temp->siguiente);
        temp->siguiente=nuevo;
        listSize++;
    }
}

template<typename T>
void LSL<T>::erease(size_t position)
{
    if(empty())
        throw invalid_argument("Erease() on empty list");
    else if(position >= listSize)
        throw invalid_argument("Erease() on no valid position");
    else  if(position == 0)
        pop_front();
    else if(position == listSize -1)
        pop_back();
    else{
        NodoLSL* temp = listFront;
        for(size_t i=0; i<position-1; i++)
            temp= temp ->siguiente;
        NodoLSL *eliminar = temp->siguiente;
        temp->siguiente=eliminar->siguiente;
        delete eliminar;
        eliminar = nullptr;
        listSize--;
    }
}

template<typename T>
void LSL<T>::clear()
{
    if(!empty()){
        for(size_t i=0; i<listSize; i++)
            pop_front();
    }
    listFront=nullptr;
    listBack=nullptr;
    listSize=0;
}

template<typename T>
void LSL<T>::remove(const T &value)
{
    if(empty())
        throw invalid_argument("remove() on empty list");
    NodoLSL* temp = listFront;
    size_t i = 0;
    T dato;
    while(temp != nullptr)
    {
        dato = temp -> dato;
        temp = temp -> siguiente;
        if(dato == value)
        {
            erease(i);
            i--;
        }
        i++;
    }
}

template<typename T>
T &LSL<T>::operator[](size_t idx)const
{
    if(empty())
        throw invalid_argument("[] on empty list");
    else if(idx >= listSize)
        throw invalid_argument("index out of range");
    NodoLSL* temp = listFront;
    for(size_t i=0; i<idx; i++)
        temp=temp->siguiente;
    return temp->dato;
}




#endif // LSL_H
