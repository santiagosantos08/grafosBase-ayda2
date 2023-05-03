//
// Created by santiago on 5/3/23.
//

#ifndef GRAFOSAYDA_GRAFO_H
#define GRAFOSAYDA_GRAFO_H
#include <list>
#include <set>
#include <map>

template <typename C> class Grafo{

public:
    class Arco{
    public:
        Arco();
        Arco(int adyacente, const C & costo);
        ~Arco();
        int devolver_adyacente() const;
        const C & devolver_costo() const;
    private:
        int vertice;
        C privCosto;
        bool vacio;
    };

    Grafo();
    //Grafo(const Grafo & otroGrafo);
    ~Grafo();
    Grafo & operator = (const Grafo & otroGrafo);

    bool esta_vacio() const; //esta_vacio
    int devolver_longitud() const; //devolver_longitud
    bool existe_vertice(int vertice) const;
    bool existe_arco(int origen, int destino) const;
    const C & costo_arco(int origen, int destino) const;
    void devolver_vertices(std::list<int> & vertices) const;
    void devolver_adyacentes(int origen, std::list<Arco> & adyacentes) const;
    void agregar_vertice(int vertice);
    void eliminar_vertice(int vertice);
    void modificar_costo_arco(int origen, int destino, const C & costo);
    void agregar_arco(int origen, int destino, const C & costo);
    void eliminar_arco(int origen, int destino);
    void dfs(int origen, std::set<int> & visitados, std::list<int> recorrido) const;
    void dfsForest(std::list<int> & recorridos) const;
    void vaciar();

    //funcion de agregar deberian ser boolean para notificar si se pudo agregar o no, asi ahorras tirar un assert o dejarlo sin hacer y sin notificar 8como ahora


private:
    std::map<int, std::map<int, C> > ady;
    int privCardinal;

};

#endif //GRAFOSAYDA_GRAFO_H
