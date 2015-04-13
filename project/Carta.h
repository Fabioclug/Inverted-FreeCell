#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

#include <allegro.h>
#include <string>

using namespace std;

class Carta {
    int numero;  // Cofificado de 1 a 13
    int naipe;   // 1-Ouro  2-Espada  3-Copas  4-Paus
    BITMAP *img;  //imagem da carta
public:
    Carta();
    Carta(char, int, char *);
    int getCor();
    Carta &operator=(Carta);
    void setNumero(int);
    int getNumero();
    void setNaipe(int);
    int getNaipe();
    void setIMG(char *);
    void imprimeCarta(int, int, BITMAP*);
    void imprimeMeiaCarta(int, int, BITMAP*);
};
#endif // CARTA_H_INCLUDED
