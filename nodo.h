#ifndef NODO_H
#define NODO_H

#include<iostream>

class nodo{
    public:
        nodo(int n, std::string rot);
        nodo(int n);
        virtual ~nodo();
        std::string rotulo() const;
        int numero() const;

    private:
        std::string nbre;
        int nro;
        bool rotulado;
};

#endif // NODO_H
