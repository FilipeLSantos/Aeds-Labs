#ifndef __ARVORE_H__
#define __ARVORE_H__

typedef enum{false,true} bool;

typedef struct No_aux {
  int valor;
  struct No_aux * esq;
  struct No_aux * dir;
} No;
typedef No* Arvore;

/** Insere valor x na árvore de busca binária */
bool insere(Arvore* ap_arv, int x);

/** Remove valor x da árvore de busca binária. Em caso de nó com dois filhos, deve-se trocar de posição com o antecessor do nó removido e o remover então.  */
bool remove_(Arvore* ap_arv, int x);

/** Busca valor x na árvore de busca binária */
bool busca(Arvore arv, int x);

/** Imprime a árvore de busca binária */
void imprime(Arvore arv);

#endif
