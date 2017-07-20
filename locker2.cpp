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

int n, arr [50], ret = 0;
vector<int> times;
bool used [50];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n); memset(used, false, sizeof(used));
    for(int i = 0; i < n; i++){
        if(arr[i] > 30) ret++;
        else times.push_back(arr[i]);
    }
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
        if(buddyIndex != -1){
            if(times[buddyIndex] == 15 && buddyIndex-i > 1){
                int nindex = buddyIndex-(buddyIndex-i+1)%3;
                for(int j = i+1; j <= nindex; j++) used[j] = true;
                ret += (buddyIndex-i+1)/3;
                continue;
            }
            used[buddyIndex] = true;
        }
        ret++;
    }
    cout << ret << '\n';
    return 0;
}
