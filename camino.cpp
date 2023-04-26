#include "camino.h"
#include <set>
#include <list>

template <typename C>
bool existe_camino(const grafo<C> & g, int origen, int destino){
    bool existe = false;

    return existe;
}

//Devolver si existe UN camino
template <typename C>
bool devolver_camino(const grafo<C> & g, int origen, int destino, std::list<int> & camino){
    return false;
}

//Devolver TODOS los caminos
template <typename C>
void devolver_caminos(const grafo<C> & g, int origen, int destino, std::list<std::list<int> > & caminos){
}

//Devolve el MEJOR de los caminos
template <typename C>
void encontrar_mejor_camino(const grafo<C> & g, int origen, int destino, std::list<int> & camino){
}
