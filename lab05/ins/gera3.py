import random

X=[]

for i in range(1000):
    x = (random.randint(0, 5000))
    print "insere", x
    print "imprime"
    X = X + [x]

print X
    
for i in range(500):
    x = (random.randint(0, len(X)-1))
    print "remove", X[x]
    print "imprime"
    
