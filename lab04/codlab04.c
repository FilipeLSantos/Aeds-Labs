#include <stdio.h>

int calc(int n, int m, int peso[], int valor[]);

int main()
{
    int n, m, i, max;

    scanf("%d %d", &n, &m);

    int peso[n], valor[n];

    for(i = 0; i <n; i++){
        scanf("%d %d", &peso[i], &valor[i]);
    }
        
    max =  calc(n -1, m, peso, valor);

    printf("%d\n", max);

    return 0;
}

int calc(int ult, int m, int peso[], int valor[])
{
    int soma, naoSoma;
    // caso base - olha a quantidade de iteração compararando com o N || m(peso) == 0
    if(ult< 0 || m == 0)
        return 0;
    // caso o peso seja maior que m
    if(peso[ult] > m)
        return calc(ult-1, m, peso, valor);
    // faz a soma acumulativa
    soma = valor[ult] + calc(ult-1, m - peso[ult], peso, valor);
    naoSoma =  calc(ult-1, m, peso, valor);

    return (soma > naoSoma)? soma : naoSoma;
}