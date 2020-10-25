def solve():
    n=int(input())
    row,col=(n,n)
    res=""
    for i in range(row):
        for j in range(col):
            if i==j:
                res+='1 '
            elif i==j-1:
                res+='1 '
            elif i==j+1:
                res+='1 '
            else:
                res+='0 '
        if i!=n-1:
            res+='\n'
    print(res)  

for _ in range(int(input())):
    solve()

