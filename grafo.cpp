#include "grafo.h"

#include<cassert>
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<utility>
#include "nodo.h"

grafo::grafo(){
    cardinal = 0;
}

grafo::~grafo(){
    //dtor
}

bool grafo::aggVert(){
    std::set<std::pair<int,int>> vacio;
    nodo nuevo(this->cardinal+1);
    this->vertices.push_back(nuevo);
    this->ady.push_back(vacio);
    this->cardinal++;
    return true;
}

bool grafo::aggVertRotulado(std::string rotulo){
    std::set<std::pair<int,int>> vacio;
    nodo nuevo(this->cardinal+1, rotulo);
    this->vertices.push_back(nuevo);
    this->ady.push_back(vacio);
    this->cardinal++;
    return true;
}

bool grafo::aggArcoCosto(int n1, int n2, int costo){ //arco simple con costo
    if(n1 > this->cardinal || n2 > this->cardinal) return false;
    this->ady[n1].insert(std::pair<int,int>(costo,n2));
    return true;
}

bool grafo::aggArco(int n1, int n2){ //arco simple sin costo
    return aggArcoCosto(n1,n2,0);
}

bool grafo::aggArcoDoble(int n1, int n2){ //arco ida y vuelta sin costo
    return (aggArco(n1,n2) && aggArco(n1,n2));
}

bool grafo::aggArcoDobleCosto(int n1, int n2, int costo){ //arco doble con costo
    return (aggArcoCosto(n1,n2,costo) && aggArcoCosto(n2,n1,costo));
}

std::set<std::pair<int,int>> grafo::adyacentes(int n){
    assert(n<=this->cardinal);
    return this->ady[n-1];
}

int grafo::cantVert() const{
    return this->cardinal;
}

nodo grafo::getNodo(int n) const{
    assert(n<=this->cardinal);
    return this->vertices[n-1]; //n-1 ya que indexa en 0 el primero
}
