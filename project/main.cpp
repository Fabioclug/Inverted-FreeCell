#include <allegro.h>
#include "Carta.h"
#include "Pilha.h"
#include "Pilhabaixo.h"
#include "Pilhacima.h"
#include <time.h>

volatile int FecharJogo = FALSE;

void BotaoFechar()
{
    FecharJogo = TRUE;
}

inline void init()
{
    allegro_init();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 650, 0, 0);

    install_timer();
    install_keyboard();
    install_mouse();
}

inline void deinit()
{
    clear_keybuf();
    allegro_exit();
}

void ImprimeJogo(BITMAP *buffer,Carta celula1,Carta celula2,Carta celula3,Carta celula4,Pilhacima P1,Pilhacima P2,Pilhacima P3,Pilhacima P4,Pilhabaixo P5,Pilhabaixo P6,Pilhabaixo P7,Pilhabaixo P8,Pilhabaixo P9,Pilhabaixo P10,Pilhabaixo P11,Pilhabaixo P12)
{
    BITMAP *rei = load_bitmap("./bitmaps/rei.bmp", NULL);
    clear_to_color( buffer, makecol(0, 64, 0) );
    rect(buffer, 46, 46, 125, 149, makecol(112,146,190));
    rect(buffer, 146, 46, 225, 149, makecol(112,146,190));
    rect(buffer, 246, 46, 325, 149, makecol(112,146,190));
    rect(buffer, 346, 46, 425, 149, makecol(112,146,190));
    blit(rei,buffer, 0,0,450,46,76,76);
    rect(buffer, 546, 46, 625, 149, makecol(112,146,190));
    rect(buffer, 646, 46, 725, 149, makecol(112,146,190));
    rect(buffer, 746, 46, 825, 149, makecol(112,146,190));
    rect(buffer, 846, 46, 925, 149, makecol(112,146,190));
    if (celula1.getNumero()!=0)
        celula1.imprimeCarta(50,50,buffer);
    if (celula2.getNumero()!=0)
        celula2.imprimeCarta(150,50,buffer);
    if (celula3.getNumero()!=0)
        celula3.imprimeCarta(250,50,buffer);
    if (celula4.getNumero()!=0)
        celula4.imprimeCarta(350,50,buffer);
    P1.imprimePilha(550,buffer);
    P2.imprimePilha(650,buffer);
    P3.imprimePilha(750,buffer);
    P4.imprimePilha(850,buffer);
    P5.imprimePilha(100,buffer);
    P6.imprimePilha(200,buffer);
    P7.imprimePilha(300,buffer);
    P8.imprimePilha(400,buffer);
    P9.imprimePilha(500,buffer);
    P10.imprimePilha(600,buffer);
    P11.imprimePilha(700,buffer);
    P12.imprimePilha(800,buffer);
    textprintf_ex(buffer, font, 200, 640, makecol(255,255,255), -1, "Controles: botao esquerdo para desempilhar, direito para empilhar");
}

void Ganhou(Pilhacima P1,Pilhacima P2,Pilhacima P3,Pilhacima P4, BITMAP *buffer) {
    if (P1.cheia() && P2.cheia() && P3.cheia() && P4.cheia()) {
        BITMAP *ganhou = load_bitmap("./bitmaps/ganhou.bmp", NULL);
        clear_to_color( buffer, makecol(0, 64, 0) );
        blit(ganhou,buffer,0,0,0,180,1000,270);
        P1.imprimePilha(550,buffer);
        P2.imprimePilha(650,buffer);
        P3.imprimePilha(750,buffer);
        P4.imprimePilha(850,buffer);
        rect(buffer, 546, 46, 625, 149, makecol(112,146,190));
        rect(buffer, 646, 46, 725, 149, makecol(112,146,190));
        rect(buffer, 746, 46, 825, 149, makecol(112,146,190));
        rect(buffer, 846, 46, 925, 149, makecol(112,146,190));
        blit(buffer,screen,0,0,0,0,1000,650);
    }
}

