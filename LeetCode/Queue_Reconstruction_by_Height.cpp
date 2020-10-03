// I've been expecting you <3
#include<bits/stdc++.h>
using namespace std;
bool sortcol( const vector<int>& v1, 
    const vector<int>& v2 ) { 
    return v1[0] < v2[0]; 
} 
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end(),sortcol);
    vector< vector<int> > v(people.size());
    for(int i=0;i<people.size(); i++){
        int cnt=0;
        for(int j=0;j<people[i][1];j++){
            auto it1=v[j].begin();
            auto it2=v[j].end();
            if(){
                cout<<"i am here!";
            }
        }
    }
}
int main(){
    vector<int,int>v={{1,2}};
    reconstructQueue(v);
}