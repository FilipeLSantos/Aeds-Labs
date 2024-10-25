import random

X=[]

for i in range(100):
    x = (random.randint(0, 1000))
    print "insere", x
    print "imprime"
    X = X + [x]

print X
    
for i in range(100):
    x = (random.randint(0, 99))
    print "remove", X[x]
    print "imprime"
    
