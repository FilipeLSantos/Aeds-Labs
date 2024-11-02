# Lab's de AEDS 🧪

Este repositório contém uma coleção de laboratórios desenvolvidos para a disciplina de Algoritmos e Estruturas de Dados (AEDS). Cada laboratório aborda um conjunto de problemas e soluções aplicados ao estudo de algoritmos e estruturação de dados.

## [lab00](/lab00)
Escreva um programa de computador que leia 2 números naturais da entrada (menores do que 1 milhão) e imprima na saída uma linha igual a "amigos" ou a "nao amigos" (sem acento), respectivamente indicando que os 2 números da entrada são ou não são amigos. Dizemos que dois números são amigos se a soma de todos os divisores próprios de um deles é igual ao outro e vice-versa. 

- Por exemplo:
    - 220 e 284 são amigos
- Para compilar e executar:
    ```bash 
        gcc -g -Wall -pedantic codlab00.c -o execlab00
        
        ./execlab00
        
        for((i=1; i<21; i=i+1)); do ./execlab00 < ins/$i.in > ins/$i.meu; diff ins/$i.meu ins/$i.out; done

## [lab01](/lab01)
Implemente as funções do arquivo lista.h em um novo arquivo lista.c. Em seguida, teste e confirme a corretude de seu programa com os arquivos .in e .out. Finalmente submeta somente o arquivo lista.c

- Para compilar e executar:
    ```bash 
    gcc -g -Wall -pedantic codlab01.c lab01.c lista.h -o execlab01

    ./execlab01

    for((i=1; i<14; i=i+1)); do ./execlab01 < ins/$i.in > ins/$i.meu; diff ins/$i.meu ins/$i.out; done

## [lab02](/lab02)
Implemente as seguintes funcoes de um Tipo Abstrato de Dados de um Polinômio de coeficientes inteiros. Utilize uma lista circular duplamente ligada com no cabeca, mantendo sempre os coeficientes ordenados por grau. Somente os coeficientes nao zero devem ser armazenados.

- Para compilar e executar:
    ```bash 
    gcc -g -Wall -pedantic codlab02.c lab02.c polinomio.h -o execlab02
    
    ./execlab02

    for((i=1; i<8; i=i+1)); do ./execlab02 < ins/$i.in > ins/$i.meu; diff ins/$i.meu ins/$i.out; done



## [lab03](/lab03)
Dado um natural n, e uma coleção W de subconjuntos de
S={0,1,2,...,n-1}, encontrar um Wlinha subcoleção de W, se existir,
tal que cada elemento de S aparece em precisamente um dos conjuntos
dentro de Wlinha.

- Por exemplo:
    - Se n = 8, e 
    - W={A={0,1,2},B={0,2,4},C={1,2,5},D={2,4},
    E={1,3,5},F={3,5,7},G={2,7},H={1,6},I={2,4,6,7}}. 
    - Então, uma solução possível é Wlinha={B={0,2,4},F={3,5,7}, H={1,6}}.

A entrada dada representará um único caso de teste.  A primeira
linha da entrada contém um número natural n, representando o
tamanho do conjunto S.  A segunda linha contém um número natural m
representando o tamanho do conjunto W. As m linhas seguintes
conterão, cada uma delas, a representação de um elemento de W.
Cada elemento A de W será representado por uma linha que começa com
um número natural k, representando o número de elementos do
conjunto A, que é elemento de W. Em seguida, a linha representando
A conterá k números naturais, iguais aos elementos de A. Estes
número estarão ordenados.

Os casos de teste passados terão:
- 0 < n <= 15 e 0 < m <= 15. 

Caso a instância passada na entrada não tenha solução, seu programa
deve imprimir uma única linha contendo a palavra "Insoluvel" (sem
acentos).  Caso a instância passada na entrada tenha solução
Wlinha, seu programa deve imprimir uma linha contendo um natural R
igual ao número de elementos de Wlinha, seguida de R linhas, onde
cada linha representa um elemento de Wlinha. A representação de um
elemento A de Wlinha é igual àquela de elementos de W na entrada.

As entradas passadas ou 
- Não terão solução, ou 
- Terão solução única. 

Por exemplo, o caso descrito no exemplo acima seria representado por
uma entrada com as seguintes linhas: 

```
8 
9
3  0 1 2
3  0 2 4
3  1 2 5
2  2 4
3  1 3 5
3  3 5 7
2  2 7
2  1 6
4  2 4 6 7

