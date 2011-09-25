/* contem todo o jogo em si */

#include "boleanos.h"
#include "porrinha.h"
#include <stdlib.h>

void jogo( int num) 
{
    
    int fim_de_jogo = FALSE;
    int rodadas = 0;
    int total_palitos = (num+1) * 3; 
    
    int i;
    int ganhador;
    int palitos_rodada;
    int ganhador_rodada = -1;
    int ordem[] = {JOG1,JOG2,JOG3,JOG4};
  
    // alocacao dinamica de uma matriz (de ponteiros para) strings 
    char *nomes[4]; 
    
    struct jogad jogadores[num+1];
    
    for (i = 0 ; i <= num; i++) {
	jogadores[i].tpalitos = 3;
	jogadores[i].palitos  = 0;
	jogadores[i].palpite  = -1;	
    }
    ;;

    nomes[0] = "Jogador 1";
    nomes[1] = "Bruno";
    nomes[2] = "Rodrigo";
    nomes[3] = "Iuri";
    
    // a matriz de strings
    tela_todos_os_palitos (jogadores, num, FALSE);
       
    rodadas = 1;

    STATUS(); // limpar barra de estatus
    tela_rodada(rodadas);

    while (fim_de_jogo == FALSE ) {
	
	palitos_rodada = pegue_palitos(jogadores, num, rodadas, total_palitos);

#ifdef __DEBUG__
	
// DEBUG
	POS(24,2);
	printf (">>>>>>>>  CHUTE CORRETO %d <<<<<<<<<<<", palitos_rodada);
#endif	


	// fazer as apostas
	palpites(jogadores, num, ordem, total_palitos);
	
	// fazer ganhadores e mudar a ordenacao da matriz de ordem
	
	JANELA2(); // redenha janela
	
	STATUS(); // coloca o cursor na posicao de STATUS e limpa esta
	printf("Jogada correta: [%2d]", palitos_rodada);
	
	// verifica se alguem ganhou e faz as mudacao na ordem dos jogadores.
		
	if (alguem_ganhou(jogadores, ordem, num, palitos_rodada, &ganhador) == TRUE){
	    
	    //diminii o total de palitos em jogo
	    total_palitos--;
	    
	    if (ganhador)
	       printf(", %s acertou!!!", nomes[ganhador]);
	    else
	       printf(", Você acertou!!!");
	                   
	    if (jogadores[ganhador].tpalitos == 0){

	      fim_de_jogo = TRUE;

	    }

	} else {
	    
	    printf(", Ninguem acertou...");
	    
	}

	// atualiza a rodada 
	tela_rodada(rodadas+1);
	// resenha palitos
	tela_todos_os_palitos (jogadores, num, TRUE);
	// deve-se encrentar rodada depois de redesenhar a tela.
	rodadas++;
	
    }	
    
    JANELA2();

    i = 18;
    POS(i++,5);
    	    
    if (ganhador)
	printf("%s Ganhou o JOGO!!!", nomes[ganhador]);
    else
	printf("Você GANHOU!!!");
    ;;
    POS(i++,5);
    printf("O jogo acabou");
    
}

int alguem_ganhou(struct jogad jogadores[], int ordem[], int num, int palitos_rodada, int *ganhador){
  int i, j, jog;
  for(i=0; i<=num; i++){
    if (jogadores[i].palpite == palitos_rodada){
    
      //decrementa o numero de palitos do vencedor
      jogadores[i].tpalitos--;
      
      //ordena a matriz de ordem; que venceu comeca
      jog = i;
      for (j=0; j<=num; j++){
        ordem[j] = jog;
	jog++;
	if (jog>num)
	 jog = 0;
      }
      ;;
      
      //ganhador fica com o numero do vencedor
      *ganhador = i;
      return(TRUE);
    }
  }
  
  //Ordena a matriz de ordem, caso ninguem tenha ganhado
  jog = ordem[1];

  for (j=0; j<=num; j++){
    ordem[j] = jog;
    jog++;
    if (jog>num)
	jog = 0;
    }
  ;;

  return(FALSE);
}

