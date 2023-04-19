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
        void aggVertice(int vertice);
        void elimVertice(int vertice);
        void modCosto(int origen, int destino, const C & costo);
        void aggArco(int origen, int destino, const C & costo);
        void elimArco(int origen, int destino);
        void vaciar();

        //posiblemente tenga que hacer un metodo que devuelva los vert a los que no les llega ningun arco para
        //poder hacer los D/BFS-forest por afuera

    private:
        std::map<int, std::map<int, C> > ady;
        int privCardinal;

};

#endif // GRAFO_H
