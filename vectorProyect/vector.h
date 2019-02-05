#ifndef VECTOR_H
#define VECTOR_h
#include <iostream>
using namespace std;

template<typename T>
class vector{


private:
    size_t vectorSize;
    size_t vectorCapacity;
    T *container;

public:
    vector(){
        vectorSize=0;
        vectorCapacity=1;
        container= new T[vectorCapacity];
    }
    ~vector(){
        delete []container;
        vectorSize=0;
        vectorCapacity=1;
        container= new T[vectorCapacity];
    }
    const size_t size() const;
    const size_t capacity() const;
    void push_back(const T& element);
    void pop_back();
    void insert(size_t position,const T& element);
    void erease(size_t position);
    void clear();
    void resize();
    T& at(size_t position) const;
    T &operator[](size_t idx) const;
    T &operator=(const vector& other) &;
};
#endif // VECTOR_H

template<typename T>
const size_t vector<T>::size() const
{
    return vectorSize;
}

template<typename T>
const size_t vector<T>::capacity() const
{
    return vectorCapacity;
}

template<typename T>
void vector<T>::push_back(const T& element)
{
    if(vectorCapacity==vectorSize){}
        resize();
    container[vectorSize]=element;
    vectorSize++;
}

template<typename T>
void vector<T>::pop_back()
{
    if(size()==0)
        return throw invalid_argument("Error Pop Back Empty()");
    container[vectorSize-1]=0;
    vectorSize--;
}

template<typename T>
void vector<T>::insert(size_t position, const T &element)
{
    if(position)
        position--;
    if(position < vectorCapacity){
        for(size_t i=vectorSize;i>=position+1;i--){
            container[i+1]=container[i];
        }
        container[position+1]=element;
        vectorSize++;
    }else{
        resize();
        insert(position,element);
    }
}

template<typename T>
void vector<T>::erease(size_t position)
{
    if(size()==0)
        throw invalid_argument("Erease() on empty list");
    else if(position > size())
        throw invalid_argument("Erease() on no valid position");
    for(size_t i=position;i<=vectorSize;i++){
        container[i]=container[i+1];
        }
    vectorSize--;
}

template<typename T>
void vector<T>::clear()
{
    delete []container;
    vectorSize=0;
    vectorCapacity=1;
    container= new T[vectorCapacity];
}

template<typename T>
void vector<T>::resize()
{
    if(vectorCapacity==1)
        vectorCapacity++;
    else
        vectorCapacity=vectorCapacity*vectorCapacity;

    T* new_array = new T[vectorCapacity];
    for (size_t i = 0; i < vectorSize; i++)
        {
            new_array[i] = container[i];
        }

    delete [] container;
    container = new_array;
}

template<typename T>
T& vector<T>::at(size_t position)const
{
    if(size()==0)
        throw invalid_argument("at() on empty list");
    else if(position >=size())
        throw invalid_argument("at() on no valid position");
    return container[position];
}

template<typename T>
T &vector<T>::operator[](size_t idx) const
{
    if(size()==0)
        throw invalid_argument("[] on empty list");
    else if(idx >= vectorSize)
        throw invalid_argument("index out of range");
    return container[idx];
}

template<typename T>
T &vector<T>::operator=(const vector &other) &
{
    for(size_t i=0;i<other.size();i++)
        push_back(other[i]);
}








