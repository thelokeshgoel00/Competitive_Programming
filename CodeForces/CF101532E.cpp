#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int kase, N;
long long wanted, ret;
vector<vector<long long>> li, ri;
unordered_map<long long, long long> leftFreq, rightFreq;

void recurseLeft(int index, long long curProduct){
    if(index == li.size()){
        if(leftFreq.find(curProduct) == leftFreq.end()) leftFreq[curProduct] = 0ll;
        leftFreq[curProduct]++;
        return;
    }
    for(int i = 0; i < 6; i++) recurseLeft(index+1, (curProduct*li[index][i])%MOD);
}

void recurseRight(int index, long long curProduct){
    if(index == ri.size()){
        if(rightFreq.find(curProduct) == rightFreq.end()) rightFreq[curProduct] = 0ll;
        rightFreq[curProduct]++;
        return;
    }
    for(int i = 0; i < 6; i++) recurseRight(index+1, (curProduct*ri[index][i])%MOD);
}

long long modInverse(long long a, long long m){ //Assume That a and m are relatively prime to each other
    long long m0 = m, t, q;
    long long x0 = 0ll, x1 = 1ll;
    while(a > 1ll){
        // q is quotient
        q = a/m;
        t = m;
        // m is remainder now, process same as
        // Euclid's Algorithm
        m = a%m, a = t;
        t = x0;
        x0 = x1-q*x0;
        x1 = t;
    }
    // Make x1 positive
    if(x1 < 0) x1 += m0;
    return x1;
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d", &kase);
    for(int kk = 1; kk <= kase; kk++){
        scanf("%d %I64d", &N, &wanted); ret = 0ll;
        li.clear(); ri.clear();
        leftFreq.clear(); rightFreq.clear();
        for(int i = 0; i < N/2; i++){
            vector<long long> temp;
            for(int j = 0; j < 6; j++){
                long long x; scanf("%I64d", &x);
                temp.push_back(x);
            }
            li.push_back(temp);
        }
        for(int i = N/2; i < N; i++){
            vector<long long> temp;
            for(int j = 0; j < 6; j++){
                long long x; scanf("%I64d", &x);
                temp.push_back(x);
            }
            ri.push_back(temp);
        }
        if(li.size() == 0){
            for(int i = 0; i < 6; i++)
                if(ri[0][i] == wanted)
                    ret++;
            printf("%I64d\n", ret);
        }
        recurseLeft(0, 1ll); recurseRight(0, 1ll);
        //cout << li.size() << " " << ri.size() << endl;
        //for(auto it = rightFreq.begin(); it != rightFreq.end(); it++) cout << it->first << " " << it->second << endl;
        for(auto it = leftFreq.begin(); it != leftFreq.end(); it++){
            long long MI = (modInverse(it->first, MOD)*wanted)%MOD;
            //cout << it->first << /*" " << MI << " " << rightFreq[MI] <<*/ " " << it->second << endl;
            ret += it->second*rightFreq[MI];
        }
        printf("%I64d\n", ret);
    }
    return 0;
}
