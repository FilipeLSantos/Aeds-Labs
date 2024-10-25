from random import randrange
n = 15
m = 17
k = 4
print n
print m
for i in range(m):
    V = [0 for nada in range(n)]
    conta = 0
    for j in range(k):
        x = randrange(n)
        if (V[x] == 0):
            conta += 1
        V[x] += 1
    print conta, 
    for j in range(n):
        if (V[j] > 0):
            print j, 
    print
