#ifndef PILHACIMA_H_INCLUDED
#define PILHACIMA_H_INCLUDED

#include "Carta.h"
#include "Pilha.h"

class Pilhacima : public Pilha {
public:
    Pilhacima(int num) : Pilha(num) {}
    int Empilha(Carta);
    void imprimePilha(int coord_x, BITMAP *buffer);

};

#endif // PILHACIMA_H_INCLUDED
