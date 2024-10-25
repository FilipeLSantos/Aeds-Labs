#include <stdio.h>
#define Max 1000000

// i - vai ser o meu divisor
// somaDiv - vai somar o divisores de cada um dos numeros

int somaDivisores(int n);

int main()
{
    int num1, num2;
    int somaDivNum1, somaDivNum2;

    scanf("%d", &num1);
    scanf("%d", &num2);

    somaDivNum1 = somaDivisores(num1);
    somaDivNum2 = somaDivisores(num2);

    // testar se eles são iguais
    if(somaDivNum1 == num2 && somaDivNum2 == num1)
        printf("amigos\n");
    else
        printf("nao amigos\n");

    return 0;
}

int somaDivisores(int n)
{
    int i;
    int somaDiv = 0;

    for(i = 1; i < n; i++)
    {
        if(n % i == 0)
        {
            somaDiv += i;
        }
    }
    return somaDiv;
}
