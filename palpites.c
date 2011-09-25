/* contem as funcoes para gerar o palpite de todos os jogadores */

#include "boleanos.h"
#include "porrinha.h"

void palpites (struct jogad jogador[], int num, int ordem[], int total)
{
    int i,j,z;
    int palpites[num+1];
    int palpite;
    int erro;
    
    for ( i = 0; i <= num; i++ )
	jogador[i].palpite = -1;
    ;;
    
    tela_todos_os_palitos(jogador, num, FALSE);
    STATUS();
    
    for (i = 0; i <= num; i++) {
	
	JANELA2();
	if (ordem[i]  ==  JOG1 ) { // vez do jogador humano.
	    z = 18;
	    
	    POS (z++, 5);
	    printf("Jogador, voc� tem [%d] palitos na m�o", jogador[0].palitos);
	    
	    if (jogador[0].palitos == jogador[0].tpalitos) {
		POS (z++, 5);
		printf("Voc� pode jogar at� [%2d] palitos.", total);
	
	    } else {
		POS (z++, 5);
		printf("Ent�o, tirando os palitos que voc� tem, s� pode haver at� [%2d] palitos",
		        total - (jogador[0].tpalitos - jogador[0].palitos)  );
		;;
		POS (z++, 5);
		printf("no jogo, mas voc� pode jogar at� %d palitos se quiser blefar.", total);
	
	    }
	    ;;
	    
    	    POS (z++, 5);
	    printf("Quantos palitos voc� acha que vai dar? "); scanf("%d", &palpite);
	    
	    palpite_invalido( &palpite, &total); // teste se o palpite � v�lido
	    
	    if ( i != 0) { //entra somente se ninguem apostou.
		
		erro = TRUE;
		
		while ( erro == TRUE ) {
		    
		    for ( j = 0 ; j < i; j++) {
		
			if (palpites[j] == palpite) { // alguem anterior, ja fez esse palpite?
			
			    erro = TRUE; // se sim, continua acusando erro.
			    break; // sai do for
			
			} else {
			
			    erro = FALSE; // nao achou palpites iguais, nao da mais erro.
			
			}
			;;
		
		    }
		    ;;
		
		    if (erro == TRUE) { // pede um novo palpite
			JANELA2();
			z=18;
			STATUS();
			printf("Algum jogador j� apostou esse n�mero");
			POS(z++,5);
			printf("Quantos palitos voce acha que vai dar? "); scanf("%d", &palpite);
		    }
		    ;;
		}
		;;
	    }
	    ;;	
	    
	    jogador[0].palpite = palpite; //palpite verificado quanto a repiticao
	    palpites[i] = palpite;  
	    POS(z++,5);
	    printf ( "Voce chutou [%2d] palitos", palpite);
	    
	} else {  //jogador nao-humano.
	    
	    // gera o palpite por n�meros aleatorios.
	    // inteligencia desse m�todo 0.
	    
	    palpite = aleatorio (total - jogador[i].palitos) + jogador[i].palitos;
	    
	    if ( i != 0) { //alguem ja apostou

		erro = TRUE;

		while ( erro == TRUE ) {
		    
		    for ( j = 0 ; j < i; j++) {
		
			if (palpites[j] == palpite){// alguem anterior, ja fez esse palpite?
			
			    erro = TRUE; // se sim, continua acusando erro.
			    break; //sai do for
			
			} else {
			
			    erro = FALSE; // nao achou palpites iguais, nao da mais erro.
			
			}
			;;
		
		    }
		    ;;
		
		    if (erro == TRUE)  // gerar um novo palpite
			palpite = aleatorio (total - jogador[i].palitos) + jogador[i].palitos;
		    ;;
		}
		;;
	    
	    }	    
	    ;;
	    
	    // papite ja verificado quanto a repeticao eh atribuido ao jogador
	    palpites[i] = palpite; 
	    jogador[ ordem[i] ].palpite = palpite;
	    
	}
	;;
    	tela_todos_os_palitos(jogador, num, FALSE);

    }
    ;;
}
;;

void palpite_invalido(int *num, int *total) //exemplo de while com funcao recursiva

{

    if (  *num > *total || *num < 0 ) {
		JANELA2();
		STATUS();
		printf("Palpite inv�lido");
		POS(18,5);
		printf("Quantos palitos voc� acha que vai dar? ");
		scanf("%d", num);
		palpite_invalido(num, total);
    }
    		
}

