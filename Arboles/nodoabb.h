#ifndef NODOABB_H
#define NODOABB_H

struct NodoABB
{
    T dato;
    NodoABB* izq;
    NodoABB* der;

    NodoABB(const T& element,
            NodoABB* i = nullptr,
            NodoABB* d = nullptr) :
        dato(element),
        izq(i),
        der(d) {}
};

#endif // NODOABB_H
