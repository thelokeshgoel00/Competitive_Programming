#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long int maxSubsetSize(vector<long int> &);

int main()
{
    long int num;
    int divisor;

    cin>>num>>divisor;
    vector<long int> remainderFreq(divisor,0);

    for(long int i=0;i<num;i++)
    {
        long int element;
        int remainder;
        cin>>element;
        remainder = element%divisor;
        remainderFreq[remainder]++;
    }

    long int max = maxSubsetSize(remainderFreq);

    cout<<max<<endl;

    return(0);
}

long int maxSubsetSize(vector<long int> &freq)
{
    int length = freq.size();
    long int currentSize = 0;

    int checkIndex = length/2;
    for(int i=0;i<=checkIndex;i++)
    {
        if(i==0 || i == (length-i))
        {
            if(freq[i] != 0)
               currentSize++;
            continue;
        }

        currentSize += max(freq[i],freq[length-i]);
    }

    return(currentSize);
}

