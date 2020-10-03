#include <bits/stdc++.h> 

int main(){
  int numCubes, tolerance;
  long long mod = 1000000009ll, res = 1ll;
  scanf("%d%d", &numCubes, &tolerance); int cubes[numCubes];
  for(int i = 0; i < numCubes; i++){
    int x; scanf("%d", &x); cubes[i] = x;
  }
  std::sort(cubes, cubes+numCubes);
  int p1 = 0, p2 = 0;
  for(int i = 1; i < numCubes; i++){
    p2 = i; while(p1 < p2 && cubes[p1] + tolerance < cubes[p2]) p1++;
    res = (res*(p2-p1+1))%mod;
  }
  std::cout << res;
  return 0;
} 
