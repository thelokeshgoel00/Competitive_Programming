#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

class BIT{
    public:
        int maxi;
        long long tree [20500];
        BIT(int len): maxi(len) {}
        void add(int pos, long long x){
            while(pos <= maxi){
                tree[pos] += x;
                pos += (pos&-pos);
            }
        }
        long long query(int pos){
            long long sum = 0ll;
            while(pos > 0){
                sum += tree[pos];
                pos -= (pos&-pos);
            }
            return sum;
        }
};

int kase, num, pos, arr [20500];

int main(){
    scanf("%d", &kase);
    for(int kk = 1; kk <= kase; kk++){
        scanf("%d", &num); pos = 1;
        BIT fenwick(num);
        for(int i = 1; i <= num; i++) fenwick.add(i, 1);
        for(int i = 1; i <= num; i++){
            pos = (pos+i)%(num-i+1); if(pos == 0) pos = num-i+1;
            int s = 1; int e = num;
            while(s <= e){
                int mid = (s+e)/2;
                //cout << "check1" << endl;
                if(fenwick.query(mid) >= pos) e = mid-1;
                else s = mid+1;
                //cout << "check2" << endl;
            }
            //cout << "check3" << endl;
            arr[s] = i; fenwick.add(s, -1);
            //cout << s << arr[s] << endl;
        }
        stringstream ret; ret << arr[1];
        for(int i = 2; i <= num; i++) ret << " " << arr[i];
        cout << ret.str() << endl;
    }
    return 0;
}
