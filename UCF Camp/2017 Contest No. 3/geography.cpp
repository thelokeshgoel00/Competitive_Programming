#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int main(){
    int numCities, numRoads, counter = 0; vector<int> adjacency [510]; scanf("%d %d", &numCities, &numRoads);
    for(int i = 0; i < numRoads; i++){
        int a, b; scanf("%d %d", &a, &b);
        adjacency[a].push_back(b);
    }
    for(int i = 1; i <= numCities; i++){
        bool visited [510]; memset(visited, false, sizeof(visited));
        queue<int> q; q.push(i);
        while(q.size() > 0){
            int now = q.front(); q.pop();
            if(visited[now]) continue;
            visited[now] = true; counter++;
            for(int x = 0; x < adjacency[now].size(); x++)
                if(!visited[adjacency[now][x]])
                    q.push(adjacency[now][x]);
        }
    }
    cout << counter-numCities << '\n';
    return 0;
}
