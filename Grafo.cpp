//
// Created by santiago on 5/3/23.
//

#include "Grafo.h"
#include <list>
#include <set>
#include <map>
#include <utility>
#include <cassert>

// ====== clase ARCO =====

template <typename C> Grafo<C>::Arco::Arco(){
    this->vacio = true;
    //ctor, setear todo en 0? que hace con el generico?
}

template <typename C> Grafo<C>::Arco::Arco(int adyacente, const C & costo){
    this->vacio = false;
    this->vertice = adyacente;
    this->privCosto = costo;
}

template <typename C> int Grafo<C>::Arco::devolver_adyacente() const{
    assert(!this->vacio && "Se accedió al adyacente de un arco vacio - clase arco");
    return this->vertice;

}

template <typename C> const C & Grafo<C>::Arco::devolver_costo() const{
    assert(!this->vacio && "Se accedió al costo de un arco vacio - clase arco");
    return this->privCosto;
}

template <typename C> Grafo<C>::Arco::~Arco(){
    //dtor
}

// ===== FIN de ARCO ======

template <typename C> Grafo<C>::Grafo(){
    this->privCardinal = 0;
}

//template <typename C> Grafo<C>::Grafo(const Grafo & otrografo){}

template <typename C> Grafo<C>::~Grafo(){}

template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo){
    //implementar
    return *this;
}

template <typename C> bool Grafo<C>::esta_vacio() const {
    return this->privCardinal == 0; //no lo verifica realmente pero no debria dar problema
    //en cualquier caso hacer
    //return this->ady.begin() == this->ady.end();
}

template <typename C> int Grafo<C>::devolver_longitud() const {
    return this->privCardinal;
}

template <typename C> bool Grafo<C>::existe_vertice(int vertice) const {
    return (this->ady.find(vertice) != this->ady.end());
}

template <typename C> bool Grafo<C>::existe_arco(int origen, int destino) const {
    auto it = this->ady.find(origen);
    if ((it != this->ady.end()) && (it->second.find(destino) != it->second.end())) return true;
    return false;
}

template <typename C> const C & Grafo<C>::costo_arco(int origen, int destino) const {
    auto it = this->ady.find(origen);
    assert(((it != this->ady.end()) && (it->second.find(destino) != it->second.end()))
           && "Se accedió al costo de un arco que no existe - de: clase Grafo - Función costoArco");
    return it->second.at(destino);
}

template <typename C> void Grafo<C>::devolver_vertices(std::list<int> &vertices) const {
    auto it = this->ady.begin();
    while(it != this->ady.end()){
        vertices.push_back(it->first);
        it++;
    }
}

template <typename C> void Grafo<C>::devolver_adyacentes(int origen, std::list<Arco> &adyacentes) const {
    auto it = this->ady.find(origen);
    if(it != this->ady.end()){
        auto it2 = it->second.begin();
        while(it2 != it->second.end()){
            adyacentes.push_back(Arco(it2->first,it2->second));
            it2++;
        }
    }
}

template <typename C> void Grafo<C>::agregar_vertice(int vertice) {
    if(!existe_vertice(vertice)){
        std::map<int, C> vacio;
        this->ady.insert(std::make_pair(vertice,vacio));
        this->privCardinal++;
    }
}

template <typename C> void Grafo<C>::eliminar_vertice(int vertice) {
    if(existe_vertice(vertice)){
        this->ady.erase(vertice);
        auto it = this->ady.begin();
        while(it != this->ady.end()){ //el it recorre todos los vertices
            it->second.erase(vertice); //en cada vertice elimina lso arcos con vertAEliminar
            it++;
        }
        this->privCardinal--;
    }
}

template <typename C> void Grafo<C>::modificar_costo_arco(int origen, int destino, const C &costo) {
    auto it = this->ady.find(origen);
    if ((it != this->ady.end()) && (it->second.find(destino) != it->second.end()))
        this->ady[origen][destino] = costo;
}

template <typename C> void Grafo<C>::agregar_arco(int origen, int destino, const C &costo) {
    if(existe_vertice(origen) && existe_vertice(destino))
        this->ady[origen][destino] = costo;
}

template <typename C> void Grafo<C>::eliminar_arco(int origen, int destino) {
    if(existe_vertice(origen) && existe_vertice(destino)){
        auto it = this->ady.find(origen);
        it->second.erase(destino);
    }
}

template <typename C> void Grafo<C>::dfs(int origen, std::set<int> & visitados, std::list<int> recorrido) const{

}

template <typename C> void Grafo<C>::dfsForest(std::list<int> & recorridos) const{

}

template <typename C> void Grafo<C>::vaciar(){
    this->ady.clear();
    this->privCardinal = 0;
}

template class Grafo<int>;