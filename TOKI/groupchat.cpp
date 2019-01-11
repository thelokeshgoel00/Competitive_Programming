/*
Solution
	- Apply (x, y) -> (x+y, x-y) so the distance function is now max(|x1-x2|, |y1-y2|)
	- Binary search by answer
	- Problem becomes to check if some points can be covered by 2 squares
	- We test both pairs of squares with corners at opposite sides of the bounding box
*/

#include "group.h"
#include <bits/stdc++.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 1e-9
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int getMinimumDelay(int N, vector<int> x, vector<int> y){
	  long long minX = 2*MOD, maxX = -2*MOD, minY = 2*MOD, maxY = -2*MOD;
	  for(int i = 0; i < N; i++){
		    x[i] = x[i]+y[i]; y[i] = x[i]-2*y[i];
		    minX = min(minX, (long long)x[i]); maxX = max(maxX, (long long)x[i]);
		    minY = min(minY, (long long)y[i]); maxY = max(maxY, (long long)y[i]);
	  }
	  long long lo = 0, hi = 2*MOD; int ret;
	  while(lo <= hi){
		    long long mid = (lo+hi)/2;
		    bool one = true, two = true;
		    for(int i = 0; i < N; i++){
			      one &= (x[i] <= minX+mid && y[i] <= minY+mid)||(x[i] >= maxX-mid && y[i] >= maxY-mid);
			      two &= (x[i] <= minX+mid && y[i] >= maxY-mid)||(x[i] >= maxX-mid && y[i] <= minY+mid);
		    }
		    if(one || two){ hi = mid-1; ret = (int)mid; }
		    else lo = mid+1;
	  }
	  return ret;
}
