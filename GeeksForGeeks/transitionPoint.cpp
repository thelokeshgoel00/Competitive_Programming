#include<iostream>
using namespace std;

// return transition point of a binary array, i.e. ,
// first occurence of 1 .
int minIndex1(int arr[],int l,int h) {
    if(l<=h) {
        int mid = (l+h)/2;
        if(arr[mid]==1) {
            if(mid == 0 )
                return mid;
            if(arr[mid-1] == 0)
                return mid;
            else
                return minIndex1(arr,l,mid-1);
        }
        else 
            return minIndex1(arr,mid+1,h);
    }
    return -1;
}

int transitionPoint(int arr[], int n) {
    return minIndex1(arr,0,n-1);
}

//driver code
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a[n], i;
		for (i = 0; i < n; i++) 
			cin>>a[i];
		cout<<transitionPoint(a, n);
	}
	return 0;
}



