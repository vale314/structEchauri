#ifndef COLA_H
#define COLA_H
#include<iostream>
#include<stdexcpt.h>
#include<lsl.h>

using namespace std;

template <typename T>
class Cola
{
private:
    LSL<T> lista;
public:
    Cola(){

    }
    ~Cola(){
        lista.clear();
    }
    bool empty() const;
    size_t size() const;
    const T& front()const;
    const T& back() const;
    void push(const T &elem);
    void pop();
};

#endif // COLA_H

template<typename T>
bool Cola<T>::empty() const
{
    return lista.empty();
}

template<typename T>
size_t Cola<T>::size() const
{
    return  lista.size();
}

template<typename T>
const T &Cola<T>::front() const
{
    if(empty())
        throw invalid_argument("front() on empty  queue");
    return lista.front();
}

template<typename T>
const T &Cola<T>::back() const
{
    if(empty())
        throw invalid_argument("back() on emoty queue");
    return lista.back();
}

template<typename T>
void Cola<T>::push(const T &elem)
{
    lista.push_back(elem);
}

template<typename T>
void Cola<T>::pop()
{
    if(empty())
        throw invalid_argument("pop() on empty queue");
    lista.pop_front();
}
