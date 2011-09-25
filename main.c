/****************************************************************/
/*	Programa de jogo de porrinha				*/
/*	versao 0.3						*/
/*	data de início: 08/02/2003				*/
/* 	ultima atualizacao: 11/02/2003				*/
/****************************************************************/
/*	HISTORICO DE VERSOES					*/
/*								*/
/*	Versao 0.1: 08/02/2003					*/
/*		- inicio da programacao do jogo			*/
/*	Versao 0.2: 10/02/2003					*/
/*		- todas as funcoes do jogo feitas		*/
/*		- implementado debug (make debug && make)	*/
/*		- ja eh possivel jogar.				*/
/*	Versao 0.3: 11/02/2003					*/
/*		- implentado uma interface grafica		*/
/*		- corrigido alguns bugs pequenos		*/
/*              - melhorada a interligencia do computador       */
/*                nos palpites                                  */
/****************************************************************/

//definicoes do jogo porrinha
#include "porrinha.h"

main()
{    
    int njogad;
    char aux;
    LIMPAR_TELA();

    do {

	tela_inicial(); // mostra a tela inicial na linha 3
    
	njogad = num_jogadores(); //pega o numero de jogadores
    
	jogo(njogad); // início do jogo com numero de jogadores = njogad
	// fim do jogo
	
	do {
	    
    	    POS(20,5);
    	    printf("Deseja jogar novamente (S/N)? ");
	    scanf("%c", &aux);
	    aux = toupper(aux);

	} while ((aux != 'S') && (aux != 'N'));
	;;
	
	
    } while (aux == 'S');
    ;;
    
    LIMPAR_TELA();
    tela_saida(); // tela de saída
    
    return(0);

}
;;
