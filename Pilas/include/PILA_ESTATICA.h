#ifndef PILA_ESTATICA_H
#define PILA_ESTATICA_H
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>

class Pila_Estatica{

    public:
        Pila_Estatica(): index(0){}
        bool _empty();
        bool full();
        size_t _size();
        const T& top();
        void push(const T& elem);
        void pop();

    private:
        static const size_t CAPACITY = 1000;
        T elements[CAPACITY];
        size_t index;

};

template<typename T>
bool Pila_Estatica<T>::_empty(){
    return index==0;
}

template <typename T>
bool Pila_Estatica<T>::full(){
    return index==CAPACITY;
}

template <typename T>
size_t Pila_Estatica<T>::_size(){
    return index;
}

template <typename T>
const  T& Pila_Estatica<T>::top(){
    if(_empty())
        throw invalid_argument("TOP() ON EMTY  ELEMNETS");

    return elements[index-1];
}

template <typename T>
void Pila_Estatica<T>::push(const T &elem){
    if(full())
        throw invalid_argument("push");


    elements[index]= elem;
    index++;
}

template <typename T>
void Pila_Estatica<T>::pop(){
    if(_empty())
        throw invalid_argument("pop()");
    index--;
}

#endif // PILA_ESTATICA_
