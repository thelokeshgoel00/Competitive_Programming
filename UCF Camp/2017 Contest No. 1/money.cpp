#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

//Hi Senpai Arup - Viraj

int main(){
    int coins, ret = 0, target, arr [15]; cin >> coins >> target;
    for(int i = 0; i < coins; i++) cin >> arr[i];
    for(int mask = 0; mask < (1<<coins); mask++){
        int curr = 0;
        for(int j = 0; j < coins; j++)
            if((mask&(1<<j)) > 0)
                curr += arr[j];
        if(curr == target) ret++;
    }
    cout << ret << '\n';
    return 0;
}
