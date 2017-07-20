#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string.h>
#include <math.h>

using namespace std;

int n, arr [50], ret;
vector<int> times;
bool used [50];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n); memset(used, false, sizeof(used));
    int freq15 = 0;
    while(arr[freq15] == 15){ freq15++; }
    ret = freq15/3; freq15 -= freq15%3;
    for(int i = freq15; i < n; i++) times.push_back(arr[i]);
    for(int i = 0; i < times.size(); i++){
        //cout << times[i] << endl;
        if(used[i]) continue;
        int buddyIndex = -1;
        for(int j = i+1; j < times.size(); j++){
            if(used[j]) continue;
            if(times[i]+times[j] <= 45) buddyIndex = j;
            else break;
        }
        used[i] = true;
        if(buddyIndex != -1) used[buddyIndex] = true;
        ret++;
    }
    cout << ret << '\n';
    return 0;
}
