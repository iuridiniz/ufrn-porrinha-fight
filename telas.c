#include "boleanos.h"
#include "porrinha.h"

void tela_todos_os_palitos(struct jogad jogadores[], int num, int kz) 
{
    char *nomes[4];
    int i;
    
    nomes[0] = "Jogador 1";
    nomes[1] = "Bruno";
    nomes[2] = "Rodrigo";
    nomes[3] = "Iuri";
    
    JANELA1();    
    
    for (i = 0; i <= num; i++) {

        POS(4, i*19+5);
        printf("%s", nomes[i]);
        POS(5, i*19+5);
	
	if (kz == TRUE) { // mostrar palitos dos outros jogadores
	    printf("Tinha %d na mao", jogadores[i].palitos);
        } else {
	    
	    if (i == 0) {
		printf("Palitos na mao: %d", jogadores[0].palitos);
	    } else {
		printf("Palitos na mao: ?");
	    }
	    ;;
	    
	        	    
	}
	;;
   
	if (jogadores[i].palpite >= 0) {
	    POS(6, i*19+5);
	    printf("Palpite: %d", jogadores[i].palpite);
	}
		    
	desenha_palitos(8, i*19+5, jogadores[i].tpalitos);
    
    }
   
}

//desenha n palitos na posicao linha, coluna
void desenha_palitos(int x, int y, int n)
{
   int i, j;
   for(i=0; i<n; i++)
     {
	POS(x, y+i*2);
        printf("\x1B[4%cm ", VERMELHO);
	for(j=1; j<=TAMANHO_PALITO; j++)
	  {
	     POS(x+j, y+i*2);
             printf("\x1B[4%cm ", BRANCO);
	  }
	
     }
   printf("\x1B[4%cm ", AZUL);

     
   return;
}

void desenha_janela(int x1, int y1, int x2, int y2, char cor_fundo)
{
   int i, j;
   for(i=y1; i<=y2; i++) //bordas superior e inferior
     { 
	POS(x1, i);
        printf("\x1B[4%cm ", BRANCO);
	POS(x2, i);
        printf("\x1B[4%cm ", BRANCO);
     }
   for(i=x1; i<=x2; i++)//bordas esquerda e direita
     {
	POS(i, y1);
        printf("\x1B[4%cm  ", BRANCO);
	POS(i, y2);
        printf("\x1B[4%cm  ", BRANCO);
     }
   for(i=x1+1; i<=x2-1; i++)
     {
	for(j=y1+2; j<=y2-1; j++)
	  {
              POS(i, j);
              printf("\x1B[4%cm ", cor_fundo);
	  }	
     }   
}

void tela_inicial()
{
    int i = 4; // linha inicial
    
    JANELA1();
        
    POS(i++, 15);
    printf("                 PORRINHA  FIGHT                  ");    POS(i++,15);
    printf("                                                  ");    POS(i++,15);
    printf("                   COMPONENTES                    ");    POS(i++,15);
    printf("                 Allison da Costa                 ");    POS(i++,15);
    printf("                    Bruno Cruz                    ");    POS(i++,15);
    printf("                   Gabriel Dias                   ");    POS(i++,15);
    printf("                    Iuri Gomes                    ");    POS(i++,15);
    printf("                  Rafael Chacon                   ");    POS(i++,15);
    printf("                 Rodrigo Pereira                  ");    POS(i++,15);

    JANELA2();
    STATUS();     
}
;;

void tela_saida()
{

    LIMPAR_TELA();    
    desenha_janela(5,10,19,70, PRETO);
    POS(7,23);
    printf("OBRIGADO POR JOGAR PORRINHA FIGHT");
    POS(23,0);
    printf("\x1B[4%cm ", PRETO); //deixa o fundo preto


}
;;

void tela_rodada(int num)
{
    
    POS (25,62);
    printf("Rodada número [%2d]", num);
    
}	

void tela_num_jogadores(int *num)
{
    
    POS(18,5);
    printf("Digite o número de oponentes (de 1 a 3): "); scanf("%d", num);
    
    if (*num < 1 || *num > 3) {
	
	POS (25,1);
	printf("numero de jogadores invalido");
	tela_num_jogadores(num);
	
    }
    ;;
}
