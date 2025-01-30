# Jogo da Velha (Tic-Tac-Toe) em C

Jogo da velha simples feito em C, para a matéria de Inteligência artificial, onde o jogador enfrenta o computador.

## Como jogar

O jogo é executado no terminal. O jogador deve escolher uma posição de 1 a 9 para marcar com a letra "X", e o computador vai jogar com a letra "O". O objetivo é formar uma linha, coluna ou diagonal com três letras iguais.

## Compilando e executando

Para compilar o jogo, utilize um compilador C como `gcc`:

```sh
gcc main.c -o jogo
```

Para rodar o jogo:

```sh
./jogo
```

## Funcionalidades

- O jogo exibe o tabuleiro atualizado a cada rodada.
- O jogador escolhe a posição que deseja jogar digitando um número de 1 a 9.
- O computador tem uma lógica para tentar vencer ou bloquear o jogador.
- O jogo termina quando alguém vence ou quando empata.