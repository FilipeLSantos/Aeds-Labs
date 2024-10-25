#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

Polinomio insereFim(Polinomio cab, int grau, int coef);

/* Inicializa um polinômio vazio. */
void inicializa_polinomio(Polinomio *ap_pol)
{
    *ap_pol = (No*)malloc(sizeof(No));

    if(*ap_pol == NULL) return;

    (*ap_pol)->prox = *ap_pol;
    (*ap_pol)->antec = *ap_pol;

}

/* Define que o coeficiente de grau grau do polinomio pol eh igual a coef. Deve manter os 
 * coeficientes ordenados por grau. */
void define_coeficiente(Polinomio pol, int grau, int coef)
{
    No *novo, *insere;
    insere = (No*)malloc(sizeof(No));
    novo = pol->prox;

    if(coef == 0) return;

    /*essa para pegar o indice para adicionar ordenado
     anterior vai pegar o indice para eu ordenar e quando 
     for adicionado vai ser anteriot mais 1*/
    while (novo != pol && novo->valor.grau < grau)
    {
        novo = novo->prox;
    }
    
    /*mesmo grau ou coeficiente == 0*/
    if(novo != pol && novo->valor.grau == grau){
        novo->valor.coef = coef;
        free(insere);
    }else{
        /*adicona os valores do polinomio*/
        insere->valor.grau = grau;
        insere->valor.coef = coef;

        /*Insere Apos*/
        insere->prox = novo;
        insere->antec = novo->antec;
        novo->antec->prox = insere;
        novo->antec = insere;
    }
    
}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera(Polinomio pol)
{
    /*proximoNo tem a função de anda e atual de libera a memoria*/
    No *atual, *proximoNo;
    atual = pol->prox;

    while (atual != pol)
    {
        proximoNo = atual->prox;
        free(atual);
        atual = proximoNo;
        
    }

    pol->prox = pol;
    pol->antec = pol;
    pol->valor.coef = 0;
    pol->valor.grau = -1;

}

/* Computa a soma dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma(Polinomio res, Polinomio a, Polinomio b)
{
    int soma = 0;
    No *atualA, *atualB;
    zera(res);
    atualA = a->prox;
    atualB = b->prox;

    /* tem a função de um polinomio for maior ou menor que o outro continua a operação*/
    while (atualA != a || atualB != b)
    {
        /* se A tiver acabdao recebe todo o restante de B*/
        if (atualA == a)
        {
            insereFim(res, atualB->valor.grau, atualB->valor.coef);
            atualB = atualB->prox;
        }
        else if (atualB == b)
        {
            /* se B tiver acabdao recebe todo o restante de A*/
            insereFim(res, atualA->valor.grau, atualA->valor.coef);
            atualA = atualA->prox;
        }
        else
        {
            /* Se A for maior que B*/
            if (atualA->valor.grau < atualB->valor.grau)
            {
                insereFim(res, atualA->valor.grau, atualA->valor.coef);
                atualA = atualA->prox;
            }
            else if (atualA->valor.grau > atualB->valor.grau)
            {
                /*Se B for maior que A*/
                insereFim(res, atualB->valor.grau, atualB->valor.coef);
                atualB = atualB->prox;
            }
            else
            {
                soma = atualA->valor.coef + atualB->valor.coef;
                /*Se os graus de A e B forem iguais soma*/
                if(soma != 0)
                    insereFim(res, atualA->valor.grau, soma);
                atualA = atualA->prox;
                atualB = atualB->prox;
                soma = 0;
            }
        }
    }
}

/* Computa a subtracao dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b)
{
    int subtrai = 0;
    No *atualA, *atualB;
    zera(res);
    atualA = a->prox;
    atualB = b->prox;

    while (atualA != a || atualB != b)
    {
        if (atualA == a)
        {
            insereFim(res, atualB->valor.grau, -atualB->valor.coef);
            atualB = atualB->prox;
        }
        else if (atualB == b)
        {
            insereFim(res, atualA->valor.grau, atualA->valor.coef);
            atualA = atualA->prox;
        }
        else
        {
            if (atualA->valor.grau < atualB->valor.grau)
            {
                insereFim(res, atualA->valor.grau, atualA->valor.coef);
                atualA = atualA->prox;
            }
            else if (atualA->valor.grau > atualB->valor.grau)
            {
                insereFim(res, atualB->valor.grau, -atualB->valor.coef);
                atualB = atualB->prox;
            }
            else
            {
                subtrai = atualA->valor.coef - atualB->valor.coef;
                if(subtrai != 0)
                    insereFim(res, atualA->valor.grau, subtrai);
                atualA = atualA->prox;
                atualB = atualB->prox;
                subtrai = 0;
            }
        }
    }
}

/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,-2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau 3 com valor -2 e o de
 * grau 10 com valor 5. 
 */
void imprime(Polinomio pol)
{
    No *novo;
    novo = pol->prox;

    printf("[");

    while(novo != pol)
    {
        printf("(%d,%d)", novo->valor.grau, novo->valor.coef);
        if(novo->prox != pol)
            printf(",");
        novo = novo->prox;
    }
    printf("]\n");
}

/*ele insere no fim de modo ordenado(crescente)*/
Polinomio insereFim(Polinomio cab, int grau, int coef)
{
    No *novo;
    novo =  (No*)malloc(sizeof(No));
    
    novo->valor.grau = grau;
    novo->valor.coef = coef;

    novo->prox = cab;
    novo->antec = cab->antec;
    cab->antec->prox = novo;
    cab->antec = novo;

    return cab;
}

/* Desaloca toda a memória alocada da lista.*/
void desaloca_polinomio(Polinomio *ap_pol)
{
    /*LiberaAnt =  ela recebe o nó anterior e libera a memoria dele,
    assim o novo vai percorrendo e passando a variavel para ele*/
    No *atual, *proximoNo;
    atual = (*ap_pol)->prox;

    while (atual != (*ap_pol))
    {
        proximoNo = atual->prox;
        free(atual);
        atual = proximoNo;
    }
    free(*ap_pol);
}