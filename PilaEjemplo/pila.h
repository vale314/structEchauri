#ifndef PILA_H
#define PILA_H
#include  <iostream>
#include <stdexcept>
#include "lsl.h"

using namespace std;
template <typename T>
class Pila
{
    private:
    LSL<T> lista;

    public:
    Pila(){

    }
    ~Pila()
    {
        lista.clear();
    }

    bool empty()const;
    size_t size() const;
    const T& top()const;
    void push(const T& elem);
    void pop();
};
#endif // PILA_H

template<typename T>
bool Pila<T>::empty() const
{
    return lista.empty();
}

template<typename T>
size_t Pila<T>::size() const
{
    return lista.size();
}

template<typename T>
const T &Pila<T>::top() const
{
    if(empty())
        throw invalid_argument("top() on empty stack");
    return lista.front();
}

template<typename T>
void Pila<T>::push(const T &elem)
{
    lista.push_front(elem);
}

template<typename T>
void Pila<T>::pop()
{
    if(empty())
        throw invalid_argument("pop() on empty stack");
    lista.pop_front();
}

