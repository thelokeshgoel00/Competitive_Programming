#include<bits/stdc++.h>
using namespace std;

void showdq(deque <char> g) 
{ 
    deque <char> :: iterator it; 
    for (it = g.begin(); it != g.end(); ++it) 
        cout <<*it; 
    cout << '\n'; 
}

int main() {
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n=s.size();
        deque<char> q;
        for(int i=0;i<n;i++){
            if(n%2 != 0){
                int x=s[i];
                if(i%2 != 0){q.push_front(x);}
                else {q.push_back(x);}
            }
            else{
                int x=s[i];
                if(i%2 != 0){q.push_back(x);}
                else {q.push_front(x);}
            }
        }
        showdq(q);
    }
}