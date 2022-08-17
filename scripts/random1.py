from random import randint
import sys

n = int(sys.argv[1])

filename = f"{sys.argv[2]}/array_{n}.txt"
with open(filename,"w") as fp:
    fp.write(f"{n} ")
    for _ in range(1, n):
        x = randint(-n,n)
        fp.write(f"{str(x)} ")
    x = randint(-n,n)
    fp.write(f"{str(x)} ")
    
