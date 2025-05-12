#include <stdio.h>

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int linhas, int colunas, int tabuleiro[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            tabuleiro[i][j] = 0;  // 0 representa água
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int linhas, int colunas, int tabuleiro[linhas][colunas]) {
    printf("    ");
    for (int j = 0; j < colunas; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < linhas; i++) {
        printf("%2d ", i);
        for (int j = 0; j < colunas; j++) {
            if (tabuleiro[i][j] == 3) {
                printf(" N ");
            } else {
                printf(" ~ ");
            }
        }
        printf("\n");
    }
}

// Verifica se um navio pode ser posicionado
int podePosicionar(int linhas, int colunas, int tamanhoNavio, int tabuleiro[linhas][colunas], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < tamanhoNavio; i++) {
        int novaLinha = linha + i * deltaLinha;
        int novaColuna = coluna + i * deltaColuna;

        if (novaLinha < 0 || novaLinha >= linhas || novaColuna < 0 || novaColuna >= colunas)
            return 0;
        if (tabuleiro[novaLinha][novaColuna] == 3)
            return 0;
    }
    return 1;
}

// Posiciona um navio após validar
void posicionarNavio(int tamanhoNavio, int tabuleiro[10][10], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < tamanhoNavio; i++) {
        int novaLinha = linha + i * deltaLinha;
        int novaColuna = coluna + i * deltaColuna;
        tabuleiro[novaLinha][novaColuna] = 3;  // 3 representa navio
    }
}

int main() {
    int linhas = 10, colunas = 10;
    int tamanhoNavio = 3;
    int tabuleiro[10][10];

    inicializarTabuleiro(linhas, colunas, tabuleiro);

    // Navio horizontal
    if (podePosicionar(linhas, colunas, tamanhoNavio, tabuleiro, 1, 1, 0, 1))
        posicionarNavio(tamanhoNavio, tabuleiro, 1, 1, 0, 1);

    // Navio vertical
    if (podePosicionar(linhas, colunas, tamanhoNavio, tabuleiro, 4, 7, 1, 0))
        posicionarNavio(tamanhoNavio, tabuleiro, 4, 7, 1, 0);

    // Navio diagonal principal (\)
    if (podePosicionar(linhas, colunas, tamanhoNavio, tabuleiro, 6, 0, 1, 1))
        posicionarNavio(tamanhoNavio, tabuleiro, 6, 0, 1, 1);

    // Navio diagonal secundária (/)
    if (podePosicionar(linhas, colunas, tamanhoNavio, tabuleiro, 3, 6, 1, -1))
        posicionarNavio(tamanhoNavio, tabuleiro, 3, 6, 1, -1);

    exibirTabuleiro(linhas, colunas, tabuleiro);

    return 0;
}

