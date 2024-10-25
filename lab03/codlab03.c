#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tamSubSets;
    int elementsSubSets;
}Subconjuntos;


/*Numero maximo de sub conjuntos e quntidade de elementos(tamanho)*/
#define nElements 15
#define nSets 15

void buscaBitaBit(int qtdSubConj, Subconjuntos *w, int n);

int main()
{

    /*n = 0 ... n-1 | 
    qtdSubSets = qtd de sub conjuntos de W | tamSubSets = TAM de cada sub conjunto |
    valor = elementos de cada sub conjunto*/
    int n, qtdSubSets, tamSubSets, valor;

    /*Indice - para percorrer*/
    int j = 0, k = 0, l = 0;

    /*Estrutura*/
    Subconjuntos *w;

    /*elementos do conjunto W - 0 ... n-1*/
    scanf("%d", &n);

    /*quantidade de sub conjuntos de W*/
    scanf("%d", &qtdSubSets);
    /*Criando aminha estrutura de sub Conjunto com o tamanho desejado pelo o dado de entrada*/
    w = (Subconjuntos*)malloc(sizeof(Subconjuntos)*qtdSubSets);
    for(j = 0; j<qtdSubSets; j++){
        /*vou zerar a minha estrututura de elementos do sub conjunto*/
        w[j].elementsSubSets = 0;
    }

    for(k = 0; k < qtdSubSets; k++){
        scanf("%d", &tamSubSets);
        /* armazenar o tamanho do meu sub conjunto de W*/
        w[k].tamSubSets = tamSubSets;
        for(l = 0; l < tamSubSets; l++){
            /*elemento de cada subconjunto*/
            scanf("%d", &valor);
            /*pegar o valor anterior mais o atual e faz o OU Bit a Bit*/
            w[k].elementsSubSets |= (1 << valor); 
        }

    }

    buscaBitaBit(qtdSubSets, w, n);

    free(w);

    return 0;
}

void buscaBitaBit(int qtdSubConj, Subconjuntos *w, int n)
{
    /* indice de cada for*/
    int i, j, k;
    /*conjSol =* responsavel por fazer a comparação se temm os elementos desejado para o meu subConjunto
      qtdSol = responsavel por conta a quantidade de solucao | uConj = realizar uniaão dos sub conjuntos de W  
      checker = responsavel pela cobertura de toda a sub coleçao e se uma soluçaõ foi encontrada  
      solucaoExata = verifica toda a cobertura sub coleção de W, sem repetiçao de lementos(numeros dos sub conjunto) 
      freqElementos = verifica a frequencia dos elementos do sub conjuntos de W - para ter uma unica soluçao exata(sem repetiçao de elementos, pq sem isso ele acaha uma solução so que repete elementos dos sub conjuntos)
    */
  
    int conjSol = (1 << n)-1;
    int qtdSol = 0, uConj = 0, checker = 0;
    int solucaoExata = 1;

    /*fazer o teste de todas as combinações possiveis*/
    for (i = 0; i < (1 << qtdSubConj); i++)
    {
        uConj = 0;
        qtdSol = 0;
        solucaoExata = 1;
        int freqElementos[nElements] = {0};
        
        
        /*percorrer todas as sub coleção de W*/
        for (j = 0; j < qtdSubConj; j++)
        {
            /*verifica se n sub conjuntos esta incluindo na combinação atual de i*/
            if(i & (1 << j)){
                /*vai fazer a união de todos sub conjuntos - que vai fazer a aoperação com OU Bit a Bit
                que pegar a anterior mais atual | uconj = w[j].elementsSubSets | w[j].elementsSubSets */
                uConj |= w[j].elementsSubSets;
                qtdSol++;

                /*verifica a frequencia de cada elementos da sub coelçao de W
                  um elemntos não pode a parecer mais de uma vez para a soluçoa exata de 0... n-1 - isso signiifca que me um soluçao eue posso ter dois numeros zeros
                */
                for(k = 0; k < n; k++){
                    if(w[j].elementsSubSets & (1 << k)){
                        /*Conta a frequencia de elementos*/
                        freqElementos[k]++;

                        /*faz a verificação da frequncia de elemntos - para ter uma cobertura de solução exata*/
                        if(freqElementos[k] > 1){
                            solucaoExata = 0;
                            break;
                        }
                    }
                }
                /*para a verificação se a soluçoa não for unica ou exta sem a repetição*/
                if(!solucaoExata) break;
            }
        }

        /*verifica se a cobertura foi feita de maneira completa - cobrido toda coleçao de W*/
        if(uConj == conjSol && solucaoExata){
            /*que dizer que deu certo a cobertura exata de todas as subColeçaõ de W*/
            checker = 1;
            printf("%d\n", qtdSol);

            /*imprime o resultado*/
            for(j = 0; j < qtdSubConj; j++){
                /*fazer a comparação para fazer a busca da solução*/
                if(i & (1 << j))
                {
                    /*imprime o tamanho do sub conjuntos*/
                    printf("%d", w[j].tamSubSets);
                    for(k = 0; k < n; k++){
                        if(w[j].elementsSubSets & (1 << k))
                            printf(" %d", k);
                    }
                    printf("\n");
                }
            }
            break;
        }
        
    }
    
    /* caso não tenha uma solução*/
    if(!checker){
        printf("Insoluvel\n");
    }
}
