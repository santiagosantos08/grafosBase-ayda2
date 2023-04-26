#include <iostream>
#include "grafo.h"
#include "arco.h"
#include "auxiliares.h"
#include <list>
#include <set>
#include <map>
#include <algorithm>


bool existeCaminoDfs(grafo<int> & g,int origen,int destino,std::list<int> & camino,std::set <int> & visitados,std::map<int,int> & colores){ //modificacion de un dfs con condicionales extra

    std::list<arco<int>> ady;
    bool buscando = true; //para cortar si lo encuentra ya que solo interesa saber si hay un camino no encontrar todos ni el mejor
    bool caminoPosible = colores.at(origen)!=rojo; //si el actual es rojo no es un camino posible, si el origen es rojo ningun camino sera posible
    int siguiente;

    camino.push_back(origen);
    visitados.insert(origen);
    g.adyacentesA(origen,ady);
    auto it = ady.begin();

    if(origen == destino){
        buscando = false;
        return true;
    }

    while(it != ady.end() && buscando && caminoPosible){ //se chequea camino posible tambien aca para no tener que hacer un if por afuera
        siguiente = it->adyacente();
        if(visitados.find(siguiente) == visitados.end()){ //si el sig no está visitado recorro
            if(existeCaminoDfs(g,siguiente,destino,camino,visitados,colores)) return true; //si hago return directamente no puedo hacer el pop_back de los caminos que no sirven
            //cambiar el if interno a un bool para comparar todo en uno solo??
            camino.pop_back();
        }
        it++;
    }
    return false;
}

bool existeCaminoBfs(grafo<int> & g,int origen,int destino,std::list<int> & camino,std::set <int> & visitados,std::map<int,int> & colores){ //modificacion de un dfs con condicionales extra

    std::list<arco<int>> ady;
    std::list<int> cola;
    std::map<int,int> padres;
    bool buscando = true; //para cortar si lo encuentra ya que solo interesa saber si hay un camino no encontrar todos ni el mejor
    int inicial = origen;

    if(origen == destino){
        buscando = false;
        return true;
    }

    cola.push_back(origen);
    camino.push_back(origen);
    visitados.insert(origen);

    while(!cola.empty() && buscando && colores.at(origen)!=rojo){
        origen = cola.front();
        cola.pop_front();
        ady.clear();
        g.adyacentesA(origen,ady);
        auto it = ady.begin();
        while(it != ady.end() && buscando && colores.at(origen)!=rojo){
            if(visitados.find(it->adyacente()) == visitados.end() && colores.at(it->adyacente()) != rojo){
                visitados.insert(it->adyacente());
                cola.push_back(it->adyacente());
                padres[it->adyacente()]=origen;
                if(it->adyacente() == destino){
                    buscando = false;
                }
            }
            it++;
        }
    }

    if(!buscando){
        camino.push_front(destino);
        int k = destino;
        while(k != inicial){
            k = padres[k];
            camino.push_front(k);
        }
        camino.pop_back();  //mal cambiar, funciona pero evidentemente no esta bien
    }
    return !buscando;
}

bool existeCamino(grafo<int> & g, int origen, int destino,std::list<int> & camino,std::map<int,int> & colorinches){ //agregar opcion para elegir dfs o bfs?
    std::set<int> visitados;
    if(existeCaminoDfs(g,origen,destino,camino,visitados,colorinches)) printLista(camino);
    camino.clear();
    visitados.clear();
    bool existe = existeCaminoBfs(g,origen,destino,camino,visitados,colorinches);
    if(existe) std::cout<<"encontrobfs";
    printLista(camino);
    return false;
}

void ejercicio(){
    grafo<int> test;
    std::map<int,int> colorinches;
    std::list<int> camino;

	cargarVertices(test,1,12); //agregar lam excecion cuando agrego un arco en vertices que no existe sino es re confuso usarlo pq no avisa
    cargarArcos(test);
    cargarColores(colorinches);

    bool existe = existeCamino(test,2,11,camino,colorinches);

}

int main(){
	ejercicio();
	return 0;
}

