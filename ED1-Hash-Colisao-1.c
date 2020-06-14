#include <stdio.h>
#include <string.h>
#define MAX 100

int enche_vetor(int vetor[], int tamanho, int n){
    int i;
    for(i=0; i<tamanho; i++)
        vetor[i] = n;
}

int dispersao_dupla(int posicoes[], int n_elementos, int M, int novas_posicoes[]){
    int i, j;

    enche_vetor(novas_posicoes, MAX, -1);
    for(i=0; i<n_elementos; i++){
        int k=0, posicao = posicoes[i];
        for(j=0; j<n_elementos; j++){
            if(novas_posicoes[j] == -1){
                novas_posicoes[j]=posicao;
                break;
            }
            if(posicao == novas_posicoes[j]){
                j=0;
                k++;
                posicao = (posicoes[i] + k*(1 + posicoes[i]%13) )%M;
            }
        }
    }
}

int tentativa_quadratica(int posicoes[], int n_elementos, int M, int a_1, int a_2, int novas_posicoes[]){
    int i, j;
    enche_vetor(novas_posicoes, MAX, -1);

    for(i=0; i<n_elementos; i++){
        int k=0, posicao = posicoes[i];
        
        for(j=0; j<n_elementos; j++){
            if(novas_posicoes[j] == -1){
                novas_posicoes[j]=posicao;
                break;
            }
            if(posicao == novas_posicoes[j]){
                j=0;
                k++;
                posicao = (posicoes[i] + a_1*k*k + a_2*k)%M;
            }
        }
    }
}

int tentativa_linear(int posicoes[], int n_elementos, int M, int novas_posicoes[]){
    int i, j;
    enche_vetor(novas_posicoes, MAX, -1);

    for(i=0; i<n_elementos; i++){
        int k=0, posicao = posicoes[i];
        
        for(j=0; j<n_elementos; j++){
            if(novas_posicoes[j] == -1){
                novas_posicoes[j]=posicao;
                break;
            }
            if(posicao == novas_posicoes[j]){
                j=0;
                k++;
                posicao = (posicoes[i]+k)%M;
            }
        }
    }
}  

int main(){
    int i, M, q_posicoes, posicoes[MAX], novas_posicoes[MAX];

    printf("Digite M: ");
    scanf("%d", &M);
    printf("Digite quantas posicoes deseja converter: ");
    scanf("%d", &q_posicoes);

    for(i=0; i<q_posicoes; i++){
        printf("Novas posicao %d: ", i+1);
        scanf("%d", &posicoes[i]);
    }

    // DISPERSAO DUPLA
    printf("\n\nDISPERSAO DUPLA\n");
    printf("g(x) = h(x)%%3\n");

    enche_vetor(novas_posicoes, MAX, 0);
    dispersao_dupla(posicoes, q_posicoes, M, novas_posicoes);
    printf("Novas posicoes: ");
    for(i=0; i<q_posicoes; i++){
        printf(" %d ", novas_posicoes[i]);
    }

    ////////////////////

    // TENTATIVA LINEAR
    printf("\n\nTENTATIVA LINEAR\n");

    enche_vetor(novas_posicoes, MAX, 0);
    tentativa_linear(posicoes, q_posicoes, M, novas_posicoes);
    printf("Posicoes: ");
    for(i=0; i<q_posicoes; i++){
        printf(" %d ", novas_posicoes[i]);
    }

    ////////////////////


    // TENTATIVA QUADRATICA
    printf("\n\nTENTATIVA QUADRATICA\n");

    enche_vetor(novas_posicoes, MAX, 0);
    int a_1, a_2;

    printf("Digite a1: ");
    scanf("%d", &a_1);
    printf("Digite a2: ");
    scanf("%d", &a_2);

    tentativa_quadratica(posicoes, q_posicoes, M, a_1, a_2, novas_posicoes);
    printf("Novas posicoes: ");
    for(i=0; i<q_posicoes; i++){
        printf(" %d ", novas_posicoes[i]);
    }

    ////////////////////
}