#include <iostream>
#include <list>
#include <set>
#include <map>
#include "Grafo.h"
|
const int rojo = 1;
const int blanco = 0;
void printLista(std::list<int> & camino);
void pruebaInteractiva();
void pruebaPreCargada();

bool existeCaminoDfs(Grafo<int> & g,int origen,int destino,std::list<int> & camino,std::set<int> & visitados,std::map<int,int> & colores){

    if(colores.at(origen) == rojo) return false;
    if(origen == destino){camino.push_front(origen);return true;}

    std::list<Grafo<int>::Arco> ady; //pasar una lista vacia desde afuera asi usa la misma en la recursividad y no crea una por cada llamado
    int siguiente;
    visitados.insert(origen);
    g.devolver_adyacentes(origen,ady);
    auto it = ady.begin();

    while(it != ady.end()){ // recorre O(adyacentes a origen), en el peor caso todos son adyacentes: -> O(n)
        siguiente = it->devolver_adyacente();
        if(visitados.find(siguiente) == visitados.end()){ //si el sig no está visitado recorro
            if(existeCaminoDfs(g,siguiente,destino,camino,visitados,colores)){
                camino.push_front(origen);
                return true;
            }
        }
        it++;
    }
    return false;
}

bool existeCamino(Grafo<int> & g, int origen, int destino,std::list<int> & camino,std::map<int,int> & colorinches){
    if(colorinches.find(destino) == colorinches.end()){
        std::cout<<"      Verificar que exista destino."<<std::endl;
        return false;
    }
    if(colorinches.find(origen) == colorinches.end()){
        std::cout<<"      Verificar que exista origen."<<std::endl;
        return false;
    }

    std::set<int> visitados;
    bool dfs = existeCaminoDfs(g,origen,destino,camino,visitados,colorinches);
    std::cout<<"   |Por Dfs: "<<std::endl;

    if(dfs)printLista(camino);
    else std::cout<<"   |   No se encontró camino"<<std::endl;

    return dfs;
}

void ejercicio(){
    int opcion = 1;
    while(opcion != 0){
        std::cout<<"================================================================================"<<std::endl;
        std::cout<<"   1) Probar casos pre-cargados mostrados en el informe"<<std::endl;
        std::cout<<"   2) Crear un grafo desde 0"<<std::endl;
        std::cout<<"   0) Salir"<<std::endl;
        std::cout<<"   Ingrese Opcion: ";
        std::cin>>opcion;
        if(opcion == 1) pruebaPreCargada();
        else if(opcion == 2) pruebaInteractiva();
    }
    std::cout<<"================================================================================"<<std::endl;
    std::cout<<"                =  TP algoritmos de grafos. AyDA II 1C-2023  = "<<std::endl;
    std::cout<<"                =  Loza Ciappa, Joaquin.  Santos, Santiago.  ="<<std::endl;
    std::cout<<"================================================================================"<<std::endl;
}

int main(){
    ejercicio();
    return 0;
}

//======================================================================================================================

void printLista(std::list<int> & camino){
    auto it = camino.begin();
    std::cout<<"   |   Camino:";
    while(it != camino.end()){
        std::cout<<" -> "<<*it;
        it++;
    }
    std::cout<<" "<<std::endl;
}

void cargarVertices(Grafo<int> & g,int base,int tope){
    for(int i = base; i <= tope; i++){
        g.agregar_vertice(i);
    }
}

void cargarColoresDefault(std::map<int,int> & c, std::list<int> & vertices){
    auto it = vertices.begin();
    while(it != vertices.end()){
        c[*it] = blanco;
        it++;
    }
}

void cargarColoresManual(std::map<int,int> & c, std::list<int> & vertices){
    int color;
    auto it = vertices.begin();
    while(it != vertices.end()){
        std::cout<<"   Vertice ["<<*it<<"] es rojo? (1 = si, 0 = no) :  ";
        std::cin>> color;
        if(color == 1) c[*it] = rojo;
        else c[*it] = blanco;
        it++;
    }
}

void cargarArcosManual(Grafo<int> & g){
    int origen,destino;
    bool cargar = true;
    std::cout<<"================================================================================"<<std::endl;
    std::cout<<"   Carga de arcos, para finalizar ingrese -1 en cualquier momento "<<std::endl;
    while(cargar){
        std::cout<<"   Origen? :  ";
        std::cin>>origen;
        if (origen == -1){
            std::cout<<"      Carga finalizada ya que origen == -1"<<std::endl;
            cargar = false;
        } else{
            std::cout<<"   Destino? :  ";
            std::cin>> destino;
            if(destino == -1){
                std::cout<<"      Carga finalizada ya que destino == -1"<<std::endl;
                cargar = false;
            } else{
                g.agregar_arco(origen,destino,0); //si se agrega q aggArco sea bool hace un if p imprimir
                std::cout<<"    - Se agregó arco de: "<<origen<<" a: "<<destino<<std::endl;
            }
        }
    }
}

void crearGrafo(Grafo<int> & g,std::map<int,int> & color){
    int cantVertices;
    std::list<int> vertices;
    std::cout<<"================================================================================"<<std::endl;
    std::cout<<"   Introduzca la cantidad de vertices que desee :   ";
    std::cin>> cantVertices;

    cargarVertices(g,1,cantVertices);
    g.devolver_vertices(vertices);
    cargarColoresDefault(color,vertices);
    std::cout<<"   Se creo el grafo de "<<cantVertices<<" vertices. Por defecto todos son blancos "<<std::endl;
}

