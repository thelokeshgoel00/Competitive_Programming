//I've been expecting you <3
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
string longDivide(string s){
    int idx=-1;
    int temp=0;
    while(2>temp){
        temp=temp*10+(s[++idx]-'0');
    }
    string ans="";
    while(s.length()>idx){
        ans+=temp/2+'0';
        temp=(temp%2)*10+(s[++idx]-'0');
    }
    if(ans.length()==0){
        return "0";
    }
    else return ans;
}
string longSubtract(string s1,string s2)
{
    if (s1.length() > s2.length())
    {
        swap(s1, s2);
    }
    else if (s2.length() == s1.length())
    {
        for (int i = 0; i < s1.length(); i++)
        {
            if ((s1[i] - '0') > (s2[i] - '0'))
            {
                swap(s1, s2);
                break;
            }
        }
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int i, carry = 0;
    string ans = "";
    for (i = 0; i < s1.length(); i++)
    {
        int sub = (s2[i] - '0') - (s1[i] - '0') - carry;
        if (sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else
            carry = 0;
        ans += (sub + '0');
    }
    for (; i < s2.length(); i++)
    {
        int sub = (s2[i] - '0') - carry;
        if (sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else
            carry = 0;
        ans += (sub + '0');
    }
    i = 0;
    reverse(ans.begin(), ans.end());
    while (ans[i] == '0')
    {
        // cout<<ans[i]
        i++;
    }
    ans.erase(0, i);
    return ans;
}
string longSum(string s1, string s2) 
{ 
    if (s1.length() > s2.length()) 
        swap(s1, s2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = s1.length(), n2 = s2.length(); 
  
    // Reverse both of strings 
    reverse(s1.begin(), s1.end()); 
    reverse(s2.begin(), s2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((s1[i]-'0')+(s2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((s2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
int main()
{
    int t=10;
    while (t--)
    {
        string s1, s2;
        cin >> s1;
        cin >> s2;
        string Klaudia=longDivide(longSubtract(s1,s2));
        string Natalia=longSum(Klaudia,s2);
        cout<<Natalia<<endl<<Klaudia<<endl;
    }
}