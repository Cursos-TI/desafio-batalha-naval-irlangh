#include <stdio.h>

int TAMANHO = 10;
int TAMANHO_NAVIO = 3;

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro com coordenadas
void exibirTabuleiro(int tabuleiro[10][10]) {
    printf("    ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%2c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(" ~ ");
            } else if (tabuleiro[i][j] == 3) {
                printf(" N ");
            } else if (tabuleiro[i][j] == 5) {
                printf(" * ");
            } else {
                printf(" ? "); // qualquer outro valor inesperado
            }
        }
        printf("\n");
    }
}

// Valida se a posição está dentro do tabuleiro
int dentroLimite(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO;
}

// Verifica se há espaço livre para posicionar navio
int podePosicionar(int tabuleiro[10][10], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int x = linha + i * dx;
        int y = coluna + i * dy;
        if (!dentroLimite(x, y) || tabuleiro[x][y] != 0)
            return 0;
    }
    return 1;
}

// Posiciona um navio com direção
void posicionarNavio(int tabuleiro[10][10], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i * dx][coluna + i * dy] = 3;
    }
}

// Sobrepõe matriz de habilidade no tabuleiro com origem no centro
void aplicarHabilidade(int tabuleiro[10][10], int efeito[5][5], int origemLinha, int origemColuna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (efeito[i][j] == 1) {
                int x = origemLinha + i - 2;
                int y = origemColuna + j - 2;
                if (dentroLimite(x, y) && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

// Constrói matriz de cone apontando para baixo
void construirCone(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = 0;
        }
    }
    matriz[0][2] = 1;
    matriz[1][1] = matriz[1][2] = matriz[1][3] = 1;
    matriz[2][0] = matriz[2][1] = matriz[2][2] = matriz[2][3] = matriz[2][4] = 1;
}

// Constrói matriz de cruz
void construirCruz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = 0;
        }
    }
    for (int i = 0; i < 5; i++) {
        matriz[2][i] = 1; // linha do meio
        matriz[i][2] = 1; // coluna do meio
    }
}

// Constrói matriz de octaedro (losango)
void construirOctaedro(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = 0;
        }
    }
    matriz[0][2] = 1;
    matriz[1][1] = matriz[1][2] = matriz[1][3] = 1;
    matriz[2][0] = matriz[2][1] = matriz[2][2] = matriz[2][3] = matriz[2][4] = 1;
    matriz[3][1] = matriz[3][2] = matriz[3][3] = 1;
    matriz[4][2] = 1;
}

int main() {
    int tabuleiro[10][10];
    inicializarTabuleiro(tabuleiro);

    // Posiciona navios
    if (podePosicionar(tabuleiro, 1, 1, 0, 1))  // horizontal
        posicionarNavio(tabuleiro, 1, 1, 0, 1);

    if (podePosicionar(tabuleiro, 3, 5, 1, 0))  // vertical
        posicionarNavio(tabuleiro, 3, 5, 1, 0);

    if (podePosicionar(tabuleiro, 0, 0, 1, 1))  // diagonal \
        posicionarNavio(tabuleiro, 0, 0, 1, 1);

    if (podePosicionar(tabuleiro, 2, 9, 1, -1)) // diagonal /
        posicionarNavio(tabuleiro, 2, 9, 1, -1);

    // Construir habilidades
    int cone[5][5], cruz[5][5], octaedro[5][5];
    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplicar habilidades com origens diferentes
    aplicarHabilidade(tabuleiro, cone, 6, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 3, 7);

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
