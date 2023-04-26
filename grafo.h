#ifndef GRAFO_H
#define GRAFO_H

#include "arco.h"
#include <list>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>

template <typename C> class grafo{

    public:
        grafo();
        //grafo(const grafo & otroGrafo);
        ~grafo();
        grafo & operator = (const grafo & otroGrafo);

        bool vacio() const; //esta_vacio
        int cardinal() const; //devolver_longitud
        bool existeVertice(int vertice) const;
        bool existeArco(int origen, int destino) const;
        const C & costoArco(int origen, int destino) const;
        void listarVertices(std::list<int> & vertices) const;
        void adyacentesA(int origen, std::list<arco<C>> & adyacentes) const;
        void adyacentesAsoloInt(int origen, std::list<int> & adyacentes) const;
        //void adyacentesAset(int origen, std::set<arco<C>> & adyacentes) const;
        void aggVertice(int vertice);
        void elimVertice(int vertice);
        void modCosto(int origen, int destino, const C & costo);
        void aggArco(int origen, int destino, const C & costo);
        void elimArco(int origen, int destino);
        void dfs(int origen, std::set<int> & visitados, std::list<int> recorrido) const;
        void dfsForest(std::list<int> & recorridos) const;
        void vaciar();


    private:
        std::map<int, std::map<int, C> > ady;
        int privCardinal;

};

#endif // GRAFO_H
