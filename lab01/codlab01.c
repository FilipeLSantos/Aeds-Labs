#include <stdlib.h>
#include <stdio.h>
#include "lista.h"


/* Inicializa a lista como lista vazia. */
void inicializa_lista(Lista * ap_lista)
{
  (*ap_lista) = NULL;
}

/* Insere valor no fim da lista apontada por ap_lista. ap_lista aponta para o inicio da lista. */
void insere_fim(Lista * ap_lista, int valor)
{
  No *novo;
  No *atual;
  novo = (No *)malloc(sizeof(No));
  novo->valor =  valor;
  novo->proximo =  NULL;
  atual = *ap_lista;

  if((*ap_lista) ==  NULL)
  {
    *ap_lista = novo;
    return;
  }

  while (atual->proximo != NULL)
  {
    atual = atual->proximo;
  }
  atual->proximo = novo;

  return;
}

/* Insere valor no inicio da lista apontada por ap_lista. */
void insere_inicio(Lista * ap_lista, int valor)
{
  No *novo;
  novo = (No *)malloc(sizeof(No));
  novo->valor = valor;
  novo->proximo = (*ap_lista);
  (*ap_lista) = novo;

  return;
}

/* Remove valor do fim da lista apontada por ap_lista e retorna este valor. */
int remove_fim(Lista * ap_lista)
{
  No *novo, *anterior;
  int valorRem = -1;
  novo = *ap_lista;

  if (*ap_lista == NULL) return -1;

  /*caso seja o unico elemento da lista*/
  if(novo->proximo ==NULL)
  {
    valorRem = novo->valor;
    free(novo);
    *ap_lista =  NULL;
    return valorRem;
  }
  
  while (novo->proximo != NULL){
    anterior =  novo;
    novo = novo->proximo;
  }
     
  valorRem = novo->valor;
  
  free(novo);
  /*como nao tem proximo ele recebe vazio o ultimo nó atualizado*/
  anterior->proximo = NULL;
  return valorRem;
  
}

/* Remove valor do inicio da lista apontada por ap_lista e retorna este valor. */
int remove_inicio(Lista * ap_lista)
{
  No *novo;
  int valorRem = -1;
  
  if(*ap_lista == NULL) return -1;

  novo =  *ap_lista;
  valorRem = novo->valor;
  /*Como removir o primeiro nó tem que apontar ele para o proximo que era o segundo anteriomente*/
  *ap_lista =  novo->proximo;

  free(novo);
  return valorRem;
}

/* Remove ocd i-ésimo elemento da lista, caso ele exista. Retorna se o elemento 
foi removido. As posições são contadas a partir de 1, sendo 1 a primeira posição. */
bool remove_i_esimo(Lista * ap_lista, int i)
{
  No *novo =  *ap_lista;
  No *anterior = NULL;
  int j = 0;

  if(*ap_lista ==  NULL || i < 1) return false;
  /*o uso do null é para fazer o teste no percorrer*/
  for(j = 1; j < i && novo != NULL; ++j)
  {
    /*adiciona o nó anterio nele para quando o desejado
    for removido para não ter problema*/
    anterior = novo;
    /*para fazer o papel de anda a cada iteração*/
    novo = novo->proximo;
  }
  if(novo == NULL) return false;

  /*remocao do nó selecionado pelo o indice */
  /*significa que o primeiro nó da lista*/
  if (anterior == NULL)
  {
    /* achei o indice desejado ai ele remove, o nó e apontar para o proximo depois do nó removido*/
    *ap_lista = novo->proximo;
  }else{
    anterior->proximo = novo->proximo;
  }
  
  free(novo);
  return true;
}

/* Retorna o valor do i-ésimo elemento da lista, caso ele exista. 
Retorna -1 caso contrário. As posições são contadas a partir de 1, sendo 1 a primeira posição. */
int recupera_i_esimo(Lista lista, int i)
{
  No *novo = lista;
  int j = 0;

  for(j = 1; j < i && novo != NULL; ++j)
  {
    novo = novo->proximo;
  }

  if(novo == NULL) return -1;

  return novo->valor;
}

/* Retorna o tamanho da lista. */
int tamanho(Lista lista)
{
  No *novo;
  int tam = 0;
  novo = lista;
  while (novo != NULL)
  {
    tam =  tam + 1;
    /*pra ele anda que vai paontar para o proximo*/
    novo =  novo->proximo;
  }

  return tam;   
}

/* Remove todas as ocorrências de valor da lista apontada por ap_lista. 
 * Retorna o numero de ocorrências removidas.
 */
int remove_ocorrencias(Lista *ap_lista, int valor)
{
  /*cria um temporario para fazer a remoçao do dedejado*/
  No *novo, *temp, *anterior = NULL;
  int qtd_ocor;
  novo = *ap_lista;
  qtd_ocor = 0;

  if(*ap_lista == NULL) return -1;

  while (novo !=  NULL)
  {
    if(novo->valor == valor)
    {
      if(anterior == NULL)
      {
        *ap_lista = novo->proximo;
      }else{
        anterior->proximo = novo->proximo;
      }

      qtd_ocor++;

      temp = novo;
      novo =  novo->proximo;
      free(temp);
    }else{
      anterior = novo;
      novo = novo->proximo;
    }
    
  }
  
  return qtd_ocor;
}


/* Busca elemento valor na lista. 
  Retorna a posição na lista, começando de 1=primeira posição.
  Retorna -1 caso não encontrado.
*/
int busca(Lista lista, int valor)
{
  int buscaInd = 1;
  No *novo = lista;
  while (novo != NULL)
  {
    if(novo->valor == valor)
    {
      return buscaInd;
    }
    /*para ele apontar para o proximo, no qual ele vai andar ate procura o desejado*/
    novo = novo->proximo;
    buscaInd++;
  }

  return -1;
    
}

/* Imprime a lista na saida padrão, no formato:
   (1,3,2,3,4,2,3,1,4)
   em uma linha separada.
 */
void imprime(Lista lista)
{
  No* novo;
  novo = lista;
  printf("(");
  while (novo != NULL)
  {
    printf("%d", novo->valor);
    /*para aparecer a virgula*/
    if (novo->proximo != NULL)
    {
      printf(",");
    }
    novo = novo->proximo;
    
  }
  printf(")\n");
  
}

/* Desaloca toda a memória alocada da lista.*/
void desaloca_lista(Lista *ap_lista)
{
  No *novo;
  No *desaloca;

  novo = *ap_lista;
  desaloca = novo;
  while (novo != NULL)
  {
    desaloca = novo;
    novo =  novo->proximo;
    free(desaloca);
  }
  (*ap_lista) = NULL;
}
