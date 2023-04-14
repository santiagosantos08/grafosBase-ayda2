#ifndef GRAFO_H
#define GRAFO_H

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<utility>
#include "nodo.h"
//ahora mismo nodo solo acepta un string de rotulo pero la idea
//es hacer la clase para un generico y que acepte cualquier cosa

class grafo{
    public:
        grafo();
        virtual ~grafo();
        bool aggVert(); //no se pasa el num ya que siempre se agrega como card+1
        bool aggVertRotulado(std::string rotulo);

        //agregar funcionalidad para eliminar un vertice x

        //-----------NOTAS-----------
        //deberian ser clases diferentes, dirigido con costo como base
        //y despues otra que limite a llamar a arcoDoble para sin dirigir
        //y lo mismo con los llamados a x_Costo
        //nodo tranquilamente podría ser otro std par pero queda muy complicado el acceso..
        //revisar, además llevaría ams trabajo implementar el generico supongo ? no revisé mucho como funciona
        //son todas bool para notificar si se realizó o no, ya que se puede dar que un vertice ya exista o un arco se quiera agregar a un vert que no existe
        //---------------------------

        //n1 siempre es origen y n2 siempre es destino

        //para usar como dirigido sin costo
        bool aggArco(int n1, int n2);
        //para usar como dirigido con costo
        bool aggArcoCosto(int n1, int n2, int costo);
        //para usar como no dirigido sin costo
        bool aggArcoDoble(int n1, int n2);
        //para usar con costo
        bool aggArcoDobleCosto(int n1, int n2, int costo); //si se quieren usar costo diferentes p idea y vuelta se llama dos veces a aggArcoCosto
        int cantVert() const;
        std::set<std::pair<int,int>> adyacentes(int n);
        nodo getNodo(int n) const;

    private:
        std::vector<std::set<std::pair<int,int>>> ady;
        //la entrada al vector con .at(x) es el vert al cual le quiero chekear los adyacentes
        //despues en el set estan los pares con los adyacentes y su respectivo costo de ir hasta ahí

        std::vector<nodo> vertices; //esto es solo para tener facil acceso a los rotulos, guardo los nodos ahi para no tener que buscarlos despues
        //ya que en adyacentes cada entrada al vector no es el nodo en si sino el nro y luego tengo los adyacentes además dentro de un pair

        int cardinal;
};

#endif // GRAFO_H
