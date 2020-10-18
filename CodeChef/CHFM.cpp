#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    vector<long long int>::iterator it;
    long long int mean,x,sum;
    vector<long long int> v;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        v.clear();
        sum=0;
        for(int j=0;j<n;j++){
            cin>>x;
            v.push_back(x);
            sum+=x;
        }
        // sum = accumulate(v.begin(),v.end(),0);
        if(sum%n!=0){
             cout << "Impossible\n";
            //  cout<<sum%n<<"\n";
        }
        else{
            mean = sum/n;     
            it = find(v.begin(), v.end(),mean);
            if(it != v.end())
                cout << it-v.begin()+1 << "\n";
            else
                cout << "Impossible\n";
         }
    }
    return 0;
}