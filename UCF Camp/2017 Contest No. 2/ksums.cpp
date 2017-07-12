#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

struct Window{
    long long sum;
    int id;
    Window(int a, long long b){ id = a; sum = b; }
    bool operator<(const Window &other) const{
        if(sum == other.sum) return id < other.id;
        return sum > other.sum;
    }
};

int main(){
    int n, winSize, num = 1; scanf("%d %d", &n, &winSize);
    long long curSum = 0ll, arr [100000];
    vector<Window> ret;
    for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    for(int i = 0; i < winSize-1; i++) curSum += arr[i];
    for(int i = winSize-1; i < n; i++){
        curSum += arr[i];
        ret.push_back(Window(num++, curSum));
        curSum -= arr[i-winSize+1];
    }
    sort(ret.begin(), ret.end());
    for(int i = 0; i < ret.size()-1; i++) cout << ret[i].id << " ";
    cout << ret[ret.size()-1].id << '\n';
    return 0;
}
