#include "arco.h"
#include <cassert>

template <typename C> arco<C>::arco(){
    this->vacio = true;
    //ctor, setear todo en 0? que hace con el generico?
}

template <typename C> arco<C>::arco(int adyacente, const C & costo){
    this->vacio = false;
    this->vertice = adyacente;
    this->privCosto = costo;
}

template <typename C> int arco<C>::adyacente() const{
    assert(!this->vacio && "Se accedió al adyacente de un arco vacio - clase arco");
    return this->vertice;

}

template <typename C> const C & arco<C>::costo() const{
    assert(!this->vacio && "Se accedió al costo de un arco vacio - clase arco");
    return this->privCosto;
}

template <typename C> arco<C>::~arco(){
    //dtor
}

template class arco<int>;
