#include "grafo.h"
#include "arco.h"

#include <list>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <cassert>

//hacer los typedef para los mapas y los iteradores

//cambiar los auto x esto segun corresponda
//typedef typename std::map<int, std::map<int, C> >::iterator itA
//typedef typename std::map<int, std::map<int, C> >::const_iterator itAConst
//typedef typename std::map<int, C>::iterator itB
//typedef typename std::map<int, C>::iterator itBConst

template <typename C> grafo<C>::grafo(){
    this->privCardinal = 0;
}

//template <typename C> grafo<C>::grafo(const grafo & otrografo){}

template <typename C> grafo<C>::~grafo(){}

template <typename C> grafo<C> & grafo<C>::operator = (const grafo & otrografo){
    //implementar
    return *this;
}

template <typename C> bool grafo<C>::vacio() const{
    return this->privCardinal == 0; //no lo verifica realmente pero no debria dar problema
    //en cualquier caso hacer
    //return this->ady.begin() == this->ady.end();
}

template <typename C> int grafo<C>::cardinal() const{
    return this->privCardinal;
}

template <typename C> bool grafo<C>::existeVertice(int vertice) const{
    return (this->ady.find(vertice) != this->ady.end());
}

template <typename C> bool grafo<C>::existeArco(int origen, int destino) const{
    auto it = this->ady.find(origen);
    if ((it != this->ady.end()) && (it->second.find(destino) != it->second.end())) return true;
    return false;
}

template <typename C> const C & grafo<C>::costoArco(int origen, int destino) const{
    auto it = this->ady.find(origen);
    assert(((it != this->ady.end()) && (it->second.find(destino) != it->second.end()))
    && "Se accedió al costo de un arco que no existe - de: clase Grafo - Función costoArco");
    return it->second.at(destino);
}

template <typename C> void grafo<C>::listarVertices(std::list<int> & vertices) const{
    auto it = this->ady.begin();
    while(it != this->ady.end()){
        vertices.push_back(it->first);
        it++;
    }
}

template <typename C> void grafo<C>::adyacentesA(int origen,std::list<arco<C>> & adyacentes) const{
    auto it = this->ady.find(origen);
    if(it != this->ady.end()){
        auto it2 = it->second.begin();
        while(it2 != it->second.end()){
            adyacentes.push_back(arco<int>(it2->first,it2->second));
            it2++;
        }
    }
}

template <typename C> void grafo<C>::adyacentesAsoloInt(int origen,std::list<int> & adyacentes) const{
    auto it = this->ady.find(origen);
    if(it != this->ady.end()){
        auto it2 = it->second.begin();
        while(it2 != it->second.end()){
            adyacentes.push_back(it2->first);
            it2++;
        }
    }
}
/* NO ES NECESARIA EXTRAA
template <typename C> void grafo<C>::adyacentesAset(int origen,std::set<arco<C>> & adyacentes) const{
    auto it = this->ady.find(origen);
    if(it != this->ady.end()){
        auto it2 = it->second.begin();
        while(it2 != it->second.end()){
            adyacentes.insert(arco<int>(it2->first,it2->second));
            it2++;
        }
    }
}
*/
template <typename C> void grafo<C>::aggVertice(int vertice){
    if(!existeVertice(vertice)){
        std::map<int, C> vacio;
        this->ady.insert(std::make_pair(vertice,vacio));
        this->privCardinal++;
    }
}

template <typename C> void grafo<C>::elimVertice(int vertice){
    if(existeVertice(vertice)){
        this->ady.erase(vertice);
        auto it = this->ady.begin();
        while(it != this->ady.end()){ //el it recorre todos los vertices
            it->second.erase(vertice); //en cada vertice elimina lso arcos con vertAEliminar
            it++;
        }
        this->privCardinal--;
    }
}

template <typename C> void grafo<C>::modCosto(int origen, int destino, const C & costo){
    auto it = this->ady.find(origen);
    if ((it != this->ady.end()) && (it->second.find(destino) != it->second.end()))
        this->ady[origen][destino] = costo;
}

template <typename C> void grafo<C>::aggArco(int origen, int destino, const C & costo){
    if(existeVertice(origen) && existeVertice(destino))
        this->ady[origen][destino] = costo;
}

template <typename C> void grafo<C>::elimArco(int origen, int destino){
    if(existeVertice(origen) && existeVertice(destino)){
        auto it = this->ady.find(origen);
        it->second.erase(destino);
    }
}

template <typename C> void grafo<C>::dfs(int origen, std::set<int> & visitados, std::list<int> recorrido) const{

}

template <typename C> void grafo<C>::dfsForest(std::list<int> & recorridos) const{

}

template <typename C> void grafo<C>::vaciar(){
    this->ady.clear();
    this->privCardinal = 0;
}

template class grafo<int>;
