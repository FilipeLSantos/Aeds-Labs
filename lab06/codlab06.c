#include <stdio.h>
#include <stdlib.h>

typedef enum{false, true} bool;

typedef enum{soma = '+', subt = '-', mult = '*', divi = '/', resDiv = '%'} oper;

typedef struct auxArvore{
    bool ehValor;
    oper op;
    int val;
    struct auxArvore *esq, *dir;
}NoArvore;

typedef struct auxPArv{
    NoArvore *arv;
    struct auxPArv *prox;
}NoP_Arv;

typedef struct auxPOper{
    oper tipo;
    struct auxPOper *prox;
}NoP_Oper;

typedef NoArvore Arvore;
typedef NoP_Arv PilhaArv;
typedef NoP_Oper PilhaOper;

NoArvore *novoNoValor(int x);

NoArvore *novoNoOper(oper tipo, NoArvore *esq, NoArvore *dir);

void empilhaArv(PilhaArv **pArv, NoArvore *arv);

NoArvore *desempilhaArv(PilhaArv **pArv);

void empilhaOper(PilhaOper **pOper, oper tipo);

oper desempilhaOper(PilhaOper **pOper);

void operacaoDePilhas(PilhaOper **pOper, PilhaArv **pArv);

int calc(Arvore *arv);

int precedencia(oper tipo);

void imprimePreFixa(Arvore *arv);

void imprimePosFixa(Arvore *arv);

void desalocaArv(NoArvore *ap_arv);

void desalocaP_Oper(PilhaOper *pOper);

void desalocaP_Arv(PilhaArv *pArv);

int main()
{
    PilhaArv *pArv = NULL;
    PilhaOper *pOper = NULL;

    char operadores[1001];
    char aux[1001];
    int numeros[1001];
    int qtdNum = 0, qtdOper = 0;

    scanf("%d", &numeros[qtdNum++]);
    while (scanf("%s", aux) == 1 && scanf("%d", &numeros[qtdNum++]) == 1){
        operadores[qtdOper++] = aux[0];
    }

    empilhaArv(&pArv, novoNoValor(numeros[0]));

    for (int i = 0; i < qtdOper; i++){
        while (pOper && precedencia(operadores[i]) <= precedencia(pOper->tipo)){
            operacaoDePilhas(&pOper, &pArv);
        }
        empilhaOper(&pOper, operadores[i]);
        empilhaArv(&pArv, novoNoValor(numeros[i + 1]));
    }

    while (pOper != NULL){
        operacaoDePilhas(&pOper, &pArv);
    }
    
    NoArvore *raiz = desempilhaArv(&pArv);

    imprimePreFixa(raiz);
    printf("\n");

    imprimePosFixa(raiz);
    printf("\n");
    
    printf("%d\n", calc(raiz));

    desalocaArv(raiz);
    desalocaP_Arv(pArv);
    desalocaP_Oper(pOper);

    return 0;
}

NoArvore *novoNoValor(int x)
{
    NoArvore *novo = (NoArvore*)malloc(sizeof(NoArvore));
    novo->ehValor = true;
    novo->val = x;
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

NoArvore *novoNoOper(oper tipo, NoArvore *esq, NoArvore *dir)
{
    NoArvore *novo = (NoArvore*)malloc(sizeof(NoArvore));
    novo->ehValor = false;
    novo->op = tipo;
    novo->dir = dir;
    novo->esq = esq;

    return novo;
}

void empilhaArv(PilhaArv **pArv, NoArvore *arv)
{
    PilhaArv *novo = (PilhaArv*)malloc(sizeof(PilhaArv));
    novo->arv = arv;
    novo->prox = *pArv;
    *pArv = novo;
}

NoArvore *desempilhaArv(PilhaArv **pArv)
{
    if(*pArv == NULL)
        return NULL;
    PilhaArv *rem = *pArv;
    NoArvore *arv = rem->arv;
    *pArv = rem->prox;
    free(rem);

    return arv;
}

void empilhaOper(PilhaOper **pOper, oper tipo)
{
    PilhaOper *novo = (PilhaOper*)malloc(sizeof(PilhaOper));
    novo->tipo = tipo;
    novo->prox = *pOper;
    *pOper = novo;
}

oper desempilhaOper(PilhaOper **pOper)
{
    if(*pOper == NULL)
        return 0;
    PilhaOper *rem = *pOper;
    oper tipo = rem->tipo;
    *pOper = rem->prox;
    free(rem);

    return tipo;
}

void operacaoDePilhas(PilhaOper **pOper, PilhaArv **pArv)
{
    NoArvore *dir = desempilhaArv(pArv);
    NoArvore *esq = desempilhaArv(pArv);
    oper tipo = desempilhaOper(pOper);
    empilhaArv(pArv, novoNoOper(tipo, esq, dir));
}

int calc(Arvore *arv)
{
    if(arv->ehValor == true)
        return arv->val;
    int e = calc(arv->esq);
    int d = calc(arv->dir);
    switch (arv->op)
    {
        case soma:
            return e+d;
        case subt:
            return e-d;
        case mult:
            return e*d;
        case divi:
            return e/d;
        case resDiv:
            return e%d;
    }
    return 0;
}

int precedencia(oper tipo)
{
    // grau de precedencia 3 - maior | 1 - menor 
    if (tipo == mult || tipo == divi)
        return 3;
    else if(tipo == soma || tipo == subt)
        return 2;
    return 1;
}

void imprimePreFixa(Arvore *arv)
{
    if(arv == NULL)
        return;
    if(arv->ehValor)
        printf("%d", arv->val);
    else
        printf("%c", arv->op);
    if(arv->esq != NULL){
        printf(" ");
        imprimePreFixa(arv->esq);
    }if(arv->dir != NULL){
        printf(" ");
        imprimePreFixa(arv->dir);
    }
}

void imprimePosFixa(Arvore *arv)
{
    if(arv == NULL)
        return;
    if(arv->esq != NULL){
        imprimePosFixa(arv->esq);
        printf(" ");
    } if(arv->dir != NULL){
        imprimePosFixa(arv->dir);
        printf(" ");
    }
    if(arv->ehValor)
        printf("%d", arv->val);
    else
        printf("%c", arv->op);
}

void desalocaArv(NoArvore *ap_arv)
{
    if(ap_arv ==  NULL)
        return;
    desalocaArv(ap_arv->esq);
    desalocaArv(ap_arv->dir);
    free(ap_arv);
}

void desalocaP_Oper(PilhaOper *pOper)
{
    while (pOper != NULL){
        PilhaOper *temp  = pOper;
        pOper = pOper->prox;
        free(temp);
    }
}

void desalocaP_Arv(PilhaArv *pArv)
{
    while (pArv != NULL){
        PilhaArv *temp = pArv;
        pArv = pArv->prox;
        free(temp);
    }
    
}