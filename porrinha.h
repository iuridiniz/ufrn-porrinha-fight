int zz; // uma variavel global para a barra de status

// a estrutura da ma matriz jogadores

struct jogad {
	int tpalitos;
	int palitos;
	int palpite;
};


// todas as funcoes
void tela_inicial();
void tela_saida();
void tela_rodada(int numero_da_rodada);
void tela_num_jogadores(int *num_de_jogadores);
void tela_todos_os_palitos (struct jogad jogadores[], int num_de_jogadores, int mostrar_palitos_dos_outros_jogadores);
void desenha_palitos(int linha, int coluna, int num_de_palitos);
void desenha_janela(int linha_inicial, int coluna_inicial, int linha_final, int coluna_final, char cor_de_fundo);

void jogo(int numero_de_jogadores);

int num_jogadores();
int pegue_palitos(struct jogad jogadores[] , int num_de_jogadores, int n_de_rodadas, int total_palitos_da_rodada);
int aleatorio(int num_maximo);
int alguem_ganhou(struct jogad jogadores[], int ordem[], int num_de_jogadores, int palitos_da_rodada, int *ganhador_da_rodada);

// funcao recursiva, que so sai quando o palpite eh valido
void palpite_invalido(int *palpite, int *maximo);


//posicione
#define POS(linha,coluna) printf("\x1B[%d;%df",linha,coluna)


//numero das cores
#define PRETO      '0'
#define VERMELHO   '1'
#define VERDE      '2'
#define AMARELO    '3'
#define AZUL       '4'
#define ROSA       '5'
#define CIANO      '6'
#define BRANCO     '7'

//LIMPAR TELA
#define LIMPAR_TELA()   system("clear")

// tamanho dos palitos
#define TAMANHO_PALITO 4

// abstracao para os jogadores
#define JOG1 0
#define JOG2 1
#define JOG3 2
#define JOG4 3

//LIMPAR JANELAS E BARRA DE STATUS, POSICIONANDO NELAS, LOGO EM SEGUIDA.
#define JANELA1()     desenha_janela(2, 1, 14, 79, AZUL)
#define JANELA2()     desenha_janela(16, 2, 23, 78, VERMELHO)

#define STATUS()    POS(25,1);\
    for ( zz = 0 ; zz <= 79; zz++)\
        printf("\x1B[4%cm ", VERMELHO);\
    POS(25,1)
