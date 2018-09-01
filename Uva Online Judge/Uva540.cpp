#include<bits/stdc++.h>
using namespace std;

int main(){

   int GroupNumber[1000001];
   int teamnumber;
   char command[20];
   int teamId;
   int testCases = 0;

   while(scanf("%d",&teamnumber) && teamnumber){
      int numberOfelements;

      for(int i = 1; i <= teamnumber; i++){

         scanf("%d",&numberOfelements);

         for(int j = 0; j < numberOfelements; j++){
            scanf("%d",&teamId);
            GroupNumber[teamId] = i;
         }
      }

      queue<int> teams[1001];
      queue<int> merge_queue;
      printf("Scenario #%d\n",++testCases);

      while(scanf("%s",command) && command[0] != 'S'){

         if(command[0] == 'E'){

            scanf("%d",&teamId);
            int Id = GroupNumber[teamId];
            if(teams[Id].empty()){
                merge_queue.push(Id);
            }

            teams[Id].push(teamId);
         }

         else
         {
             int topMost = merge_queue.front();

             printf("%d\n",teams[topMost].front());
             teams[topMost].pop();
             if(teams[topMost].empty())
                merge_queue.pop();
         }
      }
      printf("\n");
   }

   return 0;
}
