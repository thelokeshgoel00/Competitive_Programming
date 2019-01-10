#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h>

using namespace std;

int M, N = 0, pointer = 0;
long long ret = 0;
pair<long long, long long> original [50000], rects [50000];
vector<pair<long, long>> lines;

bool bad(int a, int b, int c){
    return (lines[c].second-lines[a].second)*(lines[a].first-lines[b].first)
    < (lines[b].second-lines[a].second)*(lines[a].first-lines[c].first);
}

void add(long long slope, long long intercept){
    lines.push_back(make_pair(slope, intercept));
    while(lines.size() >= 3 && bad(lines.size()-3, lines.size()-2, lines.size()-1)) lines.erase(lines.end()-2);
}

long long query(long long val){
    if(pointer > lines.size()-1) pointer = lines.size()-1;
    while(pointer < lines.size()-1 && lines[pointer+1].first*val+lines[pointer+1].second < lines[pointer].first*val+lines[pointer].second)
        pointer++;
    return lines[pointer].first*val+lines[pointer].second;
}

int main(){
    scanf("%d", &M);
    for(int i = 0; i < M; i++) scanf("%lld %lld", &original[i].first, &original[i].second);
    sort(original, original+M);
    for(int i = 0; i < M; i++){
        while(N > 0 && rects[N-1].second <= original[i].second) N--;
        rects[N++] = original[i];
    }
    add(rects[0].second, 0);
    for(int i = 0; i < N; i++){
        ret = query(rects[i].first);
        if(i < N-1) add(rects[i+1].second, ret);
    }
    cout << ret << '\n';
    return 0;
}
