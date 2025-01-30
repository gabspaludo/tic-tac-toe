#include <stdio.h>

    #define tamanhoJogo 3
    const char jogador = 'X';
    const char computador = 'O';
    char ticTacToe[tamanhoJogo][tamanhoJogo];

    void definirValores() {
      // define as posições do jogo de 1 a 9 para o jogador poder escolher
      int posicao = 1;
      for (int linhas = 0; linhas < tamanhoJogo; linhas++) {
        for (int colunas = 0; colunas < tamanhoJogo; colunas++) {
          ticTacToe[linhas][colunas] = '0' + posicao;
          posicao++;
        }
      }
    }

    void mostrarJogo() {
      // mostra como está o jogo no momento
      printf("\n");
      for (int linhas = 0; linhas < tamanhoJogo; linhas++) {
        for (int colunas = 0; colunas < tamanhoJogo; colunas++) {
          printf(" %c ", ticTacToe[linhas][colunas]);
          if (colunas < tamanhoJogo - 1)
            printf("|");
        }
        printf("\n");
        if (linhas < tamanhoJogo - 1)
          printf("---|---|---\n");
      }
    }

    int checarVitoria() {
      for (int linhas = 0; linhas < tamanhoJogo; linhas++) {
        // verifica a vitória nas linhas
        if (ticTacToe[linhas][0] == ticTacToe[linhas][1] &&
            ticTacToe[linhas][1] == ticTacToe[linhas][2])
          return ticTacToe[linhas][0] == jogador ? -10 : 10;
        // verifica vitória nas colunas
        if (ticTacToe[0][linhas] == ticTacToe[1][linhas] &&
            ticTacToe[1][linhas] == ticTacToe[2][linhas])
          return ticTacToe[0][linhas] == jogador ? -10 : 10;
      }
      // verifica a vitória nas diagonais
      if (ticTacToe[0][0] == ticTacToe[1][1] && ticTacToe[1][1] == ticTacToe[2][2])
        return ticTacToe[0][0] == jogador ? -10 : 10;
      if (ticTacToe[0][2] == ticTacToe[1][1] && ticTacToe[1][1] == ticTacToe[2][0])
        return ticTacToe[0][2] == jogador ? -10 : 10;
      return 0;
    }

    void maquinaJogar() {
      int linhas, colunas;

      // verifica se pode vencer na próxima jogada
      for (linhas = 0; linhas < tamanhoJogo; linhas++) {
        for (colunas = 0; colunas < tamanhoJogo; colunas++) {
          if (ticTacToe[linhas][colunas] != jogador &&
              ticTacToe[linhas][colunas] != computador) {
            char temp = ticTacToe[linhas][colunas];
            ticTacToe[linhas][colunas] = computador;
            if (checarVitoria() == 10) {
              return;
            }
            ticTacToe[linhas][colunas] = temp;
          }
        }
      }

      // verifica se o jogador vai vencer e bloqueia ele
      for (linhas = 0; linhas < tamanhoJogo; linhas++) {
        for (colunas = 0; colunas < tamanhoJogo; colunas++) {
          if (ticTacToe[linhas][colunas] != jogador &&
              ticTacToe[linhas][colunas] != computador) {
            char temp = ticTacToe[linhas][colunas];
            ticTacToe[linhas][colunas] = jogador;
            if (checarVitoria() == -10) {
              ticTacToe[linhas][colunas] = computador;
              return;
            }
            ticTacToe[linhas][colunas] = temp;
          }
        }
      }

      // joga na posição do meio se não estiver ocupada
      if (ticTacToe[1][1] != jogador && ticTacToe[1][1] != computador) {
        ticTacToe[1][1] = computador;
        return;
      }

      // caso a posição do meio já esteja ocupada, joga nos cantos
      int cantos[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
      for (linhas = 0; linhas < 4; linhas++) {
        int x = cantos[linhas][0];
        int y = cantos[linhas][1];
        if (ticTacToe[x][y] != jogador && ticTacToe[x][y] != computador) {
          ticTacToe[x][y] = computador;
          return;
        }
      }

      // se nenhum dos cantos estiver disponível, joga nos lados
      int lados[4][2] = {{0, 1}, {1, 0}, {1, 2}, {2, 1}};
      for (linhas = 0; linhas < 4; linhas++) {
        int x = lados[linhas][0];
        int y = lados[linhas][1];
        if (ticTacToe[x][y] != jogador && ticTacToe[x][y] != computador) {
          ticTacToe[x][y] = computador;
          return;
        }
      }
    }

    int main() {
      int posicaoEscolhida, jogadas = 9;
      definirValores();
      mostrarJogo();

      while (jogadas > 0) {
        int posicaoValida = 0;
        printf("\nSelecione a posição desejada: ");
        scanf("%d", &posicaoEscolhida);

        for (int linhas = 0; linhas < tamanhoJogo; linhas++) {
          for (int colunas = 0; colunas < tamanhoJogo; colunas++) {
            if (ticTacToe[linhas][colunas] == '0' + posicaoEscolhida) {
              ticTacToe[linhas][colunas] = jogador;
              posicaoValida = 1;
              jogadas--;
            }
          }
        }

        if (!posicaoValida) {
          printf("\nPosição já escolhida ou inexistente, tente novamente.\n");
          continue;
        }

        mostrarJogo();
        if (checarVitoria() == -10) {
          printf("\nO vencedor foi %c\n", jogador);
          break;
        }

        if (jogadas > 0) {
          maquinaJogar();
          jogadas--;
          mostrarJogo();

          if (checarVitoria() == 10) {
            printf("\nO vencedor foi %c\n", computador);
            break;
          }
        }

        if (jogadas == 0) {
          printf("\nO jogo terminou em empate!\n");
          break;
        }
      }

      printf("\nO jogo acabou!\n");
      return 0;
    }