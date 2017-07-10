#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    int n, arr [200], ret1 = 0; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        ret1 += temp*arr[i];
    }
    cin >> n; int ret2 = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        ret2 += temp*arr[i];
    }
    cout << ret1 << " " << ret2 << '\n';
    return 0;
}
