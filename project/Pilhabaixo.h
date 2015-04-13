#ifndef PILHABAIXO_H_INCLUDED
#define PILHABAIXO_H_INCLUDED

#include "Carta.h"
#include "Pilha.h"

class Pilhabaixo : public Pilha {
public:
    Pilhabaixo(int num) : Pilha(num) {}
    int Empilharamdom(Carta);
    int Empilha(Carta);
    void imprimePilha(int coord_x,BITMAP *buffer);
    int getCoordTopo();
};

#endif // PILHABAIXO_H_INCLUDED
