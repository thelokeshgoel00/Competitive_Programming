#include <bits/stdc++.h>
using namespace std;
#define ss(n) scanf("%d", &n)
#define pp(n) printf("%d\n",n )
int cashe(int n, int b, int m, int *arr){
int count=1;
int pre = arr[0]/b;
	for(int i=1; i<m; i++){
			if(arr[i]/b !=pre){
				count++;
				pre = arr[i]/b;
			}
	}
	return count++;
}
int main(){
	int test;
	ss(test);
	while(test--){
		int n, b,m;
		ss(n);ss(b);ss(m);
		int *arr = new int[m];
		for(int i=0; i<m; i++)
			ss(arr[i]);
		int ans = cashe(n, b, m, arr);
		pp(ans);
	}
}
