#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int ret = 0, temp = 0;
string stuff;
stack<char> brackets;

int main(){
    freopen("clumsy.in", "r", stdin); freopen("clumsy.out", "w", stdout);
    cin >> stuff;
    for(int i = 0; i < stuff.length(); i++){
        char c = stuff[i];
        if(c == ')' && brackets.size() > 0 && brackets.top() == '(') brackets.pop();
        else brackets.push(c);
    }
    ret = brackets.size()/2;
    while(brackets.size() > 0 && brackets.top() == '('){ brackets.pop(); temp++; }
    ret += temp%2;
    cout << ret << endl;
    return 0;
}
