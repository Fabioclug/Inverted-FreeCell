#include "Pilha.h"
#include "Carta.h"

Pilha :: Pilha(int n) { //m�todo construtor
    if (n > 0) {
    elementos = new Carta[n]; //Aloca n posi��es
    topo = -1; //Pilha vazia
    tamanho = n;
    }
}

bool Pilha :: cheia() {
    if (topo == (tamanho-1))
        return true;
    else return false;
}

bool Pilha :: vazia() {
    if (topo == -1)
        return true;
    else return false;
}

Carta Pilha :: Desempilha() { //m�todo para desempilhar
    Carta valor;
    if (vazia()==false) {
        valor = elementos[topo];
        topo--;
    }
    return valor;
}

