#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>

using namespace std;

struct Cow{
    int id, pos [5];
    Cow(){ id = -1; for(int i = 0; i < 5; i++) pos[i] = -1; }
    bool operator<(const Cow &other) const{
        int beat = 0;
        for(int i = 0; i < 5; i++)
            if(pos[i] < other.pos[i])
                beat++;
        return beat > 2;
    }
};

int N;
map<int, int> brand;
vector<Cow> cows;

int main(){
    freopen("photo.in", "r", stdin); freopen("photo.out", "w", stdout);
    scanf("%d", &N);
    for(int j = 0; j < N; j++){
        int x; scanf("%d", &x);
        brand.insert(make_pair(x, j)); Cow temp; temp.id = x; temp.pos[0] = j;
        cows.push_back(temp);
    }
    for(int i = 1; i < 5; i++)
        for(int j = 0; j < N; j++){
            int x; scanf("%d", &x);
            cows[brand.find(x)->second].pos[i] = j;
        }
    sort(cows.begin(), cows.end());
    for(int i = 0; i < N; i++) cout << cows[i].id << endl;
    return 0;
}
