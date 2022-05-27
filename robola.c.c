//importções necessárias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define velocidade_max 2.8 //definindo a velocidade do robo
#define aceleracao 2.8 //definindo a aceleracao 
#define interc 0.115 //definindo raio de interceptacao

int arraytime(float tempovetor[1001]){ //função para armazenar valores em vetor tempo
    FILE *time; //criando ponteiro
    int i=0; //criando variável de contador
    time = fopen("time.txt", "r"); //abrindo e lendo no arquivo
    if(time==NULL){ //condição para existencia do arquivo
        printf("Arquivo não encontrado\n"); //printf para arquivo nao encontrado
        exit(0); //comando de saida da condição
    }
    char g; //crinado variavel char
    fscanf(time, "%f", &tempovetor[i]); //leitura de toda a linha e armazenamento em tempovetor
    g = fgetc(time); //leitura de um caracter apos o outro
    i++; //adicionando 1 ao contador

    while(g != EOF){ //estrutura de repetição enquanto o char nao atingir o fim do arquivo
        if(g == '\n'){ //o ponteiro pulará para o próximo caracter após encontrar \n
            fscanf(time, "%f", &tempovetor[i]); //ler a linha em forma de float
            i++; //adicionar 1 ao contador
        }
    g = fgetc(time); //lendo os caracteres de um a um
    } 
    g = fgetc(time); //novamente a leitura de cada caracter enquanto são printados

    int v; //criando variavel v

    fclose(time); //fechando o arquivo

}

int arrayX(float Xvetor[1001]){ //função para armazenar valores em vetor x
    FILE *xball; //criando ponteiro
    int i=0; //criando variavel contador
    xball = fopen("xball.txt", "r"); //abrindo e lendo o arquivo
    if(xball==NULL){ //condição de existencia do arquivo
        printf("Arquivo não encontrado\n"); //printf para arquivo nao encontrado
        exit(0); //comando de saida da condição
    }
    char g; //criando variavel char
    fscanf(xball, "%f", &Xvetor[i]); //leitura de toda a linha e armazenamento em Xvetor
    g = fgetc(xball); //leitura de um caracter apos o outro
    i++; //adiciona 1 ao contador

    while(g != EOF){ //estrutura de repetição enquanto o char nao atingir o fim do arquivo
        if(g=='\n'){ //o ponteiro pulará para o proximo caracter após encontrar \n
            fscanf(xball, "%f", &Xvetor[i]); //ler a linha em forma de float
            i++; //adicionar 1 ao contador
        }
    g = fgetc(xball); //lendo caracteres um a um
    }
    g = fgetc(xball); //novamente a leitura de cada caracter enquanto são printados

    int v; //criando variavel v

    fclose(xball); //fechando o arquivo
}

int arrayY(float Yvetor[1001]){ //função para armazenar valores no vetor y
    FILE *yball; //criando ponteiro
    int i=0; //criando variavel de contador
    yball = fopen("yball.txt", "r"); //abrindo e lendo o arquivo
    if(yball == NULL){ //condição de existencia do arquivo
        printf("Arquivo não encontrado\n"); //printf para arquivo nao encontrado
        exit(0); //comando de saida da condição
    }
    char g; //criando variavel char
    fscanf(yball, "%f", &Yvetor[i]); //leitura de toda a linha e armazenamento em Yvetor
    g = fgetc(yball); //leitura de um caracter após o outro
    i++; //adicionando 1 ao contador

    while(g != EOF){ //estrutura de repetição enquanto o char nao atingir o fim do arquivo
        if(g == '\n'){ //o ponteiro pulará para o próximo caracter após encontrar \n
            fscanf(yball, "%f", &Yvetor[i]); //ler linha em forma de float
            i++; //adicionando 1 ao contador
        }
    g = fgetc(yball); //lendo caracteres um a um
    }
    g = fgetc(yball); //lendo novamente cada caracter enquanto são printados

    int v; //criando variavel v

    fclose(yball); //fechando o arquivo
}

