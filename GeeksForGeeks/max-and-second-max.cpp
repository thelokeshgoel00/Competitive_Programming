vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = INT_MIN, max2= INT_MIN;
    map<int,int>m1;
    for(int i=0;i<sizeOfArray;i++){
        m1[arr[i]]++;
    }
    auto it = m1.rbegin();
    vector<int>res;
    res.push_back(it->first);
    it++;
    if(it==m1.rend()){
        res.push_back(-1);
    }
    else res.push_back(it->first);
    return res;
    /*********************************
     * Your code here
     * This function should return a
     * vector with first element as
     * max and second element as 
     * second max
     * *******************************/
     
}

//solution-2
    
    package java_assignment;

import java.util.Scanner;

public class ques_3 
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter no of items: ");
		int n=sc.nextInt();
		int arr[]=new int[n];
		System.out.print("Enter The elements: ");
		for(int i=0;i<n;i++)
		{
			arr[i]=sc.nextInt();
        }
		int temp=2;
		int j=0;
		while(temp!=0)
		{
			int max=0;
			for(int i=0;i<n-j;i++)
			{
				if(arr[i]>arr[max])
					max=i;
			}
			System.out.print(arr[max]+" ");
			int t=arr[max];
			arr[max]=arr[n-1-j];
			arr[n-1-j]=t;
			j++;
			temp--;
		}
	}
}
