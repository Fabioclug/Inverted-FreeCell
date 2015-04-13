#include "Carta.h"

Carta :: Carta() {
    numero = 0;
    naipe = 0;
}

Carta :: Carta(char n,int np,char *imagem) {
    numero = n;
    naipe = np;
    img = load_bitmap(imagem,NULL);
}

int Carta :: getCor() {
        int cor;
        if (naipe % 2 == 0)
            cor = 1;
        else cor = 0;
        return cor;
}

Carta &Carta :: operator=(Carta valor) {
    numero = valor.numero;
    naipe = valor.naipe;
    img = valor.img;
    return (*this);
}

void Carta :: setNumero(int n) {
    numero = n;
    }

int Carta :: getNumero() {
    return numero;
}

void Carta :: setNaipe(int np) {
    naipe = np;
}

int Carta :: getNaipe() {
    return naipe;
}

void Carta :: setIMG(char *imagem) {
    img = load_bitmap(imagem,NULL);
}

void Carta :: imprimeCarta(int x, int y,BITMAP *buffer) {
    blit(img, buffer, 0, 0, x, y, 72, 96);
}

void Carta :: imprimeMeiaCarta(int x, int y, BITMAP *buffer) {
    blit(img, buffer, 0, 0, x, y, 72, 30);
}