int main() {
    init();
    Carta *deck;
    deck = new Carta[52];
    Carta aux,celula1,celula2,celula3,celula4;
    int n,np,i=0,j,controle=0,deucerto=0,click=0;
    char imagem[10];
    Pilhacima P1(13),P2(13),P3(13),P4(13);
    Pilhabaixo P5(13),P6(13),P7(13),P8(13),P9(13),P10(13),P11(13),P12(13);
    BITMAP *buffer = create_bitmap(1000,650); //Double buffering para evitar que a tela pisque a cada jogada
    srand(time(NULL));

    for (np = 1;np<=4;np++){
        for (n=1;n<=13;n++) {
            sprintf(imagem, "./bitmaps/%d.bmp", i+1);
            deck[i].setNumero(n);
            deck[i].setNaipe(np);
            deck[i].setIMG(imagem);
            i++;
        }
    }

    for (i=0; i < 52; i++) {   // função para embaralhar o deck

        //sorteia um índice
        j = rand()%52;

        //troca o conteúdo dos índices i e j do vetor
        aux = deck[i];
        deck[i] = deck[j];
        deck[j] = aux;
    }

    i=0;
    while (i<52)
    {
        P5.Empilharamdom(deck[i]);
        i++;
        P6.Empilharamdom(deck[i]);
        i++;
        P7.Empilharamdom(deck[i]);
        i++;
        P8.Empilharamdom(deck[i]);
        i++;

        if (i<52)
        {
            P9.Empilharamdom(deck[i]);
            i++;
            P10.Empilharamdom(deck[i]);
            i++;
            P11.Empilharamdom(deck[i]);
            i++;
            P12.Empilharamdom(deck[i]);
            i++;
        }
    }

    delete [] deck;

    ImprimeJogo(buffer,celula1,celula2,celula3,celula4,P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12);
    blit(buffer,screen,0,0,0,0,1000,650);

    LOCK_FUNCTION(BotaoFechar);
    show_mouse(screen);
    set_close_button_callback(BotaoFechar);
    set_window_title("FreeCell");

    aux.setNumero(0);
    while (!FecharJogo )
    {
        if (aux.getNumero()==0)
        {
            if (mouse_b & 1 && mouse_x >=46 && mouse_x <= 125 && mouse_y >=46 && mouse_y <=149 && celula1.getNumero() != 0)
            {
                controle=1;
                aux = celula1;
                celula1.setNumero(0);
                click++;
            }
            else
            {
                if (mouse_b & 1 && mouse_x >=146 && mouse_x <= 225 && mouse_y >=46 && mouse_y <=149 && celula2.getNumero() != 0)
                {
                    controle=2;
                    aux = celula2;
                    celula2.setNumero(0);
                    click++;
                }
                else
                {
                    if (mouse_b & 1 && mouse_x >=246 && mouse_x <= 325 && mouse_y >=46 && mouse_y <=149 && celula3.getNumero() != 0)
                    {
                        controle=3;
                        aux = celula3;
                        celula3.setNumero(0);
                        click++;
                    }
                    else
                    {
                        if (mouse_b & 1 && mouse_x >=346 && mouse_x <= 425 && mouse_y >=46 && mouse_y <=149 && celula4.getNumero() != 0)
                        {
                            controle=4;
                            aux = celula4;
                            celula4.setNumero(0);
                            click++;
                        }
                        else
                        {
                            if (mouse_b & 1 && mouse_x >= 100 && mouse_x<=172 && P5.getCoordTopo()!=0 && mouse_y >=P5.getCoordTopo() && mouse_y <= (P5.getCoordTopo()+96))
                            {
                                controle = 5;
                                aux = P5.Desempilha();
                                click++;
                            }
                            else
                            {
                                if (mouse_b & 1 && mouse_x >= 200 && mouse_x<=272 && P6.getCoordTopo()!=0 && mouse_y >=P6.getCoordTopo() && mouse_y <= (P6.getCoordTopo()+96))
                                {
                                    controle=6;
                                    aux = P6.Desempilha();
                                    click++;
                                }
                                else
                                {
                                    if (mouse_b & 1 && mouse_x >= 300 && mouse_x<=372 && P7.getCoordTopo()!=0 && mouse_y >=P7.getCoordTopo() && mouse_y <= (P7.getCoordTopo()+96))
                                    {
                                        controle=7;
                                        aux = P7.Desempilha();
                                        click++;
                                    }
                                    else
                                    {
                                        if (mouse_b & 1 && mouse_x >= 400 && mouse_x<=472 && P8.getCoordTopo()!=0 && mouse_y >=P8.getCoordTopo() && mouse_y <= (P8.getCoordTopo()+96))
                                        {
                                            controle=8;
                                            aux = P8.Desempilha();
                                            click++;
                                        }
                                        else
                                        {
                                            if (mouse_b & 1 && mouse_x >= 500 && mouse_x<=572 && P9.getCoordTopo()!=0 && mouse_y >=P9.getCoordTopo() && mouse_y <= (P9.getCoordTopo()+96))
                                            {
                                                controle=9;
                                                aux = P9.Desempilha();
                                                click++;
                                            }
                                            else
                                            {
                                                if (mouse_b & 1 && mouse_x >= 600 && mouse_x<=672 && P10.getCoordTopo()!=0 && mouse_y >=P10.getCoordTopo() && mouse_y <= (P10.getCoordTopo()+96))
                                                {
                                                    controle=10;
                                                    aux = P10.Desempilha();
                                                    click++;
                                                }
                                                else
                                                {
                                                    if (mouse_b & 1 && mouse_x >= 700 && mouse_x<=772 && P11.getCoordTopo()!=0 && mouse_y >=P11.getCoordTopo() && mouse_y <= (P11.getCoordTopo()+96))
                                                    {
                                                        controle=11;
                                                        aux = P11.Desempilha();
                                                        click++;
                                                    }
                                                    else
                                                    {
                                                        if (mouse_b & 1 && mouse_x >= 800 && mouse_x<=872 && P12.getCoordTopo()!=0 && mouse_y >=P12.getCoordTopo() && mouse_y <= (P12.getCoordTopo()+96))
                                                        {
                                                            controle=12;
                                                            aux = P12.Desempilha();
                                                            click++;
                                                        }
                                                        else
                                                            click = 0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

        }

        else
        {
            if (click==1 && mouse_b & 2)
            {
                click=0;
                if (mouse_x >=46 && mouse_x <= 125 && mouse_y >=46 && mouse_y <=149 && celula1.getNumero() == 0)
                {
                    celula1 = aux;
                    deucerto=1;
                }
                else
                {
                    if (mouse_x >=146 && mouse_x <= 225 && mouse_y >=46 && mouse_y <=149 && celula2.getNumero() == 0)
                    {
                        celula2 = aux;
                        deucerto=1;
                    }
                    else
                    {
                        if (mouse_x >=246 && mouse_x <= 325 && mouse_y >=46 && mouse_y <=149 && celula3.getNumero() == 0)
                        {
                            celula3 = aux;
                            deucerto=1;
                        }
                        else
                        {
                            if (mouse_x >=346 && mouse_x <= 425 && mouse_y >=46 && mouse_y <=149 && celula4.getNumero() == 0)
                            {
                                celula4 = aux;
                                deucerto=1;
                            }
                            else
                            {
                                if (mouse_x >=546 && mouse_x <= 625 && mouse_y >=46 && mouse_y <=149)
                                {
                                    deucerto = P1.Empilha(aux);
                                }
                                else
                                {
                                    if (mouse_x >=646 && mouse_x <= 725 && mouse_y >=46 && mouse_y <=149)
                                    {
                                        deucerto = P2.Empilha(aux);
                                    }
                                    else
                                    {
                                        if (mouse_x >=746 && mouse_x <= 825 && mouse_y >=46 && mouse_y <=149)
                                        {
                                            deucerto = P3.Empilha(aux);
                                        }
                                        else
                                        {
                                            if (mouse_x >=846 && mouse_x <= 925 && mouse_y >=46 && mouse_y <=149)
                                            {
                                                deucerto = P4.Empilha(aux);
                                            }
                                            else
                                            {
                                                if (mouse_x >=100 && mouse_x<=172 && mouse_y>=180 && mouse_y <= (P5.getCoordTopo()+96))
                                                    deucerto = P5.Empilha(aux);
                                                else
                                                {
                                                    if (mouse_x >=200 && mouse_x<=272 && mouse_y>=180 && mouse_y <= (P6.getCoordTopo()+96))
                                                        deucerto = P6.Empilha(aux);
                                                    else
                                                    {
                                                        if (mouse_x >=300 && mouse_x<=372 && mouse_y>=180 && mouse_y <= (P7.getCoordTopo()+96))
                                                            deucerto = P7.Empilha(aux);
                                                        else
                                                        {
                                                            if (mouse_x >=400 && mouse_x<=472 && mouse_y>=180 && mouse_y <= (P8.getCoordTopo()+96))
                                                                deucerto = P8.Empilha(aux);
                                                            else
                                                            {
                                                                if (mouse_x >=500 && mouse_x<=572 && mouse_y>=180 && mouse_y <= (P9.getCoordTopo()+96))
                                                                    deucerto = P9.Empilha(aux);
                                                                else
                                                                {
                                                                    if (mouse_x >=600 && mouse_x<=672 && mouse_y>=180 && mouse_y <= (P10.getCoordTopo()+96))
                                                                        deucerto = P10.Empilha(aux);
                                                                    else
                                                                    {
                                                                        if (mouse_x >=700 && mouse_x<=772 && mouse_y>=180 && mouse_y <= (P11.getCoordTopo()+96))
                                                                            deucerto = P11.Empilha(aux);
                                                                        else
                                                                        {
                                                                            if (mouse_x >=800 && mouse_x<=872 && mouse_y>=180 && mouse_y <= (P12.getCoordTopo()+96))
                                                                            {
                                                                                deucerto = P12.Empilha(aux);
                                                                            }
                                                                            else
                                                                            {
                                                                                deucerto = 0;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (deucerto == 0) {
                    switch (controle)
                    {
                    case 1:
                        celula1 = aux;
                        break;
                    case 2:
                        celula2 = aux;
                        break;
                    case 3:
                        celula3 = aux;
                        break;
                    case 4:
                        celula4 = aux;
                        break;
                    case 5:
                        P5.Empilharamdom(aux);
                        break;
                    case 6:
                        P6.Empilharamdom(aux);
                        break;
                    case 7:
                        P7.Empilharamdom(aux);
                        break;
                    case 8:
                        P8.Empilharamdom(aux);
                        break;
                    case 9:
                        P9.Empilharamdom(aux);
                        break;
                    case 10:
                        P10.Empilharamdom(aux);
                        break;
                    case 11:
                        P11.Empilharamdom(aux);
                        break;
                    case 12:
                        P12.Empilharamdom(aux);
                        break;
                    }
                }
                aux.setNumero(0);
                ImprimeJogo(buffer,celula1,celula2,celula3,celula4,P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12);
                blit(buffer,screen,0,0,0,0,1000,650);
            }
        }
        Ganhou(P1,P2,P3,P4,buffer);

    }


    deinit();
    return 0;
}
END_OF_MAIN()
