#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 1

int main() {
    // Declara��o do tabuleiro 10x10 e inicializa��o com 0 (�gua)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (linha, coluna)
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 6;
    int colunaNavioVertical = 7;

    int i;
    int sobreposicao = 0;

    // ===== Posicionando o navio horizontal =====
    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaNavioHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica sobreposi��o antes de posicionar
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] != VALOR_AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        // Posiciona se n�o houver sobreposi��o
        if (!sobreposicao) {
            for (i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = VALOR_NAVIO;
            }
        } else {
            printf("Erro: Navio horizontal se sobrep�e a outro navio!\n");
            return 1;
        }
    } else {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro!\n");
        return 1;
    }

    // ===== Posicionando o navio vertical =====
    sobreposicao = 0; // reseta verifica��o

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaNavioVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica sobreposi��o antes de posicionar
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] != VALOR_AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        // Posiciona se n�o houver sobreposi��o
        if (!sobreposicao) {
            for (i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = VALOR_NAVIO;
            }
        } else {
            printf("Erro: Navio vertical se sobrep�e a outro navio!\n");
            return 1;
        }
    } else {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro!\n");
        return 1;
    }

    // ===== Exibindo o tabuleiro =====
    printf("\n===== Tabuleiro Batalha Naval =====\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}

