for _ in range(int(input())):
	m=int(input().split()[1])
	sum1=sum(map(int,input().split()))
	if m==sum1:
		print("YES")
	else:
		print("NO")
