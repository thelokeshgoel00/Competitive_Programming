#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <unordered_set>

using namespace std;

struct Point{
    int x, y;
    Point(){ x = -1; y = -1; }
    bool operator<(const Point &other) const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

int N, tree [2501], numBuckets = 0;
long long ret = 0;
vector<Point> points;
vector<int> buckets [2501];
unordered_set<int> distinctY;

void add(int pos, int val){
    while(pos < 2501){
        tree[pos] += val;
        pos += (pos&-pos);
    }
}

long long query(int pos){
    int sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return (long long)(sum);
}

int main(){
    //freopen("shufflegold.in", "r", stdin); freopen("shufflegold.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        Point temp; scanf("%d %d", &temp.x, &temp.y);
        points.push_back(temp);
    }
    sort(points.begin(), points.end());
    for(int i = 0; i < N;){
        int temp = i;
        while(temp < N && points[temp].x == points[i].x){
            buckets[numBuckets].push_back(points[temp].y);
            temp++;
        }
        i = temp; numBuckets++;
    }
    for(int i = 0; i < numBuckets; i++){
        distinctY.clear(); memset(tree, 0, sizeof(tree));
        for(int j = 0; j < buckets[i].size(); j++)
            if(distinctY.find(buckets[i][j]) == distinctY.end()){
                distinctY.insert(buckets[i][j]);
                add(buckets[i][j], 1);
            }
        for(int j = i+1; j < numBuckets; j++){
            for(int k = 0; k < buckets[j].size(); k++)
                if(distinctY.find(buckets[j][k]) == distinctY.end()){
                    distinctY.insert(buckets[j][k]);
                    add(buckets[j][k], 1);
                }
            int last = 1, li = 0, ri = 0;
            while(li < buckets[i].size() && ri < buckets[j].size()){
                while(li < buckets[i].size() && buckets[i][li] < last) li++;
                while(ri < buckets[j].size() && buckets[j][ri] < last) ri++;
                if(li >= buckets[i].size() || ri >= buckets[j].size()) break;
                int mini = min(buckets[i][li], buckets[j][ri]);
                int maxi = max(buckets[i][li], buckets[j][ri]);
                if(mini == maxi) ret--;
                ret += (query(mini)-query(last-1))*(query(2500)-query(maxi-1));
                last = mini+1;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}
