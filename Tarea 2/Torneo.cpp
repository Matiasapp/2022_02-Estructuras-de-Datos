#include <iostream>
#include "Equipo.hpp"
using namespace std;

struct tNodoArbolBin{
    Equipo info;
    tNodoArbolBin* izq;
    tNodoArbolBin* der;
};

class arbolBin {
    private:
        tNodoArbolBin* raiz;
        int nElems;

    public:
        arbolBin(){
            raiz=nullptr;
        }
        
        bool crear_torneo(Equipo* equipos, int n){
            int grado = log2(n);
            int gradoactual=0;
            tNodoArbolBin *NodoRaiz = new tNodoArbolBin;
            raiz = NodoRaiz;
            tNodoArbolBin *tNodoNuevo = new tNodoArbolBin;
            


            tNodoNuevo->izq=tNodoNuevo->der=nullptr;
            
        }
        void imprimir_bracket(){

        }
        void avanzar_ronda(){

        }
        




};