main(){ //função principal
    int i; //criando variavel contador
    float Xvetor[1001]; //criando vetor x
    float Yvetor[1001]; //criando vetor y 
    float tempovetor[1001]; //criando vetor tempo
    float cosseno[1001]; //criando vetor cosseno
    float seno[1001]; //criando vetor seno
    float robo_velocidade[1001]; //criando vetor da velocidade do robo

    for(i = 0; i < 1002; i++){ //restringindo o contador ao tamanho dos vetores
        robo_velocidade[i] = 0; //igualando valores do robo_velocidade a 0
    }

    float Xrobo_vetor[1001]; //criando vetor do robo em x
    float Yrobo_vetor[1001]; //criando vetor do robo em y


    int v; //criando a variavel v

    arraytime(tempovetor); //chamando função do tempo
    arrayX(Xvetor); //chamando função do x
    arrayY(Yvetor); //chamando função do y


    printf("Modelo do robo: Small Size\n\n"); //printf do modelo do robo
    printf("Digite a posicao inicial do robo em X: "); //pedindo a posição do robo em x
    scanf("%f", &Xrobo_vetor[0]); //scanf do primeiro valor de Xrobo_vetor
    printf("Digite a posicao inicial do robo em Y: "); //pedidno a posição do robo em y
    scanf("%f", &Yrobo_vetor[0]); //scanf do primeiro valor de Yrobo_vetor
    printf("Velocidade da robo: %.3f\n", velocidade_max); //printf da velocidade do robo
    printf("Aceleracao do robo: %.3f\n", aceleracao); //printf da aceleração do robo
    printf("Raio de interceptacao: %.3f metros", interc); //printf do raio de interceptação

    float b_distancia[1001]; //criando vetor de distancia

    for(v = 0; v < 1002; v++){ //restringiu contador v ao tamanho dos vetores
        robo_velocidade[v] = aceleracao*tempovetor[v]; //armazenando os valores de aceleração vezes o tempo no vetor robo_velocidade 

        if(robo_velocidade[v] >= velocidade_max){ //condição para que os valores de robo_velocidade nao ultrapassem 2.8
            robo_velocidade[v] = velocidade_max; //caso isso aconteça ele voltará a ser 2.8
        }
    }

    for(i = 0; i < 1002; i++){ //restringindo o contador ao tamanho dos vetores
        b_distancia[i] = ((Xvetor[i] - Xrobo_vetor[i])*(Xvetor[i] - Xrobo_vetor[i])) + ((Yvetor[i] - Yrobo_vetor[i])*(Yvetor[i] - Yrobo_vetor[i])); //atribuindo valores ao vetor da distancia

        cosseno[i] = (Xvetor[i] - Xrobo_vetor[i]) / sqrt(b_distancia[i]); //achando o cosseno
        seno[i] = (Yvetor[i] - Yrobo_vetor[i]) / sqrt(b_distancia[i]); //achando o seno

        Xrobo_vetor[i+1] = Xrobo_vetor[i] + (cosseno[i] * 0.04); //aumentar o x do robo
        Yrobo_vetor[i+1] = Yrobo_vetor[i] + (seno[i] * 0.05); //aumentar o y do robo

        if(Xrobo_vetor[i] >= Xvetor[i] - interc && Xrobo_vetor[i] <= Xvetor[i] + interc && Yrobo_vetor[i] >= Yvetor[i] - interc && Yrobo_vetor[i] <= Yvetor[i] + interc){ //condições para quando o robo encontrar a bola
            printf("O robo acaba de encontrou a bola!!!\n"); //printf avisando que a bola foi encontrada
            printf("Posicao X do robo: %.3f\n", Xrobo_vetor[i]); //printf da posição do robo em x
            printf("Posicao Y do robo: %.3f\n", Yrobo_vetor[i]); //printf da posição do robo em y
            printf("Velocidade do robo: %.3f\n", robo_velocidade[i]); //printf da velocidade do robo
            printf("Posicao X da bola: %.3f\n", Xvetor[i]); //printf da posição da bola em x
            printf("Posicao Y da bola: %.3f\n", Yvetor[i]); //printf da posição da bola em y
            printf("Tempo: %.3f\n\n", tempovetor[i]); //printf do tempo

            break; //comando para interromper o codigo

        }

        else{ //caso contrario o programa continuará gerando valores
            printf("\n\nPosicao X do robo: %.3f\n", Xrobo_vetor[i]); //printf da posição do robo em x
            printf("Posicao Y do robo: %.3f\n", Yrobo_vetor[i]); //printf da posição do robo em y
            printf("Velocidade do robo: %.3f\n", robo_velocidade[i]); //printf da velocidade do robo
            printf("Posicao X da bola: %.3f\n", Xvetor[i]); //printf da posição da bola em x
            printf("Posicao Y da bola: %.3f\n", Yvetor[i]); //printf da posição da bola em y
            printf("Tempo: %.3f\n\n", tempovetor[i]); //printf do tempo
        }
    }

    system("pause"); //comando para que o programa nao rode em looping eterno

}