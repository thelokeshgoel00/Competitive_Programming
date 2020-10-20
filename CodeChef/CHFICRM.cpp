#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,x,i,five,ten,fifteen;
    cin>>t;
    int f=0;

    while(t--)
    {
        five=0;ten=0;fifteen=0;
        cin>>n;
        f=0;
        for(i=0;i<n;i++)
        {
            cin>>x;
            if(f==0)
            {

                if(x==5)
                    {
                        five+=1;
                    }
                else if(x==10)
                    {
                        if(five<1)
                        {
                            f = 1;
                        }
                        else{
                            ten+=1;
                            five-=1;
                        }
                    }
                else if(x==15)
                    {
                        if(ten<1)
                        {
                            if(five<2)
                            {
                                f = 1;
                            }
                            else{
                            five-=2;
                            fifteen+=1; 
                            }
                        }
                        else{
                            ten-=1;
                            fifteen+=1;
                        }
                    } 
            }
        }
        if(f==0)
            cout<<"YES\n";
            else{
                cout<<"NO\n";
            }
    }
    return 0;
}