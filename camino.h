#ifndef CAMINO_H
#define CAMINO_H

#include "grafo.h"
#include <list>

template <typename C>
bool existe_camino(const grafo<C> & g, int origen, int destino);

template <typename C>
bool devolver_camino(const grafo<C> & g, int origen, int destino, std::list<int> & camino);

template <typename C>
void devolver_caminos(const grafo<C> & g, int origen, int destino, std::list<std::list<int> > & caminos);

template <typename C>
void encontrar_mejor_camino(const grafo<C> & g, int origen, int destino, std::list<int> & camino);

#endif // CAMINO_H
