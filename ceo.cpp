#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

#define rating first
#define startTime second

typedef pair<int, int> Player;
//Player.first = rating;
//Player.second = startTime;

struct Event{
    int meetTime, rating1, rating2, time1, time2;
    Event(int a, int b, int c, int d, int e){ meetTime = a; rating1 = b; rating2 = c; time1 = d; time2 = e; }
    bool operator>(const Event &other) const{
        if(meetTime == other.meetTime){
            if(time1 == other.time1) return time2 > other.time2;
            return time1 > other.time1;
        }
        return meetTime > other.meetTime;
    }
};

int n, wait, ret = 0, playerIter = 1, curTime = 0;
Player players [100001];
set<Player> inQueue;
priority_queue<Event, vector<Event>, greater<Event>> events;

int main(){
    /*set<int> test;
    test.insert(2); test.insert(1);
    auto dist = distance(test.begin(), test.find(2));
    cout << dist << endl;*/
    scanf("%d %d", &n, &wait);
    for(int i = 1; i <= n; i++) scanf("%d %d", &players[i].startTime, &players[i].rating);
    while(playerIter <= n || events.size() > 0){
        if(playerIter <= n && (events.size() == 0 || (events.top().meetTime > players[playerIter].startTime))){
            curTime = players[playerIter].startTime;
            inQueue.insert(players[playerIter]);
            auto index = inQueue.find(players[playerIter]);
            auto hindex = next(index);
            if(hindex != inQueue.end()){
                Player p = *hindex;
                int when = max(max(players[playerIter].startTime, p.startTime),
                               abs(players[playerIter].rating-p.rating)+min(players[playerIter].startTime, p.startTime));
                Event temp = Event(when, players[playerIter].rating, p.rating, players[playerIter].startTime, p.startTime);
                if(players[playerIter].startTime > p.startTime){
                    swap(temp.time1, temp.time2);
                    swap(temp.rating1, temp.rating2);
                }
                events.push(temp);
            }
            if(index != inQueue.begin()){
                auto lindex = prev(index);
                Player p = *lindex;
                int when = max(max(players[playerIter].startTime, p.startTime),
                               abs(players[playerIter].rating-p.rating)+min(players[playerIter].startTime, p.startTime));
                Event temp = Event(when, players[playerIter].rating, p.rating, players[playerIter].startTime, p.startTime);
                if(players[playerIter].startTime > p.startTime){
                    swap(temp.time1, temp.time2);
                    swap(temp.rating1, temp.rating2);
                }
                events.push(temp);
            }
            playerIter++;
        }
        else{
            Event e = events.top(); events.pop();
            if(inQueue.find(Player(e.rating1, e.time1)) == inQueue.end() || inQueue.find(Player(e.rating2, e.time2)) == inQueue.end()) continue;
            curTime = e.meetTime;
            if(curTime-e.time1 >= wait) ret++;
            if(curTime-e.time2 >= wait) ret++;
            auto index1 = e.rating1 < e.rating2 ? inQueue.find(Player(e.rating1, e.time1)) : inQueue.find(Player(e.rating2, e.time2));
            auto index2 = e.rating1 > e.rating2 ? inQueue.find(Player(e.rating1, e.time1)) : inQueue.find(Player(e.rating2, e.time2));
            auto hindex = next(index2);
            if(index1 != inQueue.begin() && index2 != inQueue.begin()){
                auto lindex = prev(index1);
                Player p1 = *lindex; Player p2 = *hindex;
                int when = max(max(p1.startTime, p2.startTime),
                               abs(p1.rating-p2.rating)+min(p1.startTime, p2.startTime));
                Event temp = Event(when, p1.rating, p2.rating, p1.startTime, p2.startTime);
                if(p1.startTime > p2.startTime){
                    swap(temp.time1, temp.time2);
                    swap(temp.rating1, temp.rating2);
                }
                events.push(temp);
            }
            inQueue.erase(Player(e.rating1, e.time1)); inQueue.erase(Player(e.rating2, e.time2));
        }
    }
    cout << ret+inQueue.size() << '\n';
    return 0;
}
