#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

int fenwick [1000001];

void add(int pos, int val){
    while(pos < 1000001){
        fenwick[pos] += val;
        pos += (pos&-pos);
    }
}
long long query(int pos){
    long long sum = 0;
    while(pos > 0){
        sum += fenwick[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

int n, arr [1000001], ri [1000001], freq [1000001], id = 1;
long long ret = 0ll;
map<int, int> reassign;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int x; scanf("%d", &x);
        if(reassign.find(x) == reassign.end()) reassign.insert(pair<int, int>(x, id++));
        arr[i] = reassign.find(x)->second;
    }
    for(int i = n; i > 0; i--){
        freq[arr[i]]++; ri[i] = freq[arr[i]];
        add(ri[i], 1);
    }
    memset(freq, 0, sizeof(freq));
    for(int i = 1; i <= n; i++){
        add(ri[i], -1); freq[arr[i]]++;
        ret += query(freq[arr[i]]-1);
    }
    cout << ret << endl;
    return 0;
}
