
# Jogo da Forca em C

Esse é um jogo da forca implementado em C. O jogo consiste em adivinhar uma palavra secreta letra por letra até que todas as letras sejam reveladas.


O jogo tem as seguintes características: 

* O jogador pode adicionar novas palavras secretas ao jogo, que são armazenadas em um arquivo "palavraSecreta.txt".
* A palavra secreta é escolhida aleatoriamente a partir do arquivo "palavraSecreta.txt".
* O jogador pode tentar adivinhar uma letra por vez, e o jogo informará se a letra existe na palavra secreta.
* O jogo é encerrado quando o jogador acertar todas as letras ou a forca for completamente desenhada.

## Como jogar

* Ao iniciar o jogo, uma abertura com o título "JOGO DA FORCA" será exibida.
* O jogo escolherá uma palavra secreta aleatória e informará quantas letras a palavra tem com traços.
* O jogador pode tentar adivinhar uma letra digitando-a no terminal.
* Se a letra existir na palavra secreta, o jogo informará em que posição(s) ela está.
* Se a letra não existir na palavra secreta, o jogo desenhará a forca progressivamente.
* O jogador pode continuar tentando adivinhar letras até que todas as letras sejam reveladas ou até que a forca seja completamente desenhada.

## Instalação

1. Clone o repositório do jogo

```
git clone https://github.com/anthonyMeds/Jogo-da-Forca.git


```
2. Compile e execute

```
gcc  forca.c -o forca

./forca

```
    
