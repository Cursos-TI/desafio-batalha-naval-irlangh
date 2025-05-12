#include <stdio.h>

// Tamanho do tabuleiro fixo (10x10)
int TAMANHO = 10;
// Tamanho fixo dos navios (3 posições)
int TAMANHO_NAVIO = 3;

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro com as coordenadas em letras para as colunas
void exibirTabuleiro(int tabuleiro[10][10]) {
    printf("    ");  // Espaço inicial para as coordenadas das linhas
    for (int j = 0; j < TAMANHO; j++) {
        printf("%2c ", 'A' + j);  // Exibe as coordenadas das colunas (letras de A a J)
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i);  // Exibe a coordenada da linha (números de 0 a 9)
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);  // Exibe o valor da célula
        }
        printf("\n");
    }
}

// Função para posicionar os navios (um horizontal e outro vertical)
void posicionarNavios(int tabuleiro[10][10]) {
    // Navio Horizontal
    int linhaH = 2, colunaH = 2;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Navio Vertical
    int linhaV = 5, colunaV = 5;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }
}

int main() {
    // Declaração da matriz do tabuleiro
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios no tabuleiro
    posicionarNavios(tabuleiro);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
