#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

int n, ordering, curPos, curAdd;
vector<string> toppings, ret;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        toppings.push_back(s);
    }
    sort(toppings.begin(), toppings.end());
    cin >> ordering;
    for(int i = n; i > 0; i--){
        if(((1<<i)&ordering) > 0) continue;
        int temp = ordering%(1<<i)-1;
        if(temp < 0) temp = (1<<i)-1;
        ordering = ordering/(1<<i)*(1<<i)+temp;
        //cout << ordering << '\n';
    }
    for(int i = 0; i < n; i++)
        if(((1<<(n-1-i))&ordering) == 0)
            ret.push_back(toppings[i]);
    cout << ret[0];
    for(int i = 1; i < ret.size(); i++) cout << " " << ret[i];
    cout << '\n';
    return 0;
}

/*

***Alternate Method by Arup***

int rank = stdin.nextInt();

boolean space = false;
for(int i = 0; i < n; i++){
   
    // Nothing more to print.
    if (rank <= 0) break;
    
    // In this situation, we want topping i.
    if (rank <= (1<<(n-i-1))) {
        if (space) System.out.print(" ");
        System.out.print(toppings[i]);
        space = true;

        // This is only one item we are going past, in terms of rank.
        rank--;
    }

    // Don't print and subtract out this bit mask, for all the ranks we're skipping.
    else rank -= (1<<(n-i-1));
}

*/
