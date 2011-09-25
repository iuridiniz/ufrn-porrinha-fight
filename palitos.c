#include "porrinha.h"

int pegue_palitos(struct jogad jogador[] , int num, int rodadas, int total_palitos )
{

    int i;
    int palitos;
    
    do { // pegar a quantidade de palitos do jogador humano
	
	// posicao inicial das mensagens
	i=18;
	JANELA2();
	
	POS (i++,5);
	printf ("Você possui [%d] palitos, há [%2d] palitos em jogo", jogador[0].tpalitos, total_palitos);
	
	POS (i++,5);
	printf ("Jogador, digite quantos palitos quer jogar, para sair [-1]: "); 
	
	// muda palitos antes do condicional,
	// isto previne sair do programa quando palitos == -1
	scanf("%d", &palitos);

	// caso se escolha -1, isto eh sair do jogo
	if ( palitos == -1) { 
	    tela_saida(); 	//mostra tela de saída
	    exit(0); 		//saí do jogo
	}	
	
	if ( (palitos < 0) || ( palitos > jogador[0].tpalitos) ) {
	    STATUS();
	    printf("Quantidade inválida de palitos");
	
	}
	;;

	if ((rodadas == 1) && (palitos == 0)) {
	    STATUS();
	    printf("Na primeira rodada a quantidade de palitos deve ser maior que 0");
	    palitos= -1; // para não sair no laço pois continue não funcionou
	}
	;;
	
    } while ( (palitos < 0) || ( palitos > jogador[0].tpalitos) );
    ;;
    
    jogador[0].palitos = palitos;    
    
    for (i = 1; i < num + 1; i++) {
	
	// gera um numero de palitos a jogar por numeros aleatorios 
	// inteligencia=0.
	jogador[i].palitos = aleatorio(jogador[i].tpalitos);
	
	
	if ((rodadas == 1) && (jogador[i].palitos == 0)) 
	    i--; // decrementa i para permanecer no mesmo jogador
	;;

    }
    ;;
    
    palitos = 0;
        
    for (i = 0; i <= num ; i++) 
	palitos += jogador[i].palitos; //total de palitos
    ;;    

    return(palitos);
    
}
;;
