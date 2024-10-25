#include<stdio.h>
#include<string.h>
#include "Arvore.h"

int main() {
  char comando[123];
  int x;
  Arvore Arv;
  Arv = NULL;
  while(scanf(" %s", comando) == 1) {
    if (strcmp(comando, "insere") == 0) {
      if (scanf("%d", &x) != 1) return 1;
      if (insere(&Arv, x)) {
	printf("Inserido %d.\n", x);
      } else {
	printf("Insercao de %d falhou.\n", x);	
      }
    } else if (strcmp(comando, "remove") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      if (remove_(&Arv, x)) {
	printf("Removido %d.\n", x);
      } else {
	printf("Remocao de %d falhou.\n", x);	
      }

    } else if (strcmp(comando, "busca") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      if (busca(Arv, x)) {
	printf("Elemento %d encontrado.\n", x);
      } else {
	printf("Elemento %d nao encontrado.\n", x);	
      }
    } else if (strcmp(comando, "imprime") == 0) {
      imprime(Arv);
    } else {
      printf("Comando invalido.\n");
    }
  }
  
  return 0;
}
