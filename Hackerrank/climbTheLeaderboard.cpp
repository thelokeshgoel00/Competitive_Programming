#include <bits/stdc++.h>
using namespace std;

struct player{
    long int score;
    long int position;
};

long int getPosition(vector<player> &,long int);

int main()
{
    long int players;
    cin>>players;

    vector<player> playerData(players);

    long int position = 1;
    cin>>playerData[0].score;
    playerData[0].position = position;
    long int lastScore = playerData[0].score;

    for(long int i=1;i<players;i++)
    {
        cin>>playerData[i].score;

        if(playerData[i].score != lastScore)
           position++;

        playerData[i].position = position;

        lastScore = playerData[i].score;   
    }

    long int games;
    cin>>games;

    for(long int i=0;i<games;i++)
    {
        long int aliceScore;
        cin>>aliceScore;
        long int alicePosition = getPosition(playerData,aliceScore);
        cout<<alicePosition<<endl;
    }

    return(0);
}

long int getPosition(vector<player> &leaderboards,long int score)
{
   long int leftIndex = 0;
   long int rightIndex = leaderboards.size()-1;
   long int searchIndex,playerPos;

   while(leftIndex <= rightIndex)
   {
       long int midIndex = (leftIndex+rightIndex)/2;
       long int midScore = leaderboards[midIndex].score;

       if(score > midScore)
          rightIndex = midIndex-1;

       if(score < midScore)
          leftIndex = midIndex+1;

        if(score == midScore)
          break;      
   }

    searchIndex = (leftIndex+rightIndex)/2;
    long int searchScore = leaderboards[searchIndex].score;
    long int searchPos = leaderboards[searchIndex].position;

    if(searchScore > score)
      playerPos = searchPos+1;
    else
      playerPos = searchPos;
         
    return(playerPos);   
}