void pruebaInteractiva(){
    int opcion = 1;
    int origen, destino;
    Grafo<int> g;
    std::map<int,int> color;
    std::list<int> camino;
    std::list<int> vertices;
    crearGrafo(g,color);
    g.devolver_vertices(vertices);

    while(opcion != 0){
        std::cout<<"================================================================================"<<std::endl;
        std::cout<<"   1) Buscar un camino en el grafo"<<std::endl;
        std::cout<<"   2) Cambiar colores de los vertices"<<std::endl;
        std::cout<<"   3) Editar arcos"<<std::endl;
        std::cout<<"   0) Salir de la prueba manual"<<std::endl;
        std::cout<<"   Ingrese Opcion: ";
        std::cin>>opcion;
        if(opcion == 1){
            std::cout<<"================================================================================"<<std::endl;
            std::cout<<"   Desde que vertice comenzar la busqueda? :  ";
            std::cin>>origen;
            std::cout<<"   Hasta que vertice buscar? :   ";
            std::cin>>destino;
            existeCamino(g,origen,destino,camino,color);
            camino.clear();
        } else if(opcion == 2){
            cargarColoresManual(color,vertices);
        } else if(opcion == 3){
            cargarArcosManual(g);
        }
    }
}

void cargarArcosDefault(Grafo<int> & g){
    g.agregar_arco(1,8,0);
    g.agregar_arco(1,3,0);
    g.agregar_arco(1,4,0);
    g.agregar_arco(4,1,0);
    g.agregar_arco(12,1,0);
    g.agregar_arco(12,5,0);
    g.agregar_arco(5,2,0);
    g.agregar_arco(1,6,0);
    g.agregar_arco(1,5,0);
    g.agregar_arco(6,7,0);
    g.agregar_arco(5,7,0);
    g.agregar_arco(2,7,0);
    g.agregar_arco(9,7,0);
    g.agregar_arco(7,10,0);
    g.agregar_arco(9,10,0);
    g.agregar_arco(3,9,0);
    g.agregar_arco(3,10,0);
    g.agregar_arco(10,11,0);
    g.agregar_arco(11,10,0);
    g.agregar_arco(11,3,0);
    g.agregar_arco(4,11,0);
    g.agregar_arco(12,11,0);
    g.agregar_arco(4,12,0);
    g.agregar_arco(6,12,0);
    g.agregar_arco(6,6,0);
    g.agregar_arco(2,8,0);
    g.agregar_arco(8,2,0);
    g.agregar_arco(5,6,0);
    g.agregar_arco(1,2,0);
    g.agregar_arco(3,4,0);
}

void aislarVertice(int vert,std::map<int,int> & c,Grafo<int> & g){
    std::list<Grafo<int>::Arco> ady;
    g.devolver_adyacentes(vert,ady);
    auto it = ady.begin();
    while(it != ady.end()){
        c[it->devolver_adyacente()] = rojo;
        it++;
    }
}

void pruebaPreCargada(){

    int origen = 1;
    int destino = 11;

    Grafo<int> test;
    std::map<int,int> colorinches;
    std::list<int> camino;
    std::list<int> vertices;

    cargarVertices(test,1,13);
    cargarArcosDefault(test);
    test.devolver_vertices(vertices);

    std::cout<<"================================================================================"<<std::endl;
    std::cout<<" Caso 0: existen origen["<<origen<<"] y destino["<<destino<<"], existe camino (no hay rojos)"<<std::endl;
    cargarColoresDefault(colorinches,vertices);
    existeCamino(test,origen,destino,camino,colorinches);
    camino.clear();

    std::cout<<"================================================================================"<<std::endl;
    std::cout<<" Caso 1: existen origen[1] y destino[13], no existe camino (no hay rojos)"<<std::endl;
    existeCamino(test,1,13,camino,colorinches);
    camino.clear();

    std::cout<<"================================================================================"<<std::endl;
    std::cout<<" Caso 2: existen origen["<<origen<<"] y destino["<<destino<<"], existe camino, destino es rojo"<<std::endl;
    colorinches[destino] = rojo;
    existeCamino(test,origen,destino,camino,colorinches);
    camino.clear();
    colorinches[destino] = blanco;

    std::cout<<"================================================================================"<<std::endl;
    std::cout<<" Caso 3: existen origen["<<origen<<"] y destino["<<destino<<"], origen es rojo"<<std::endl;
    colorinches[origen] = rojo;
    existeCamino(test,origen,destino,camino,colorinches);
    camino.clear();
    colorinches[origen] = blanco;

    std::cout<<"================================================================================"<<std::endl;
    std::cout<<" Caso 4: existen origen["<<origen<<"] y destino["<<destino<<"], existe camino"<<std::endl;
    std::cout<<"   |---: mod de 0) uno de ese camino se marcó rojo [7-Dfs]"<<std::endl;
    colorinches[7] = rojo;
    existeCamino(test,origen,destino,camino,colorinches);
    camino.clear();
    cargarColoresDefault(colorinches,vertices);

    std::cout<<"================================================================================"<<std::endl;
    std::cout<<" Caso 5: existen origen["<<origen<<"] y destino["<<destino<<"], no existe camino (a causa de rojos)"<<std::endl;
    aislarVertice(origen,colorinches,test);
    existeCamino(test,origen,destino,camino,colorinches);
    camino.clear();
    cargarColoresDefault(colorinches,vertices);

    std::cout<<"================================================================================"<<std::endl;
    std::cout<<" Caso 6: no existe origen[25]"<<std::endl;
    existeCamino(test,25,destino,camino,colorinches);
    camino.clear();

    std::cout<<"================================================================================"<<std::endl;
    std::cout<<" Caso 7: no existe destino[50]"<<std::endl;
    existeCamino(test,origen,50,camino,colorinches);
    camino.clear();
}