#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.14159265

int kase;
double x, y, n, travelAng, ret;

int main(){
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> x >> y >> n;
        travelAng = 2.0*PI/n-2.0*acos(x/(x+y));
        if(travelAng < 0) ret = sqrt(2*pow(x+y, 2)*(1-cos(2.0*PI/n)))-2*y;
        else ret = 2.0*sqrt(pow(x+y, 2.0)-pow(x, 2.0))+travelAng*x-2*y;
        printf("%.2lf\n", ret);
    }
    return 0;
}
