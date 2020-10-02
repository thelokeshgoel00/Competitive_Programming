#include <bits/stdc++.h>
using namespace std;

int main()
{
    int attendies,subjects,maxTeamKnowledge = 0,teamKnowledge;
    long count=0;

    cin>>attendies>>subjects;
    string attendiesKnowledge[attendies];

    for(int i=0;i<attendies;i++)
       cin>>attendiesKnowledge[i];
    
    for(int i=0;i<attendies-1;i++)
    {
        for(int j=i+1;j<attendies;j++)
        {
           teamKnowledge = 0;
           for(int k=0;k<subjects;k++)
           {
               int firstMemberKnowledge = int(attendiesKnowledge[i][k])-48;
               int secondMemberKnowledge = int(attendiesKnowledge[j][k])-48;
               teamKnowledge += firstMemberKnowledge|secondMemberKnowledge;
           }
           if(teamKnowledge > maxTeamKnowledge)
           {
               maxTeamKnowledge = teamKnowledge;
               count = 0;
           }
          if(teamKnowledge == maxTeamKnowledge)
           count++;
        }
    }
    cout<<maxTeamKnowledge<<endl<<count<<endl;
    return(0);
}

