#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct Loc{
    vector<long> nums;
    long x, e;
    Loc(vector<long> a, long b, long c){
        for(int i = 0; i < a.size(); i++) nums.push_back(a[i]);
        x = b; e = c;
    }
    bool operator<(const Loc &other) const{
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != other.nums[i])
                return nums[i] < other.nums[i];
        return x < other.x;
    }
    bool eq(Loc other){
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != other.nums[i])
                return false;
        return true;
    }
};

int K, N;
//bal = prefix sum before jth character of ith string; ( = +1, ) = -1
//ending[i][j] = the first place in the bracket sequence i where the range [j,ending[i][j]] has more ) than ( 
long bal [15][60000], ending [15][60000];
long long ret = 0;
vector<Loc> locs;

int main(){
    freopen("cbs.in", "r", stdin); freopen("cbs.out", "w", stdout);
    scanf("%d %d", &K, &N);
    for(int i = 0; i < K; i++){
        bal[i][0] = 2*N; char now [60000]; scanf("%s", &now); long last [4*N];
        for(int j = 0; j < 4*N; j++) last[j] = N+2;
        for(int j = 1; j <= N; j++){
            bal[i][j] = bal[i][j-1];
            if(now[j-1] == '(') bal[i][j]++;
            else bal[i][j]--;
        }
        for(int j = N; j > -1; j--){
            ending[i][j] = last[bal[i][j]-1];
            last[bal[i][j]] = j;
        }
    }
    for(int i = 0; i <= N; i++){
        vector<long> li; long en = ending[0][i];
        for(int j = 0; j < K; j++){
            en = min(en, ending[j][i]);
            li.push_back(bal[j][i]);
        }
        locs.push_back(Loc(li, i, en));
    }
    sort(locs.begin(), locs.end());
    for(int i = 0; i <= N; i++){
        if(i != 0 && locs[i].eq(locs[i-1])) continue;
        vector<Loc> stuff;
        for(int j = i; j <= N; j++){
            if(!locs[i].eq(locs[j])) break;
            stuff.push_back(locs[j]);
        }
        for(int j = 0; j < stuff.size(); j++){
            int low = j; int high = stuff.size()-1;
            while(low < high){
                int mid = (low+high+1)/2;
                if(stuff[mid].x <= stuff[j].e) low = mid;
                else high = mid-1;
            }
            ret += (long long)(low-j);
        }
    }
    cout << ret << endl;
    return 0;
}
