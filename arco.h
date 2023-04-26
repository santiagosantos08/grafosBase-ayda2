#ifndef ARCO_H
#define ARCO_H

template <typename C> class arco{
    public:
        arco();
        arco(int adyacente, const C & costo);
        ~arco();
        int adyacente() const;
        const C & costo() const;
    private:
        int vertice;
        C privCosto;
        bool vacio;
};

#endif // ARCO_H
