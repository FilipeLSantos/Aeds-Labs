#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

No *novoNo(int x);

/* Insere valor x na árvore de busca binária */
bool insere(Arvore* ap_arv, int x)
{
    //folha
    if(*ap_arv == NULL){
        (*ap_arv) = novoNo(x);
        return 1;
    }  
    //adiciona a esquerda se ele for menor
    if(x < (*ap_arv)->valor)
        return insere(&((*ap_arv)->esq), x);
    //adiciona a direita se ele for maior
    if(x > (*ap_arv)->valor)
        return insere(&((*ap_arv)->dir), x);
    
    return 0;
    
}

int max(No *ap_arv)
{
    if(ap_arv->dir == NULL)
        return ap_arv->valor;
    return max(ap_arv->dir);
}

/* Remove valor x da árvore de busca binária. Em caso de nó com dois filhos, deve-se trocar de 
posição com o antecessor do nó removido e o remover então.  */
bool remove_(Arvore* ap_arv, int x)
{
    if((*ap_arv) ==  NULL)
        return 0;
    if(x < (*ap_arv)->valor)
        return remove_(&((*ap_arv)->esq), x);
    if(x > (*ap_arv)->valor)
        return remove_(&((*ap_arv)->dir), x);
    if((*ap_arv)->esq == NULL){
        No *rem = (*ap_arv);
        (*ap_arv) = rem->dir;
        free(rem);
        return 1;
    }
    if((*ap_arv)->dir == NULL){
        No *rem = (*ap_arv);
        (*ap_arv) = rem->esq;
        free(rem);
        return 1;
    }

    int m = max((*ap_arv)->esq);
    (*ap_arv)->valor = m;
    remove_(&((*ap_arv)->esq), m);
    return 1;

}

/*Busca valor x na árvore de busca binária */
bool busca(Arvore arv, int x)
{
    if(arv == NULL)
        return 0;
    if(arv->valor == x)
        return 1; 
    if(x < arv->valor)
        return busca(arv->esq, x);
    return busca(arv->dir, x);
}


/*Imprime a árvore de busca binária */
void imprimeRec(Arvore arv)
{
    if(arv == NULL){
        printf(".");
    }else{
        printf("[%d:", arv->valor);
        printf("e=");
        imprimeRec(arv->esq);
        printf(",d=");
        imprimeRec(arv->dir);
        printf("]");
    }

}

void imprime(Arvore arv)
{
    imprimeRec(arv);
    printf("\n");
}

No *novoNo(int x)
{
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = x;
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

// desaloca a arvore binaria
void desaloca(No *ap_arv)
{
    if(ap_arv ==  NULL)
        return;
    desaloca(ap_arv->esq);
    desaloca(ap_arv->dir);
    free(ap_arv);
}