A saída para a entrada do exemplo acima seria:
3
3  0 2 4
3  3 5 7
2  1 6
```


- Para compilar e executar:
    ```bash 
    gcc -g -Wall -pedantic codlab03.c -o execlab03
    
    ./execlab03

    for((i=0; i<8; i=i+1)); do ./execlab03 < ins/$i.in > ins/$i.meu; diff ins/$i.meu ins/$i.out; done


## [lab04](/lab04)
Considere o problema de dados conjunto S com n objetos, com funções peso P:S->N e valor V:S->N, e um natural M, encontrar um subconjunto X de S tal que a soma dos pesos dos elementos de X seja menor do que ou igual a M e cuja soma dos valores dos elementos de X seja máxima. Seu programa deve imprimir somente o valor ótimo de alguma solução ótima, sem precisar identificá-la. 

A entrada será dada na entrada padrão. A primeira linha conterá dois naturais n e M (n <=20, M<=10^6). As n linhas seguintes conterão 2 naturais cada, representando respectivamente o peso e o valor de um elemento de S.

A saída deve ser dada em uma única linha contendo um único inteiro que indica o valor ótimo de alguma solução ótima do problema. 

```
Exemplo de entrada:
5 100
30 1000
30 1100
30 1200
40 1500
40 1400

Exemplo de saída:
3800
```

- Para compilar e executar:
    ```bash 
    gcc -g -Wall -pedantic codlab04.c -o execlab04
    
    ./execlab04

    for((i=1; i<16; i=i+1)); do ./execlab04 < ins/$i.in > ins/$i.meu; diff ins/$i.meu ins/$i.out; done


## [lab05](/lab05)
Implemente as funções descritas no Arquivo arvore.h e as teste com os casos de entrada.

- Para compilar e executar:
    ```bash 
    gcc -g -Wall -pedantic Arvore.h lab05.c codlab05.c -o execlab05
    
    ./execlab05

    for((i=1; i<7; i=i+1)); do ./execlab05 < ins/$i.in > ins/$i.meu; diff ins/$i.meu ins/$i.out; done


## [lab06](/lab06)
Escreva um programa que leia uma única linha representando uma expressão aritmética. Esta expressão conterá somente os operadores +, -, *, /, % e sem parênteses em notação infixa. Todos os operandos desta linha serão números inteiros menores do que mil. Os operandos e operadores estarão separados por espaços. 

Após a leitura seu programa deve gerar uma árvore representando a expressão aritmética representada na linha, considerando a precedência de operadores: 
- maior para * e / 
- segunda maior para + e - 
- menor para %. 

Além disso, caso haja 2 operadores de mesma precedência em sequência, deve-se adotar associatividade à esquerda. 
- Por exemplo: 
    - 10-5-7=(10-5)-7. 

Em seguida seu programa deve imprimir a expressão aritmética em notação prefixa em uma única linha, com espaço separando operandos e operadores. Em seguida, ele deve imprimi-la em notação pós-fixa em uma única linha, com espaço separando operandos e operadores. Finalmente, o valor calculado da expressão deve ser impresso na linha final da saída.

- Para compilar e executar:
    ```bash 
    gcc -g -Wall -pedantic codlab06.c -o execlab06
    
    ./execlab06

    for((i=1; i<4; i=i+1)); do ./execlab06 < ins/$i.in > ins/$i.meu; diff ins/$i.meu ins/$i.out; done