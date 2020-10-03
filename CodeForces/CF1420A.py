#Cube Sorting Div-2 24th sep
def merge(v, temp, l, m, r): 
    count = 0
  
    i,j,k = l,m,l
    while ((i <= m - 1) and (j <= r)): 
        if (v[i] <= v[j]): 
            temp[k] = v[i] 
            k += 1
            i += 1
        else: 
            temp[k] = v[j] 
            k += 1
            j += 1
  

            count = count + (m - i) 
  

    while (i <= m - 1): 
        temp[k] = v[i] 
        k += 1
        i += 1
  

    while (j <= r): 
        temp[k] = v[j] 
        k += 1
        j += 1
  

    for i in range(l,r+1,1): 
        v[i] = temp[i] 
  
    return count 
  

def mSort(v, temp, l, r): 
    count = 0
    if (r > l): 
        m = int((r + l)/2) 
  
        count = mSort(v, temp, l, m) 
        count += mSort(v, temp, m+1, r) 
  
        count += merge(v, temp, l, m+1, r) 
  
    return count 
  

def countSwaps(v, n): 
    temp = [0 for i in range(n)] 
    return mSort(v, temp, 0, n - 1) 
  

T=int(input())
while T!=0:
    n=int(input())
    v=[int(i) for i in input().split()] 
    flag=1
    n = len(v) 
    if countSwaps(v, n)> (n*(n-1)/2)-1:
        flag=0
    
    if flag==0:
        print('NO')
    else:
        print('YES')
    T-=1