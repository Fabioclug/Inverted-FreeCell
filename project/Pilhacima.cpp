#include "Pilhacima.h"
#include "Pilha.h"
#include "Carta.h"

int Pilhacima :: Empilha(Carta valor) {  //método para empilhar
    if (topo == -1)
    {
        if (valor.getNumero() == 13)
        {
            topo++;
            elementos[topo] = valor;
            return 1;
        }
        else return 0;
    }
    else
    {
        if ((cheia() == false ) && (valor.getNaipe() == elementos[topo].getNaipe()) && (valor.getNumero() == elementos[topo].getNumero() - 1))   //Evita o Stack Overflow, verifica se a carta é de cor diferente e a próxima na sequência
        {
            topo++;
            elementos[topo] = valor;
            return 1;
        }
        else return 0;
    }
}

void Pilhacima :: imprimePilha(int coord_x,BITMAP *buffer) {
    if (!vazia())
        elementos[topo].imprimeCarta(coord_x,50,buffer);
}
