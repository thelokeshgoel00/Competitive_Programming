#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int citizens;
long long give, arr [100000], ret = 0;

int main(){
    scanf("%d %lld", &citizens, &give);
    for(int i = 0; i < citizens; i++) scanf("%lld", &arr[i]);
    long long low = 0; long long high = 2000000000000;
    while(low <= high){
        long long mid = (low+high)/2; long long temp = give;
        for(int i = 0; i < citizens; i++){
            temp -= max(0ll, mid-arr[i]);
            if(temp < 0) break;
        }
        if(temp < 0) high = mid-1;
        else{ ret = mid; low = mid+1;}
    }
    cout << ret << '\n';
    return 0;
}
