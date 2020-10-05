// Using stack
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    stack<char> s;   
	    int res=1;  //res=0 means unbalanced, 1 means balanced
	    for(int i=0;i<str.length();i++)
	    {
	        if(str[i]=='(' || str[i]=='{'|| str[i]=='[')
	       {
	       		// push opening brackets into stack
	           s.push(str[i]);
	       }
	        else if(s.empty())    
	        {
	            res=0;   // if character is closing bracket, stack should not be empty
	        }
	        else 
	        {
	        	// if corresponding opening bracket is not found means expression is unbalanced
	            if(str[i]==')')
	            {
	                if(s.top()!='(')
	                    res=0;
	                    s.pop();
	            }
	            else if(str[i]=='}')
	            {
	                if(s.top()!='{')
	                    res=0;
	                    s.pop();
	            }
	            else
	            {
	                if(s.top()!='[')
	                res=0;
	                s.pop();
	            }
	        }
	        if(res==0)
	                break;
	    }
	    if(!s.empty()) // no character must be left in stack
	        res=0;
	    if(res==1)
	        cout<<"balanced\n";
	    else
	        cout<<"not balanced\n";
	}
	return 0;
}
