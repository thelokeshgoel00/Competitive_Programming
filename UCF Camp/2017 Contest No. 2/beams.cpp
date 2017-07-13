#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

int algo(string now){
    int ret = 0; bool removed = true; string ss = now;
    while(ss.length() > 0 && removed){
        int curRun = 1; char curLetter = ss[0];
        string temp = "";
        removed = false;
        for(int i = 1; i < ss.length(); i++){
            if(ss[i] == curLetter) curRun++;
            else{
                ret += curRun/2;
                if(curRun/2 > 0) removed = true;
                if(curRun%2 == 1) temp += ss[i-1];
                curRun = 1; curLetter = ss[i];
            }
        }
        if(curRun/2 > 0) removed = true;
        if(curRun%2 == 1) temp += ss[ss.length()-1];
        ret += curRun/2; ss = temp;
    }
    return ret+max(0, int(ss.length())-1)/2;
}

int ans;
string s;

int main(){
    string s; cin >> s;
    ans = algo(s);
    if(s.length() > 2 && s[0] == s[s.length()-1]) ans = max(ans, 1+algo(s.substr(1, s.length()-2)));
    cout << ans << '\n';
    return 0;
}
