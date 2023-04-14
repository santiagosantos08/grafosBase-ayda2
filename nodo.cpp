#include "nodo.h"
#include<iostream>
#include<cassert>

nodo::nodo(int n){
    this->nro = n;
    this->nbre = " ";
    this->rotulado = false;
}
nodo::nodo(int n,std::string nombre){
    this->nro = n;
    this->nbre = nombre;
    this->rotulado = true;
}

std::string nodo::rotulo() const{
    assert(this->rotulado);
    return this->nbre;
}
int nodo::numero() const{
    return this->nro;
}

nodo::~nodo(){
    //dtor
}

