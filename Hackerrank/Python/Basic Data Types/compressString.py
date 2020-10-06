from itertools import groupby
i = input()
for c, x in groupby(i):
    print((len(list(x)),int(c)), end=' ')
    #print(x)