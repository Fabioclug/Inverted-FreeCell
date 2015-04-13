#include "Pilhabaixo.h"
#include "Pilha.h"
#include "Carta.h"

int Pilhabaixo :: Empilharamdom(Carta valor) {
    if (cheia() == false) {
        topo++;
        elementos[topo] = valor;
        return 1;
    }
    else return 0;
}

int Pilhabaixo :: Empilha(Carta valor) {   //m�todo para empilhar
    if (topo == -1) {  // Se a pilha est� vazia,n�o tem restri��o
        topo++;
        elementos[topo] = valor;
        return 1;
    }
    else
    {
        if ((cheia() == false) && (valor.getCor() != elementos[topo].getCor()) && (valor.getNumero() == elementos[topo].getNumero() + 1)) {  //Evita o Stack Overflow, verifica se a carta � de cor diferente e a pr�xima na sequ�ncia
            topo++;
            elementos[topo] = valor;
            return 1;
        }
        else return 0;
    }
}

void Pilhabaixo :: imprimePilha(int coord_x,BITMAP *buffer) {
    int i,coord_y = 180;
    if (!vazia()) {
        for (i =0; i < topo; i++) {
            elementos[i].imprimeMeiaCarta(coord_x,coord_y,buffer);
            coord_y+=30;
        }
        elementos[topo].imprimeCarta(coord_x,coord_y,buffer);
    }
    else
        rect(buffer, coord_x, 180, coord_x + 72, 276, makecol(112,146,190));
}

int Pilhabaixo :: getCoordTopo() {
    int i,coord_y=180;
    if (!vazia()) {
        for (i =0; i < topo; i++) {
            coord_y+=30;
        }
        return coord_y;
    }
    else return coord_y;
}
