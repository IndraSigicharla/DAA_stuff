import sys

n = int(sys.argv[1])

if sys.argv[2] == 'inc':
    filename = f"{sys.argv[3]}/ascending_{n}.txt"
    with open(filename,"w") as fp:
        fp.write(f"{n} ")
        for i in range(1, n + 1):
            fp.write(f"{str(i)} ")

if sys.argv[2] == 'dec':
    filename = f"{sys.argv[3]}/descending_{n}.txt"
    with open(filename,"w") as fp:
        fp.write(f"{n} ")
        for i in range(n, 0, -1):
            fp.write(f"{str(i)} ")

# python generate.py <number of elements> <a/d>

