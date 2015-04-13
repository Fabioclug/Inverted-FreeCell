#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "Carta.h"
class Pilha {
protected:
    Carta *elementos;
    int topo;
    int tamanho;
public:
    Pilha(int);
    bool cheia();
    bool vazia();
    virtual int Empilha(Carta valor)=0;
    virtual void imprimePilha(int coord_x,BITMAP* buffer)=0;
    Carta Desempilha();

};

#endif // PILHA_H_INCLUDED
