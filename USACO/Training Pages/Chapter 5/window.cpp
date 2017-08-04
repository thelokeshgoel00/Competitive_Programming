/*
ID: vamaddu1
PROG: window
LANG: C++11
*/

#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

struct Screen{
    int x1, y1, x2, y2, level;
    Screen(){ }
    Screen(int a, int b, int c, int d, int e){ x1 = a; y1 = b; x2 = c; y2 = d; level = e; }
    bool operator<(Screen const &other) const{ return level < other.level; }
};

int a, b, c, d, top = 0, bot = 0;
char filling, oper, id;
map<char, Screen> screens;
vector<Screen> data;

int coverIt(int x1, int y1, int x2, int y2, int index){
    while(index < data.size() && (x1 >= data[index].x2 || x2 <= data[index].x1 || y1 >= data[index].y2 || y2 <= data[index].y1)) index++;
    if(index == data.size()) return (x2-x1)*(y2-y1);
    int ret = 0;
    if(x1 < data[index].x1){
        ret += coverIt(x1, y1, data[index].x1, y2, index);
        x1 = data[index].x1;
    }
    if(x2 > data[index].x2){
        ret += coverIt(data[index].x2, y1, x2, y2, index);
        x2 = data[index].x2;
    }
    if(y1 < data[index].y1){
        ret += coverIt(x1, y1, x2, data[index].y1, index);
        y1 = data[index].y1;
    }
    if(y2 > data[index].y2){
        ret += coverIt(x1, data[index].y2, x2, y2, index);
        y2 = data[index].y2;
    }
    return ret;
}

int main(){
    freopen("window.in", "r", stdin); freopen("window.out", "w", stdout);
    while(cin >> oper){
        if(oper == 'w'){
            cin >> filling >> id >> filling >> a >> filling >> b >> filling >> c >> filling >> d >> filling;
            if(a > c) swap(a, c);
            if(b > d) swap(b, d);
            screens[id] = Screen(a, b, c, d, ++top);
        }
        else if(oper == 't'){
            cin >> filling >> id >> filling;
            screens[id].level = ++top;
        }
        else if(oper == 'b'){
            cin >> filling >> id >> filling;
            screens[id].level = --bot;
        }
        else if(oper == 'd'){
            cin >> filling >> id >> filling;
            screens.erase(screens.find(id));
        }
        else{
            cin >> filling >> id >> filling; data.clear();
            for(auto it = screens.begin(); it != screens.end(); it++){
                if(it->second.level <= screens[id].level) continue;
                Screen temp = it->second;
                temp.x1 = max(temp.x1, screens[id].x1);
                temp.y1 = max(temp.y1, screens[id].y1);
                temp.x2 = min(temp.x2, screens[id].x2);
                temp.y2 = min(temp.y2, screens[id].y2);
                if(temp.x1 >= temp.x2 || temp.y1 >= temp.y2) continue;
                data.push_back(temp);
            }
            sort(data.begin(), data.end());
            double area = (screens[id].x2-screens[id].x1)*(screens[id].y2-screens[id].y1), covered = 0.0;
            for(int i = data.size()-1; i > -1; i--) covered += coverIt(data[i].x1, data[i].y1, data[i].x2, data[i].y2, i+1);
            printf("%.3lf\n", 100.0*(1-covered/area));
        }
    }
    return 0;
}
