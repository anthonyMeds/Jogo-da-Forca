#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "headerFilesForca.h"


// Header files das funçoes no arquivo headerFilesForca.h

// Variáveis globais
char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;


// Função abertura para imprimir calendário
void abertura(){
    printf("***********************\n");
    printf("*    JOGO DA FORCA    *\n");
    printf("***********************\n");
    printf("\n  Adivinhe a fruta\n");

}

// Capturar chute 
void chuta(){
    char chute;

    printf("Qual a letra?  ");
    scanf(" %c", &chute);

    chutes[chutesDados] = chute;
    
}

// Função ja chutou irá retornar valor de achou para main
int jaChutou(char letra){
    int achou = 0;

    for (int j = 0; j < chutesDados; j++) //percorer os array de chutes e verifica se existe o caractere no array da palavra secreta
        {
            if((chutes[j]) == letra){
                achou = 1;
                break;
            }
        }
        return achou;
}

// Função desenha forca

void desenhaForca(){
     int erros = chutesErrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=4?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=5?'/':' '), (erros>=6?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    printf("Erros = %d\n\n",erros);

    
    // função ja chutou irá retornar um valor a ser armazenado em uma variável
     for ( int i = 0; i < strlen(palavraSecreta); i++) //imprimir palavra secreta
        {
            int achou = jaChutou(palavraSecreta[i]);
            
            if (achou == 1) //se achar imprime a propria letra, se não, imprime _
            {
                printf("%c ", palavraSecreta[i]);
            }else {
                printf("_ ");
            }
        }
        printf("\n\n");
         

}


// FUNÇÃO PARA ADICIONAR PALAVRAS NO ARQUIVO DE PALAVRAS SECRETAS
void adicionaPalavras(){
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo ? (S/N)\n");
    scanf(" %c", &quer);

    if (quer == 'S')
    {
        char novaPalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra ? \n");
        scanf("%s", novaPalavra);

        // Escrita no arquivo r+ = leitura e escrita
        FILE *f;
        f = fopen("palavraSecreta.txt", "r+");
        if (f == 0)
        {
            printf("Erro na leitura/escrita do arquivo.\n");
            exit(1);
        }

        // Atualizar quantidade de palavras e escrever no final do arquivo
        int qtd;
        
        fscanf(f, "%d", &qtd); //leitura da quantidade
        qtd++;

        fseek(f,0,SEEK_SET); //escrita no início do arquivo = atualizar quantidade
        fprintf(f,"%d", qtd);

        fseek(f,0,SEEK_END); //ir para o fim do arquivo e adicionar nova palavra
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);

    }
    


}



// FUNÇÃO PARA ESCOLHER PALAVRA SECRETA ALEATÓRIA 

void escolhePalavra(){
    // Declaração do ponteiro do arquivo
    FILE *f;

    f = fopen("palavraSecreta.txt", "r");

    int qtdPalavras;

    fscanf(f,"%d", &qtdPalavras); //ler a 1 linha do arquivo palvraSecreta.txt com as palavras secretas
    if(f == 0){
        printf("Erro na leitura do arquivo.\n");
        exit(1);
    }

    // Aleatorizar a escolha da palavra secreta
    srand(time(0));
    int palavraEscolhida = rand() % qtdPalavras;

    // Leitura do arquivo palavra por palavra até achar a palavra aleatória
    for ( int i = 0; i <= palavraEscolhida; i++)
    {
        fscanf(f, "%s", palavraSecreta);
    }
    
    // fechar arquivo
    fclose(f);
}

// Função - quantidade de erros
int chutesErrados(){
      int erros = 0;

    for(int i =0; i < chutesDados; i++)
    {
        int existe = 0;

        for ( int j = 0; j < strlen(palavraSecreta); j++)
        {
            if (chutes[i] == palavraSecreta[j])
            {
                existe = 1;
                break;
            }
        }
            if(!existe) erros++;
    }

    return erros;
}

// Função enforcou() define fim do jogo 
int enforcou(){
    
    return chutesErrados() >= MAX_ERROS;
}

int acertou(){
    for ( int i = 0; i < strlen(palavraSecreta); i++)
    {
        if (!jaChutou(palavraSecreta[i]))
        {
            return 0; //se não chutou todas letras da palavra secreta
        }
    }

    return 1; //se já chutou todas as letras da palavra secreta

}


// MAIN
int main(){

    // cabeçalho
    abertura();
    // escolher palavra secreta
    escolhePalavra();
    
    do{
        //desenhaForca
        desenhaForca();

        // Capturar chute
        chuta();

        chutesDados++;
    }while(!acertou() && !enforcou()); //enquanto não acertou e não enforcou
        
   

    if (acertou())
    {
        printf("\nA palavra secreta é %s!\n\n", palavraSecreta);
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    }else{

         printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
    


     adicionaPalavras();

    return 0;

}
